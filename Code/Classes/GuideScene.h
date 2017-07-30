//
//  GuideScene.h
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#ifndef GuideScene_h
#define GuideScene_h

#include <stdio.h>
#include "cocos2d.h"

class GuideScene
:public cocos2d::Scene
{
private:
    GuideScene();
    ~GuideScene();
    virtual bool init();
public:
    CREATE_FUNC(GuideScene);
};

#endif /* GuideScene_h */
