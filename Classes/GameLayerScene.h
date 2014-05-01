#ifndef __GAMELAYER_SCENE_H__
#define __GAMELAYER_SCENE_H__
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class CGameLayer : public cocos2d::Layer
{
private:
	double m_Tick; 

	Point m_TouchStart, m_TouchEnd;

	void RealTimeUpdate(void);
	void RealTimeRenders(Renderer *renderer, const kmMat4 &transform, bool transformUpdated);

	CCMenuItemImage* DoCreateTestMenuIcon(int ntag, char* s1, char* s2);
	//Sprite *m_sprite;
public:
	//virtual void draw();
	//virtual void draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated) override;

    virtual bool init();  

    
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    void menuDebugCallback(CCObject* pSender);
	void menuActCallback(CCObject* pSender);

	void update(float dt);
	
	//virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	//virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	//virtual void ccTouchesEnded(CCSet* touches, CCEvent* event);


	bool onTouchBegan(Touch* touch, Event* event);

	void onTouchMoved(Touch* touch, Event* event);

	void onTouchEnded(Touch* touch, Event* event);

	//virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	//virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	//virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);

    CREATE_FUNC(CGameLayer);

	static CGameLayer* getInstance(void);

	Point GetLastTouchPoint(void);

	//void didAccelerate(CCAcceleration* pAccelerationValue);
	virtual void onAcceleration(Acceleration* acc, Event* unused_event);
};

#endif // __GAMELAYER_SCENE_H__
