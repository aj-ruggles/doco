//
//  Food.h
//  Docos
//
//  Created by Austin Ruggles on 9/3/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#ifndef Docos_Food_h
#define Docos_Food_h
#include <iostream>


class Food
{
private:
    int m_iEnergy;
public:
    
    Food();
    ~Food();
    int getEnergy();
    void draw();
};


#endif
