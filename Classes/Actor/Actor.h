#ifndef _ACTOR_H_
#define _ACTOR_H_
#include "cocos2d.h"

USING_NS_CC;

class Actor : public Node
{
public:
	Animate* getAnimate(char keycode);//执行动画
	//void registerKeyboardEvent();//获取键盘
	//void registerMouseEvent();//获取鼠标
	void initSprite(Sprite* sprite, Layer* layer);//初始精灵
	Sprite* getSprite();//获取精灵

private:
	bool isAnimation = false;
	Sprite* sprite;
};

#endif