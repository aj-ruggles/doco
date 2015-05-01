//
//  Time.cpp
//  Docos
//
//  Created by Austin Ruggles on 9/1/12.
//  Copyright (c) 2012 Austin Ruggles. All rights reserved.
//

#include "Utility.h"


Utility::Utility()
{
    srand( static_cast<int>( time(NULL)) );
}
Utility::~Utility()
{
    
}
void Utility::delay(int seconds)
{
    time_t start, current;
    
    time(&start);
    
    do
    {
        time(&current);
    }
    while ((current - start) < seconds);
}
int Utility::Random(int max)
{
    return (rand() % max);
}
int Utility::mSleep(unsigned long milisec)
{
    struct timespec req={0};
    time_t sec=(int)(milisec/1000);
    milisec=milisec-(sec*1000);
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;
    while(nanosleep(&req,&req)==-1)
        continue;
    return 1;
}
