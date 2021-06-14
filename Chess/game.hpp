//
//  game.hpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "player.hpp"

using namespace std;

class game {
    
private:
    bool active;
    
    board* chessBoard;
    player* playerWhite;
    player* playerBlack;
    
    sf::Texture* chessPieceTexture;
    sf::Texture* dotTexture;
    
    int turn;
    
public:
    game();
    void generateEndScreen(sf::RenderWindow &window);
    void updateGame(sf::RenderWindow &window);
    void drawActivePieces(sf::RenderWindow &window, vector<string> validMoves);
    void drawValidMoves(sf::RenderWindow &window, vector<string> validMoves);
    
    chessPiece* returnActivePiece(string squareClicked, bool myPiece);
    vector<string> returnCastlingPositions(bool whiteTurn, chessPiece* king);
    
    void endGame();
    void restart();
    bool returnActive();
    void switchTurn();
    int returnTurn();
    ~game();
};

#endif /* game_hpp */
