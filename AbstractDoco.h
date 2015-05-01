//
//  AbstractDoco.h
//  Docos
//
//  Created by Austin Ruggles on 9/4/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#ifndef __Docos__AbstractDoco__
#define __Docos__AbstractDoco__

#include <iostream>
#include "string.h"
#include "Move.h"
class Move;
using namespace std;

class AbstractDoco
{
private:
    int xPos;
    int yPos;
    int iEnergy;
    
    string heading;
    string movement;
public:
    AbstractDoco();
    Move *m;
    
    void setEnergy(int plusMinus);
    int getEnergy();
    
    void setXpos(int plusMinus);
    int *getXpos();
    
    void setYpos(int plusMinus);
    int *getYpos();
    
    void setHeading(string h);
    string getHeading();
    
    void setMovement(string d);
    string getMovement();
    
    

    virtual ~AbstractDoco() = 0;
    virtual void draw() = 0;
    virtual void move() = 0;
};


#endif /* defined(__Docos__AbstractDoco__) */
