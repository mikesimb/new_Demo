

#include "cocos2d.h"
#include "ImageFile.h"
class Test : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void menuOpenfileCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Test);
    
    void update(float dt);
    
private:
    CImageFile * file;
    Sprite * sp;
    unsigned int m_lastTick;
    int index;
    
};

