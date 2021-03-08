//
//  player.cpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#include "player.hpp"
#include "chessPiece.hpp"
#include "pieceType.hpp"

#include <string>
using namespace std;

player::player(string color, sf::Texture *chessPieceTexture) {
    
    //determine whether the player is white or black
    this->color = color;
    
    //if the player is white, initially set their turn to true
    if (!(color.compare("w"))) {
        this->turn = true;
    }
    else {
        this->turn = false;
    }
    
    //initially set their score to 0
    this->score = 0;
    
    
    //initialize and add a pawn instance
    pawn *pawn0 = new pawn("a2", chessPieceTexture, "w");
    
    activePieces.push_back(pawn0);
    
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

player::~player() {
    ;
}

