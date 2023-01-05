#include "MainMenuScene.h"
#include "GameScene.h"
#include "GameScene2.h"
#include "GameScene3.h"
USING_NS_CC;

Scene* MainMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenu::create();
    scene->addChild(layer);
    return scene;
   
}


bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto menuTitle =
        MenuItemImage::create("logo.jpg",
            "logo.jpg");
    auto playItem =
        MenuItemImage::create("play.png",
            "play.png",
            CC_CALLBACK_1(MainMenu::GoToGameScene, this));
    auto menu = Menu::create(menuTitle, playItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);
    return true;
}

void MainMenu::GoToGameScene(Ref* pSender)
{
    auto scene = GameScreen3::createScene();

    Director::getInstance()->replaceScene(scene);
    
}