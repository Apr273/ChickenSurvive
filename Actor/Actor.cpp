#include "Actor.h"

/*��ʼ������*/
void Actor::initSprite(Sprite* sprite,Layer*layer)
{
	this->sprite = sprite;
	sprite->setScale(3.0f);
	sprite->setPosition(200, 200);
	layer->addChild(sprite);
}

/*��ȡ����*/
Sprite* Actor::getSprite() 
{ 
	return this->sprite; 
}

/*���鶯��*/
Animate* Actor::getAnimate(char keycode) 
{
    //������������
	auto* m_frameCache = SpriteFrameCache::getInstance();
	m_frameCache->addSpriteFramesWithFile("monsterT.plist", "monsterT.png");
	Vector<SpriteFrame*>frameArray;
	//ѭ������
	for (int i = 1; i < 4; ++i)
	{
		auto* frame = m_frameCache->getSpriteFrameByName(StringUtils::format("monster%c%d.png",keycode, i));
		frameArray.pushBack(frame);//��֡����������
	}
    //��������
	Animation* animation = Animation::createWithSpriteFrames(frameArray);
	//ÿһ֡�л�Ƶ��
	animation->setDelayPerUnit(0.1f);
	//����ִ�д����� - 1Ϊ����ִ��
	animation->setLoops(-1);
	//����������ָ�����һ֡
	animation->setRestoreOriginalFrame(true);
	//������������
	auto *animate = Animate::create(animation);
	return animate;
}

///*���̼���*/
//void Actor::registerKeyboardEvent() 
//{
//	//�������̼����¼�
//	auto keylistener = EventListenerKeyboard::create();
//	//�����̱�����ʱ��Ӧ
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
//    //ֹͣ֡��������
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
//	//���¼��������볡����
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
//}

//void Actor::registerMouseEvent()
//{
//	//�����¼�����������������¼�
//	auto myMouseListener = EventListenerMouse::create();
//	//����걻����
//	myMouseListener->onMouseDown = [=](Event* event)
//	{
//		Sprite* bullet = Sprite::create("bullet_1.png");
//		bullet->setPosition(getSprite()->getPosition());//�ӵ�λ��
//		bullet->setScale(0.5f);//�ӵ���С
//		this->addChild(bullet);
//		EventMouse* e = (EventMouse*)event;
//		//�ҵ�λ��ʹ���ӵ������Ļ��
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
//	//���¼��������볡����
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);
//}