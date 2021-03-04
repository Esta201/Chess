//
//  main.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "initializationFunctions.hpp"

using namespace std;

int main() {
    // generate window
    sf::RenderWindow window( sf::VideoMode(1400, 1400), "Chess");
    
    // generate background texture (chess board)
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("/Users/earlene/Desktop/Chess/Chess/Assets/chessBoard.png")) { //make texture path non-absolute
        cout << "Background image couldn't be loaded" << endl;
    };
    
    // create sprite for background (chess board)
    sf::Sprite chessBoard;
    chessBoard.setTexture(boardTexture);
    
    chessBoard.setScale(0.729, 0.729);
    
    // create sprites for all chess pieces
    
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent (event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        
        window.clear();
        
        window.draw(chessBoard);
        
        initializePieces(window);
        
        window.display();
    }
    
    return 0;
}
