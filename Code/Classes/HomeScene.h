//
//  HomeScene.h
//  NewGame
//
//  Created by 胡可 on 15/10/10.
//
//

#ifndef HomeScene_h
#define HomeScene_h

#include <stdio.h>
#include "cocos2d.h"
#include "TopStateBar.h"
#include "BottomStateBar.h"
#include "MapBar.h"
#include "ChapterBar.h"
#include "PlayStateBar.h"
class HomeScene
:public cocos2d::Scene
{
private:
    HomeScene();
    ~HomeScene();
    virtual bool init();
public:
    CREATE_FUNC(HomeScene);
private:
    MapBar* _mapbar;
    TopStateBar* _topstatebar;
    BottomStateBar* _bottomstatebar;
    ChapterBar* _chapterbar;
    PlayStateBar* _playstatebar;
};

#endif /* HomeScene_h */
