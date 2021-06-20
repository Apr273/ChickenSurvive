//#include "SpeedGun.h"
//
//SpeedGun::SpeedGun()
//{
//
//}
//
//bool SpeedGun::init()
//{
//	if (!LongRange::init())
//	{
//		return false;
//	}
//	//m_Speed_cost = 3;
//	m_bullet_num = 100;
//	m_range = 100;
//	m_bullet_damage = 10;
//	m_bullet_speed = 800;
//	m_attack_speed = 0.1f;
//	//m_crit_rate = 0.3f;
//	//m_bullet_picture = std::string("bullet_3.png");
//	auto sprite = Sprite::create("bullet_3.png");
//	bindSprite(sprite);
//	/*bindSprite(Sprite::create("SpeedGun!.png"));
//	m_sprite->setAnchorPoint(Vec2(0.0f, 0.5f));*/
//	m_weaponName = "SpeedGun!";
//	//test
//	//auto upgrade_effect = ParticleFlower::create();
//	//upgrade_effect->setEmitterMode(ParticleSystem::Mode::RADIUS);
//	//upgrade_effect->setPositionType(ParticleSystem::PositionType::RELATIVE);
//	//upgrade_effect->setAutoRemoveOnFinish(true);
//	//upgrade_effect->setTotalParticles(100);
//	//upgrade_effect->setPosition(getSprite()->getContentSize().width / 2, getSprite()->getContentSize().height / 2);
//	//upgrade_effect->setDuration(-1);
//	//upgrade_effect->setStartRadius(50.0f);
//	//upgrade_effect->setStartRadiusVar(25.0f);
//	//upgrade_effect->setEndRadius(50.0f);
//	//getSprite()->addChild(upgrade_effect);
//
//	return true;
//}
//
//
////void SpeedGun::upgrade()
////{
////	isUpgrate = true;
////	//m_Speed_cost = 3;
////	m_bullet_num = 200;
////	m_range = 100;
////	m_bullet_damage = 20;
////	m_bullet_speed = 750;
////	m_attack_speed = 0.1f;
////	//m_crit_rate = 0.5f;
////	auto upgrade_effect = ParticleFlower::create();
////	upgrade_effect->setEmitterMode(ParticleSystem::Mode::RADIUS);
////	upgrade_effect->setPositionType(ParticleSystem::PositionType::RELATIVE);
////	upgrade_effect->setAutoRemoveOnFinish(true);
////	upgrade_effect->setTotalParticles(100);
////	upgrade_effect->setPosition(getSprite()->getContentSize().width / 2, getSprite()->getContentSize().height / 2);
////	upgrade_effect->setDuration(-1);
////	upgrade_effect->setStartRadius(50.0f);
////	upgrade_effect->setStartRadiusVar(25.0f);
////	upgrade_effect->setEndRadius(50.0f);
////	getSprite()->addChild(upgrade_effect);
////}
//
//SpeedGun::~SpeedGun()
//{
//
//}