//
//  movementFunctions.hpp
//  Chess
//
//  Created by Earlene on 4/03/21.
//

#ifndef movementFunctions_hpp
#define movementFunctions_hpp

#include <stdio.h>
#include <string>

using namespace std;

string returnCurrentSquare(int x, int y, int windowX, int windowY);
bool find(string pos, vector<string> activePos);

#endif /* movementFunctions_hpp */
