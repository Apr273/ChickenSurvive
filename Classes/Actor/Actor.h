#ifndef _ACTOR_H_
#define _ACTOR_H_
#include "cocos2d.h"

USING_NS_CC;

class Actor : public Node
{
public:
	Animate* getAnimate(char keycode);//ִ�ж���
	//void registerKeyboardEvent();//��ȡ����
	//void registerMouseEvent();//��ȡ���
	void initSprite(Sprite* sprite, Layer* layer);//��ʼ����
	Sprite* getSprite();//��ȡ����

private:
	bool isAnimation = false;
	Sprite* sprite;
};

#endif