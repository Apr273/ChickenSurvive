#ifndef __DirectionController_H__
#define __DirectionController_H__
#pragma once
#include "Controller.h"
#include "Actor/Player.h"
#include "cocos2d.h"
using namespace cocos2d;

class DirectionController :public MyController
{
public:
    CREATE_FUNC(DirectionController);
    virtual bool init();
    virtual void update(float dt);
    //设置X方向移动速度
    void setXSpeed(int iSpeed);
    //设置Y方向移动速度
    void setYSpeed(int iSpeed);
    std::map<EventKeyboard::KeyCode, bool> keyMap;
    void setPlayer(Player* myPlayer);
private:
    int m_XSpeed;
    int m_YSpeed;
    Player* m_Player;
    //注册键盘操控事件
    void registeKeyboardEvent();

};

#endif // !__DirectionController_H__