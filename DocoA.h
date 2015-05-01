//
//  DocoA.h
//  Docos
//
//  Created by Austin Ruggles on 9/4/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#ifndef __Docos__DocoA__
#define __Docos__DocoA__

#include <iostream>
#include "AbstractDoco.h"
//_________________________________________//
//                                        
// Class defining DocoA With specific
//   perameters unique to its type
//        ~~subclass of AbstractDoco           
//_________________________________________//
class DocoA : public AbstractDoco
{
public:
    DocoA(int x, int y);
    ~DocoA();
    void draw();
    void move();
private:
};

#endif /* defined(__Docos__DocoA__) */