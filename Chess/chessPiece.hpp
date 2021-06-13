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

//abstract class
class chessPiece {
protected:
    
    int uniqueID;
    bool active;
    static int nextAvailableID;
    sf::Texture *chessPieceTexture;
    string color;
    bool firstMove;
    vector<string> validMoves;
    
    string type;
    //will be defined by subclasses
    sf::Sprite piece;

    string position;    
public:
    chessPiece(string position, sf::Texture *chessPieceTexture, string color);
    
    bool returnActive();
    string returnPosition();
    int returnID();
    string returnType();
    
    bool returnFirstMove();
    void setFirstMove(bool value);
    
    void deactivate();
    sf::Sprite returnPiece();
    void movePiece(string newPos);
    
    void createSprite(sf::Texture *chessPieceTexture, int xStart);
    
    //update all valid moves
    vector<string> returnValidMoves();
    void setValidMoves(vector<string> validMoves);
    virtual void findValidMoves(bool turn, vector<string> whitePieces, vector<string> blackPieces);
    int returnVerticalPosition();
    
    ~chessPiece();
};


#endif /* chessPieces_hpp */
