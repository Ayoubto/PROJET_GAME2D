#include "GameScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"
#include "MainMenuScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsJoint.h"
#include "AudioEngine.h"
#include "GameScene2.h"






USING_NS_CC;

Scene* GameScreen::createScene()
{
    auto scene = Scene::createWithPhysics();
    PhysicsWorld* world = scene->getPhysicsWorld();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -500));
    scene->getPhysicsWorld()->setDebugDrawMask(0);
    


    auto layer = GameScreen::create();
    scene->addChild(layer);
    return scene;

}


bool GameScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }


    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //pause button
    auto pauseItem =
        MenuItemImage::create("Pause_Button.png",
            "Pause_Button.png",
            CC_CALLBACK_1(GameScreen::GoToPauseScene, this));
    pauseItem->setPosition(Point(pauseItem->getContentSize().width -
        (pauseItem->getContentSize().width / 4) + origin.x,
        visibleSize.height - pauseItem->getContentSize().height +
        (pauseItem->getContentSize().width / 4) + origin.y));
    auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);


    //background


    auto backgroundSprite = Sprite::create
    ("back2.png");
    backgroundSprite->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(backgroundSprite, -1);

    //add floor
    auto *floor = Sprite::create("floor2.png");
    floor->setAnchorPoint(Vec2(0, 0));
    floor->setPosition(Vec2(1, 0));
    floor->setScale(0.425);
    this->addChild(floor, 1);
    //add floor2
    auto* floor2 = Sprite::create("floor2.png");
    floor2->setAnchorPoint(Vec2(0, 0));
    floor2->setPosition(Vec2(280, 0));
    floor2->setScale(0.425);
    this->addChild(floor2, 1);

    //add floor3
    auto* floor3 = Sprite::create("floor2.png");
    floor3->setAnchorPoint(Vec2(0, 0));
    floor3->setPosition(Vec2(210, 0));
    floor3->setScale(0.090);
    floor3->setTag(10);
    this->addChild(floor3, 3);


    //add floor4
    auto* floor4 = Sprite::create("9.png");
    floor4->setAnchorPoint(Vec2(0, 0));
    floor4->setPosition(Vec2(250, 12));
    floor4->setScale(0.390);
   
    this->addChild(floor4, 1);
    

        //add win
     auto* floor5 = Sprite::create("trones.png");
    floor5->setAnchorPoint(Vec2(0, 0));
    floor5->setPosition(Vec2(380, 100));
    floor5->setTag(11);
    floor5->setScale(0.950);

    this->addChild(floor5, 1);
    //add player
    auto player = Sprite::create("play1.png");
    player->setAnchorPoint(Vec2(0.5, 0.5));
    player->setPosition(Vec2(40, 180));
    player->setScale(0.2); //scale dyal player
    player->setName("player");
   
    player->setTag(10);
    this->addChild(player, 2);
    //physique player
    auto physicsBody1 = PhysicsBody::createBox(Size(140.0f, 135.0f), PhysicsMaterial(5000.0f, 0.5f, 0.5f));
    physicsBody1->setDynamic(true);
    physicsBody1->setContactTestBitmask(1);
    physicsBody1->setRotationEnable(false);
    physicsBody1->setCollisionBitmask(1);
    player->setPhysicsBody(physicsBody1);
    Vec2 force = Vec2(0, -physicsBody1->getMass() * 1.8f);
    physicsBody1->applyForce(force);
    //physique floor 1
    auto physicsBody_floor = PhysicsBody::createBox(Size(500.0f, 60.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor->setDynamic(false);
    physicsBody_floor->setCollisionBitmask(1);
    physicsBody_floor->setCategoryBitmask(1);
    floor->setPhysicsBody(physicsBody_floor);



    //physique floor 2
    auto physicsBody_floor2 = PhysicsBody::createBox(Size(500.0f, 60.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor2->setDynamic(false);
    physicsBody_floor2->setCollisionBitmask(1);
    physicsBody_floor2->setCategoryBitmask(1);
    floor2->setPhysicsBody(physicsBody_floor2);
    //physique floor 3
    auto physicsBody_floor3 = PhysicsBody::createBox(floor3->getContentSize(), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor3->setDynamic(false);
    physicsBody_floor3->setCollisionBitmask(3);
    physicsBody_floor3->setCategoryBitmask(1);
    physicsBody_floor3->setContactTestBitmask(1);
    floor3->setPhysicsBody(physicsBody_floor3);

    //physique floor 4
    auto physicsBody_floor4 = PhysicsBody::createBox(Size(100.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor4->setDynamic(false);
    physicsBody_floor4->setCollisionBitmask(1);
    physicsBody_floor4->setCategoryBitmask(1);
    floor4->setPhysicsBody(physicsBody_floor4);
    



    //physique floor 5  win
    auto physicsBody_floor5 = PhysicsBody::createBox(Size(20.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor5->setDynamic(false);
    physicsBody_floor5->setCollisionBitmask(1);
    physicsBody_floor5->setCategoryBitmask(1);
    floor5->setPhysicsBody(physicsBody_floor5);
    physicsBody_floor5->setContactTestBitmask(1);

    //new 







    // Create a keyboard event listener
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScreen::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScreen::onKeyPressed, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    keyboardListener->onKeyPressed = [player](EventKeyboard::KeyCode KeyCode, Event* event)
    {

        if (KeyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
            auto action1 = JumpBy::create(0.57f, Vec2(50, 100), 15.0f, 1);
            auto easeAction = EaseOut::create(action1, 2.0f);
            player->runAction(action1);

        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 20.0f, 1);
            MoveBy* moveAction = MoveBy::create(1.2, Vec2(70, 0));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player->runAction(repeatAction);

        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
            auto jump = JumpBy::create(0.5f, Vec2(50, 50), 50.0f, 1);
            MoveBy* moveAction = MoveBy::create(1.2, Vec2(-70, 0));
            RepeatForever* repeatAction = RepeatForever::create(moveAction);
            player->runAction(repeatAction);

        }

    };


    keyboardListener->onKeyReleased = [player](EventKeyboard::KeyCode KeyCode, Event* event)
    {
        if (KeyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
            player->stopAllActions();
        }
        if (KeyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
            player->stopAllActions();
        }

    };



    ////////////////////////////// contact Event


    auto contactListener =
        EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [](PhysicsContact& contact)
    {
        auto shapeA = contact.getShapeA();
        auto bodyA = shapeA->getBody();
        auto shapeB = contact.getShapeB();
        auto bodyB = shapeB->getBody();

        auto nodeA = contact.getShapeA()->getBody()->getNode();
        auto nodeB = contact.getShapeB()->getBody()->getNode();

        if (nodeA->getTag() == 10 && nodeB->getTag() == 10)
        {


            Director::getInstance()->replaceScene(GameOver::createScene());


        }
        else {
            Director::getInstance()->replaceScene(GameScreen2::createScene());
        }
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);


    //win
  

   






        return true; 

}




bool GameScreen::onContactBegin(cocos2d::PhysicsContact& contact) {



    return true;
}
void GameScreen::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene = PauseMenu::createScene();

    Director::getInstance()->pushScene(scene);
}
void GameScreen::GoToGameOverScene(cocos2d::Ref* pSender)
{
    auto scene = GameOver::createScene();

    Director::getInstance()->replaceScene(scene);
}


