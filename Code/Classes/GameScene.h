//
//  GameScene.h
//  NewGame
//
//  Created by 胡可 on 15/9/8.
//
//

#ifndef __NewGame__GameScene__
#define __NewGame__GameScene__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class GameScene
:public Scene
{
private:
    GameScene();
    ~GameScene();
public:
    CREATE_FUNC(GameScene);
    virtual bool init();
};

#endif /* defined(__NewGame__GameScene__) */
