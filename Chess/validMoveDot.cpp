//
//  validMoveDot.cpp
//  Chess
//
//  Created by Earlene on 14/06/21.
//

#include "validMoveDot.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
float size[] = {0.15, 0.15};
float initialOffset[] = {17, 16};

#define MOVERIGHT 174.2
#define MOVELEFT 174.2

validMoveDot::validMoveDot(sf::Texture *dotTexture, string position) {
    //create sprite
    createSprite(dotTexture);
    
    this->position = "a8"; //store starting position of dot
    //move to required position
    moveDot(position);
}

void validMoveDot::createSprite(sf::Texture *dotTexture) {
    sf::Sprite dotSprite;
    
    dotSprite.setTexture(*dotTexture);
    dotSprite.setScale(size[0], size[1]);
    dotSprite.move(initialOffset[0], initialOffset[1]);
    this->dotSprite = dotSprite;
    
}

void validMoveDot::moveDot(string newPos) {
    //find the difference between the new position and the old position, and change x and y position accordingly
    this->dotSprite.move((int(newPos[0]) - int(this->position[0])) * MOVERIGHT,(int(this->position[1]) - int(newPos[1])) * MOVELEFT);
    
    //set new position of piece
    this->position = newPos;
}

sf::Sprite validMoveDot::returnSprite() {
    return this->dotSprite;
}

validMoveDot::~validMoveDot() {
    ;
}
