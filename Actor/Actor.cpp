#include "Actor.h"

/*初始化精灵*/
void Actor::initSprite(Sprite* sprite,Layer*layer)
{
	this->sprite = sprite;
	sprite->setScale(3.0f);
	sprite->setPosition(200, 200);
	layer->addChild(sprite);
}

/*获取精灵*/
Sprite* Actor::getSprite() 
{ 
	return this->sprite; 
}

/*精灵动画*/
Animate* Actor::getAnimate(char keycode) 
{
    //创建动画序列
	auto* m_frameCache = SpriteFrameCache::getInstance();
	m_frameCache->addSpriteFramesWithFile("monsterT.plist", "monsterT.png");
	Vector<SpriteFrame*>frameArray;
	//循环播放
	for (int i = 1; i < 4; ++i)
	{
		auto* frame = m_frameCache->getSpriteFrameByName(StringUtils::format("monster%c%d.png",keycode, i));
		frameArray.pushBack(frame);//将帧加入序列中
	}
    //创建动画
	Animation* animation = Animation::createWithSpriteFrames(frameArray);
	//每一帧切换频率
	animation->setDelayPerUnit(0.1f);
	//动画执行次数， - 1为无限执行
	animation->setLoops(-1);
	//动画结束后恢复到第一帧
	animation->setRestoreOriginalFrame(true);
	//创建动画动作
	auto *animate = Animate::create(animation);
	return animate;
}

///*键盘监听*/
//void Actor::registerKeyboardEvent() 
//{
//	//创建键盘监听事件
//	auto keylistener = EventListenerKeyboard::create();
//	//当键盘被按下时响应
//	keylistener->onKeyPressed = [&](EventKeyboard::KeyCode keycode, Event*) 
//	{
//		static Vec2 last;
//		static bool isRight = true;
//		if (keycode != EventKeyboard::KeyCode::KEY_D &&
//			keycode != EventKeyboard::KeyCode::KEY_W &&
//			keycode != EventKeyboard::KeyCode::KEY_A &&
//			keycode != EventKeyboard::KeyCode::KEY_S &&
//			keycode != EventKeyboard::KeyCode::KEY_J &&
//			keycode != EventKeyboard::KeyCode::KEY_K)
//		{
//			last.set(1.0, 0);
//		}
//
//		switch (keycode) 
//		{
//		case EventKeyboard::KeyCode::KEY_A:
//			last.set(1.0, 0);
//			if (!isAnimation)
//			{
//				getSprite()->runAction(getAnimate('L'));
//				isAnimation = true;
//			}
//			break;
//
//		case EventKeyboard::KeyCode::KEY_D:
//			last.set(1.0, 0);
//			if (!isAnimation) 
//			{
//				getSprite()->runAction(getAnimate('R'));
//				isAnimation = true;
//			}
//			break;
//
//		case EventKeyboard::KeyCode::KEY_W:
//			last.set(1.0, 0);
//			if (!isAnimation) 
//			{
//				getSprite()->runAction(getAnimate('U'));
//				isAnimation = true;
//			}
//			break;
//
//		case EventKeyboard::KeyCode::KEY_S:
//			last.set(1.0, 0);
//			if (!isAnimation)
//			{
//				getSprite()->runAction(getAnimate('D'));
//				isAnimation = true;
//			}
//			break;
//		}
//	};
//    //停止帧动画动作
//	keylistener->onKeyReleased = [&](EventKeyboard::KeyCode keycode, Event*)
//	{
//		switch (keycode)
//		{
//		case EventKeyboard::KeyCode::KEY_D:
//			getSprite()->stopAllActions();
//			isAnimation = false;
//			break;
//
//		case EventKeyboard::KeyCode::KEY_W:
//			getSprite()->stopAllActions();
//			isAnimation = false;
//			break;
//
//		case EventKeyboard::KeyCode::KEY_A:
//			getSprite()->stopAllActions();
//			isAnimation = false;
//			break;
//
//		case EventKeyboard::KeyCode::KEY_S:
//			getSprite()->stopAllActions();
//			isAnimation = false;
//			break;
//		}
//	};
//	//将事件监听器与场景绑定
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
//}

//void Actor::registerMouseEvent()
//{
//	//创建事件监听器，监听鼠标事件
//	auto myMouseListener = EventListenerMouse::create();
//	//当鼠标被按下
//	myMouseListener->onMouseDown = [=](Event* event)
//	{
//		Sprite* bullet = Sprite::create("bullet_1.png");
//		bullet->setPosition(getSprite()->getPosition());//子弹位置
//		bullet->setScale(0.5f);//子弹大小
//		this->addChild(bullet);
//		EventMouse* e = (EventMouse*)event;
//		//找到位置使得子弹射出屏幕外
//		Vec2 mouseLocation = Point(e->getCursorX(), e->getCursorY());
//		Vec2 offset = mouseLocation - getSprite()->getPosition();
//		offset.normalize();
//		auto shootAmount = offset * 1000;
//		auto realDest = shootAmount + getSprite()->getPosition();
//
//		auto actionMove = MoveTo::create(2.0f, realDest);
//		auto actionRemove = RemoveSelf::create();
//		bullet->runAction(Sequence::create(actionMove, actionRemove, nullptr));
//		/*MoveTo* moveTo = MoveTo::create(0.25f,Point(e->getCursorX(),e->getCursorY()));
//		bullet->runAction(moveTo);*/
//	};
//	//将事件监听器与场景绑定
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);
//}