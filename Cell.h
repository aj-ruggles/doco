//
//  Cell.h
//  Docos
//
//  Created by Austin Ruggles on 9/2/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#ifndef __Docos__Cell__
#define __Docos__Cell__

#include <iostream>
#include <string>
#include "AbstractDoco.h"
#include "Food.h"


class Cell
{
private:
    int m_iFoodCount;       // int number of food in the cell
    bool m_bFood;           // bool check if food
    bool m_bDoco;           // bool check if doco
    Food *ptrFood;
    AbstractDoco *ptrDoco;
public:
    
    /*
     * default destructor
     */
    
    ~Cell();
    
    /*
     * default constructor...
     */
    Cell();
    
    bool isDoco();
    bool isFood();
    
    //returns the number of food in the cell
    int amountOfFood();
    void setFood(int fc);
    
    //there can be upto 3 food in each cell, a simple check to see if there is a food
    Food *getFood();
    void setFoodptr(Food *f);
    
    //This is a simple check to see if there is a doco in the cell
    AbstractDoco *getDoco();
    void setDocoptr(AbstractDoco *d);
    
    //This will draw the char symbole for the cell '-'
    void draw();
};

#endif /* defined(__Docos__Cell__) */
