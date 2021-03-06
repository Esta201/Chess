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
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        
                        string chessSquare = returnCurrentSquare(event.mouseButton.x, event.mouseButton.y, window.getSize().x, window.getSize().y);
                        cout << chessSquare << endl;
                        
                        //hard code for the current dummy chess piece
//                        if (chessSquare == "a8") {
//                            chessPiece.movePiece("a8");
//                        };
                    }
                    break;
                default:
                    break;
            }
        }
        
        currentGame.updateGame(window);
    }
    
    return 0;
}
