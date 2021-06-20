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
	//void jump();//跳跃函数
	void hit();//玩家受到碰撞伤害
	int getiHP();//获取血量
	int getiGrade();//获取积分
	void setiGrade(int grade);//设置积分
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
	bool isJumping; // 标记主角是否碰撞了障碍物，在反弹中
	bool m_isjumping; //标记主角是否正在跳跃
	int m_iHP ;
	TMXLayer* meta;//检测碰撞的地图图层

	// 将像素坐标转换为地图格子坐标
	Point tileCoordForPosition(Point pos);
	int m_numLongRange;
	Bullet* m_bullet;
	int m_iGrade ;
};

#endif // !__Player_H__

