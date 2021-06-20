#include "Monster.h"
Monster::Monster() 
{
	m_isAlive = false;
}

Monster::~Monster(){}

bool Monster::init()
{
	auto sprite = Sprite::create("MonsterD1.png");
	bindSprite(sprite);
	return true;
}
//bool Monster::isCollideWithPlayer(Player* player)
//{
//	/*获取碰撞检查对象的boundingBox*/
//	Rect entityRect = player->getBoundingBox();
//
//	Point monsterPos = getPosition();
//
//	/*判断boundingBox和怪物中心点是否有交集*/
//	return entityRect.containsPoint(monsterPos);
//	
//}
//bool Monster::hitByBullet(Bullet* bullet)
//{
//	Rect entityRect = bullet->getBoundingBox();
//
//	Point monsterPos = getPosition();
//	/*判断boundingBox和怪物中心点是否有交集*/
//	return getBoundingBox().intersectsRect(bullet->getBoundingBox());
//}
void Monster::show()
{
	if (getSprite() != NULL)
	{
		setVisible(true);//设置可见
		m_isAlive = true;//标记怪物为活动状态
	}
}

void Monster::hide() 
{
	if (getSprite() != NULL)
	{
		setVisible(false);//设置不可见
		//reset();
		m_isAlive = false;//标记怪物为非活动状态
		log("monster is hidden");
	}
	
}

void Monster::reset()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(CCRANDOM_0_1()*1000, CCRANDOM_0_1()*1000));
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

//bool Monster::hit(Bullet* bullet)
//{
//	/*获取碰撞检查对象的boundingBox*/
//	Rect entityRect = bullet->getBoundingBox();
//
//	Point monsterPos = getPosition();
//
//	/*判断boundingBox和怪物中心点是否有交集*/
//	return entityRect.containsPoint(monsterPos);
//}

//bool Monster::isCollideWithPlayer(Player* player)
//{
//	/*获取碰撞检测对象的boundingBox*/
//	if (player != NULL)
//	{
//		Rect entityRect = player->getBoundingBox();
//		Point monsterPos = getPosition();
//		return entityRect.containsPoint(monsterPos);
//	}
//}

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