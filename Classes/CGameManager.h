//
//  CGameManager.h
//  mir_new_Demo
//
//  Created by zhang zaiwei on 14-5-1.
//
//

#ifndef __mir_new_Demo__CGameManager__
#define __mir_new_Demo__CGameManager__


#include "cocos2d.h"
#include "map.h"


using namespace cocos2d;

class GameManager :public Ref
{
private:
    Scene* m_GameSence;
    Scene * m_TestSence;
    CMap* m_map;
public:
    Scene* getGameSence();
    Layer * getGameLayer();
    GameManager();
    ~GameManager();
    
    static GameManager* getInstance();
    void Init();
};

#endif /* defined(__mir_new_Demo__CGameManager__) */
