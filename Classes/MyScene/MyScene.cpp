#include "MyScene.h"
#include "MonsterManager.h"

#include"Scene/SelectScene.h"
#include "Scene/OutScene.h"
#include"Scene/SetItemScene.h"

#include"Weapon/NumberBullet.h"
#include"Weapon/PowerBullet.h"
#include"Weapon/SpeedBullet.h"

USING_NS_CC;

Scene* MyScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    auto layer = MyScene::create();
    scene->addChild(layer);
    return scene;
}

void MyScene::update(float delta)
{

    //if (!(m_monsterList->isGameOver()))
    //{
    //    for (auto monster : m_monsterArr)
    //    {
    //        if (monster->isAlive())
    //        {
    //            if (monster->isCollideWith(m_player))
    //            {
    //                //m_player->hit();
    //                //��������
    //                monster->die();
    //            }
    //            //�޸��ӵ���
    //            else if (monster->isCollideWith(m_bullet))
    //            {
    //                log("bullet collide");
    //                //���ڲ���
    //                monster->die();
    //                //monster->hurt(m_bullet->getDamage());
    //            }
    //        }
    //        else
    //        {
    //            monster->show();
    //
    //        }
    //    }
    //}
    //else
    //{
    //    log("over");
    //}

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    Sprite* pBloodManSp = Sprite::create("Blood.png");//��Ѫ��
    removeChild(pBloodProGress, true);
    pBloodProGress = ProgressTimer::create(pBloodManSp);
    pBloodProGress->setType(ProgressTimer::Type::BAR);
    pBloodProGress->setBarChangeRate(Vec2(1, 0));
    pBloodProGress->setMidpoint(Vec2(0, 0));
    pBloodProGress->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 6 - width));
    //pBloodProGress->setPercentage(player.getiHP() / 10);
    pBloodProGress->setPercentage((m_player->getiHP()) / 6);
    this->addChild(pBloodProGress, 100, 1);  //Ѫ��
    log("Hp %d", m_player->getiHP());
    if ((m_player->getiHP()) / 6 <= 0)
    {
        unscheduleUpdate();
        Director::getInstance()->replaceScene(OutScene::createScene());
    }

    removeChild(GRADE, true);
    GRADE = Label::createWithSystemFont((Value(m_player->getiGrade())).asString().c_str(), "fonts/arial.ttf", 30);
    GRADE->setTextColor(Color4B::WHITE);
    GRADE->setPosition(Vec2(origin.x + visibleSize.width / 2 + length * 14 / 9, origin.y + visibleSize.height / 2 + width * 28 / 4.8));
    this->addChild(GRADE, 100);  //ʱ��


    removeChild(TIME_s, true);
    TIME_s = Label::createWithSystemFont((Value((int)time_record(begin) / 1000 % 60)).asString().c_str(), "fonts/arial.ttf", 30);
    TIME_s->setTextColor(Color4B::WHITE);
    TIME_s->setPosition(Vec2(origin.x + visibleSize.width / 2 + 25, origin.y + visibleSize.height / 6 + width * 10));
    this->addChild(TIME_s, 100);  //ʱ��
    if ((int)time_record(begin) / 1000 / 60)
    {
        removeChild(TIME_min, true);
        TIME_min = Label::createWithSystemFont((Value((int)time_record(begin) / 1000 / 60)).asString().c_str(), "fonts/arial.ttf", 30);
        TIME_min->setTextColor(Color4B::WHITE);
        TIME_min->setPosition(Vec2(origin.x + visibleSize.width / 2 - length / 13 + 10, origin.y + visibleSize.height / 6 + width * 10));
        this->addChild(TIME_min, 100);  //ʱ��
    }
    if ((int)time_record(begin) / 1000 / 60 / 60)
    {
        removeChild(TIME_h, true);
        TIME_h = Label::createWithSystemFont((Value((int)time_record(begin) / 1000 / 60 / 60)).asString().c_str(), "fonts/arial.ttf", 30);
        TIME_h->setTextColor(Color4B::WHITE);
        TIME_h->setPosition(Vec2(origin.x + visibleSize.width / 2 - length / 6, origin.y + visibleSize.height / 6 + width * 10));
        this->addChild(TIME_h, 100);  //ʱ��
    }

}

