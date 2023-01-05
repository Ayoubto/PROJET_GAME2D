#include "PauseScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"



USING_NS_CC;

Scene* PauseMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = PauseMenu::create();
    scene->addChild(layer);
    return scene;

}


bool PauseMenu::init()
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
            CC_CALLBACK_1(PauseMenu::Resume, this));
    auto retryItem =
        MenuItemImage::create("Retry.png",
            "Retry.png",
            CC_CALLBACK_1(PauseMenu::Retry, this));
    auto mainMenuItem =
        MenuItemImage::create("Menu.png",
            "Menu.png",
            CC_CALLBACK_1(PauseMenu::GoToMainMenuScene, this));
    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,
        NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);
    return true;
}

void PauseMenu::Resume(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}
void PauseMenu::GoToMainMenuScene(cocos2d::Ref* pSender)
{
    auto scene = MainMenu::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}
void PauseMenu::Retry(cocos2d::Ref* pSender)
{
    auto scene = GameScreen::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}