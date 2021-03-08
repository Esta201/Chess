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
#include <vector>

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

//abstract class
class chessPiece {
protected:
    
    int uniqueID;
    bool active;
    static int nextAvailableID;
    sf::Texture *chessPieceTexture;
    string color;

    //will be defined by subclasses
    sf::Sprite piece;

    string position;
    vector<string> validMoves();
    
public:
    chessPiece(string position, sf::Texture *chessPieceTexture, string color);
    
    bool returnActive();
    string returnPosition();
    int returnID();
    
    sf::Sprite returnPiece();
    void movePiece(string newPos);

    ~chessPiece();
};


#endif /* chessPieces_hpp */
