//
//  Actor.h
//  mir_new_Demo
//
//  Created by zhang zaiwei on 14-5-3.
//
//

#ifndef __mir_new_Demo__Actor__
#define __mir_new_Demo__Actor__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class CActor :public Ref
{
private:
    //首先需要一个现实图片的地方
    Sprite * m_sprite;
    //记录方向
    int  m_iDir;
    //记录角色当前状态
    int  m_state;//空闲，跑，打，释放魔法，死亡，挖这个状态表示了他当前在做这个动作中。
    //消息队列
    Vector<int> m_Msglist；
    
    
    
    
    
public:
    CActor();
    ~CActor();
    
    //这个是每一帧的更新的地方。
    void update(float dt);
    //这个是从当前的消息队列中取出消息并执行
    void ProcessMsg();
    
    

    
    void doStand();
    void doRun();
    void doHit();
    void doMagic();
    void doDie();
    void doDig();
    
    
};


#endif /* defined(__mir_new_Demo__Actor__) */
