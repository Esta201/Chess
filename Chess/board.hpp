//
//  board.hpp
//  Chess
//
//  Created by Earlene on 5/03/21.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class board {
private:
    sf::Sprite chessBoard;
    sf::Texture *bgTexture;
public:
    board();
    void rotateBoard();
    sf::Sprite returnChessBoard();
    
    ~board();
};
#endif /* board_hpp */
