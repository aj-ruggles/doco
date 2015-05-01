//
//  World.cpp
//  Docos
//
//  Created by Austin Ruggles on 9/10/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#include "World.h"

World::World()
{
    DocoFactory = new AbstractFactory();
    data = new DataParser("/Users/austinruggles/Documents/xCode Projects/Docos/Docos/DOCOData01.xml");
    util = new Utility();
    food = new Food();
    worldHeight = data->getDOCOWorldHeight();
    worldWidth  = data->getDOCOWorldWidth();
}


World::~World() { }


int World::getInstanceNumber()
{
    return this->instanceNumber;
}
World *World::getInstance()
{
    static World *theinstance;
    static int counter = 1;
    if (theinstance == NULL)
    {
        theinstance = new World();
        theinstance->instanceNumber = counter;
        counter++;
    }
    return theinstance;
}

Cell World::getCell(int x, int y)
{
    if (x < 0 || y < 0 || x > (worldHeight - 1) || y > (worldWidth - 1))
    {
        return cell[0][0];
    }
    else
        return cell[x][y];
}



void World::createFood(int howMany)
{
    int forceCheck = 0;
    while (howMany != 0)
    {
        forceCheck++;
        int x = util->Random(data->getDOCOWorldHeight());
        int y = util->Random(data->getDOCOWorldWidth());
        
        if ((cell[x][y].amountOfFood() < 3) && (cell[x][y].getDoco() == NULL))
        {
            cell[x][y].setFood(1);
            cell[x][y].setFoodptr(food);
            howMany--;
        }
        if (forceCheck == 1000)
        {
            return;
        }
    }
}
void World::removeFood(int x, int y)
{
    if (cell[x][y].amountOfFood() == 0)
    {
        return;
    }
    else
    {
        cell[x][y].setFoodptr(NULL);
        for (int remove = 0; remove < cell[x][y].amountOfFood(); remove++)
        {
            if (cell[x][y].amountOfFood() == 0)
            {
                break;
            }
            cell[x][y].setFood(-1);
        }
    }
}





void World::createDocos()
{
    ///*
    for (int count = 0; count < data->getDOCOCount(); count++)
    {
        AbstractDoco *m_doco = DocoFactory->GetDoco(0, 0, 'A');
        doco.push_back(m_doco);
    }
    
    for (int count = 0; count < data->getDOCOCount(); count++)
    {
        data->getDOCOData(NULL, doco[count]->getXpos(), doco[count]->getYpos());
    }
    //*/
    //AbstractDoco *m_doco = DocoFactory->GetDoco(2,2, 'A');
    //doco.push_back(m_doco);
}

void World::removeDoco(int x, int y)
{
    
}


void World::moveDoco()
{
    for (int count = 0; count < doco.size(); count++)
    {
        doco[count]->move();
    }
}




void World::createGrid()
{
    cell.resize(data->getDOCOWorldHeight());
    for (int i = 0; i < data->getDOCOWorldHeight(); i++)
    {
        cell[i].resize(data->getDOCOWorldWidth());
    }

    for (int row = 0; row < data->getDOCOWorldHeight(); row++)
    {
        for (int col = 0; col < data->getDOCOWorldWidth(); col++)
        {
            Cell m_cell = *new Cell();
            cell[row].push_back(m_cell);
        }
    }
    //Cell m_cell = *new Cell();
    //cell[100].push_back(m_cell);
}

void World::upDate()
{
    for (int row = 0; row < data->getDOCOWorldHeight(); row++)
    {
        for (int col = 0; col < data->getDOCOWorldWidth(); col++)
        {
            cell[row][col].setDocoptr(NULL);
        }
    }
    
    for (int count = 0; count < doco.size(); count++)
    {
        doco[count]->setEnergy(-10);
        cell[*doco[count]->getXpos()][*doco[count]->getYpos()].setDocoptr(doco[count]);
        if (doco[count]->getEnergy() <= 0)
        {
            doco.erase(doco.begin()+(count));
        }
    }
}



void World::draw()
{
    
    
    for (int row = 0; row < data->getDOCOWorldHeight(); row++)
    {
        for (int col = 0; col < data->getDOCOWorldWidth(); col++)
        {
            if ((cell[row][col].getDoco()) != nullptr)
            {
                AbstractDoco *tempDocoPtr;
                tempDocoPtr = cell[row][col].getDoco();
                tempDocoPtr->draw();
            }
            else if ((cell[row][col].getFood()) != nullptr)
            {
                Food *tempFoodPtr;
                tempFoodPtr = cell[row][col].getFood();
                tempFoodPtr->draw();
                //cout<<cell[row][col].amountOfFood();
            }
            else
            {
                cell[row][col].draw();
            }
        }
        cout<<endl;
    }
     /*
    for (int count = 0; count < doco.size(); count++)
    {
        cout<<*doco[count]->getXpos()<<"\t";
        cout<<*doco[count]->getYpos()<<"\t";
        cout<<doco[count]->getEnergy()<<"\t";
        cout<<doco[count]->getHeading()<<"\t\n";
    }*/
}