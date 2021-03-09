//
//  chessPieces.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//

#include "chessPiece.hpp"
#include <iostream>
#define X_SCALE 0.7
#define Y_SCALE 0.7
#define MOVERIGHT 174.2
#define MOVELEFT 174.2

#define PIECE_WIDTH 250
#define PIECE_HEIGHT 250
#define START_HEIGHT_WHITE 20
#define START_HEIGHT_BLACK 353


int chessPiece::nextAvailableID = 0;

chessPiece::chessPiece(string position, sf::Texture *chessPieceTexture, string color) {
    this->uniqueID = nextAvailableID;
    nextAvailableID++;
    this->active = true;
    
    //set default position of all pieces to a8
    this->position = "a8";
    
    this->chessPieceTexture = chessPieceTexture;
    this->color = color;
}

bool chessPiece::returnActive() {
    return this->active;
}

string chessPiece::returnPosition() {
    return this->position;
}

int chessPiece::returnID() {
    return this->uniqueID;
}

string chessPiece::returnType() {
    return this->type;
}

sf::Sprite chessPiece::returnPiece() {
    return this->piece;
}

void chessPiece::createSprite(sf::Texture *chessPieceTexture, int xStart) {
    sf::Sprite piece;
    piece.setTexture(*chessPieceTexture);
    
    if (this->color == "w") {
        piece.setTextureRect(sf::IntRect(xStart, START_HEIGHT_WHITE, PIECE_WIDTH, PIECE_HEIGHT));
    }
    else {
        piece.setTextureRect(sf::IntRect(xStart, START_HEIGHT_BLACK, PIECE_WIDTH, PIECE_HEIGHT));
    }
    
    piece.setScale(X_SCALE, Y_SCALE);
    this->piece = piece;

}

void chessPiece::movePiece(string newPos) {
    
    //find teh difference between the new position and the old position, and change x and y position accordingly
    this->piece.move((int(newPos[0]) - int(this->position[0])) * MOVERIGHT,(int(this->position[1]) - int(newPos[1])) * MOVELEFT);
    
    //set new position of piece
    this->position = newPos;
    
}

chessPiece::~chessPiece() {
    ;
}
