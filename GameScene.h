
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "physics/CCPhysicsWorld.h"
#include "physics-nodes/CCPhysicsSprite.h"
#include "physics/CCPhysicsContact.h"
#include "Box2D/Box2D.h"
#include "Box2D/Dynamics/b2WorldCallbacks.h"
USING_NS_CC;
using namespace cocos2d;
class GameScreen : public cocos2d::Layer
{
public:
 cocos2d::Sprite* floor;
    static cocos2d::Scene* createScene();
    cocos2d::Sprite *player;

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScreen);
    cocos2d::Sprite* backgroundSpriteArray;

    void GoToPauseScene(Ref* pSender);
    void GoToGameOverScene(Ref* pSender);


    
    void reload1(Ref* pSender); 

    bool onContactBegin(cocos2d::PhysicsContact& contact);
    bool winonContactBegin(cocos2d::PhysicsContact& contact);

};

#endif // __HELLOWORLD_SCENE_H__

