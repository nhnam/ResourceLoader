#include "HelloWorldScene.h"
#include "ResourceLoader.h"
#include <functional>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    std::vector<std::string> texture;
    texture.push_back("texture_01");
    texture.push_back("texture_02");
    texture.push_back("texture_03");
    texture.push_back("texture_04");
    texture.push_back("texture_05");
    texture.push_back("texture_06");
    texture.push_back("texture_08");
    texture.push_back("texture_09");
    texture.push_back("texture_10");
    texture.push_back("texture_11");
    ResourceLoader::getInstance()->loadTexture(texture, [this, visibleSize, origin](bool success)
    {
        auto spr = Sprite::createWithSpriteFrameName("a_sprite_frame.png");
        this->addChild(spr);
        spr->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    });
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
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
