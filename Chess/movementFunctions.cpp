//
//  movementFunctions.cpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//

#include "movementFunctions.hpp"
#include <iostream>
#include <string>
#include <array>
#include "chessPiece.hpp"
#include "pieceType.hpp"

using namespace std;
// given the x and y coordinates of a click, return which chess square the user is on

string returnCurrentSquare(int mouseX, int mouseY, int windowX, int windowY) {
    //to find which square in the x direction the user is on, divide the location of the x and y positions by the length of a square
    int locationX = mouseX/(windowX/8); //how far to the right the user is
    int locationY = mouseY/(windowY/8); //how far down the user is
    
    //define inverse array for y vaulues (i.e, have it go from bottom to top, rather than the other way around)
    int inverseY[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    
    //convert x value to letter equivalent (a-h)
    locationX += 97;
    char xChar = locationX;
    
    return (string(1, xChar) + to_string(inverseY[locationY]));
}

bool find(string pos, vector<string> activePos) {
    
    if (std::find(activePos.begin(), activePos.end(), pos) != activePos.end()) {
        return true;
    }
    else {
        return false;
    };
}

