#ifndef __ControllerListener_H__
#define __ControllerLIstener_H__
#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class ControllerListener
{
public:
	//����Ŀ������
	virtual void setTagPosition(int x, int y) = 0;
	//��ȡĿ������
	virtual Point getTagPosition() = 0;

};

#endif // !__ControllerListener_H__
