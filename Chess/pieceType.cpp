//
//  pieceType.cpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include "pieceType.hpp"
#include <SFML/Graphics.hpp>
#include "movementFunctions.hpp"

int pieceStartValues[6] = {1514, 2, 1180};

pawn::pawn(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color){
    this->type = "pawn";
    
    createSprite(chessPieceTexture, 0);
    movePiece(position);
}

pawn::~pawn() {
    ;
}

void pawn::findValidMoves(bool whiteMove, vector<string> whitePieces, vector<string> blackPieces) {
    //turn == 0, means it's white, else it's black
    bool validMove;
    vector<int> vMovement;
    vector<int> hMovement = {-1, 1};
    vector<string> validMoves;
    vector<string> ownPieces;
    vector<string> opposingPieces;
    string potentialMove;
    int currentDigitPos;
    
    //convert digit position into integer
    stringstream ss;
    
    //convert position to integer
    ss << position[1];
    ss >> currentDigitPos;
    
    
    if (whiteMove) {
        ownPieces = whitePieces;
        opposingPieces = blackPieces;
        vMovement = {2, 1};
    }
    else {
        ownPieces = blackPieces;
        opposingPieces = whitePieces;
        vMovement = {-2, -1};
    }
    
    //if first turn, then do a check for two+
    for (int i = 0; i < vMovement.size(); i++) {
        potentialMove = position[0] + to_string(currentDigitPos + vMovement[i]);
        validMove = false;
        bool ownPieceInWay = find(potentialMove, ownPieces);
        bool opposingPieceInWay = find(potentialMove, opposingPieces);
        if (!ownPieceInWay and !opposingPieceInWay) {
            validMove = true;
        }
        
        if (i != 0 and validMove) {
            validMoves.push_back(potentialMove);
            cout << "not zero :  " + potentialMove << endl;
        }
        else {
            if (firstMove and validMove) {
                validMoves.push_back(potentialMove);
                setFirstMove(false);
                cout << "first turn : " + potentialMove << endl;
            }
        }
    }
    
    //check if there are opposing pieces diagonal, and allow to move
    for (int i = 0; i < hMovement.size(); i++) {
        int verticalMovement = vMovement[1]; //will be -1 or 1 depending on the color
        int horizontalMovement = hMovement[i]; //will be -1 or 1 for both white and black
        
        potentialMove = char((int)position[0] + horizontalMovement) + to_string(currentDigitPos + verticalMovement);
        cout << "horizontal move : " + potentialMove << endl;
        
        if (find(potentialMove, opposingPieces)) {
            validMoves.push_back(potentialMove);
        }
    }
    for (int i = 0; i < validMoves.size(); i++) {
        cout << validMoves[i] << endl;
    }
    setValidMoves(validMoves);
    
}

rook::rook(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color) {
    this->type = "rook";
    
    createSprite(chessPieceTexture, 1);
    movePiece(position);
    
}

rook::~rook() {
    ;
}

knight::knight(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color) {
    this->type = "knight";
    
    createSprite(chessPieceTexture, 2);
    movePiece(position);
}
    
knight::~knight() {
    ;
}

bishop::bishop(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color) {
    this->type = "bishop";
    
    createSprite(chessPieceTexture, 3);
    movePiece(position);
}

bishop::~bishop() {
    ;
}

king::king(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color) {
    this->type = "king";
    
    createSprite(chessPieceTexture, 4);
    movePiece(position);
}

king::~king() {
    ;
}

queen::queen(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color) {
    this->type = "queen";
    
    createSprite(chessPieceTexture, 5);
    movePiece(position);
}

queen::~queen() {
    ;
}
