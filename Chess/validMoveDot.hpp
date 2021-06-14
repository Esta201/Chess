//
//  validMoveDot.hpp
//  Chess
//
//  Created by Earlene on 14/06/21.
//

#ifndef validMoveDot_hpp
#define validMoveDot_hpp

#include <stdio.h>
#include <string>
using namespace std;
#include <SFML/Graphics.hpp>

class validMoveDot {
private:
    sf::Sprite dotSprite;
    string position;
public:
    
    validMoveDot(sf::Texture *dotTexture, string position);
    
    void createSprite(sf::Texture *dotTexture);
    void moveDot(string newPos);
    
    sf::Sprite returnSprite();
    
    ~validMoveDot();
};
#endif /* validMoveDot_hpp */
