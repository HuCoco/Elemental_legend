//
//  TrailGameScene.hpp
//  NewGame
//
//  Created by 胡可 on 15/11/18.
//
//

#ifndef TrailGameScene_h
#define TrailGameScene_h

#include "cocos2d.h"

class TrailGameScene
:public cocos2d::Scene
{
private:
    TrailGameScene();
    ~TrailGameScene();
    virtual bool init();
public:
    CREATE_FUNC(TrailGameScene);
};
#endif /* TrailGameScene_hpp */
