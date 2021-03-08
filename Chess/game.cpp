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


using namespace std;
int first = 2;

chessPiece* activePiece;

game::game() {
    
    //initialise the chess board
    this->chessBoard = new board();
    
    //import the texture for the chess pieces
    sf::Texture *chessPieceTexture = new sf::Texture();
    
    if (!chessPieceTexture->loadFromFile("/Users/earlene/Desktop/Chess/Chess/Assets/chessPieces.png")) {
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
                case sf::Event::Closed:
                    window.close();
                    break;
                
                //if the mouse button is clicked, check that there's an active piece w/ the player's piece there
                case sf::Event::MouseButtonPressed: {
                    string squareClicked = returnCurrentSquare(event.mouseButton.x, event.mouseButton.y, window.getSize().x, window.getSize().y);
                    
                    
                    break;
                }
                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        string chessSquare = returnCurrentSquare(event.mouseButton.x, event.mouseButton.y, window.getSize().x, window.getSize().y);
                        cout << chessSquare << endl;
                    }
                    break;
                default:
                    break;
            }
            
            window.clear();
            window.draw(chessBoard->returnChessBoard());
            
            vector<chessPiece*> activePieces = playerWhite->returnActivePieces();
            
            chessPiece* pawn0 = activePieces[0];
            
            window.draw(pawn0->returnPiece());
            
            window.display();
        }
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
