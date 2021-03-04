//
//  initializationFunctions.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "initializationFunctions.hpp"

using namespace std;

void initializePieces(sf::RenderWindow &window) {
// download catch-all png
sf::Texture chessPieces;
if (!chessPieces.loadFromFile("/Users/earlene/Desktop/Chess/Chess/Assets/chessPieces.png")) {
    cout << "Chess pieces image couldn't be loaded" << endl;
};

//create pawn sprite
sf::Sprite pawn;

pawn.setTexture(chessPieces);
pawn.setTextureRect(sf::IntRect(1800, 200, 100, 300));

    window.draw(pawn);
    
}