bool MyScene::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    if (!Layer::init())
    {
        return false;
    }
    //ע��������
    registeMouseEvent();

    //����Tiled��ͼ����ӵ�������

    TMXTiledMap* map = TMXTiledMap::create("Map/map2.tmx");
    auto layer = map->getLayer("tree");
    this->addChild(map);
    addPlayer(map);

    //�������������
   //MonsterManager* monsterMgr = MonsterManager::create();
    this->addChild(monsterMgr, 4);

    //�����ƶ�·��
    ccBezierConfig bezier1;
    bezier1.controlPoint_1 = Point(20, 20);
    bezier1.controlPoint_2 = Point(50, 70);
    bezier1.endPosition = Point(0, 0);

    BezierTo* bezierTo1 = BezierTo::create(4.0f, bezier1);
    RepeatForever* repeatForeverAction1 = RepeatForever::create(bezierTo1);
    monsterMgr->runAction(repeatForeverAction1);
    //
    MonsterManager* Monster2 = MonsterManager::create();
    this->addChild(Monster2, 4);
    Monster2->bindPlayer(m_player);
    
    ccBezierConfig bezier2;
    bezier2.controlPoint_1 = Point(0, -20);
    bezier2.controlPoint_2 = Point(70, 20);
    bezier2.endPosition = Point(-40, 0);
    
    BezierTo* bezierTo2 = BezierTo::create(4.0f, bezier2);
    RepeatForever* repeatForeverAction2 = RepeatForever::create(bezierTo2);
    Monster2->runAction(repeatForeverAction2);
    
    //m_bullet->setPosition(-100, -100);
    //this->addChild(m_bullet);
    //m_bullet->setPosition(m_player->getPosition());//�ӵ�λ��
    //����ڱ�
    Director::getInstance()->setProjection(Director::Projection::_2D); 
    

    MenuItemFont::setFontName("fonts/STHUPO.ttf");
    MenuItemFont::setFontSize(30);

    auto SetItem = MenuItemImage::create(
        "Item//SetItem.png",
        "Item//SetItem.png",             //����ͼƬ
        CC_CALLBACK_1(MyScene::SetScene, this));
    SetItem->setPosition(Vec2(origin.x + visibleSize.width / 2 - length * 16 / 10.1, origin.y + visibleSize.height / 2 + width * 28 / 4.8));  //��ʾλ��


    Sprite* pBloodKongSp = Sprite::create("Bar.png");//��Ѫ��
    pBloodKongSp->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 6 - width));
    this->addChild(pBloodKongSp);
    Sprite* pBloodManSp = Sprite::create("Blood.png");//��Ѫ��


    auto Timeitem = MenuItemFont::create("Time: ");
    Timeitem->setPosition(Vec2(visibleSize.width / 2 - length / 3, origin.y + visibleSize.height / 6 + width * 10));
    //��ʾ�������
    TIME_s = Label::createWithSystemFont((Value(0)).asString().c_str(), "fonts/arial.ttf", 30);
    TIME_s->setTextColor(Color4B::WHITE);
    TIME_s->setPosition(Vec2(origin.x + visibleSize.width / 2 + 30, origin.y + visibleSize.height / 6 + width * 10));
    this->addChild(TIME_s, 100);
    auto maoitem_ = MenuItemFont::create(":");
    maoitem_->setPosition(Vec2(visibleSize.width / 2 - length / 10, origin.y + visibleSize.height / 6 + width * 10));
    TIME_min = Label::createWithSystemFont((Value(0)).asString().c_str(), "fonts/arial.ttf", 30);
    TIME_min->setTextColor(Color4B::WHITE);
    TIME_min->setPosition(Vec2(origin.x + visibleSize.width / 2 - length / 13 + 10, origin.y + visibleSize.height / 6 + width * 10));
    this->addChild(TIME_min, 100);
    auto maoitem = MenuItemFont::create(":");
    maoitem->setPosition(Vec2(visibleSize.width / 2 - length / 10 + 30, origin.y + visibleSize.height / 6 + width * 10));
    TIME_h = Label::createWithSystemFont((Value(0)).asString().c_str(), "fonts/arial.ttf", 30);
    TIME_h->setTextColor(Color4B::WHITE);
    TIME_h->setPosition(Vec2(origin.x + visibleSize.width / 2 - length / 6, origin.y + visibleSize.height / 6 + width * 10));
    this->addChild(TIME_h, 100);


    auto GradeItem = MenuItemFont::create("Grade: ");
    GradeItem->setPosition(Vec2(origin.x + visibleSize.width / 2 + length * 14 / 10.1, origin.y + visibleSize.height / 2 + width * 28 / 4.8));  //��ʾλ��
    GRADE = Label::createWithSystemFont((Value((int)end)).asString().c_str(), "fonts/arial.ttf", 30);
    GRADE->setTextColor(Color4B::WHITE);
    GRADE->setPosition(Vec2(origin.x + visibleSize.width / 2 + length * 14 / 10.3, origin.y + visibleSize.height / 2 + width * 28 / 4.8));
    this->addChild(GRADE, 100);


    auto menu = Menu::create(Timeitem, SetItem, GradeItem, maoitem, maoitem_, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 100);

    begin = time_record(0);
    this->scheduleUpdate();
    return true;
}

