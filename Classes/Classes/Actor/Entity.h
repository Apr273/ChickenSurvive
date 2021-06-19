#ifndef __Entity_H__
#define __Entity_H__
#pragma once

#include "Controller/ControllerListener.h"
#include "Controller/Controller.h"


USING_NS_CC;

class Entity : public Node, public ControllerListener
{//��ɫ��Ϊ�����������ƵĶ���
public:
	Entity();
	~Entity();
	Sprite* getSprite();//��ȡ�������
	void bindSprite(Sprite* sprite);//�󶨾������
	void setController(MyController* controller);//���ÿ�����
	virtual void setTagPosition(int x, int y);//���ýӿ�
	virtual Point getTagPosition();

protected:
	Sprite* m_sprite;
	MyController* m_controller;
};

#endif // !__Entity_H__
