//
//  player.hpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#ifndef player_hpp
#define player_hpp
#include <vector>
#include <stdio.h>
#include "chessPiece.hpp"

class player{
    
private:
    int score;
    string color;
    vector<chessPiece> activePieces;
    vector<chessPiece> inactivePieces;
    bool turn;
    
public:
    player(string color);
    int returnScore();
    char returnColor();
    bool returnTurn();
    void calculateScore();
    void updatePieces();
};

#endif /* player_hpp */
