//
//  game.cpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#include "game.hpp"
#include "player.hpp"
#include "validMoveDot.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "movementFunctions.hpp"
#include "ResourcePath.hpp"

using namespace std;
int first = 2;

chessPiece* activePiece;
chessPiece* opposingPiece;

bool active = false;
bool mousePressed = false;

vector<string> castlingMoves;

game::game() {
    
    //initialise the chess board
    this->chessBoard = new board();
    
    //import the texture for the chess pieces
    sf::Texture *chessPieceTexture = new sf::Texture();
    sf::Texture *dotTexture = new sf::Texture();
    
    if (!chessPieceTexture->loadFromFile("Resources/chessPieces.png")) {
        cout << "Couldn't import chess piece images" << endl;
    }
    
    if (!dotTexture->loadFromFile("Resources/dot.png")) {
        cout << "Couldn't import do image" << endl;
    }
    
    this->chessPieceTexture = chessPieceTexture;
    this->dotTexture = dotTexture;
    
    //create pointers to players
    this->playerWhite = new player("w", chessPieceTexture);
    this->playerBlack = new player("b", chessPieceTexture);
    
    //set game to active initially
    this->active = true;
    
    //set initial turn to white
    this->turn = 1;
}

void game::updateGame(sf::RenderWindow &window) {
    
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            switch (event.type) {
                    
                //close the window if user clicks the exit button
                case sf::Event::Closed: {
                    window.close();
                    break;
                }
                //if the mouse button is clicked, check that there's an active piece w/ the player's piece there
                case sf::Event::MouseButtonPressed: {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        string squareClicked = returnCurrentSquare(event.mouseButton.x, event.mouseButton.y, window.getSize().x, window.getSize().y);
                            activePiece = returnActivePiece(squareClicked, true);
                        
                        //if there's a valid piece in the chosen square, store the piece as the current "Active Piece"
                        if (activePiece != NULL) {
                            active = true;
                            
                            //update all valid moves for the chosen piece
                            activePiece->findValidMoves(returnTurn(), playerWhite->returnActivePiecePos(), playerBlack->returnActivePiecePos());
                            if (activePiece->returnType() == "king") {
                                castlingMoves = returnCastlingPositions(turn, activePiece);
                            }
                            mousePressed = true;
                            drawValidMoves(window, activePiece->returnValidMoves());
                            cout << activePiece->returnPosition() << endl;
                        }
                        else {
                            active = false;
                        }
                        
                        break;
                    }
                }
                

                case sf::Event::MouseButtonReleased: {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        string squareClicked = returnCurrentSquare(event.mouseButton.x, event.mouseButton.y, window.getSize().x, window.getSize().y);

                        if (active) {
                            chessPiece* ownPiece = returnActivePiece(squareClicked, true);
                            
                            if (squareClicked == activePiece->returnPosition()) {
                                active = false;
                            }
                            //check if player has their own active piece the chosen square
                            else if(ownPiece != NULL){
                                //don't allow player to move into own piece square
                                active = false;
                            }
                        }

                        if (active) {
                            
                            //check if the opposing player has a piece in the square chosen
                            
                            //if so, deactivate the other players piece
                            opposingPiece = returnActivePiece(squareClicked, false);
                            if (opposingPiece != NULL) {
                                if (returnTurn() == 1) {
                                    playerBlack->addToInactivePieces(opposingPiece);
                                    cout << "Recognizes opposing black piece" << endl;
                                }
                                else {
                                    playerWhite->addToInactivePieces(opposingPiece);
                                    cout << "Recognizes opposing white piece" << endl;
                                }
                            }
                            
                            //this needs to be updated to check that it's a valid move
                            //move the active piece into its chosen square
                            if((activePiece->returnType() == "pawn") or (activePiece->returnType() == "rook") or (activePiece->returnType() == "knight") or (activePiece->returnType() == "bishop") or (activePiece->returnType() == "queen")) {
                                vector<string> validMoves = activePiece->returnValidMoves();
                                if (find(squareClicked, validMoves)) {
                                    activePiece->movePiece(squareClicked);
                                    switchTurn();
                                }
                            }
                            else if (activePiece->returnType() == "king") {
                                activePiece->movePiece(squareClicked); //move king two places over
                                //move the bishop as well
                                for (int i = 0; i < 2; i++) {
                                    if (castlingMoves[i] != "0") {
                                        chessPiece* rook = returnActivePiece(castlingMoves[i + 2], true); //get the bishop
                                        rook->movePiece(castlingMoves[i]); //move it to new valid position
                                        rook->setFirstMove(false);
                                    }
                                }
                                
                                switchTurn();
                            }
                            else {
                                activePiece->movePiece(squareClicked);
                                switchTurn();
                            }
                            
                            activePiece->setFirstMove(false); //set first move to false after moving the piece for the first time
                            //switch turns
                            
                        }
                        
                        active = false;
                        mousePressed = false;
                        cout << squareClicked << endl;
                    }
                    break;
                }
                default:
                    break;
            }
            
            //update the board
            vector<string> validMoves;
            if (activePiece != NULL) {
                validMoves = activePiece->returnValidMoves();
            } else {
                validMoves = vector<string>();
            }
            drawActivePieces(window, validMoves);
        }
    }
}

