#ifndef __PAUSE_SCENE_H__
#define __PAUSE_SCENE_3_H__

#include "cocos2d.h"

class PauseMenu3 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(PauseMenu3);

    void Resume(Ref* pSender);
    void GoToMainMenuScene(Ref* pSender);
    void Retry(Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__

