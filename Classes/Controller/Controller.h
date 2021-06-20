#ifndef __Controller_H__
#define __Controller_H__
#pragma once
#include "cocos2d.h"
#include "ControllerListener.h"

using namespace cocos2d;

class MyController :public Node
{
public:
	//���ü�������
	void setControllerListener(ControllerListener* controllerListener);
protected:
	ControllerListener* m_controllerListener;
};

#endif // !__Controller_H__
