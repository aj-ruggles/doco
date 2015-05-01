//
//  Move.cpp
//  Docos
//
//  Created by Austin Ruggles on 9/8/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#include "Move.h"

Move::Move()
{
    u = new Utility();
    w = World::getInstance();
}
void Move::checkDirection(AbstractDoco *d)
{
    int amountOfFood = 0;
    
    if (w->getCell((*d->getXpos() - 1), (*d->getYpos() - 1)).isFood() &&
        (w->getCell((*d->getXpos() - 1), (*d->getYpos() - 1)).amountOfFood() > amountOfFood))
    {
        amountOfFood = w->getCell((*d->getXpos() - 1), (*d->getYpos() - 1)).amountOfFood();
        
        d->setHeading("NW");
    }
    if (w->getCell((*d->getXpos() - 1), *d->getYpos()).isFood() &&
        (w->getCell((*d->getXpos() - 1), (*d->getYpos())).amountOfFood() > amountOfFood))
    {
        amountOfFood = w->getCell((*d->getXpos() - 1), (*d->getYpos())).amountOfFood();
        
        d->setHeading("NN");
    }
    if (w->getCell((*d->getXpos() - 1), (*d->getYpos() + 1)).isFood() &&
        (w->getCell((*d->getXpos() - 1), (*d->getYpos() + 1)).amountOfFood() > amountOfFood))
    {
        amountOfFood = w->getCell((*d->getXpos() - 1), (*d->getYpos() + 1)).amountOfFood();
        
        d->setHeading("NE");
    }
    if (w->getCell(*d->getXpos(), (*d->getYpos() + 1)).isFood() &&
        (w->getCell((*d->getXpos()), (*d->getYpos() + 1)).amountOfFood() > amountOfFood))
    {
        amountOfFood = w->getCell((*d->getXpos()), (*d->getYpos() + 1)).amountOfFood();
        
        d->setHeading("EE");
    }
    if (w->getCell(*d->getXpos(), (*d->getYpos() - 1)).isFood() &&
        (w->getCell((*d->getXpos()), (*d->getYpos() - 1)).amountOfFood() > amountOfFood))
    {
        amountOfFood = w->getCell((*d->getXpos()), (*d->getYpos() - 1)).amountOfFood();
        
        d->setHeading("WW");
    }
    if (w->getCell((*d->getXpos() + 1), (*d->getYpos() - 1)).isFood() &&
        (w->getCell((*d->getXpos() + 1), (*d->getYpos() - 1)).amountOfFood() > amountOfFood))
    {
        amountOfFood = w->getCell((*d->getXpos() + 1), (*d->getYpos() - 1)).amountOfFood();
        
        d->setHeading("SW");
    }
    if (w->getCell((*d->getXpos() + 1), *d->getYpos()).isFood() &&
        (w->getCell((*d->getXpos() + 1), (*d->getYpos())).amountOfFood() > amountOfFood))
    {
        amountOfFood = w->getCell((*d->getXpos() + 1), (*d->getYpos())).amountOfFood();
        
        d->setHeading("SS");
    }
    if (w->getCell((*d->getXpos() + 1), (*d->getYpos() + 1)).isFood() &&
        (w->getCell((*d->getXpos() + 1), (*d->getYpos() + 1)).amountOfFood() > amountOfFood))
    {
        amountOfFood = w->getCell((*d->getXpos() + 1), (*d->getYpos() + 1)).amountOfFood();
        
        d->setHeading("SE");
    }
    
    if ((*d->getXpos() == 0) &&
        ((d->getHeading() == "NW") || (d->getHeading() == "NN") ||
         (d->getHeading() == "NE")))
    {
        switch (u->Random(5))
        {
            case 0:
                d->setHeading("EE");
                break;
            case 1:
                d->setHeading("WW");
                break;
            case 2:
                d->setHeading("SW");
                break;
            case 3:
                d->setHeading("SS");
                break;
            case 4:
                d->setHeading("SE");
                break;
            default:
                break;
        }
    }
    else if ((*d->getXpos() == (w->worldHeight -1) &&
              ((d->getHeading() == "SW") || (d->getHeading() == "SS") ||
               (d->getHeading() == "SE"))))
    {
        switch (u->Random(5))
        {
            case 0:
                d->setHeading("EE");
                break;
            case 1:
                d->setHeading("WW");
                break;
            case 2:
                d->setHeading("NW");
                break;
            case 3:
                d->setHeading("NE");
                break;
            case 4:
                d->setHeading("NN");
                break;
            default:
                break;
        }
    }
    else if ((*d->getYpos() == 0) &&
             ((d->getHeading() == "SW") || (d->getHeading() == "WW") ||
              (d->getHeading() == "NW")))
    {
        switch (u->Random(5))
        {
            case 0:
                d->setHeading("NN");
                break;
            case 1:
                d->setHeading("SS");
                break;
            case 2:
                d->setHeading("SE");
                break;
            case 3:
                d->setHeading("EE");
                break;
            case 4:
                d->setHeading("NE");
                break;
            default:
                break;
        }
    }
    else if ((*d->getYpos() == (w->worldWidth - 1) &&
              ((d->getHeading() == "NE") || (d->getHeading() == "EE") ||
               (d->getHeading() == "SE"))))
    {
        switch (u->Random(5))
        {
            case 0:
                d->setHeading("WW");
                break;
            case 1:
                d->setHeading("NW");
                break;
            case 2:
                d->setHeading("SW");
                break;
            case 3:
                d->setHeading("SS");
                break;
            case 4:
                d->setHeading("NN");
                break;
            default:
                break;
        }
    }
    if ((*d->getXpos() == 0) && (*d->getYpos() == 0) &&
        ((d->getHeading() == "WW") || (d->getHeading() == "NW") ||
         (d->getHeading() == "SW") || (d->getHeading() == "NN") || (d->getHeading() == "NE")))
    {
        switch (u->Random(3))
        {
            case 0:
                d->setHeading("EE");
                break;
            case 1:
                d->setHeading("SS");
                break;
            case 2:
                d->setHeading("SE");
                break;
            default:
                break;
        }
    }
    else if ((*d->getXpos() == (w->worldHeight - 1)) && (*d->getYpos() == 0) &&
             ((d->getHeading() == "NW") || (d->getHeading() == "WW") ||
              (d->getHeading() == "SW") || (d->getHeading() == "SS") || (d->getHeading() == "SE")))
    {
        switch (u->Random(3))
        {
            case 0:
                d->setHeading("NN");
                break;
            case 1:
                d->setHeading("EE");
                break;
            case 2:
                d->setHeading("NE");
                break;
            default:
                break;
        }
    }
    else if ((*d->getXpos() == (w->worldHeight - 1)) && (*d->getYpos() == (w->worldWidth - 1)) &&
             ((d->getHeading() == "EE") || (d->getHeading() == "SE") ||
              (d->getHeading() == "SS") || (d->getHeading() == "SW") || (d->getHeading() == "NE")))
    {
        switch (u->Random(3))
        {
            case 0:
                d->setHeading("WW");
                break;
            case 1:
                d->setHeading("NW");
                break;
            case 2:
                d->setHeading("NN");
                break;
            default:
                break;
        }
    }
    else if ((*d->getXpos() == 0) && (*d->getYpos() == (w->worldWidth - 1)) &&
             ((d->getHeading() == "NW") || (d->getHeading() == "NN") ||
              (d->getHeading() == "NE") || (d->getHeading() == "EE") || (d->getHeading() == "SE")))
    {
        switch (u->Random(3))
        {
            case 0:
                d->setHeading("WW");
                break;
            case 1:
                d->setHeading("SS");
                break;
            case 2:
                d->setHeading("SW");
                break;
            default:
                break;
        }
    }
    else return;
    
}



