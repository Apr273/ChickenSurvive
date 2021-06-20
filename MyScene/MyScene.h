#ifndef __My_SCENE_H__
#define __My_SCENE_H__

#include "cocos2d.h"
#include "Actor/Player.h"
#include "Controller/DirectionController.h"

using namespace cocos2d;

class Player;

class MyScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MyScene);
    void addPlayer(TMXTiledMap* map);
  
private:
    //Ö÷½Ç
    Player* m_player;
};


#endif