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
	void show();//��ʾ����
	void hide();//���ع���
	void reset();
	bool isAlive();
	void setTiledMap(TMXTiledMap* map);
	bool isCollideWith(Entity* entity);
	//void hit(int damage);
	//virtual void hit(int damage, float flyingDegree, bool isCriticalStrike);//�����ܵ��˺�
private:
	bool m_isAlive;
	Player* player;
	TMXTiledMap* m_map;
	TMXLayer* meta;//�����ײ�ĵ�ͼͼ��
};

