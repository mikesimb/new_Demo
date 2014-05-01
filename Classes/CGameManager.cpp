//
//  CGameManager.cpp
//  mir_new_Demo
//
//  Created by zhang zaiwei on 14-5-1.
//
//

#include "CGameManager.h"
#include "HelloWorldScene.h"

using namespace cocos2d;


static GameManager * gGameManager = NULL;



GameManager::GameManager()
{
  
      
}

GameManager::~GameManager()
{
    
}


void GameManager::Init()
{
    m_GameSence = HelloWorld::createScene();
    m_map = new CMap();
    m_map->LoadMap("map/m5.tmx");
}

 GameManager* GameManager::getInstance()
{
    
    if(gGameManager == NULL){
        gGameManager = new GameManager();
        gGameManager->Init();
    }
    return gGameManager;
}

Scene* GameManager::getGameSence()
{
    if (m_GameSence) {
        return  m_GameSence;
        
    }
    else
        return NULL;
    
}

Layer* GameManager::getGameLayer()
{
    if(m_GameSence)
    {
        Layer* layer = (Layer*)m_GameSence->getChildByTag(65534);
        return (Layer*)layer;
        
    }
    else
    return NULL;
}


