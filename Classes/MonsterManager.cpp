#include "MonsterManager.h"
#include "Actor/Player.h"
#include "Actor/Monster.h"
#include "Weapon/Bullet.h"
#include "Scene/OutScene.h"
#include"Common/CommonSetting.h"


bool MonsterManager::init()
{
	createMonsters();//创建怪物缓存
	//this->scheduleUpdate();//开启update函数调用
	this->scheduleUpdate();
	return true;
}

void MonsterManager::createMonsters()
{
	Monster* monster = NULL;
	Sprite* sprite = NULL;
	for (int i = 0; i < MAX_MONSTER_NUM; i++)
	{
		//创建怪物对象
		monster = Monster::create();
		monster->bindSprite(Sprite::create("monsterD1.png"));
		monster->reset();
		//添加怪物对象
		this->addChild(monster);
		monster->bindPlayer(m_player);
		//保存怪物对象到列表中，方便管理
		m_monsterArr.pushBack(monster);
	}

}

void MonsterManager::update(float dt)
{
	//	myplayer = Player::create();
//	m_bullet = Bullet::create();
	if (!isGameOver())
	{
		for (auto monster : m_monsterArr)
		{
			if (monster->isAlive())
			{
				if (monster->isCollideWith(m_player))
				{
					monster->die();
					m_player->setiGrade(1);
					m_player->hit();
				}
				//修改子弹中
				/*else if (monster->isCollideWith(m_bullet))
				{
					log("bullet collide");
					monster->hurt(m_bullet->getDamage());
				}*/
			}
			else
			{
				

			}
		}
	}
	else
	{
		Director::getInstance()->replaceScene(OutScene::createScene());
	}
}

void MonsterManager::bindPlayer(Player* player)
{
	m_player = player;
	this->scheduleUpdate();
}

void MonsterManager::bindBullet(Bullet* bullet)
{
	m_bullet = bullet;
	this->scheduleUpdate();
}

bool MonsterManager::isGameOver()
{
	if (m_player->getiGrade() == MAX_MONSTER_NUM*2)
	{
		return true;
	}
	else
		return false;
}
//修改中
//std::vector<Bullet*> MonsterManager::getMonsterBullets() const
//{
//	std::vector<Bullet*> monsterBullets;
//	for (auto monster : m_monsterList)
//	{
//		auto tmpBlt = monster->getMonsterWeapon()->getBullet();//获取每个怪物的武器发射出的子弹
//		for (auto blt : tmpBlt)
//			monsterBullets.push_back(blt);//将子弹塞进向量
//	}
//	return monsterBullets;
//}

//Vector<Monster*> MonsterManager::getMonster()
//{
//	return m_monsterArr;
//}

//void MonsterManager::bindBullet(Bullet* bullet)
//{
//	m_bullet =bullet;
//}