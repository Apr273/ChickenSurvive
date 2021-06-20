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

    //����Tiled��ͼ����ӵ�������
    TMXTiledMap* map = TMXTiledMap::create("Map/map1.tmx");
    auto layer = map->getLayer("background");
    this->addChild(map);
    addPlayer(map);
 
    //����ڱ�
    Director::getInstance()->setProjection(Director::Projection::_2D);

    return true;
}

/*�ڵ�ͼ��������*/
void MyScene::addPlayer(TMXTiledMap* map)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //��������
    Sprite* playerSprite = Sprite::create("monsterD1.png");
    //������󶨵���Ҷ�����
    Player* myPlayer = Player::create();
    myPlayer->bindSprite(playerSprite);
    //myPlayer->run();
    myPlayer->setTiledMap(map);

    //���ض����

    //�����������

    //�����������
    myPlayer->setPosition(Point(100, visibleSize.height / 2));
    //�������ӵ���ͼ��
    map->addChild(myPlayer);

    //������ҿ�����
    DirectionController* moveControll = DirectionController::create();
    moveControll->setXSpeed(0);
    moveControll->setYSpeed(0);
    moveControll->setPlayer(myPlayer);
    //��������ӵ�������
    this->addChild(moveControll);
    //���ÿ���������������
    myPlayer->setController(moveControll);
    
}