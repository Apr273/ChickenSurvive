#include "MonsterManager.h"
#include "Actor/Player.h"
#include "Actor/Monster.h"
#include "Weapon/Bullet.h"
#define MAX_MONSTER_NUM 10
bool MonsterManager::init()
{
	createMonsters();//�������ﻺ��
	this->scheduleUpdate();//����update��������
	return true;
}

void MonsterManager::createMonsters()
{
	Monster* monster = NULL;
	Sprite* sprite = NULL;

	for (int i = 0; i < MAX_MONSTER_NUM; i++)
	{
		//�����������
		monster = Monster::create();
		monster->bindSprite(Sprite::create("monsterD1.png"));
		monster->reset();
		//��ӹ������
		this->addChild(monster);
		//�����������б��У��������
		m_monsterArr.pushBack(monster);
	}
	//���ڲ�����ײ��ֻ����һ������
	//for (int i = 0; i < 1; i++)
	//{
	//	//�����������
	//	monster = Monster::create();
	//	monster->bindSprite(Sprite::create("monsterD1.png"));
	//	monster->reset();
	//	//��ӹ������
	//	this->addChild(monster);
	//	//�����������б��У��������
	//	m_monsterArr.pushBack(monster);
	//}
}

void MonsterManager::update(float dt)
{
//	myplayer = Player::create();
//	m_bullet = Bullet::create();
	for (auto monster : m_monsterArr)
	{
		if (monster->isAlive())
		{
			//log("isAlive()");
			///*������ﴦ�ڻ״̬*/
			//monster->setPositionX(monster->getPositionX()-4);
			/*�������X����С��0�����ʾ�Ѿ�������Ļ��Χ�����ع���*/
			if (monster->getPositionX() < 0)
			{
				monster->hide();
			}
			/*�жϹ����Ƿ���ײ���*/
			else if(monster->isCollideWith(myplayer))
			{
				myplayer->hit();
				//Ϊ����ʾ��ײ��Ŀǰ��Ч���ǹ�������
				monster->hide();
			}
			//�޸��ӵ���
			/*else if (monster->isCollideWith(mybullet))
			{
				monster->hide();
			}*/
			/*�ж��ӵ��Ƿ���ײ����*/
			/*else if (monster->hitByBullet(m_bullet))
			{
				monster->hide();
			}*/
		}
		else 
		{
			monster->show();
		}
	}
}

void MonsterManager::bindPlayer(Player* player)
{
	myplayer = player;
	this->scheduleUpdate();
}
//�޸���
//std::vector<Bullet*> MonsterManager::getMonsterBullets() const
//{
//	std::vector<Bullet*> monsterBullets;
//	for (auto monster : m_monsterList)
//	{
//		auto tmpBlt = monster->getMonsterWeapon()->getBullet();//��ȡÿ�������������������ӵ�
//		for (auto blt : tmpBlt)
//			monsterBullets.push_back(blt);//���ӵ���������
//	}
//	return monsterBullets;
//}
//
//std::vector<Monster*> MonsterManager::getMonster()const
//{
//	return m_monsterList;
//}

//void MonsterManager::bindBullet(Bullet* bullet)
//{
//	m_bullet =bullet;
//}