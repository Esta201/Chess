//
//  pieceType.cpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#include "pieceType.hpp"
#include <SFML/Graphics.hpp>

int pieceStartValues[6] = {1690, 1352, 996};

pawn::pawn(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color){
    this->type = "pawn";
    
    createSprite(chessPieceTexture, pieceStartValues[0]);
    movePiece(position);
}

pawn::~pawn() {
    ;
}

rook::rook(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color) {
    this->type = "rook";
    
    createSprite(chessPieceTexture, 1352);
    movePiece(position);
    
}

rook::~rook() {
    ;
}

knight::knight(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color) {
    this->type = "knight";
    
    createSprite(chessPieceTexture, pieceStartValues[2]);
    movePiece(position);
}
    
knight::~knight() {
    ;
}
