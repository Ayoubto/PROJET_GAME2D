#ifndef __GAME_SCENE_3_H__
#define __GAME_SCENE_3_H__

#include "cocos2d.h"

class GameScreen3 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScreen3);



    void GoToPauseScene(Ref* pSender);
    void GoToGameOverScene(Ref* pSender);

};

#endif // __HELLOWORLD_SCENE_H__


