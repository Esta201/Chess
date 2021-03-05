//
//  chessPieces.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//

#include "chessPieces.hpp"
#include <iostream>

dummyChessPiece::dummyChessPiece(string position) {
    
    this->position = position;
    
    sf::Texture dummyTexture;
    if (!dummyTexture.loadFromFile("/Users/earlene/Desktop/Chess/Chess/Assets/pawn.png")) {
        cout << "Couldn't create dummy texture" << endl;;
    };
    
    sf::Sprite dummySprite;
    dummySprite.setTexture(dummyTexture);
    
    this->chessPiece = dummySprite;
};

sf::Sprite dummyChessPiece::returnSprite() const {
    return this->chessPiece;
}

string dummyChessPiece::returnPosition() const {
    return this->position;
}
