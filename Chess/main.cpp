//
//  main.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "chessPieces.hpp"
#include "movementFunctions.hpp"

using namespace std;

int main() {
    // generate window with a fixed size
    sf::RenderWindow window( sf::VideoMode(1400, 1400), "Chess", sf::Style::Close | sf::Style::Titlebar);

    
    // generate background texture (chess board)
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("/Users/earlene/Desktop/Chess/Chess/Assets/chessBoard.png")) { //make texture path non-absolute
        cout << "Background image couldn't be loaded" << endl;
    };
    
    // create sprite for background (chess board)
    sf::Sprite chessBoard;
    chessBoard.setTexture(boardTexture);
    
    chessBoard.setScale(0.7769, 0.7777);
    
    // create sprites for all chess pieces
    
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        cout << "x:" << event.mouseButton.x << endl;
                        cout << "y:" << event.mouseButton.y << endl;
                        string chessSquare = returnCurrentSquare(event.mouseButton.x, event.mouseButton.y, window.getSize().x, window.getSize().y);
                        cout << chessSquare << endl;
                    }
                    break;
                default:
                    break;
            }
        }
        
        window.clear();
        
        window.draw(chessBoard);
        
        window.display();
    }
    
    return 0;
}
