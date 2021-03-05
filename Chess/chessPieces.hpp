//
//  chessPieces.hpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//

#ifndef chessPieces_hpp
#define chessPieces_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>

using namespace std;

class dummyChessPiece {
    
private:
    
    sf::Sprite chessPiece;
    static int nextAvailableID;
    int uniqueID;
    string position;
    
public:
    
    dummyChessPiece(string position);
    sf::Sprite returnSprite() const;
    string returnPosition() const;
    
    void movePiece(string newPos);
    
};

#endif /* chessPieces_hpp */