void Move::freeMove(AbstractDoco *d)
{
    if (w->getCell(*d->getXpos(), *d->getYpos()).amountOfFood() > 0)
    {
        w->removeFood(*d->getXpos(), *d->getYpos());
        d->setEnergy(w->getCell(*d->getXpos(), *d->getYpos()).amountOfFood() * 50);
    }
    checkDirection(d);
    if (d->getHeading() == "NN")
        moveNN(d);
    else if (d->getHeading() == "NW")
        moveNW(d);
    else if (d->getHeading() == "NE")
        moveNE(d);
    else if (d->getHeading() == "EE")
        moveEE(d);
    else if (d->getHeading() == "WW")
        moveWW(d);
    else if (d->getHeading() == "SW")
        moveSW(d);
    else if (d->getHeading() == "SS")
        moveSS(d);
    else if (d->getHeading() == "SE")
        moveSE(d);
    else exit(0);
}










void Move::moveNW(AbstractDoco *d)
{
    d->setXpos(-1);
    d->setYpos(-1);
}
void Move::moveNN(AbstractDoco *d)
{
    d->setXpos(-1);
}
void Move::moveNE(AbstractDoco *d)
{
    d->setXpos(-1);
    d->setYpos(1);
}
void Move::moveWW(AbstractDoco *d)
{
    d->setYpos(-1);
}
void Move::moveEE(AbstractDoco *d)
{
    d->setYpos(1);
}
void Move::moveSW(AbstractDoco *d)
{
    d->setXpos(1);
    d->setYpos(-1);
}
void Move::moveSS(AbstractDoco *d)
{
    d->setXpos(1);
}
void Move::moveSE(AbstractDoco *d)
{
    d->setXpos(1);
    d->setYpos(1);
}
