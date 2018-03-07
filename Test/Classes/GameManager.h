#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <Box2D/Box2D.h>

using namespace cocos2d;

class GameManager  : public cocos2d::Scene, public b2ContactListener {
private:
    Scene *gameScene;
    b2World* _world;
    
public:
    GameManager();
    static GameManager* getInstance();
    ~GameManager();
    
    void addChicken();
};

#endif
