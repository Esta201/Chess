//
//  main.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "chessPiece.hpp"
#include "board.hpp"
#include "movementFunctions.hpp"
#include "game.hpp"

using namespace std;

int main() {
    // generate window with a fixed size
    sf::RenderWindow window( sf::VideoMode(1400, 1400), "Chess", sf::Style::Close | sf::Style::Titlebar);
    
    game currentGame = game();
        
    currentGame.updateGame(window);
    
    return 0;
}
