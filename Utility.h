//
//  Time.h
//  Docos
//
//  Created by Austin Ruggles on 9/1/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#ifndef __Docos__Utility__
#define __Docos__Utility__

#include <iostream>
#include <cstdlib>
#include <ctime>

class Utility
{
public:
    Utility();
    ~Utility();
    void delay(int sec);
    int Random(int max);
    int mSleep(unsigned long milisec);
};
#endif /* defined(__Docos__Time__) */
