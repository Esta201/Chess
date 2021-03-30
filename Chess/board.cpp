//
//  board.cpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#include "board.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"

#define BOARD_X 1400
#define BOARD_Y 1400
int prevRotate = 1;
board::board() {
    
    // generate background texture (chess board)
    sf::Texture* bgTexture = new sf::Texture();
    cout << resourcePath() << endl;
    if (!bgTexture->loadFromFile("Resources/chessBoard.png")) { //make texture path non-absolute
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
    
    //rotate the board 180 degrees
    chessBoard.rotate(180);
    if (prevRotate) {
        chessBoard.setPosition(BOARD_X, BOARD_Y);
    }
    else {
        chessBoard.setPosition(-BOARD_X, -BOARD_Y);
    }
    
    prevRotate = !prevRotate;
    
    //switch positions of all the chesspieces
}
board::~board() {
    delete bgTexture;
}
