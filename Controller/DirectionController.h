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
    //����X�����ƶ��ٶ�
    void setXSpeed(int iSpeed);
    //����Y�����ƶ��ٶ�
    void setYSpeed(int iSpeed);
    std::map<EventKeyboard::KeyCode, bool> keyMap;
    void setPlayer(Player* myPlayer);
private:
    int m_XSpeed;
    int m_YSpeed;
    Player* m_Player;
    //ע����̲ٿ��¼�
    void registeKeyboardEvent();

};

#endif // !__DirectionController_H__