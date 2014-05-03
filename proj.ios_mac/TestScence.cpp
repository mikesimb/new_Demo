#include "TestScence.h"
#include "ImageFile.h"
#include "global.h"

USING_NS_CC;

Scene* Test::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Test::create();
    layer->setTag(65534);
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Test::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(Test::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    
    
    
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    auto OpenFile = MenuItemFont::create("OpenFiles", CC_CALLBACK_1(Test::menuOpenfileCallback, this));
    OpenFile->setPosition(Point(100,100));
    menu->addChild(OpenFile);
    this->addChild(menu, 1);
    
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "Test" splash screen"
    //auto sprite = Sprite::create("Test.png");
    
    // position the sprite on the center of the screen
    //sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    //TMXTiledMap * map = TMXTiledMap::create("map/m5.tmx");
    //this->addChild(map);
    
    scheduleUpdate();
    index = 0 ;
    
    return true;
    
}

void Test::update(float dt)
{
    if (!file) return ;
    unsigned int tikc = _getTickCount();
    if(tikc - m_lastTick >200)
    {
               ImgBody * ib = file->getImgItem(index++);
               Rect rc ;
               rc.origin.x = ib->x;
               rc.origin.y = ib->y;
               rc.size.width = ib->width;
               if ((ib->width % 2 ) != 0)
                   --rc.size.width;
               rc.size.height = ib->height;
        
                if ((ib->height % 2 ) != 0)
                    --rc.size.height;
        
        CCLOG("imgbody %d:%d",index,ib->width);
               sp->setTextureRect(rc);
        Point pos = Point(500,255);
        pos.x = pos.x + ib->offsetx;
        pos.y = pos.y + ib->height - ib->offsety;
        sp->setPosition(pos);
        if(index > file->getItemcount())
            index = 0 ;
        m_lastTick = _getTickCount();
        
    }
    
    
}

void Test::menuOpenfileCallback(cocos2d::Ref* pSender)
{
    //这里需要测试当前的打开文件的测试
    file  = new  CImageFile();
    file->LoadBinFile("hum/zs.age");
    
    sp = Sprite::create("hum/zs.png");
    sp->setPosition(Point(500,255));
        ImgBody * ib = file->getImgItem(0);
        Rect rc ;
        rc.origin.x = ib->x;
        rc.origin.y = ib->y;
        rc.size.width = ib->width;
        rc.size.height = ib->height;
        sp->setTextureRect(rc);
   // sp->setTextureRect(rc);
    addChild(sp);
    
}


void Test::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
