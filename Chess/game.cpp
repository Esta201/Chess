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

using namespace std;
int first = 2;
game::game() {
    
    //initialise the chess board
    this->chessBoard = new board();
    
    //create pointers to players
    playerWhite = new player("w");
    playerBlack = new player("b");
    
    //set game to active initially
    this->active = true;
    
    
}

void game::updateGame(sf::RenderWindow &window) {
    window.clear();
    window.draw(chessBoard->returnChessBoard());
    
    chessBoard->rotateBoard();

    window.display();
}

game::~game() {
    delete chessBoard;
    delete playerWhite;
    delete playerBlack;
}
