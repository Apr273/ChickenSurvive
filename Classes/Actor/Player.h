#ifndef __Player_H__
#define __Player_H__
#pragma once

#include"cocos2d.h"
#include "Entity.h"
#include"Weapon/Bullet.h"
#include "Weapon/LongRange.h"
using namespace cocos2d;

class Player :public Entity
{
public:
	CREATE_FUNC(Player);
	virtual bool init();
	void run(char m_direction);
	void setViewPointByPlayer();
	virtual void setTagPosition(int x, int y);
	void setTiledMap(TMXTiledMap* map);
	//void jump();//��Ծ����
	void hit();//����ܵ��˺�
	int getiHP();//��ȡѪ��
	Player();
	void resetData();
	bool isCollideWith(Entity* entity);
	//std::vector<Bullet*> m_bullet;
	//std::vector<Bullet*> getBullet();
	//std::array <LongRange*, 3> m_longRanges{ NULL };
private:

	TMXTiledMap* m_map;
	bool isJumping; // ��������Ƿ���ײ���ϰ���ڷ�����
	bool m_isjumping; //��������Ƿ�������Ծ
	int m_iHP;
	TMXLayer* meta;//�����ײ�ĵ�ͼͼ��

	// ����������ת��Ϊ��ͼ��������
	Point tileCoordForPosition(Point pos);
	int m_numLongRange;

};

#endif // !__Player_H__

