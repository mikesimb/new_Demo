#include "GameLayerScene.h"
//#include "AppMacros.h"
#include "global.h"
#include "gui.h"
#include "actor.h"
#include "Particles.h"
#include "map.h"
#include "GADBC.h"
#include "GAGUIManger.h"
#include "SkillEffect.h"
USING_NS_CC;

using namespace std;

static CGameLayer* g_GameLayer = NULL;

Sprite *m_sprite = NULL;


CGameLayer* CGameLayer::getInstance(void)
{
	if ( !g_GameLayer )
	{
//		CGameMgr::getInstance()->setCurScene(Scene_Game);

		g_GameLayer = new CGameLayer();	

		g_GameLayer->init();
	}
	return g_GameLayer;

}

CCScene* CGameLayer::scene()
{
    CCScene* pScene = CCScene::create();
 
	CGameLayer* pLayer = getInstance();
	pScene->addChild(pLayer);

    return pScene;
}

void CGameLayer::onAcceleration(Acceleration* acc, Event* unused_event) // didAccelerate(CCAcceleration* pAccelerationValue)
{


	//m_myCarMoveDis.x = m_myCarMoveDis.x*deceleration
	//	+  pAccelerationValue->x*sensitivity;
	//if (m_myCarMoveDis.x>=maxVelocity)
	//{
	//	m_myCarMoveDis.x = maxVelocity;
	//}
	//else if(m_myCarMoveDis.x <=-maxVelocity)
	//{
	//	m_myCarMoveDis.x = -maxVelocity;
	//}

	//char szText[100];
	//sprintf(szText, "x=%lf, y=%lf, z=%lf", pAccelerationValue->x, pAccelerationValue->y, pAccelerationValue->z);
	//CGUI::getInstance()->setLog2Text(szText);
	return;
}

bool CGameLayer::init()
{

	m_Tick = 0;

   // if ( !Layer::init() )
   //{
   //     return false;
	
   //}
	//setTouchEnabled(true);
	setAccelerometerEnabled(true);


	auto dispatcher = Director::getInstance()->getEventDispatcher();

	auto touchListener = EventListenerTouchOneByOne::create();

	

	touchListener->onTouchBegan = CC_CALLBACK_2(CGameLayer::onTouchBegan, this);

	touchListener->onTouchMoved = CC_CALLBACK_2(CGameLayer::onTouchMoved, this);

	touchListener->onTouchEnded = CC_CALLBACK_2(CGameLayer::onTouchEnded, this);

	//dispatcher->addEventListenerWithFixedPriority(touchListener, -1);

	dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    	

	//CGUI::getInstance()->init(this);

	scheduleUpdate();


	//CMap::getInstance()->LoadMap("m5"); //m5.tmx iso-test.tmx  nga0 d5071
	//CMap::getInstance()->update();

    return true;
}

CCMenuItemImage* CGameLayer::DoCreateTestMenuIcon(int ntag, char* s1, char* s2)
{
	CCMenuItemImage *p = CCMenuItemImage::create(
		s1, s2,
		this,
		menu_selector(CGameLayer::menuActCallback));
	p->setTag(ntag);

	int ni = p->getContentSize().width;

	int i = 50 + 60*ntag;		
	int j = 20;

	p->setPosition(Point(i, j));
	p->setScale(0.5f, 0.5f);

	return p;
}

void CGameLayer::menuCloseCallback(CCObject* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void CGameLayer::menuDebugCallback(CCObject* pSender)
{

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}


void CGameLayer::menuActCallback(CCObject* pSender)
{	
	CCMenuItemImage* item = (CCMenuItemImage*) pSender;

	int tag = item->getTag();

}


bool CGameLayer::onTouchBegan(Touch* touch, Event* event)
{
	auto location = touch->getLocation();
		
	//摇杆触控优先处理，这里后处理
	m_TouchStart = Director::getInstance()->convertToUI(location);

	Size winsize = Director::getInstance()->getWinSize();
//	Point screen = CGameMgr::getInstance()->getMyScreen();
//	m_TouchStart.x -= screen.x;
//	m_TouchStart.y -= screen.y;
//
//	Point pCenter = CGameMgr::getInstance()->getMyCenter();
//	int grid_x = pCenter.x + m_TouchStart.x / MAX_STEP_WIDHT;
//	int grid_y = pCenter.y + m_TouchStart.y / MAX_STEP_HEIGHT;
//
//	
//	if (CActorMgr::getInstance()->SearchActor(grid_x, grid_y))
//	{
//		// select actor
//		CActorMgr::getInstance()->SearchPathAround(grid_x, grid_y);
//	}
//	else
//	{
//		// touch on map
//		CActorMgr::getInstance()->SearchPathGrid(grid_x, grid_y);
//	}
//		
	//char szText[100];
	//sprintf(szText, "TouchStart.x=%f, TouchStart.y=%f", m_TouchStart.x, m_TouchStart.y);
	//setLog1Text(szText);

		return true;

	
}
void CGameLayer::onTouchMoved(Touch* touch, Event* event)
{

	//auto location = touch->getLocation();

	//Point TouchMove = Director::getInstance()->convertToUI(location);
	//Size winsize = Director::getInstance()->getWinSize();
	//Point screen = CGameMgr::getInstance()->getMyScreen();
	//TouchMove.x -= screen.x;
	//TouchMove.y -= screen.y;

	//CGameMgr::getInstance()->updateMyTarget( &TouchMove );
	//	

	
}


void CGameLayer::onTouchEnded(Touch* touch, Event* event)
{	
	
	//auto location = touch->getLocation();

	//m_TouchEnd = Director::getInstance()->convertToUI(location);
	//Size winsize = Director::getInstance()->getWinSize();
	//Point screen = CGameMgr::getInstance()->getMyScreen();
	//m_TouchEnd.x -= screen.x;
	//m_TouchEnd.y -= screen.y;

	//CGameMgr::getInstance()->updateMyTarget(&m_TouchEnd);

}



Point CGameLayer::GetLastTouchPoint()
{
	return m_TouchEnd;
}


//slow update, like a timer
void CGameLayer::update(float dt)
{

//	CGAGUIManger::getInstance()->Create(CGAGUIManger::FrameGUIName)->Update();
//	CGUI::getInstance()->update();
	//m_MapLastHit = m_ScreenLastHit;

	RealTimeUpdate();



}


void CGameLayer::RealTimeUpdate()
{
//	double tick = GlobalTick();
//	//if (tick - m_Tick > 100)
//	{
//		m_Tick = tick;
//
//		CGameMgr::getInstance()->update();
//
//		//char szText[100];
//		//sprintf(szText, "CGameMgr::getInstance()->update();, m_Tick=%lf", m_Tick);
//		//CGUI::getInstance()->setLog1Text(szText);
//
//	}

}

void CGameLayer::RealTimeRenders(Renderer *renderer, const kmMat4& transform, bool transformUpdated)
{

//	CGameMgr::getInstance()->draw(renderer, transform, transformUpdated);

}

