//
//  AbstractDoco.cpp
//  Docos
//
//  Created by Austin Ruggles on 9/4/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//
#include <iostream>
#include "AbstractDoco.h"



AbstractDoco::AbstractDoco()
{
    xPos = 0;
    yPos = 0;
    iEnergy = 0;
    heading = "H";
    movement = "M";
    m = new Move();
}

void AbstractDoco::setEnergy(int plusMinus)
{
    iEnergy += plusMinus;
}
int AbstractDoco::getEnergy()                  
{
    return iEnergy;
}

void AbstractDoco::setXpos(int plusMinus)       
{
    xPos += plusMinus;
}
int *AbstractDoco::getXpos()
{
    return &xPos;
}


void AbstractDoco::setYpos(int plusMinus)
{
    yPos += plusMinus;
}
int *AbstractDoco::getYpos()
{
    return &yPos;
}


void AbstractDoco::setHeading(string h)
{
    heading = h;
}
string AbstractDoco::getHeading()
{
    return heading;
}

void AbstractDoco::setMovement(string m)
{
    movement = m;
}
string AbstractDoco::getMovement()
{
    return movement;
}


AbstractDoco::~AbstractDoco() { }

void AbstractDoco::draw() { }

void AbstractDoco::move() { }







