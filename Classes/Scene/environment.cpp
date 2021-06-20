#include "Scene/environment.h"
#include <time.h>

USING_NS_CC;

Scene* environment::createScene()
{
    return environment::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool environment::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    /*int begin, int digit;
    clock_t end, TIME;
    end = clock();
    TIME = end - begin;

    auto label = Label::createWithTTF(TIME, "fonts/Marker Felt.ttf", 24);*/


    auto Time = Sprite::create("Item//Time.png");
    if (Time == nullptr)
    {
        problemLoading("'Item//Time.png'");
    }
    else
    {
        Time->setPosition(Vec2(220, 670));  //显示位置
        this->addChild(Time, 1);
    }

    auto survive = Sprite::create("Item//survive.png");
    if (survive == nullptr)
    {
        problemLoading("'Item//survive.png'");
    }
    else
    {
        survive->setPosition(Vec2(visibleSize.width - 220, 670));  //显示位置
        this->addChild(survive, 1);
    }

    auto equipment = Sprite::create("Item//equipment.png");
    if (equipment == nullptr)
    {
        problemLoading("'Item//equipment.png'");
    }
    else
    {
        equipment->setPosition(Vec2(245, 165));  //显示位置
        this->addChild(equipment, 1);
    }

    auto blood = Sprite::create("Item//blood.png");
    if (blood == nullptr)
    {
        problemLoading("'Item//main_interface.png'");
    }
    else
    {
        blood->setPosition(Vec2(visibleSize.width / 2 + origin.x, 130));  //显示位置
        this->addChild(blood, 1);
    }

    auto closeItem = MenuItemImage::create(
        "Item//CloseNormal.png",
        "Item//CloseSelected.png",             //两个图片
        CC_CALLBACK_1(environment::menuCloseCallback, this));
    closeItem->setPosition(Vec2(visibleSize.width - 200, 130));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto main = Sprite::create("Item//main_interface.png");
    if (main == nullptr)
    {
        problemLoading("'Item//main_interface.png'");
    }
    else
    {
        main->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));  //显示位置
        this->addChild(main, 0);
    }

    return true;
}

void environment::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
