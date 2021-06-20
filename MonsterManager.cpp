#include "MonsterManager.h"
#include "Actor/Player.h"
#include "Actor/Monster.h"
#include "Weapon/Bullet.h"
#define MAX_MONSTER_NUM 10
bool MonsterManager::init()
{
	createMonsters();//创建怪物缓存
	this->scheduleUpdate();//开启update函数调用
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
		//保存怪物对象到列表中，方便管理
		m_monsterArr.pushBack(monster);
	}
	//便于测试碰撞，只创建一个怪物
	//for (int i = 0; i < 1; i++)
	//{
	//	//创建怪物对象
	//	monster = Monster::create();
	//	monster->bindSprite(Sprite::create("monsterD1.png"));
	//	monster->reset();
	//	//添加怪物对象
	//	this->addChild(monster);
	//	//保存怪物对象到列表中，方便管理
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
			///*如果怪物处于活动状态*/
			//monster->setPositionX(monster->getPositionX()-4);
			/*如果怪物X坐标小于0，则表示已经超出屏幕范围，隐藏怪物*/
			if (monster->getPositionX() < 0)
			{
				monster->hide();
			}
			/*判断怪物是否碰撞玩家*/
			else if(monster->isCollideWith(myplayer))
			{
				myplayer->hit();
				//为了演示碰撞，目前的效果是怪物隐藏
				monster->hide();
			}
			//修改子弹中
			/*else if (monster->isCollideWith(mybullet))
			{
				monster->hide();
			}*/
			/*判断子弹是否碰撞怪物*/
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
//
//std::vector<Monster*> MonsterManager::getMonster()const
//{
//	return m_monsterList;
//}

//void MonsterManager::bindBullet(Bullet* bullet)
//{
//	m_bullet =bullet;
//}