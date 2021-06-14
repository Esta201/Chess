//
//  chessPieces.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//

#include "chessPiece.hpp"
#include <vector>
#include <iostream>
#include <list>
#include <stdio.h>
#include <sstream>
#include "movementFunctions.hpp"

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
    
    //initially, set first move to true
    this->firstMove = true;
    
    this->validMoves = vector<string>();
}

bool chessPiece::returnFirstMove() {
    return this->firstMove;
}

void chessPiece::setFirstMove(bool value) {
    this->firstMove = value;
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
    
    //find the difference between the new position and the old position, and change x and y position accordingly
    this->piece.move((int(newPos[0]) - int(this->position[0])) * MOVERIGHT,(int(this->position[1]) - int(newPos[1])) * MOVELEFT);
    
    //set new position of piece
    this->position = newPos;
    
}

void chessPiece::deactivate() {
    this->active = false;
}

void chessPiece::setValidMoves(vector<string> validMoves) {
    this->validMoves = validMoves;
}

void chessPiece::addToValidMoves(string value) {
    this->validMoves.push_back(value);
}

vector<string> chessPiece::returnValidMoves() {
    return this->validMoves;
}

void chessPiece::findValidMoves(bool turn, vector<string> whitePieces, vector<string> blackPieces) {
   setValidMoves(vector<string>()) ;
}

int chessPiece::returnVerticalPosition() {
    int vertPos;
    //convert digit position into integer
    stringstream ss;
    
    //convert position to integer
    ss << position[1];
    ss >> vertPos;
    
    return vertPos;
}

vector<string> chessPiece::calculateRepetitiveMovements(bool whiteMove, vector<string> whitePieces, vector<string> blackPieces, vector<int> horizontalMoveRules, vector<int> verticalMoveRules) {
    
    vector<string> validMoves = vector<string>();
    vector<int> horizontalMovement = horizontalMoveRules;
    vector<int> verticalMovement = verticalMoveRules;
    int verticalPosition = returnVerticalPosition();
    int horizontalPosition = (int)position[0];
    
    vector<string> ownPieces;
    vector<string> opposingPieces;
    
    if (whiteMove) {
        ownPieces = whitePieces;
        opposingPieces = blackPieces;
    } else {
        ownPieces = blackPieces;
        opposingPieces = whitePieces;
    }
    
    for (int i = 0; i < horizontalMovement.size(); i++) {
        bool canStillMove = true;
        int newVertical = verticalPosition;
        int newHorizontal = horizontalPosition;
        while(canStillMove) {
            
            //calculate the next position using the combination of horizontal and vertical movement (e.g., straight up, down, left, or right)
            newVertical = verticalMovement[i] + newVertical;
            newHorizontal = horizontalMovement[i] + newHorizontal; //holds the char value for letter
            string potentialMove = char(newHorizontal) + to_string(newVertical);

            //if it's out of bounds (e.g., vertical is out of the board, or the horizontal is out of the board (less than A or greater than H)
            if((newVertical < 1) or (newVertical > 8) or (newHorizontal < 97) or (newHorizontal > 104)) {
                canStillMove = false;
            }
            //if ownpiece in the way
            else if (find(potentialMove, ownPieces)) {
                canStillMove = false;
            }
            //if opposing piece in the way
            else if (find(potentialMove, opposingPieces)){
                validMoves.push_back(potentialMove);
                canStillMove = false;
            }
            //else
            else {
                validMoves.push_back(potentialMove);
            }
        }
    }
    
    return validMoves;
}

chessPiece::~chessPiece() {
    ;
}
