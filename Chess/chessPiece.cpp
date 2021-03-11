//
//  chessPieces.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//

#include "chessPiece.hpp"
#include <iostream>

#define MOVERIGHT 174.2
#define MOVELEFT 174.2

int xStart[6] = {1490, -30, 1165, 258, 550, 860};

int yStartWhite[6] = {382, 360, 350, 340, 350, 340};
int yStartBlack[6] = {0, -10, -10, -10, -10, -10};

int pieceWidth[6] = {198, 230, 270, 290, 285, 285};
int pieceHeight[6] = {233, 280, 280, 285, 280, 285};

float xScale[6] = {0.75, 0.65, 0.65, 0.60, 0.60, 0.60};
float yScale[6] = {0.7, 0.60, 0.60, 0.6, 0.6, 0.6};

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

void chessPiece::createSprite(sf::Texture *chessPieceTexture, int pieceStats) {
    sf::Sprite piece;
    piece.setTexture(*chessPieceTexture);
    
    if (this->color == "w") {
        piece.setTextureRect(sf::IntRect(xStart[pieceStats], yStartWhite[pieceStats], pieceWidth[pieceStats], pieceHeight[pieceStats]));
    }
    else {
        piece.setTextureRect(sf::IntRect(xStart[pieceStats], yStartBlack[pieceStats], pieceWidth[pieceStats], pieceHeight[pieceStats]));
    }
    
    piece.setScale(xScale[pieceStats], yScale[pieceStats]);
    this->piece = piece;

}

void chessPiece::movePiece(string newPos) {
    
    //find teh difference between the new position and the old position, and change x and y position accordingly
    this->piece.move((int(newPos[0]) - int(this->position[0])) * MOVERIGHT,(int(this->position[1]) - int(newPos[1])) * MOVELEFT);
    
    //set new position of piece
    this->position = newPos;
    
}

void chessPiece::deactivate() {
    this->active = false;
}

chessPiece::~chessPiece() {
    ;
}
