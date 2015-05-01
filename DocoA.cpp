//
//  DocoA.cpp
//  Docos
//
//  Created by Austin Ruggles on 9/4/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//_________________________________________//
//
//  implementaion class for DocoA.h
//  ~~subclass of AbstractDoco.h
//_________________________________________//
#include "DocoA.h"
DocoA::DocoA(int x, int y)
{
    setXpos(x);
    setYpos(y);
    setEnergy(500);
    setHeading("NN");
    setMovement("ALL");
}
DocoA::~DocoA()                         //delete dynamically allocated memory.
{
    
}
void DocoA::draw()                      //print doco symbole.
{
    cout<<"*";
}
void DocoA::move()
{
    m->freeMove(this);
}