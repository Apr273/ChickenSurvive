#ifndef __Entity_H__
#define __Entity_H__
#pragma once

#include "Controller/ControllerListener.h"
#include "Controller/Controller.h"


USING_NS_CC;

class Entity : public Node, public ControllerListener
{//角色作为被控制器控制的对象
public:
	Entity();
	~Entity();
	Sprite* getSprite();//获取精灵对象
	void bindSprite(Sprite* sprite);//绑定精灵对象
	void setController(MyController* controller);//设置控制器
	virtual void setTagPosition(int x, int y);//设置接口
	virtual Point getTagPosition();

protected:
	Sprite* m_sprite;
	MyController* m_controller;
};

#endif // !__Entity_H__
