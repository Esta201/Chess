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
#include <SFML/Graphics.hpp>

class player{
    
private:
    int score;
    string color;
    
    vector<chessPiece*> activePieces;
    vector<chessPiece*> inactivePieces;
    
    sf::Texture *chessPieceTexture;

    bool turn;
    
public:
    player(string color, sf::Texture *chessPieceTexture);
    
    int returnScore();
    string returnColor();
    bool returnTurn();
    
    chessPiece* returnValidPiece(string position);
    
    void calculateValidMoves(player &otherPlayer);
    void calculateScore();
    
    vector<chessPiece*> returnActivePieces();
    vector<chessPiece*> returnInactivePieces();
    
    void initializePawns();
    void initializeKnights();
    void initializeRooks();
    void initializeBishops();
    void initializeRoyals();
    
    ~player();
};

#endif /* player_hpp */
