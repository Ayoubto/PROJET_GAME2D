#include "PauseScene2.h"
#include "GameScene2.h"
#include "MainMenuScene.h"



USING_NS_CC;

Scene* PauseMenu2::createScene()
{
    auto scene = Scene::create();
    auto layer = PauseMenu2::create();
    scene->addChild(layer);
    return scene;

}


bool PauseMenu2::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();




    auto resumeItem =
        MenuItemImage::create("Retry.png",
            "Retry.png",
            CC_CALLBACK_1(PauseMenu2::Resume, this));
    auto retryItem =
        MenuItemImage::create("Retry.png",
            "Retry.png",
            CC_CALLBACK_1(PauseMenu2::Retry, this));
    auto mainMenuItem =
        MenuItemImage::create("Menu.png",
            "Menu.png",
            CC_CALLBACK_1(PauseMenu2::GoToMainMenuScene, this));
    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,
        NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);
    return true;
}

void PauseMenu2::Resume(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}
void PauseMenu2::GoToMainMenuScene(cocos2d::Ref* pSender)
{
    auto scene = MainMenu::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}
void PauseMenu2::Retry(cocos2d::Ref* pSender)
{
    auto scene = GameScreen2::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}