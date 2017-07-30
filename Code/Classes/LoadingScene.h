//
//  LoadingScene.h
//  NewGame
//
//  Created by 胡可 on 15/11/8.
//
//

#ifndef LoadingScene_h
#define LoadingScene_h

#include <stdio.h>
#include "cocos2d.h"

class LoadingScene
:public cocos2d::Scene
{
private:
    LoadingScene();
    ~LoadingScene();
    virtual bool init();
public:
    CREATE_FUNC(LoadingScene);
};

#endif /* LoadingScene_h */
