//
//  GameTopStateBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/15.
//
//

#ifndef GameTopStateBar_h
#define GameTopStateBar_h


#include "cocos2d.h"
#include <cocos-ext.h>
#include "IconLabelBar.h"
class GameTopStateBar
:public cocos2d::Layer
{
private:
    GameTopStateBar();
    ~GameTopStateBar();
    virtual bool init();
    void addPauseLayer();
    void UpdatePlayState();
public:
    CREATE_FUNC(GameTopStateBar);
private:
    cocos2d::ui::Scale9Sprite* _floor;
    cocos2d::MenuItemImage* _pausebtn;
    cocos2d::Menu* _menu;
    
    IconLabelBar* AtkLabel;
    IconLabelBar* DefLabel;
    
    int ConstATK;
    int ConstDEF;
    
    int NowATK;
    int NowDEF;
};
#endif /* GameTopStateBar_h */
