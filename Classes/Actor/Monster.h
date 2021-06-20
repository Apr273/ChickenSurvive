#pragma once
#include "cocos2d.h"
#include "Entity.h"
#include "Player.h"
#include"Weapon/Bullet.h"

USING_NS_CC;
class Monster : public Entity 
{
public:
	Monster();
	~Monster();
	CREATE_FUNC(Monster);
	virtual bool init();
	//bool hitByBullet(Bullet*bullet);

public:
	void show();//显示怪物
	void die();//隐藏怪物
	void reset();
	bool isAlive();
	void setTiledMap(TMXTiledMap* map);
	bool isCollideWith(Entity* entity);
	void hurt(int damage);
	void bindPlayer(Player* player);
	void attack(Entity* entity);
	//virtual void hit(int damage, float flyingDegree, bool isCriticalStrike);//怪物受到伤害
private:
	bool m_isAlive;
	TMXTiledMap* m_map;
	TMXLayer* meta;//检测碰撞的地图图层
	Player* m_player;
	static const int m_initHp = 30;
	int m_Hp=m_initHp;
	Sprite* sprite;
	Bullet* monster_bullet;
};

