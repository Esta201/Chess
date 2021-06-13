//
//  game.cpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#include "game.hpp"
#include "player.hpp"
#include <string>
#include <iostream>
#include "movementFunctions.hpp"
#include "ResourcePath.hpp"

using namespace std;
int first = 2;

chessPiece* activePiece;
chessPiece* opposingPiece;

bool active = false;

game::game() {
    
    //initialise the chess board
    this->chessBoard = new board();
    
    //import the texture for the chess pieces
    sf::Texture *chessPieceTexture = new sf::Texture();
    
    if (!chessPieceTexture->loadFromFile("Resources/chessPieces.png")) {
        cout << "Couldn't import chess piece images" << endl;
    }
    
    this->chessPieceTexture = chessPieceTexture;
    
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
                            if((activePiece->returnType() == "pawn") or (activePiece->returnType() == "rook")) {
                                vector<string> validMoves = activePiece->returnValidMoves();
                                if (find(squareClicked, validMoves)) {
                                    activePiece->movePiece(squareClicked);
                                    switchTurn();
                                }
                            }
                            else {
                            activePiece->movePiece(squareClicked);
                            switchTurn();
                            }
                            //switch turns
                            
                        }
                        active = false;
                        cout << squareClicked << endl;
                    }
                    break;
                }
                default:
                    break;
            }
            
            //update the board
            drawActivePieces(window);
        }
    }
}

void game::drawActivePieces(sf::RenderWindow &window) {
    
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
    
    window.display();
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
