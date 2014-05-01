//
//  Map.cpp
//  mir_new_Demo
//
//  Created by zhang zaiwei on 14-5-1.
//
//

#include "Map.h"
#include "CGameManager.h"

bool CMap::LoadMap(char * cMapname)
{
  if(cMapname)
  {

      m_tilemap = TMXTiledMap::create(cMapname);
      if(m_tilemap)
      {
        
          //m_tilemap->setPosition(Point(0.0f,0.0f));
            GameManager::getInstance()->getGameLayer()->addChild(m_tilemap);
          
      }
      else
      {
          log("CMap::LoadMap is failed!");
      }
      
      
  }
    
    return true;
};


