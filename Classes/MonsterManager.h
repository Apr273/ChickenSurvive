#ifndef __MonsterManager_H__
#define __MonsterManager_H__


#include "cocos2d.h"
#include "Actor/Monster.h"
#include "Weapon/Bullet.h"
USING_NS_CC;

class MonsterManager:public Node
{
public:
	CREATE_FUNC(MonsterManager);
	virtual bool init();

	virtual void update(float dt);
	void bindPlayer(Player* player);
	void bindBullet(Bullet* bullet);
//	std::vector<Bullet*> getMonsterBullets()const;
	//Vector<Monster*> getMonster();
	bool isGameOver();
private:
	void createMonsters();//创建怪物对象
	Player* m_player=NULL;
	Bullet* m_bullet = NULL;
	//Bullet* m_bullet;
	Vector<Monster*> m_monsterArr;//存放怪物对象列表
	//std::vector<Monster*> m_monsterArr;
	std::vector<Bullet*> m_monsterBullet;
	int i_count ;
};

#endif // !__MonsterManager_H__