//
//  chessPieces.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//

#include "chessPiece.hpp"
#include <iostream>
#define INITIAL_OFFSET_X 3
#define INITIAL_OFFSET_Y 3
#define MOVERIGHT 174.2
#define MOVELEFT 174.2

int dummyChessPiece::nextAvailableID = 1;

dummyChessPiece::dummyChessPiece(string position) {
    
    this->position = position;
    
    // assign a unique ID to this chess piece
    this->uniqueID = nextAvailableID;
    nextAvailableID++;
    
    // create a dummy sprite (in future iterations, this will be a separate class that inherits from class type chess piece (e.g., create something separate for pawns, queens, etc. You can't generate just a piece on its own)
    sf::Texture dummyTexture;
    if (!dummyTexture.loadFromFile("/Users/earlene/Desktop/Chess/Chess/Assets/pawn.png")) {
        cout << "Couldn't create dummy texture" << endl;;
    };
    
    sf::Sprite dummySprite;
    dummySprite.setTexture(dummyTexture);
    
    // set up initial location/size for the piece
    dummySprite.setScale(0.27, 0.27);
    dummySprite.move(INITIAL_OFFSET_X, INITIAL_OFFSET_Y);
    this->chessPiece = dummySprite;
};

sf::Sprite dummyChessPiece::returnSprite() const {
    return this->chessPiece;
}

string dummyChessPiece::returnPosition() const {
    return this->position;
}

void dummyChessPiece::movePiece(string newPos) {
    
    this->chessPiece.move(MOVERIGHT, MOVELEFT);
    
}

int chessPiece::nextAvailableID;

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

sf::Sprite chessPiece::returnPiece() {
    return this->piece;
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
