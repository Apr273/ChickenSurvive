#include "Player.h"

Player::Player()
{
    auto sprite = Sprite::create("PlayerD1.png");
    bindSprite(sprite);
    
}
bool Player::init()
{
    m_isjumping = false;

    m_iHP = 1000;
    return true;
}
void Player::run(char m_Direction)
{
    auto* m_frameCache = SpriteFrameCache::getInstance();
    m_frameCache->addSpriteFramesWithFile("Player.plist", "Player.png");
    SpriteFrame* frame = NULL;
    Vector<SpriteFrame*>frameArray;//创建序列

    if (m_Direction != 'T')
    {
        //创建精灵帧对象，循环播放
        for (int i = 1; i < 4; ++i)
        {
            auto* frame = m_frameCache->getSpriteFrameByName(StringUtils::format("Player%c%d.png", m_Direction, i));
            frameArray.pushBack(frame);//将帧加入序列中
        }
        //创建动画对象
        Animation* animation = Animation::createWithSpriteFrames(frameArray);
        //动画执行次数，-1为无限执行
        animation->setLoops(-1);
        //每一帧切换频率
        animation->setDelayPerUnit(0.3f);
        //创建动画动作
        auto* action = Animate::create(animation);
        //精灵执行动作
        m_sprite->runAction(action);
    }
    else if (m_Direction == 'T')
    {
        m_sprite->stopAllActions();
    }

}

//判断是否需要移动地图
void Player::setViewPointByPlayer()
{
    if (m_sprite == NULL)
    {
        return;
    }
    Layer* parent = (Layer*)getParent();

    //地图方块数量
    Size mapTiledNum = m_map->getMapSize();
    //地图单个格子大小
    Size tiledSize = m_map->getTileSize();
    //地图大小
    Size mapSize = Size(
        mapTiledNum.width * tiledSize.width,
        mapTiledNum.height * tiledSize.height);
    //屏幕大小
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //主角坐标
    Point spritePos = getPosition();
    //判断取屏幕中点坐标或主角坐标
    float x = std::max(spritePos.x, visibleSize.width / 2);
    float y = std::max(spritePos.y, visibleSize.height / 2);
    //判断取极限值坐标
    x = std::min(x, mapSize.width - visibleSize.width / 2);
    y = std::min(y, mapSize.height - visibleSize.height / 2);
    //目标点
    Point destPos = Point(x, y);
    //屏幕中点
    Point centerPos = Point(visibleSize.width / 2, visibleSize.height / 2);
    //计算屏幕中点到移动点的距离
    Point viewPos = centerPos - destPos;

    parent->setPosition(viewPos);
}

void Player::setTagPosition(int x, int y)
{
    /*--------判断前面是否不可通过---------*/
    /* 取主角前方的坐标*/
    Size spriteSize = m_sprite->getContentSize();
    Point dstPos = Point(x + spriteSize.width / 2, y);
    /* 获得当前主角坐标在地图中的各自位置*/
    Point tiledPos = tileCoordForPosition(Point(dstPos.x, dstPos.y));

    /* 获取地图各自的唯一标识 */
    int tiledGid = meta->getTileGIDAt(tiledPos);
    /*不为0，代表存在这个格子*/
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
                /*恢复状态*/
                isJumping = false;
                });
            auto actions = Sequence::create(jumpBy, callfunc, NULL);
            this->runAction(actions);
        }
    }
    Entity::setTagPosition(x, y);
    //以主角为中心移动地图
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

    int x = pos.x / tiledSize.width; // cocos2d-x的默认Y坐标是由下至上的，所以要做了一个相减操作

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
    log("hit()");
    if (getSprite() == NULL)
    {
        return;
    }

    ///*扣血飘字特效*/
    //FlowWord* flowWord = FlowWord::create();
    m_iHP -= 15;
    if (m_iHP < 0)
    {
        m_iHP = 0;
    }

    ///*创建几种动作对象*/
    //auto backMove = MoveBy::create(0.1f, Point(-20, 0));
    //auto forwardMove = MoveBy::create(0.1f, Point(20, 0));
    //auto backRotate = RotateBy::create(0.1f, -5, 0);
    //auto forwardRotate = RotateBy::create(0.1f, 5, 0);

    ///*分别组合成两种动作*/
    //auto backActions = Spawn::create(backMove, backRotate, NULL);
    //auto forwardActions = Spawn::create(forwardMove, forwardRotate, NULL);

    //auto actions = Sequence::create(backActions, forwardActions, NULL);

    //stopAllActions();/*先停止所有正在执行的动作*/
    //resetData();/*重置数据*/
    //runAction(actions);
}
int Player::getiHP()
{
    return this->m_iHP;
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
    ///*获取碰撞检查对象的boundingBox*/
    //Rect entityRect = entity->getBoundingBox();
    //Point playerPos = getPosition();
    ///*判断boundingBox和玩家中心点是否有交集*/
    //return entityRect.containsPoint(playerPos);
    return getBoundingBox().intersectsRect(entity->getBoundingBox());
}

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
