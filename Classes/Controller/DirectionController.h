#ifndef __DirectionController_H__
#define __DirectionController_H__
#pragma once
#include "Controller.h"
#include "Actor/Player.h"
#include"Weapon/Bullet.h"
#include "cocos2d.h"

using namespace cocos2d;

class DirectionController :public MyController
{
public:
    CREATE_FUNC(DirectionController);
    virtual bool init();
    void onEnter();
    void onExit();
    virtual void update(float dt);
    //����X�����ƶ��ٶ�
    void setXSpeed(int iSpeed);
    //����Y�����ƶ��ٶ�
    void setYSpeed(int iSpeed);
    std::map<EventKeyboard::KeyCode, bool> keyMap;
    void setPlayer(Player* m_player);
    void setBullet(Bullet* bullet);
    inline void setStandAnimate(Animate* animate) { m_standAnimate = animate; }
private:
    int m_XSpeed;
    int m_YSpeed;
    Player* m_Player;
    Bullet* m_bullet;
    int m_Speed = 4;
    Animate* m_walkAnimate = NULL;
    Animate* m_standAnimate = NULL;
    //ע����̲ٿ��¼�
    void registeKeyboardEvent();
    //ע�����ٿ��¼��������Ƶ�MyScene����ȥ
    //void registeMouseEvent();
    EventListenerKeyboard* m_listener = NULL;

};

#endif // !__DirectionController_H__