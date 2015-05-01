//
//  AbstractFactory.cpp
//  Docos
//
//  Created by Austin Ruggles on 9/4/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#include "AbstractFactory.h"
#include "DocoA.h"

AbstractDoco* AbstractFactory::GetDoco(int x, int y, char type)
{
    if ( type == 'A' )
    {
        return new DocoA(x, y);
    }
    else return NULL;
}