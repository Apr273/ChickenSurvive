#ifndef __My_SCENE_H__
#define __My_SCENE_H__

#include "cocos2d.h"
#include "Actor/Player.h"
#include "Controller/DirectionController.h"
#include"Weapon/Bullet.h"

#include "Common/CommonSetting.h"
#include "Common/CommonMethod.h"

using namespace cocos2d;



class MyScene : public cocos2d::Layer
{
//private:
//    Label* TIME;
//    Player player;
//
//    Sprite* pBloodManSp = Sprite::create("Blood.png");//满血条
//    ProgressTimer* pBloodProGress = ProgressTimer::create(pBloodManSp);



public:
    //void update(float delta);

    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MyScene);
    void addPlayer(TMXTiledMap* map);
  //  void addMonster(TMXTiledMap* map);
    cocos2d::Point convertToMapSpace(const cocos2d::Point& point);
    /*设计武器新加的，还没改好 void update(float dt);*/
    
  
private:
    //主角
    Player* m_player;
    //Bullet* m_bullet;
    //MonsterManager* m_monsterMgr;
};


#endif