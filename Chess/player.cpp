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
#include <vector>

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
    initializeKnightsRooksBishops();
    initializeRoyals();
    
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

void player::initializeKnightsRooksBishops() {
    string xPosRook = "ah";
    string xPosKnight = "bg";
    string xPosBishop = "cf";
    
    string yPos;
    
    if (this->color == "w") {
        yPos = "1";
    }
    else {
        yPos = "8";
    }
    string finalPosRook, finalPosBishop, finalPosKnight;
    for (int i = 0; i < 2; i++) {
        finalPosRook = xPosRook[i] + yPos;
        finalPosKnight = xPosKnight[i] + yPos;
        finalPosBishop = xPosBishop[i] + yPos;
        
        activePieces.push_back(new rook(finalPosRook, chessPieceTexture, this->color));
        activePieces.push_back(new knight(finalPosKnight, chessPieceTexture, this->color));
        activePieces.push_back(new bishop(finalPosBishop, chessPieceTexture, this->color));
    }
    
}

void player::initializeRoyals() {
    string xQueen = "e";
    string xKing = "d";
    string yPos;
    
    if (this->color == "w") {
        yPos = "1";
    }
    else {
        yPos = "8";
    }
    
    activePieces.push_back(new queen(xQueen + yPos, chessPieceTexture, this->color));
    activePieces.push_back(new king(xKing + yPos, chessPieceTexture, this->color));
    
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

void player::addToInactivePieces(chessPiece* pieceToRemove) {
    //change the piece from active to inactive
    pieceToRemove->deactivate();
    
    //find where the piece is in the active piece vector
    int id = pieceToRemove->returnID();
    //remove it from active vector
    for (int i = 0; i < activePieces.size(); i++) {
        chessPiece* currentPiece = activePieces[i];
        
        if (currentPiece->returnID() == id) {
            activePieces.erase(activePieces.begin() + i);
        }
    }
    //add it to inactive vector
    
    inactivePieces.push_back(pieceToRemove);
}

vector<string> player::returnActivePiecePos() {
    vector<string> activePiecePos = vector<string>();
    
    for (int i = 0; i < activePieces.size(); i++) {
        activePiecePos.push_back(activePieces[i]->returnPosition());
    }
    
    return activePiecePos;
}
player::~player() {
    ;
}

