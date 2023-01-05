#include "PauseScene3.h"
#include "GameScene3.h"
#include "MainMenuScene.h"



USING_NS_CC;

Scene* PauseMenu3::createScene()
{
    auto scene = Scene::create();
    auto layer = PauseMenu3::create();
    scene->addChild(layer);
    return scene;

}


bool PauseMenu3::init()
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
            CC_CALLBACK_1(PauseMenu3::Resume, this));
    auto retryItem =
        MenuItemImage::create("Retry.png",
            "Retry.png",
            CC_CALLBACK_1(PauseMenu3::Retry, this));
    auto mainMenuItem =
        MenuItemImage::create("Menu.png",
            "Menu.png",
            CC_CALLBACK_1(PauseMenu3::GoToMainMenuScene, this));
    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,
        NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);
    return true;
}

void PauseMenu3::Resume(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}
void PauseMenu3::GoToMainMenuScene(cocos2d::Ref* pSender)
{
    auto scene = MainMenu::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}
void PauseMenu3::Retry(cocos2d::Ref* pSender)
{
    auto scene = GameScreen3::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}