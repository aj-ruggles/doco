//
//  Food.cpp
//  Docos
//
//  Created by Austin Ruggles on 9/3/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#include <iostream>
#include "Food.h"
Food::Food()
{
    m_iEnergy = 50;
}
Food::~Food() {}
int Food::getEnergy()
{
    return m_iEnergy;
}
void Food::draw()
{
    std::cout<<'.';
}