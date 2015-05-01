//
//  AbstractFactory.h
//  Docos
//
//  Created by Austin Ruggles on 9/4/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#ifndef __Docos__AbstractFactory__
#define __Docos__AbstractFactory__

#include <iostream>
#include "AbstractDoco.h"



// Abstract Factory returning a mobile
class AbstractFactory
{
public:
    AbstractDoco* GetDoco(int x, int y, char type);
};


#endif /* defined(__Docos__AbstractFactory__) */
