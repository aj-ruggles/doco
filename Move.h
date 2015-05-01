//
//  Move.h
//  Docos
//
//  Created by Austin Ruggles on 9/6/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//


class AbstractDoco;
#ifndef Docos_Move_h
#define Docos_Move_h
#include <iostream>
#include <string>
#include "Utility.h"
#include "AbstractDoco.h"
#include "World.h"
class World;
class Cell;
class Move
{
private:
    Utility *u;
    World *w;
public:
    Move();
    ~Move();
    void checkDirection(AbstractDoco *d);
    void freeMove(AbstractDoco *d);
    
    void moveNW(AbstractDoco *d);
    void moveNN(AbstractDoco *d);
    void moveNE(AbstractDoco *d);
    void moveWW(AbstractDoco *d);
    void moveEE(AbstractDoco *d);
    void moveSW(AbstractDoco *d);
    void moveSS(AbstractDoco *d);
    void moveSE(AbstractDoco *d);
    
    
    
};




#endif

