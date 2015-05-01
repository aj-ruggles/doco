//
//  World.h
//  Docos
//
//  Created by Austin Ruggles on 9/10/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#ifndef __Docos__World__
#define __Docos__World__
#include <iostream>
#include <vector>
#include "DataParser.h"
#include "AbstractDoco.h"
#include "AbstractFactory.h"
#include "Food.h"
#include "Cell.h"
#include "Utility.h"

class AbstractFactory;
class Cell;
class World
{

private:
    AbstractFactory *DocoFactory;
    Utility *util;
    DataParser *data;
    Food *food;
    vector<AbstractDoco*> doco;
    vector<vector<Cell>> cell;
    
    int instanceNumber;
    World();
public:
    int worldHeight;
    int worldWidth;
    
    ~World();
    static World *getInstance();
    int getInstanceNumber();
    
    Cell getCell(int x, int y);
        
    void createFood(int howMany);
    void removeFood(int x, int y);

    void createDocos();
    void removeDoco(int x, int y);
    void moveDoco();    

    
    
    void createGrid();
    
    void upDate();

    void draw();
};



#endif /* defined(__Docos__World__) */

