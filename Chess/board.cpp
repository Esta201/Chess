//
//  board.cpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#include "board.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#define BOARD_X 1400
#define BOARD_Y 1400
int prevRotate = 1;
board::board() {
    
    // generate background texture (chess board)
    sf::Texture* bgTexture = new sf::Texture();
    
    if (!bgTexture->loadFromFile("/Users/earlene/Desktop/Chess/Chess/Assets/chessBoard.png")) { //make texture path non-absolute
        cout << "Background image couldn't be loaded" << endl;
    };
    
    this->bgTexture = bgTexture;
    
    // create sprite for background (chess board)
    sf::Sprite chessBoard = sf::Sprite();
    chessBoard.setTexture(*bgTexture);
    chessBoard.setScale(0.7769, 0.7777);
    
    
    this->chessBoard = chessBoard;
}

sf::Sprite board::returnChessBoard() {
    return this->chessBoard;
}

void board::rotateBoard() {
    chessBoard.rotate(180);
    if (prevRotate) {
        chessBoard.setPosition(BOARD_X, BOARD_Y);
    }
    else {
        chessBoard.setPosition(-BOARD_X, -BOARD_Y);
    }
    
    prevRotate = !prevRotate;
    
}
board::~board() {
    delete bgTexture;
}
