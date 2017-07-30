//
//  GateConfig.h
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#ifndef GateConfig_h
#define GateConfig_h


#include "cocos2d.h"
#include "IconLabelBar.h"

class GateConfig
:public cocos2d::Layer
{
private:
    GateConfig();
    ~GateConfig();
    virtual bool init();
    void GoToGameScene();
    void Back();
public:
    CREATE_FUNC(GateConfig);
    void InitData(int _gate);
private:
    cocos2d::ui::Scale9Sprite* _floor;
    cocos2d::MenuItemImage* _backbtn;
    cocos2d::MenuItemImage* _startbtn;
    cocos2d::Menu* _menu;
    int GateNum;
    IconLabelBar* LvBar;
    IconLabelBar* HealthBar;
    IconLabelBar* AtkBar;
    IconLabelBar* DefBar;
    IconLabelBar* SpeedBar;
    std::vector<cocos2d::Label*> AffixPool;
    cocos2d::Label* _name;
    cocos2d::Label* _info;
};

#endif /* GateConfig_h */
