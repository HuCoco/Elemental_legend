//
//  TrialScene.h
//  NewGame
//
//  Created by 胡可 on 15/11/18.
//
//

#ifndef TrialScene_h
#define TrialScene_h

#include "cocos2d.h"

class TrialScene
:public cocos2d::Scene
{
private:
    TrialScene();
    ~TrialScene();
    virtual bool init();
public:
    CREATE_FUNC(TrialScene);
};



#endif /* TrialScene_h */
