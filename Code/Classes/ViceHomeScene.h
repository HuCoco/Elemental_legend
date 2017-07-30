//
//  ViceHomeScene.h
//  NewGame
//
//  Created by 胡可 on 15/10/27.
//
//

#ifndef ViceHomeScene_h
#define ViceHomeScene_h

#include <stdio.h>
#include "cocos2d.h"

class ViceHomeScene
:public cocos2d::Scene
{
private:
    ViceHomeScene();
    ~ViceHomeScene();
    virtual bool init();
public:
    CREATE_FUNC(ViceHomeScene);
};

#endif /* ViceHomeScene_h */
