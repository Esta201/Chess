//
//  player.cpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#include "player.hpp"
#include "chessPiece.hpp"
#include "pieceType.hpp"
#include <iostream>
#include <string>

using namespace std;

player::player(string color, sf::Texture *chessPieceTexture) {
    
    //determine whether the player is white or black
    this->color = color;
    
    if (color == "w") {
        this->turn = true;
    }
    else {
        this->turn = false;
    }
    
    this->chessPieceTexture = chessPieceTexture;
    
    initializePawns();
    initializeRooks();
    initializeKnights();
    
    //initially set their score to 0
    this->score = 0;
    
}

//initialize pawns
void player::initializePawns() {
    //let white have first turn
    string row;
    
    //initialize eight pawns
    for (int i = 0; i <= 7; i++) {
        char xVal = char(97 + i);
        string position;
        position.push_back(xVal);
        if (this->color == "w") {
            row = "2";
        } else {
            row = "7";
        }
        position = position + row;
        
        activePieces.push_back(new pawn(position, chessPieceTexture, this->color));
    }
    
}

void player::initializeRooks() {
    string xPos = "ah";
    string yPos;
    
    if (this->color == "w") {
        yPos = "1";
    }
    else {
        yPos = "8";
    }
    string finalPos;
    for (int i = 0; i < 2; i++) {
        finalPos = xPos[i] + yPos;
        activePieces.push_back(new rook(finalPos, chessPieceTexture, this->color));
    }
    
}

void player::initializeKnights() {
    
    string xPos = "bg";
    string yPos;
    
    if (this->color == "w") {
        yPos = "1";
    }
    else {
        yPos = "8";
    }
    string finalPos;
    for (int i = 0; i < 2; i++) {
        finalPos = xPos[i] + yPos;
        activePieces.push_back(new knight(finalPos, chessPieceTexture, this->color));
    }
}

bool player::returnTurn() {
    return this->turn;
}

string player::returnColor() {
    return this->color;
}

int player::returnScore() {
    return this->score;
}

vector<chessPiece*> player::returnActivePieces() {
    return this->activePieces;
}

chessPiece* player::returnValidPiece(string position) {
    chessPiece* validPiece = NULL;
    
    //check whether there's an active piece in the given position
    for (int i = 0; i < activePieces.size(); i++) {
        if (!(activePieces[i]->returnPosition().compare(position))) {
            validPiece = activePieces[i];
        }
    }
    
    return validPiece;
}

player::~player() {
    ;
}

