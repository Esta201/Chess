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
    int verticalPosition = returnVerticalPosition();
    int horizontalPosition = (int)position[0];
    
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
        potentialMove = position[0] + to_string(verticalPosition + vMovement[i]);
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
        
        potentialMove = char(horizontalPosition + horizontalMovement) + to_string(verticalPosition + verticalMovement);
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

//no diagonal movement
//can move right, left, upwards/downwards, until you hit either own piece (can't move to that space) or opposing piece (can move into that space)
void rook::findValidMoves(bool whiteMove, vector<string> whitePieces, vector<string> blackPieces) {
    //initialize
    vector<string> validMoves = vector<string>();
    vector<int> horizontalMovement = {0, 0, 1, -1};
    vector<int> verticalMovement = {1, -1, 0, 0};
    int verticalPosition = returnVerticalPosition();
    int horizontalPosition = (int)position[0];
    
    vector<string> ownPieces;
    vector<string> opposingPieces;
    
    cout << "Rook valid moves" << endl;
    
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

    //set valid moves
    setValidMoves(validMoves);
    
}

rook::~rook() {
    ;
}

knight::knight(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color) {
    this->type = "knight";
    
    createSprite(chessPieceTexture, 2);
    movePiece(position);
}

void knight::findValidMoves(bool whiteMove, vector<string> whitePieces, vector<string> blackPieces) {
    vector<string> validMoves = vector<string>();
    vector<int> horizontalMovement = {1, -1, 2, -2, 1, -1, 2, -2};
    vector<int> verticalMovement = { 2,  2, 1,  1, -2, -2, -1, -1};
    int verticalPosition = returnVerticalPosition();
    int horizontalPosition = (int)position[0];
    
    vector<string> ownPieces;
    vector<string> opposingPieces;
    
    cout << "Knight valid moves" << endl;
    
    if (whiteMove) {
        ownPieces = whitePieces;
        opposingPieces = blackPieces;
    } else {
        ownPieces = blackPieces;
        opposingPieces = whitePieces;
    }
    
    for (int i = 0; i < horizontalMovement.size(); i++) {
        int newVertical = verticalPosition + verticalMovement[i];
        int newHorizontal = horizontalPosition + horizontalMovement[i];
        string potentialMove = char(newHorizontal) + to_string(newVertical);

        if(find(potentialMove, ownPieces)) {
            ;
        }
        else if((newVertical < 1) or (newVertical > 8) or (newHorizontal < 97) or (newHorizontal > 104)) {
            ;
        }
        else {
            validMoves.push_back(potentialMove);
        }
        
    }
    
    setValidMoves(validMoves);
    for (int i = 0; i < validMoves.size(); i++) {
        cout << "Valid knight move : " + validMoves[i] << endl;
    }
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
