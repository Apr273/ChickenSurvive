#include "MyScene.h"

USING_NS_CC;

Scene* MyScene::createScene()
{
    auto scene = Scene::create();
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
    TMXTiledMap* map = TMXTiledMap::create("Map/map1.tmx");
    auto layer = map->getLayer("background");
    this->addChild(map);
    addPlayer(map);
 
    //避免黑边
    Director::getInstance()->setProjection(Director::Projection::_2D);

    return true;
}

/*在地图上添加玩家*/
void MyScene::addPlayer(TMXTiledMap* map)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //创建精灵
    Sprite* playerSprite = Sprite::create("monsterD1.png");
    //将精灵绑定到玩家对象上
    Player* myPlayer = Player::create();
    myPlayer->bindSprite(playerSprite);
    //myPlayer->run();
    myPlayer->setTiledMap(map);

    //加载对象层

    //加载玩家坐标

    //设置玩家坐标
    myPlayer->setPosition(Point(100, visibleSize.height / 2));
    //将玩家添加到地图上
    map->addChild(myPlayer);

    //创建玩家控制器
    DirectionController* moveControll = DirectionController::create();
    moveControll->setXSpeed(0);
    moveControll->setYSpeed(0);
    moveControll->setPlayer(myPlayer);
    //控制器添加到场景中
    this->addChild(moveControll);
    //设置控制器到主角身上
    myPlayer->setController(moveControll);
    
}