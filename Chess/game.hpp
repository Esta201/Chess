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

using namespace std;

class game {
    
private:
    board chessBoard;
    bool active;
public:
    game();
    void generateStartingScreen(sf::Window &window);
    void generateEndScreen(sf::Window &window);
    void endGame();
    void restart();
    bool returnActive();
};

#endif /* game_hpp */
