#ifndef __Player_H__
#define __Player_H__
#pragma once

#include"cocos2d.h"
#include "Entity.h"
#include"Weapon/Bullet.h"
#include"Weapon/NumberBullet.h"
#include"Weapon/PowerBullet.h"
#include"Weapon/SpeedBullet.h"
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
	void hit();//����ܵ���ײ�˺�
	int getiHP();//��ȡѪ��
	int getiGrade();//��ȡ����
	void setiGrade(int grade);//���û���
	Player();
	void resetData();
	bool isCollideWith(Entity* entity);
	//std::vector<Bullet*> getBullet(int bullet_type);
	std::vector<Bullet*> bullets;
	/*std::array <NumberBullet*,150> m_numberBullets{ NULL };
	std::array <PowerBullet*, 80> m_powerBullets{ NULL };
	std::array <SpeedBullet*, 80> m_speedBullets{ NULL };*/
	//std::array <LongRange*, 3> m_longRanges{ NULL };

private:

	TMXTiledMap* m_map;
	bool isJumping; // ��������Ƿ���ײ���ϰ���ڷ�����
	bool m_isjumping; //��������Ƿ�������Ծ
	int m_iHP ;
	TMXLayer* meta;//�����ײ�ĵ�ͼͼ��

	// ����������ת��Ϊ��ͼ��������
	Point tileCoordForPosition(Point pos);
	int m_numLongRange;
	Bullet* m_bullet;
	int m_iGrade ;
};

#endif // !__Player_H__

