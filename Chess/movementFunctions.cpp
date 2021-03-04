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
using namespace std;
// given the x and y coordinates of a click, return which chess square the user is on

string returnCurrentSquare(int mouseX, int mouseY, int windowX, int windowY) {
    //to find which square in the x direction the user is on, divide the location of the x and y positions by the length of a square
    int locationX = mouseX/(windowX/8); //how far to the right the user is
    int locationY = mouseY/(windowY/8); //how far down the user is
    
    //define inverse array for y vaulues
    int inverseY[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    
    locationX += 97;
    char xChar = locationX;
    cout << xChar << endl;
    return (string(1, xChar) + to_string(inverseY[locationY]));
}
