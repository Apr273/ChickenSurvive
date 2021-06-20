#include "MyScene.h"
#include "MonsterManager.h"

USING_NS_CC;

Scene* MyScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    auto layer = MyScene::create();
    scene->addChild(layer);
    return scene;
}

bool MyScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    //加载Tiled地图，添加到场景中

    TMXTiledMap* map = TMXTiledMap::create("Map/map2.tmx");
    auto layer = map->getLayer("tree");
    this->addChild(map);
    addPlayer(map);
    //避免黑边
    Director::getInstance()->setProjection(Director::Projection::_2D); 

    //创建怪物管理器
    MonsterManager* Monster1 = MonsterManager::create();
    this->addChild(Monster1,4);
    Monster1->bindPlayer(m_player);//依然是有错的
   
    /*ccBezierConfig bezier;
    bezier.controlPoint_1 = Point(300, 300);
    bezier.controlPoint_2 = Point(200, 700);
    bezier.endPosition = Point(100, 100);

    BezierTo* bezierTo = BezierTo::create(4.0f, bezier);
    RepeatForever* repeatForeverAction = RepeatForever::create(bezierTo);
    Monster1->runAction(repeatForeverAction);*/

    return true;
}

/*在地图上添加玩家*/
void MyScene::addPlayer(TMXTiledMap* map)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
   ////创建精灵
   // Sprite* playerSprite = Sprite::create("monsterD1.png");
   // //将精灵绑定到玩家对象上
   // Player* myPlayer = Player::create();
   // myPlayer->bindSprite(playerSprite);
    //myPlayer->run();
    m_player = Player::create();
    m_player->setTiledMap(map);

    //Sprite* Monster1 = Sprite::create("monsterD1.png");

   
    //加载对象层
    TMXObjectGroup* objGroup = map->getObjectGroup("hero");
 //   TMXObjectGroup* objGroup1 = map->getObjectGroup("Monster1");
    //加载玩家坐标
    ValueMap playerPointMap = objGroup->getObject("PlayerPoint");
    float playerX = playerPointMap.at("x").asFloat();
    float playerY = playerPointMap.at("y").asFloat();

    //设置玩家坐标
    m_player->setPosition(Point(playerX, playerY));
    //将玩家添加到地图上
    map->addChild(m_player);

    /*ValueMap playerPointMap1 = objGroup1->getObject("First1");
    float Monster1X = playerPointMap1.at("x").asFloat();
    float Monster1Y = playerPointMap1.at("y").asFloat();
    */
    

    //创建玩家控制器
    DirectionController* moveControll = DirectionController::create();
    moveControll->setXSpeed(0);
    moveControll->setYSpeed(0);
    moveControll->setPlayer(m_player);
    //控制器添加到场景中
    this->addChild(moveControll);
    //设置控制器到主角身上
    m_player->setController(moveControll);
    
  // //this->addChild(Monster1);
  //  ccBezierConfig bezier;
  // bezier.controlPoint_1 = Point(300, 300);
  // bezier.controlPoint_2 = Point(200, 700);
  // bezier.endPosition = Point(100, 100);

  // BezierTo* bezierTo = BezierTo::create(4.0f, bezier);
  // RepeatForever* repeatForeverAction = RepeatForever::create(bezierTo);
  //// Monster1->runAction(repeatForeverAction);
}

