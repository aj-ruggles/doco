//
//  Cell.cpp
//  Docos
//
//  Created by Austin Ruggles on 9/2/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#include "Cell.h"


Cell::Cell()
{
    m_iFoodCount = 0;             // int number of food in the cell
    ptrFood = NULL;
    ptrDoco = NULL;
    
}

bool Cell::isDoco()
{
    if (ptrDoco == NULL)
    {
        return false;
    }
    else return true;
}
bool Cell::isFood()
{
    if (ptrFood == NULL)
    {
        return false;
    }
    else return true;
}

int Cell::amountOfFood()
{
    return m_iFoodCount;
}
void Cell::setFood(int fc)
{
    m_iFoodCount += fc;
}




Food* Cell::getFood()
{
    return ptrFood;
}
void Cell::setFoodptr(Food *f)
{
    ptrFood = f;
}

AbstractDoco* Cell::getDoco()
{
    return ptrDoco;
}
void Cell::setDocoptr(AbstractDoco *d)
{
    ptrDoco = d;
}


void Cell::draw()
{
    std::cout<<"-";
}

Cell::~Cell() {}





