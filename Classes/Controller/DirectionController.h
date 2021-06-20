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
    //设置X方向移动速度
    void setXSpeed(int iSpeed);
    //设置Y方向移动速度
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
    //注册键盘操控事件
    void registeKeyboardEvent();
    //注册鼠标操控事件，试着移到MyScene里面去
    //void registeMouseEvent();
    EventListenerKeyboard* m_listener = NULL;

};

#endif // !__DirectionController_H__