//
//  global.cpp
//  mir_new_Demo
//
//  Created by zhang zaiwei on 14-5-1.
//
//

#include "global.h"
#include "cocos2d.h"

unsigned int _getTickCount()
{
    timeval t;
	gettimeofday(&t, 0);
	return t.tv_sec*1000.0 + t.tv_usec / 1000.0;
}