cocos2d::Point MyScene::convertToMapSpace(const Point& point)
{
    return convertToNodeSpace(point);
}
/*设计武器时新加的，还没改好*/
//void MyScene::update(float dt)
//{
//    //碰撞检测
//    auto player_bullet = m_player->getBullet();
//    auto monsters_bullet = m_monsterMgr->getMonsterBullets();
//    auto monsters = m_monsterMgr->getMonster();
//
//	//player bullet
//	for (auto bullet : player_bullet)
//	{
//		if (bullet->isUsed())
//		{
//			continue;
//		}
//		cocos2d::Point bullet_pos = bullet->getPosition();
//		/*if (typeid(*bullet) == typeid(ExplosiveBullet))
//		{
//			auto explosive_bullet = dynamic_cast<ExplosiveBullet*>(bullet);
//			if (!explosive_bullet->isUsed() && !explosive_bullet->isExplode())
//			{
//				explosive_bullet->explode();
//			}
//			for (auto unlucky_monster : monsters)
//			{
//				if (unlucky_monster->isAlive())
//				{
//					cocos2d::Point explosive_origin_point = m_map->convertToWorldSpace(explosive_bullet->getPosition());
//					if (unlucky_monster->getBoundingBox().intersectsCircle(explosive_origin_point, explosive_bullet->getExplosionRange()))
//					{
//						unlucky_monster->hit(explosive_bullet->getExplosionDamage() * m_player->getDamageBonus(), bullet->getDegree(), 0);
//					}
//				}
//			}
//
//		}
//		else bullet->setIsUsed(true);*/
//		for (auto monster : monsters)
//		{
//
//			if (monster->isAlive())
//			{
//				if (bullet->isCollideWith(monster))
//				{
//
//					int damage = bullet->getDamage();
//					/*if (CCRANDOM_0_1() < bullet->getCritRate())
//					{
//						damage *= 2;
//						monster->hit(damage * m_player->getDamageBonus(), bullet->getDegree(), 1);
//					}
//					else
//						monster->hit(damage * m_player->getDamageBonus(), bullet->getDegree(), 0);*/
//
//
//					for (auto unlucky_monster : monsters)
//					{
//						if (unlucky_monster->isAlive())
//						{
//							cocos2d::Point explosive_origin_point = m_map->convertToWorldSpace(explosive_bullet->getPosition());
//							if (unlucky_monster->getBoundingBox().intersectsCircle(explosive_origin_point, explosive_bullet->getExplosionRange()))
//							{
//								unlucky_monster->hit(explosive_bullet->getExplosionDamage() * m_player->getDamageBonus(), explosive_bullet->getDegree(), 1);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	/*if (m_player->isAttackingWithCloseWeapon())
//	{
//		auto weapon = m_player->getCloseWeapon();
//		if (!weapon->isHit())
//		{
//			for (auto monster : monsters)
//			{
//				if (weapon->isCollideWith(monster))
//				{
//					int damage = weapon->getDamage();
//					if (CCRANDOM_0_1() < weapon->getCritRate())
//					{
//						damage *= 2;
//						monster->hit(damage * m_player->getDamageBonus(), 0.0f, 1);
//						if (typeid(*m_player) == typeid(Knight) && dynamic_cast<Knight*>(m_player)->getIsInSkill())
//						{
//							monster->hit(damage * m_player->getDamageBonus(), 0.0f, 1);
//						}
//					}
//					else
//					{
//						monster->hit(damage * m_player->getDamageBonus(), 0.0f, 0);
//						if (typeid(*m_player) == typeid(Knight) && dynamic_cast<Knight*>(m_player)->getIsInSkill())
//						{
//							monster->hit(damage * m_player->getDamageBonus(), 0.0f, 0);
//						}
//					}
//				}
//			}
//			weapon->setIsHit(true);
//		}
//	}*/
//    //auto woodWalls = m_monsterMgr->getWoodWall();
//    /*for (auto woodWall : woodWalls)
//    {
//        monsters.push_back(woodWall);
//    }*/
//}

//void MyScene::addMonster(TMXTiledMap* map)
//{
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Sprite* Monster1 = Sprite::create("monsterD1.png");
//    Monster* myMonster = Monster::create();
//    myMonster->bindSprite(Monster1);
//    myMonster->setTiledMap(map);
//
//    TMXObjectGroup* objGroup1 = map->getObjectGroup("Monster1");
//
//    map->addChild(myMonster);
//    ccBezierConfig bezier;
//    bezier.controlPoint_1 = Point(300, 300);
//    bezier.controlPoint_2 = Point(200, 700);
//    bezier.endPosition = Point(100, 100);
//
//    BezierTo* bezierTo = BezierTo::create(4.0f, bezier);
//    RepeatForever* repeatForeverAction = RepeatForever::create(bezierTo);
//    Monster1->runAction(repeatForeverAction);
//    if (myMonster->isCollideWith(m_bullet))
//    {
//        myMonster->hide();
//    }
//
//   
//    
//      
//}