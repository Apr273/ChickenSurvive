#include "DirectionController.h"

bool DirectionController::init()
{
	this->m_XSpeed = 0;
	this->m_YSpeed = 0;
	////ע����̲ٿ��¼�
	//registeKeyboardEvent();
	//registeMouseEvent();
	//ÿһ֡����update��������
	this->scheduleUpdate();
	return true;
}

void DirectionController::onEnter()
{
	Node::onEnter();
	registeKeyboardEvent();
	registeMouseEvent();
}

void DirectionController::onExit()
{
	Node::onExit();
	_eventDispatcher->removeEventListener(m_listener);
}

void DirectionController::update(float dt)
{
	if (m_controllerListener == NULL)
	{
		return;
	}

	auto left = EventKeyboard::KeyCode::KEY_A;
	auto right = EventKeyboard::KeyCode::KEY_D;
	auto up = EventKeyboard::KeyCode::KEY_W;
	auto down = EventKeyboard::KeyCode::KEY_S;

	//���ƶ�������X��Y�������������
	Point curPos = m_controllerListener->getTagPosition();
	if (keyMap[left])
	{
		m_XSpeed = -m_Speed;
	}
	if (keyMap[right])
	{
		m_XSpeed = m_Speed;
	}
	if (keyMap[up])
	{
		m_YSpeed = m_Speed;
	}
	if (keyMap[down])
	{
		m_YSpeed = -m_Speed;
	}
	curPos.x += m_XSpeed;
	curPos.y += m_YSpeed;
	m_controllerListener->setTagPosition(curPos.x, curPos.y);
}

void DirectionController::setXSpeed(int iSpeed)
{
	this->m_XSpeed = iSpeed;
}

void DirectionController::setYSpeed(int iSpeed)
{
	this->m_YSpeed = iSpeed;
}

void DirectionController::setPlayer(Player* myPlayer)
{
	this->m_Player = myPlayer;
}

void DirectionController::registeKeyboardEvent()
{
	//�������̼����¼�
	auto* keyListener = EventListenerKeyboard::create();

	//�����̱�����ʱ��Ӧ
	keyListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event*)
	{
		if (!keyMap[keyCode])
		{
			keyMap[keyCode] = true;
			switch (keyCode)
			{
				case EventKeyboard::KeyCode::KEY_D:
					m_Player->run('R');
					break;
				case EventKeyboard::KeyCode::KEY_A:
					m_Player->run('L');
					break;
				case EventKeyboard::KeyCode::KEY_S:
					m_Player->run('D');
					break;
				case EventKeyboard::KeyCode::KEY_W:
					m_Player->run('U');
					break;
			}
		}
	};
	//�����ͷ�ʱ��Ӧ
	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		setXSpeed(0);
		setYSpeed(0);
		keyMap[keyCode] = false;
		m_Player->run('T');
	};

	//���¼��������볡����
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

}

void DirectionController::registeMouseEvent()
{
	//�����¼�����������������¼�
	auto myMouseListener = EventListenerMouse::create();
	//����걻����
	myMouseListener->onMouseDown = [=](Event* event)
	{
		mybullet = Bullet::create();
		mybullet->setPosition(m_Player->getPosition());//�ӵ�λ��
		mybullet->setScale(0.5f);//�ӵ���С
		this->addChild(mybullet);
		EventMouse* e = (EventMouse*)event;
		//�ҵ�λ��ʹ���ӵ������Ļ��
		Vec2 mouseLocation = Point(e->getCursorX(), e->getCursorY());
		Vec2 offset = mouseLocation - m_Player->getPosition();
		offset.normalize();
		auto shootAmount = offset * 1000;
		auto realDest = shootAmount + m_Player->getPosition();

		auto actionMove = MoveTo::create(2.0f, realDest);
		auto actionRemove = RemoveSelf::create();
		mybullet->runAction(Sequence::create(actionMove, actionRemove, nullptr));
		/*MoveTo* moveTo = MoveTo::create(0.25f,Point(e->getCursorX(),e->getCursorY()));
		bullet->runAction(moveTo);*/
	};
	//���¼��������볡����
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);
}