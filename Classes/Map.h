//
//  Map.h
//  mir_new_Demo
//
//  Created by zhang zaiwei on 14-5-1.
//
//

#ifndef __mir_new_Demo__Map__
#define __mir_new_Demo__Map__


#include "cocos2d.h"

using namespace cocos2d;

class CMap:public Ref
{
private:
    TMXTiledMap * m_tilemap;
    
public:
    bool LoadMap(char * cMapname);
    
    
    
};

#endif /* defined(__mir_new_Demo__Map__) */
