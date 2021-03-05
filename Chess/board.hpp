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
    player playerWhite;
    player playerBlack;
    sf::Sprite chessBoard;
public:
    board();
    void switchTurn();
    sf::Sprite returnChessBoard();
};
#endif /* board_hpp */
