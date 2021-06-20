#include "DirectionController.h"

bool DirectionController::init()
{
	this->m_XSpeed = 0;
	this->m_YSpeed = 0;
	//ע����̲ٿ��¼�
	registeKeyboardEvent();
	//ÿһ֡����update��������
	this->scheduleUpdate();
	return true;
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
		m_XSpeed = -4;
	}
	if (keyMap[right])
	{
		m_XSpeed = 4;
	}
	if (keyMap[up])
	{
		m_YSpeed= 4;
	}
	if (keyMap[down])
	{
		m_YSpeed= -4;
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
	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		m_Player->stopAllActions();
		setXSpeed(0);
		setYSpeed(0);
		keyMap[keyCode] = false;
	};
	
	//���¼��������볡����
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

}