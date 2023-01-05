#include "MainMenuScene.h"
#include "GameScene3.h"
#include "GameScene.h"
#include "PauseScene3.h"
#include "GameOverScene.h"
#include "MainMenuScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsJoint.h"
#include "AudioEngine.h"

USING_NS_CC;
Scene* GameScreen3::createScene()

{
    auto scene = Scene::createWithPhysics();
    PhysicsWorld* world = scene->getPhysicsWorld();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -500));
    scene->getPhysicsWorld()->setDebugDrawMask(1);


    auto layer = GameScreen3::create();
    scene->addChild(layer);
    return scene;

}


bool GameScreen3::init()
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
            CC_CALLBACK_1(GameScreen3::GoToPauseScene, this));
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



    //add player 
        //add player
    auto player = Sprite::create("play1.png");
    player->setAnchorPoint(Vec2(0.5, 0.5));
    player->setPosition(Vec2(40, 180));
    player->setScale(0.2); //scale dyal player
    player->setName("player");
    player->setTag(10);
    this->addChild(player, 2);

    //Physique player
    auto physicsBody1 = PhysicsBody::createBox(Size(140.0f, 135.0f), PhysicsMaterial(5000.0f, 0.5f, 0.5f));
    physicsBody1->setDynamic(true);
    physicsBody1->setContactTestBitmask(1);
    physicsBody1->setRotationEnable(false);
    physicsBody1->setCollisionBitmask(1);
    player->setPhysicsBody(physicsBody1);
    Vec2 force = Vec2(0, -physicsBody1->getMass() * 1.8f);
    physicsBody1->applyForce(force);

    //add floor
    auto* floor = Sprite::create("floor2.png");
    floor->setAnchorPoint(Vec2(0, 0));
    floor->setPosition(Vec2(1, 0));
    floor->setScale(0.425);
    this->addChild(floor, 1);

    auto physicsBody_floor = PhysicsBody::createBox(Size(500.0f, 60.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor->setDynamic(false);
    physicsBody_floor->setCollisionBitmask(1);
    physicsBody_floor->setCategoryBitmask(1);
    floor->setPhysicsBody(physicsBody_floor);

    //add floor1 obstacl1 1
    auto* floor1 = Sprite::create("9.png");
    floor1->setAnchorPoint(Vec2(0, 0));
    floor1->setPosition(Vec2(215, 10));
    floor1->setScale(0.390);
    this->addChild(floor1, 1);

    auto physicsBody_floor1 = PhysicsBody::createBox(Size(100.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor1->setDynamic(false);
    physicsBody_floor1->setCollisionBitmask(1);
    physicsBody_floor1->setCategoryBitmask(1);
    floor1->setPhysicsBody(physicsBody_floor1);
    


    //add floor2 obstacl1 2
    auto* floor2 = Sprite::create("9.png");
    floor2->setAnchorPoint(Vec2(0, 0));
    floor2->setPosition(Vec2(340, 10));
    floor2->setScale(0.390);
    this->addChild(floor2, 1);

    auto physicsBody_floor2 = PhysicsBody::createBox(Size(100.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor2->setDynamic(false);
    physicsBody_floor2->setCollisionBitmask(1);
    physicsBody_floor2->setCategoryBitmask(1);
    floor2->setPhysicsBody(physicsBody_floor2);
   



    //add floor3 obstacl1 3
    auto* floor3 = Sprite::create("9.png");
    floor3->setAnchorPoint(Vec2(0, 0));
    floor3->setPosition(Vec2(440, 40));
    floor3->setScale(0.390);
    this->addChild(floor3, 1);

    auto physicsBody_floor3 = PhysicsBody::createBox(Size(100.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor3->setDynamic(false);
    physicsBody_floor3->setCollisionBitmask(1);
    physicsBody_floor3->setCategoryBitmask(1);
    floor3->setPhysicsBody(physicsBody_floor3);
  


    //add floor4 obstacl1 4
    auto* floor4 = Sprite::create("9.png");
    floor4->setAnchorPoint(Vec2(0, 0));
    floor4->setPosition(Vec2(540, 60));
    floor4->setScale(0.390);
    this->addChild(floor4, 1);

    auto physicsBody_floor4 = PhysicsBody::createBox(Size(100.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor4->setDynamic(false);
    physicsBody_floor4->setCollisionBitmask(1);
    physicsBody_floor4->setCategoryBitmask(1);
    floor4->setPhysicsBody(physicsBody_floor4);
   


    //add floor5 obstacl1 5
    auto* floor5 = Sprite::create("9.png");
    floor5->setAnchorPoint(Vec2(0, 0));
    floor5->setPosition(Vec2(640, 40));
    floor5->setScale(0.390);
    this->addChild(floor5, 1);

    auto physicsBody_floor5 = PhysicsBody::createBox(Size(100.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor5->setDynamic(false);
    physicsBody_floor5->setCollisionBitmask(1);
    physicsBody_floor5->setCategoryBitmask(1);
    floor5->setPhysicsBody(physicsBody_floor5);
    



    //add floor6 floor
    auto* floor6= Sprite::create("floor2.png");
    floor6->setAnchorPoint(Vec2(0, 0));
    floor6->setPosition(Vec2(760, 0));
    floor6->setScale(0.425);
    this->addChild(floor6, 1);

    auto physicsBody_floor6 = PhysicsBody::createBox(Size(500.0f, 60.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor6->setDynamic(false);
    physicsBody_floor6->setCollisionBitmask(1);
    physicsBody_floor6->setCategoryBitmask(1);
    floor6->setPhysicsBody(physicsBody_floor6);


    //add floor7 floor
    auto* floor7 = Sprite::create("floor2.png");
    floor7->setAnchorPoint(Vec2(0, 0));
    floor7->setPosition(Vec2(960, 0));
    floor7->setScale(0.425);
    this->addChild(floor7, 1);

    auto physicsBody_floor7 = PhysicsBody::createBox(Size(500.0f, 60.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor7->setDynamic(false);
    physicsBody_floor7->setCollisionBitmask(1);
    physicsBody_floor7->setCategoryBitmask(1);
    floor7->setPhysicsBody(physicsBody_floor7);


    //floor 8 chook
    auto* floor8 = Sprite::create("chok.png");
    floor8->setAnchorPoint(Vec2(0, 0));
    floor8->setPosition(Vec2(810, 10));
    floor8->setScale(1.390);
    floor8->setTag(10);
    this->addChild(floor8, 3);

    auto physicsBody_floor8 = PhysicsBody::createBox(Size(100.0f, 20.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor8->setDynamic(false);
    physicsBody_floor8->setCollisionBitmask(1);
    physicsBody_floor8->setContactTestBitmask(1);
    physicsBody_floor8->setCategoryBitmask(1);
    
    floor8->setPhysicsBody(physicsBody_floor8);


    //add floor9 obstacl1 9
    auto* floor9 = Sprite::create("9.png");
    floor9->setAnchorPoint(Vec2(0, 0));
    floor9->setPosition(Vec2(780, 36));
    floor9->setScale(0.390);
    this->addChild(floor9, 1);

    auto physicsBody_floor9 = PhysicsBody::createBox(Size(100.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor9->setDynamic(false);
    physicsBody_floor9->setCollisionBitmask(1);
    physicsBody_floor9->setCategoryBitmask(1);
    floor9->setPhysicsBody(physicsBody_floor9);


    //add floor10 obstacl1 10
    auto* floor10 = Sprite::create("9.png");
    floor10->setAnchorPoint(Vec2(0, 0));
    floor10->setPosition(Vec2(890, 40));
    floor10->setScale(0.390);
    this->addChild(floor10, 1);

    auto physicsBody_floor10 = PhysicsBody::createBox(Size(100.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor10->setDynamic(false);
    physicsBody_floor10->setCollisionBitmask(1);
    physicsBody_floor10->setCategoryBitmask(1);
    floor10->setPhysicsBody(physicsBody_floor10);


    //add floor10 obstacl1 11
    auto* floor11 = Sprite::create("9.png");
    floor11->setAnchorPoint(Vec2(0, 0));
    floor11->setPosition(Vec2(1131, 30));
    floor11->setScale(0.390);
    this->addChild(floor11, 1);

    auto physicsBody_floor11 = PhysicsBody::createBox(Size(100.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor11->setDynamic(false);
    physicsBody_floor11->setCollisionBitmask(1);
    physicsBody_floor11->setCategoryBitmask(1);
    floor11->setPhysicsBody(physicsBody_floor11);

    //add floor12 obstacl1 12
    auto* floor12 = Sprite::create("9.png");
    floor12->setAnchorPoint(Vec2(0, 0));
    floor12->setPosition(Vec2(1231, 40));
    floor12->setScale(0.390);
    this->addChild(floor12, 1);

    auto physicsBody_floor12 = PhysicsBody::createBox(Size(100.0f, 140.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor12->setDynamic(false);
    physicsBody_floor12->setCollisionBitmask(1);
    physicsBody_floor12->setCategoryBitmask(1);
    floor12->setPhysicsBody(physicsBody_floor12);
    //add floor13 floor
    auto* floor13 = Sprite::create("floor2.png");
    floor13->setAnchorPoint(Vec2(0, 0));
    floor13->setPosition(Vec2(1360, 50));
    floor13->setScale(0.425);
    this->addChild(floor13, 1);

    auto physicsBody_floor13 = PhysicsBody::createBox(Size(500.0f, 60.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor13->setDynamic(false);
    physicsBody_floor13->setCollisionBitmask(1);
    physicsBody_floor13->setCategoryBitmask(1);
    floor13->setPhysicsBody(physicsBody_floor13);

    //add floor14 floor
    auto* floor14 = Sprite::create("floor2.png");
    floor14->setAnchorPoint(Vec2(0, 0));
    floor14->setPosition(Vec2(1480, 50));
    floor14->setScale(0.425);
    this->addChild(floor14, 1);

    auto physicsBody_floor14 = PhysicsBody::createBox(Size(500.0f, 60.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor14->setDynamic(false);
    physicsBody_floor14->setCollisionBitmask(1);
    physicsBody_floor14->setCategoryBitmask(1);
    floor14->setPhysicsBody(physicsBody_floor14);


    //add floor  14 n   
    auto* floor15 = Sprite::create("floorScreen2.png");
    floor15->setAnchorPoint(Vec2(0, 0));
    floor15->setPosition(Vec2(1.0, -70));
    floor15->setScale(1.0985);
    floor15->setTag(10);
    this->addChild(floor15, 1);

    //physique floor 
    auto physicsBody_floor15 = PhysicsBody::createBox(Size(1905.0f, 20.0f), PhysicsMaterial(1000.0f, 0.1f, 0.009f));
    physicsBody_floor15->setDynamic(false);
    physicsBody_floor15->setCollisionBitmask(1);
    physicsBody_floor15->setContactTestBitmask(1);
    physicsBody_floor15->setCategoryBitmask(1);
    floor15->setPhysicsBody(physicsBody_floor15);


    //add win
    auto* floor16 = Sprite::create("trones.png");
    floor16->setAnchorPoint(Vec2(0, 0));
    floor16->setPosition(Vec2(1550, 130));
    floor16->setTag(11);
    floor16->setScale(0.950);

    auto physicsBody_floor16 = PhysicsBody::createBox(Size(20.0f, 160.0f), PhysicsMaterial(100.0f, 0.1f, 0.009f));

    physicsBody_floor16->setDynamic(false);
    physicsBody_floor16->setCollisionBitmask(1);
    physicsBody_floor16->setCategoryBitmask(1);
    physicsBody_floor16->setContactTestBitmask(1);
    floor16->setPhysicsBody(physicsBody_floor16);
    this->addChild(floor16, 3);






    //scroll
    auto* acc = MoveBy::create(0.07 * visibleSize.width, Point(-visibleSize.width * 4, 0));
    floor->runAction(acc->clone());
    floor1->runAction(acc->clone());
    floor2->runAction(acc->clone());
    floor3->runAction(acc->clone());
    floor4->runAction(acc->clone());
    floor5->runAction(acc->clone());
    floor6->runAction(acc->clone());
    floor7->runAction(acc->clone());
    floor8->runAction(acc->clone());
    floor9->runAction(acc->clone());
    floor10->runAction(acc->clone());
    floor11->runAction(acc->clone());
    floor12->runAction(acc->clone());
    floor13->runAction(acc->clone());
    floor14->runAction(acc->clone());
    floor16->runAction(acc->clone());





    // Create a keyboard event listener
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScreen3::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScreen3::onKeyPressed, this);

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




    //Event Listener 

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
            Director::getInstance()->replaceScene(GameScreen::createScene());
        }
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    
    return true;

}

void GameScreen3::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene = PauseMenu3::createScene();

    Director::getInstance()->pushScene(scene);
}
void GameScreen3::GoToGameOverScene(cocos2d::Ref* pSender)
{
    auto scene = GameOver::createScene();

    Director::getInstance()->replaceScene(scene);
}

