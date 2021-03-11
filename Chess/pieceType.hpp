//
//  pieceType.hpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#ifndef pieceType_hpp
#define pieceType_hpp

#include <stdio.h>
#include "chessPiece.hpp"

class pawn: public chessPiece {
private:
public:
    pawn(string position, sf::Texture *chessPieceTexture, string color);
        
    ~pawn();
};

class knight: public chessPiece {
private:
public:
    knight(string position, sf::Texture *chessPieceTexture, string color);
        
    ~knight();
};

class bishop: public chessPiece {
private:
public:
    bishop(string position, sf::Texture *chessPieceTexture, string color);
        
    ~bishop();
};

class rook: public chessPiece {
private:
public:
    rook(string position, sf::Texture *chessPieceTexture, string color);
    
    ~rook();
};

class queen: public chessPiece {
private:
public:
    queen(string position, sf::Texture *chessPieceTexture, string color);
    
    ~queen();
};

class king: public chessPiece {
private:
public:
    king(string position, sf::Texture *chessPieceTexture, string color);
    
    ~king();
};

#endif /* pieceType_hpp */
