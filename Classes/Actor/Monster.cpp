#include "Monster.h"
#include"Weapon/MonsterBullet.h"

Monster::Monster() 
{
	m_isAlive =true;
}

Monster::~Monster(){}

bool Monster::init()
{
	sprite = Sprite::create("MonsterD1.png");
	bindSprite(sprite);
	m_Hp = m_initHp;
	return true;
}

//void Monster::show()
//{
//	if (getSprite() != NULL)
//	{
//		setVisible(true);//设置可见
//		m_isAlive = true;//标记怪物为活动状态
//	}
//}

void Monster::die() 
{
	if (getSprite() != NULL)
	{
		//auto fade = FadeTo::create(1.0f, 0);//消失至某一透明度
		//this->getSprite()->runAction(fade);
		auto actionRemove = RemoveSelf::create();
		this->runAction(actionRemove);
		//reset();
		m_isAlive = false;//标记怪物为非活动状态

	}
}

void Monster::reset()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(100+CCRANDOM_0_1()*800, 100+CCRANDOM_0_1()*600));
	}
}

bool Monster::isAlive()
{
	return m_isAlive;
}

void Monster::setTiledMap(TMXTiledMap* map)
{
	this->m_map = map;

	this->meta = m_map->getLayer("meta");
	this->meta->setVisible(false);

}

bool Monster::isCollideWith(Entity* entity)
{
	return getBoundingBox().intersectsRect(entity->getBoundingBox());
}

void Monster::attack(Entity* entity)
{
	monster_bullet = MonsterBullet::create();
	monster_bullet->setPosition(this->getPosition());//子弹位置
	monster_bullet->setScale(0.5f);//子弹大小
	this->addChild(monster_bullet);

	auto actionMove = MoveBy::create(0.2+3.0* CCRANDOM_0_1(), Vec2(-50+CCRANDOM_0_1()*100, -50 + CCRANDOM_0_1() * 100));
	auto actionRemove = RemoveSelf::create();
	monster_bullet->runAction(Sequence::create(actionMove, actionRemove, nullptr));

}

void Monster::hurt(int damage)
{
	if (m_Hp > 0)
	{
		this->m_Hp -= damage;
	}
	else
	{
		die();
	}
}

void Monster::bindPlayer(Player* player)
{
	m_player = player;
}
//void Monster::hit(int damage)
//{
//	/*if (!m_isAlive)
//		return;
//	setMonsTaunted();
//	this->m_Hp -= damage;
//	std::string msg = '-' + std::to_string(damage);
//	m_damageMsg->showMonsDmg(msg.c_str(), this->getContentSize().height / 2);*/
//}


//void Monster::hit(int damage, float flyingDegree, bool isCriticalStrike)
//{
//	/*if (!m_isAlive)
//		return;
//	this->m_Hp -= damage;
//	setMonsTaunted();*/
//	this->stopAllActions();
//	auto curPos = getPosition();
//	auto vecToMove = Vec2(5 * cos(flyingDegree / 180 * 3.14), 5 * sin(flyingDegree / 180 * 3.14));
//	/*if (m_isBulkUp)
//		vecToMove *= 3;*/
//	auto targetPos = curPos + vecToMove;
//
//	//this->mySetPosition(targetPos);
//	/*if (!m_map->isBarrier(m_map->convertToMapSpace(convertToWorldSpace(targetPos))))
//	{
//		auto move_action = MoveBy::create(0.1f, vecToMove);
//		this->runAction(move_action);
//	}*/
//	if (isCriticalStrike)
//	{
//		std::string msg = std::to_string(damage) + '!';
//		//m_damageMsg->showCritDmg(msg.c_str(), this->getContentSize().height / 2);
//		return;
//	}
//	std::string msg = std::to_string(damage);
//	//m_damageMsg->showMonsDmg(msg.c_str(), this->getContentSize().height / 2);
//}