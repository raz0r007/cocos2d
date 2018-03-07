#include "B2Debug/DebugLayer.h"
#include "GameManager.h"
#include "B2Debug/DebugLayer.h"

#define SCALE_RATIO 32.0

USING_NS_CC;


GameManager::GameManager()
{
    gameScene = new Scene;
    gameScene->setName("gameScene");
    Director::getInstance()->replaceScene(gameScene);
    
    b2Vec2 gravity(0, -9.8);
    _world = new b2World(gravity);
    
   // DebugLayer *debugLayer = new DebugLayer(_world);
   // gameScene->addChild(debugLayer);
}


GameManager* GameManager::getInstance()
{
    static GameManager sharedInstance;
    return &sharedInstance;
}


void GameManager::addChicken()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //Sprite
    Sprite *sChicken = Sprite::create("chicken.png");
    sChicken->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    gameScene->addChild(sChicken);
    
    //Box2d
    b2Body *bodyChick;
    b2BodyDef chickBodyDef;
    b2PolygonShape chickShape;
    b2FixtureDef chickFixtureDef;
    
    chickBodyDef.type = b2_staticBody;
    chickBodyDef.position = b2Vec2(sChicken->getPositionX()/SCALE_RATIO, sChicken->getPositionY()/SCALE_RATIO);
    chickBodyDef.userData = sChicken;
    bodyChick = _world->CreateBody(&chickBodyDef);
    
    chickShape.SetAsBox((sChicken->getBoundingBox().size.width/2)/SCALE_RATIO, (sChicken->getBoundingBox().size.height/2)/SCALE_RATIO);
    
    chickFixtureDef.shape = &chickShape;
    chickFixtureDef.density = 1.f;
    bodyChick->CreateFixture(&chickFixtureDef);
}

GameManager::~GameManager()
{
    
}