void game::drawActivePieces(sf::RenderWindow &window, vector<string> validMoves) {
    
    window.clear();
    window.draw(chessBoard->returnChessBoard());
    
    //draw all active white pieces
    vector<chessPiece*> activeWhitePieces = playerWhite->returnActivePieces();
    
    for (int i = 0; i < activeWhitePieces.size(); i++) {
        chessPiece* whitePiece = activeWhitePieces[i];
        window.draw(whitePiece->returnPiece());
    }
    
    vector<chessPiece*> activeBlackPieces = playerBlack->returnActivePieces();
    //draw all acive black places
    
    for (int i = 0; i < activeBlackPieces.size(); i++) {
        chessPiece* blackPiece = activeBlackPieces[i];
        window.draw(blackPiece->returnPiece());
    }
    
    if (mousePressed == true) {
        drawValidMoves(window, validMoves);
    }
    
    window.display();
}

void game::drawValidMoves(sf::RenderWindow &window, vector<string> validMoves) {
    //create a new valid move testing sprite
    
    for (int i = 0; i < validMoves.size(); i++) {
        validMoveDot testingDot = validMoveDot(dotTexture, validMoves[i]);
        window.draw(testingDot.returnSprite());
    }
    
}

//calculates and sets castling pieces for chosen king, based on who's turn it is and whether the active bishops have their first turn, etc.
vector<string> game::returnCastlingPositions(bool whiteTurn, chessPiece* king) {
    vector<string> validCastlingMoves = {"0", "0"};
    //check that it's king's first turn
    bool kingFirstMove = king->returnFirstMove();
    vector<chessPiece*> ownPieces;
    vector<chessPiece*> opposingPieces;
    string rookOGPos[2];
    
    cout << "checking castling" << endl;
    
    //calculate opposing and own pieces
    if (whiteTurn) {
        ownPieces = playerWhite->returnActivePieces();
        opposingPieces = playerBlack->returnActivePieces();
        rookOGPos[0]= "a1";
        rookOGPos[1] = "h1";
    }
    else {
        ownPieces = playerBlack->returnActivePieces();
        opposingPieces = playerWhite->returnActivePieces();
        rookOGPos[0] = "a8";
        rookOGPos[1] = "h8";
    }
    
    //return activePiece in this position
    //if not null, check that it's a bishop with its first turn active --> must be a valid bishop
    for (int i = 0; i < 2; i++) {
        chessPiece* rook = returnActivePiece(rookOGPos[i], true); //return own piece in this piece
        if (rook != NULL and kingFirstMove) {
            bool firstTurn = rook->returnFirstMove();
            bool isBishop = rook->returnType() == "rook";
            if (firstTurn and isBishop) {
                int kingHorizontalPosition = (int)king->returnPosition()[0];
                int kingVerticalPosition = king->returnVerticalPosition();
                //calculate new valid for kingside bishop
                if (i == 1) {
                    bool nothingInTheWay = true;
                    //calculate if any pieces are in the way
                    for (int j = 1; j < 3; j++) { //j = 1, j = 2
                        string position = char(kingHorizontalPosition + j) + to_string(kingVerticalPosition);
                        if ( (returnActivePiece(position, true) != NULL) or (returnActivePiece(position, false) != NULL) ) {
                            nothingInTheWay = false;;
                        }
                    }
                    
                    if (nothingInTheWay) {
                        string validCastlingMove = char(kingHorizontalPosition + 2) + to_string(kingVerticalPosition);
                        king->addToValidMoves(validCastlingMove);
                        
                        string rookPosition = rookOGPos[1];
                        string newRookPosition = char(int(rookPosition[0]) - 2) + to_string(rook->returnVerticalPosition());
                        
                        cout << "New rook position : " + newRookPosition << endl;
                        
                        //calculate new rook position
                        validCastlingMoves[i] = newRookPosition;
                    }
                }
                else {
                    ; //add in calculations for bishop 2;
                }
            }
            else {
                validCastlingMoves[i] = "0";
            }
        } else {
            validCastlingMoves[i] = "0";
        }
    }
    
    //append original bishop positions to the end of the output
    for (int i = 0; i < 2; i++) {
        validCastlingMoves.push_back(rookOGPos[i]);
    }
    
    for (int i = 0; i < validCastlingMoves.size(); i++) {
        cout << validCastlingMoves[i] << endl;
    }
    
    return validCastlingMoves;
    
}

chessPiece* game::returnActivePiece(string squareClicked, bool myPiece) {
    
    //check whether the player who's turn it is has a valid piece in the chosen square
    chessPiece* validPiece = NULL;
    
        if (turn == 1) {
            if (myPiece) {
                validPiece = playerWhite->returnValidPiece(squareClicked);
            }
            else {
                validPiece = playerBlack->returnValidPiece(squareClicked);
            }
        }
        else {
            if (myPiece) {
                validPiece = playerBlack->returnValidPiece(squareClicked);
            }
            else {
                validPiece = playerWhite->returnValidPiece(squareClicked);
            }
            
        }
        
        return validPiece;
}


void game::switchTurn() {
    
    if (this->turn == 1) {
        this->turn = 0;
    }
    else {
        turn = 1;
    }
    
}

int game::returnTurn() {
    return this->turn;
}

game::~game() {
    delete chessBoard;
    delete playerWhite;
    delete playerBlack;
    delete chessPieceTexture;
}
