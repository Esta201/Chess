//
//  pieceType.cpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#include "pieceType.hpp"
#include <SFML/Graphics.hpp>

pawn::pawn(string position, sf::Texture *chessPieceTexture, string color) : chessPiece(position, chessPieceTexture, color){
    sf::Sprite piece;
    piece.setTexture(*chessPieceTexture);
    piece.setTextureRect(sf::IntRect(1690, 20, 198, 250));
    piece.setScale(0.85, 0.7);
    this->piece = piece;
    
    movePiece(position);
}

pawn::~pawn() {
    ;
}