/*�ڵ�ͼ��������*/
void MyScene::addPlayer(TMXTiledMap* map)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    m_player = Player::create();
    m_player->setTiledMap(map);

    monsterMgr->bindPlayer(m_player);

    //���ض����
    TMXObjectGroup* objGroup = map->getObjectGroup("hero");
    //�����������
    ValueMap playerPointMap = objGroup->getObject("PlayerPoint");
    float playerX = playerPointMap.at("x").asFloat();
    float playerY = playerPointMap.at("y").asFloat();

    //�����������
    m_player->setPosition(Point(playerX, playerY));
    //�������ӵ���ͼ��
    map->addChild(m_player);

    //������ҿ�����
    DirectionController* moveControll = DirectionController::create();
    moveControll->setXSpeed(0);
    moveControll->setYSpeed(0);
    moveControll->setPlayer(m_player);
    //��������ӵ�������
    this->addChild(moveControll);
    //���ÿ���������������
    m_player->setController(moveControll);
    
 
}

Bullet* MyScene::addBullet()
{

    if (SelectScene::GetOfWeapon() % 3 == 0)
    {
        m_bullet = SpeedBullet::create();
    }
    else if (SelectScene::GetOfWeapon() % 3 == 1)
    {
        m_bullet = PowerBullet::create();
    }
    else 
    {
        m_bullet = NumberBullet::create();
    }
    return m_bullet;
    //m_bullet->setPosition(-5,-5);//�ӵ�λ��
    //m_bullet->setScale(0.5f);//�ӵ���С
    //this->addChild(m_bullet);
}

////�������ѡ����ӵ�
////û�ĺ�
//int MyScene::addBullet()
//{
//    //�������������
//    MonsterManager* monsterMgr = MonsterManager::create();
//    this->addChild(monsterMgr, 4);
//    monsterMgr->bindBullet(m_bullet);
//    monsterMgr->bindPlayer(m_player);
//
//    int bullet_number = 0;
//    if (SelectScene::GetOfWeapon() % 3 == 0)
//    {
//        for ( ; bullet_number < 40; bullet_number++)
//        {
//            m_player->bullets[bullet_number] =SpeedBullet::create();
//        }
//    }
//    else if (SelectScene::GetOfWeapon() % 3 == 1)
//    {
//        for (; bullet_number <40; bullet_number++)
//        {
//            m_player->bullets[bullet_number] = PowerBullet::create();
//        }
//    }
//    else if (SelectScene::GetOfWeapon() % 3 == 2)
//    {
//        for (; bullet_number < 70; bullet_number++)
//        {
//            m_player->bullets[bullet_number] = NumberBullet::create();
//        }
//    }
//    return bullet_number;
//    //m_bullet->setPosition(-5,-5);//�ӵ�λ��
//    //m_bullet->setScale(0.5f);//�ӵ���С
//    //this->addChild(m_bullet);
//    /*if (SafeMapLayer::whichPlayer() == 1)
//        m_player = Ranger::create();
//    else if (SafeMapLayer::whichPlayer() == 2)
//        m_player = Priest::create();
//    else
//        m_player = Knight::create();
//    m_player->setPosition(Vec2(x, y));*/
//}

//ָ�Ĵ���
void MyScene::registeMouseEvent()
{
    
    monsterMgr->bindBullet(m_bullet);

    //�����¼�����������������¼�
    auto myMouseListener = EventListenerMouse::create();
    //����걻����
   // static int bullet_number = 0;
    myMouseListener->onMouseDown = [=](Event* event)
    {
        m_bullet = addBullet();
        m_bullet->setPosition(m_player->getPosition());//�ӵ�λ��
        m_bullet->setScale(0.5f);//�ӵ���С
        this->addChild(m_bullet);
        EventMouse* e = (EventMouse*)event;
        //�ҵ�λ��ʹ���ӵ������Ļ��
        Vec2 mouseLocation = Point(e->getCursorX(), e->getCursorY());
        Vec2 offset = mouseLocation - m_player->getPosition();
        offset.normalize();
        auto shootAmount = offset * 1000;
        auto realDest = shootAmount + m_player->getPosition();

        auto actionMove = MoveTo::create(100.0f / (m_bullet->getSpeed()), realDest);
        auto actionRemove = RemoveSelf::create();
        m_bullet->runAction(Sequence::create(actionMove, actionRemove, nullptr));
    };
    //���¼��������볡����
    _eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);
}

void MyScene::SetScene(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(SetItemScene::createScene());
}


/*�������ʱ�¼ӵģ���û�ĺ�*/
//void MyScene::update(float dt)
//{
//    //��ײ���
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
