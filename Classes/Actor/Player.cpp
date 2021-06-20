#include "Player.h"

Player::Player()
{
    auto sprite = Sprite::create("PlayerD1.png");
    bindSprite(sprite);
    
}
bool Player::init()
{
    m_isjumping = false;
    m_iHP = 600;
    m_iGrade = 0;
    return true;
}
void Player::run(char m_Direction)
{
    auto* m_frameCache = SpriteFrameCache::getInstance();
    m_frameCache->addSpriteFramesWithFile("Player.plist", "Player.png");
    SpriteFrame* frame = NULL;
    Vector<SpriteFrame*>frameArray;//��������

    if (m_Direction != 'T')
    {
        //��������֡����ѭ������
        for (int i = 1; i < 4; ++i)
        {
            auto* frame = m_frameCache->getSpriteFrameByName(StringUtils::format("Player%c%d.png", m_Direction, i));
            frameArray.pushBack(frame);//��֡����������
        }
        //������������
        Animation* animation = Animation::createWithSpriteFrames(frameArray);
        //����ִ�д�����-1Ϊ����ִ��
        animation->setLoops(-1);
        //ÿһ֡�л�Ƶ��
        animation->setDelayPerUnit(0.3f);
        //������������
        auto* action = Animate::create(animation);
        //����ִ�ж���
        m_sprite->runAction(action);
    }
    else if (m_Direction == 'T')
    {
        m_sprite->stopAllActions();
    }

}

//�ж��Ƿ���Ҫ�ƶ���ͼ
void Player::setViewPointByPlayer()
{
    if (m_sprite == NULL)
    {
        return;
    }
    Layer* parent = (Layer*)getParent();

    //��ͼ��������
    Size mapTiledNum = m_map->getMapSize();
    //��ͼ�������Ӵ�С
    Size tiledSize = m_map->getTileSize();
    //��ͼ��С
    Size mapSize = Size(
        mapTiledNum.width * tiledSize.width,
        mapTiledNum.height * tiledSize.height);
    //��Ļ��С
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //��������
    Point spritePos = getPosition();
    //�ж�ȡ��Ļ�е��������������
    float x = std::max(spritePos.x, visibleSize.width / 2);
    float y = std::max(spritePos.y, visibleSize.height / 2);
    //�ж�ȡ����ֵ����
    x = std::min(x, mapSize.width - visibleSize.width / 2);
    y = std::min(y, mapSize.height - visibleSize.height / 2);
    //Ŀ���
    Point destPos = Point(x, y);
    //��Ļ�е�
    Point centerPos = Point(visibleSize.width / 2, visibleSize.height / 2);
    //������Ļ�е㵽�ƶ���ľ���
    Point viewPos = centerPos - destPos;

    parent->setPosition(viewPos);
}

void Player::setTagPosition(int x, int y)
{
    /*--------�ж�ǰ���Ƿ񲻿�ͨ��---------*/
    /* ȡ����ǰ��������*/
    Size spriteSize = m_sprite->getContentSize();
    Point dstPos = Point(x + spriteSize.width / 2, y);
    /* ��õ�ǰ���������ڵ�ͼ�еĸ���λ��*/
    Point tiledPos = tileCoordForPosition(Point(dstPos.x, dstPos.y));

    /* ��ȡ��ͼ���Ե�Ψһ��ʶ */
    int tiledGid = meta->getTileGIDAt(tiledPos);
    /*��Ϊ0����������������*/
    if (tiledGid != 0) {
        Value properties = m_map->getPropertiesForGID(tiledGid);

        Value prop = properties.asValueMap().at("Collidable");

        if (prop.asString().compare("true") == 0) {
            return ;
        }
        if (prop.asString().compare("true") == 0 && isJumping == false) {
            isJumping = true;

            auto jumpBy = JumpBy::create(0.5f, Point(-100, 0), 80, 1);
            CallFunc* callfunc = CallFunc::create([&]() {
                /*�ָ�״̬*/
                isJumping = false;
                });
            auto actions = Sequence::create(jumpBy, callfunc, NULL);
            this->runAction(actions);
        }
    }
    Entity::setTagPosition(x, y);
    //������Ϊ�����ƶ���ͼ
    setViewPointByPlayer();
}

void Player::setTiledMap(TMXTiledMap* map)
{
    this->m_map = map;
    this->meta = m_map->getLayer("meta");
    this->meta -> setVisible(false);

}

Point Player::tileCoordForPosition(Point pos) {
    Size mapTiledNum = m_map->getMapSize();
    Size tiledSize = m_map->getTileSize();

    int x = pos.x / tiledSize.width; // cocos2d-x��Ĭ��Y�������������ϵģ�����Ҫ����һ���������

    int y = (1000 - pos.y) / tiledSize.height;

    if (x > 0) {
        x -= 1;
    }

    if (y > 0) {
        y -= 0;
    }

    return Point(x, y);
}

void Player::hit()
{
    if (getSprite() == NULL)
    {
        return;
    }
    ///*��ѪƮ����Ч*/
    //FlowWord* flowWord = FlowWord::create();
    m_iHP -= 50;
    if (m_iHP < 0)
    {
        m_iHP = 0;
    }
}
int Player::getiHP()
{
    return this->m_iHP;
}

int Player::getiGrade()
{
    return m_iGrade;
}
void Player::setiGrade(int grade)
{
    
    this->m_iGrade +=grade;
}

void Player::resetData()
{
   /* if (m_isJumping)
    {
        m_isJumping = false;
    }*/
    setPosition(Point(200, 140));
    setScale(1.0f);
    setRotation(0);
}
bool Player::isCollideWith(Entity* entity)
{
    ///*��ȡ��ײ�������boundingBox*/
    //Rect entityRect = entity->getBoundingBox();
    //Point playerPos = getPosition();
    ///*�ж�boundingBox��������ĵ��Ƿ��н���*/
    //return entityRect.containsPoint(playerPos);
    return getBoundingBox().intersectsRect(entity->getBoundingBox());
}


//std::vector<Bullet*> Player:: getBullet(int bullet_type)
//{ 
//    if (0 == bullet_type)
//    {
//       
//        auto numberBullet = m_numberBullets;
//        for (auto m_bullet : numberBullet)
//        {
//            bullets.push_back(m_bullet);
//        }
//    }
//    else if (1 == bullet_type)
//    {
//        auto powerBullet = m_powerBullets;
//        for (auto m_bullet : powerBullet)
//        {
//            bullets.push_back(m_bullet);
//        }
//    }
//    else if (2 == bullet_type)
//    {
//        auto speedBullet = m_speedBullets;
//        for (auto m_bullet : speedBullet)
//        {
//            bullets.push_back(m_bullet);
//        }
//    }
//    return bullets;
//}

//std::vector<Bullet*> Player::getBullet()
//{
//    std::vector<Bullet*> bullets;
//    if (m_numLongRange != 0)
//    {
//        int n = std::min(m_numLongRange, 5);
//        for (int i = 0; i < n; i++)
//        {
//            auto longRange = m_longRanges[i];
//            if (longRange == NULL)
//                continue;
//            for (auto bullet : longRange->getBullet())
//            {
//                bullets.push_back(bullet);
//            }
//        }
//    }
//    return bullets;
//}
