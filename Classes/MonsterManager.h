#ifndef __MonsterManager_H__
#define __MonsterManager_H__


#include "cocos2d.h"
#include "Actor/Monster.h"
#include "Weapon/Bullet.h"
#include"Weapon/PowerGun.h"
USING_NS_CC;

#define MAX_MONSTER_NUM 10

class MonsterManager:public Node
{
public:
	CREATE_FUNC(MonsterManager);
	virtual bool init();

	virtual void update(float dt);
	void bindPlayer(Player* player);
	//void bindBullet(Bullet* bullet);
	std::vector<Bullet*> getMonsterBullets()const;
	std::vector<Monster*> getMonster()const;
private:
	void createMonsters();//�����������
	Player* myplayer=NULL;
	//PowerGun* mybullet = NULL;//�����໹ûд�ã�����Power������
	//Bullet* m_bullet;

	Vector<Monster*> m_monsterArr;//��Ź�������б�
	std::vector<Monster*> m_monsterList;
	std::vector<Bullet*> m_monsterBullet;
};

#endif // !__MonsterManager_H__