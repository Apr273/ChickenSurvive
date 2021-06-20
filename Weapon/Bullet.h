#ifndef __Bullet_H__
#define __Bullet_H__

#include "cocos2d.h"
#include"Actor\Entity.h"

class Bullet :public Entity
{
public:
	Bullet();
	~Bullet();
	CREATE_FUNC(Bullet);
	virtual bool init();
	bool isCollideWith(Entity* entity);
	int getRange()const;
	int getDamage()const;
	void setInfo(int range, int damage);
	bool isUsed()const;
	void setIsUsed(bool status);
	void setOriginPos(const Point& pos);
	float getDistance()const;
	void setBulletAction(float degree, int speed);
	void setDegree(float degree);
	float getDegree()const;
	//设置初始子弹数量
	/*void setNumberOfBullets(int number);
	int getNumberOfBullets()const;*/
	/*void setCritRate(float rate);
	float getCritRate()const;*/
	protected:
		float m_degree;
		int m_bullet_range;
		int m_bullet_damage = 1;
		bool m_is_used;
		int m_bullet_number;
		//float m_crit_rate;
	
		Point m_origin_pos;//in map coordinate
};

#endif