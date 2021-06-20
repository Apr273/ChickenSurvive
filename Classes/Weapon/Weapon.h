//#ifndef __Weapon_H__
//#define __Weapon_H__
//
//#include <string>
//#include "cocos2d.h"
//#include "Actor\Entity.h"
//#include "MyScene.h"
//#include "Bullet.h"
//USING_NS_CC;
//
//class Weapon :public Entity
//{
//public:
//	Weapon();
//	~Weapon();
//	CREATE_FUNC(Weapon);
//	virtual bool init();
//public:
//	virtual void attack(Point pos);
//	virtual std::vector<Bullet*> getBullet() const;
//	int getRange()const;
//	void bindMap(MyScene* map);
//	//void setCritRate(float crit_rate);
//	virtual float getAttackSpeed()const;
//	void setAttackSpeed(float speed);
//	virtual int getDamage()const;
//	virtual void setDamage(int damage);
//	void resetPosition();
//	virtual void flipped(bool status/*true for flipped and false for not flipped*/);
//	virtual void setRotationByPos(Point pos);
//	virtual void upgrade();
//	//virtual bool isCloseWeapon()const;
//	const std::string& getWeaponName() { return m_weaponName; }
//	inline bool getIsUpgarte() const { return isUpgrate; }
//	bool isUsed()const { return m_is_used; }
//	void disappear();
//	void setNumberOfBullets(int number);
//	int getNumberOfBullets()const;
//	//Bullet* generateBullet(float degree, float scale_x, float scale_y);
//protected:
//	//int m_power_cost;
//	int m_range;
//	bool isUpgrate = false;
//	//float m_crit_rate;
//	float m_attack_speed;
//	bool m_is_used = false;
//	std::string m_weaponName = "none";
//	MyScene* m_map;
//	int m_bullet_num;
//
//};
//#endif