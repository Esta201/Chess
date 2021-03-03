//
//  main.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // insert code here...
    
    sf::RenderWindow window( sf::VideoMode( 800, 800), "Chess");
    sf::Texture chessBoard;
    chessBoard.loadFromFile("/Assets/chessBoard.png");
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
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
