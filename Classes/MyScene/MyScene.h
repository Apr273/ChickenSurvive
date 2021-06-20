#ifndef __My_SCENE_H__
#define __My_SCENE_H__

#include "cocos2d.h"
#include "Actor/Player.h"
#include "Controller/DirectionController.h"
#include"Weapon/Bullet.h"

#include "Common/CommonSetting.h"
#include "Common/CommonMethod.h"

#include"MonsterManager.h"

using namespace cocos2d;



class MyScene : public cocos2d::Layer
{
private:
    Label* TIME_s, * GRADE, * TIME_min, * TIME_h;
    ProgressTimer* pBloodProGress;
    int grade;
    clock_t begin, end;

public:
    void update(float delta);
    void SetScene(cocos2d::Ref* pSender);

    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MyScene);
    void addPlayer(TMXTiledMap* map);
    Bullet* addBullet();
    //int addBullet();
    //  void update(float dt);
    //  void addMonster(TMXTiledMap* map);
     // cocos2d::Point convertToMapSpace(const cocos2d::Point& point);
      /*��������¼ӵģ���û�ĺ� void update(float dt);*/
      //�����ƴ��ӵ�
    void registeMouseEvent();


private:
    //����
    Player* m_player = NULL;
    Bullet* m_bullet = NULL;
    MonsterManager* monsterMgr = MonsterManager::create();
};


#endif