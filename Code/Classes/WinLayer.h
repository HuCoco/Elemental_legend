//
//  WinLayer.h
//  NewGame
//
//  Created by 胡可 on 15/10/20.
//
//

#ifndef WinLayer_h
#define WinLayer_h


#include "cocos2d.h"
#include "ExperienceBar.h"
class WinLayer
:public cocos2d::Layer
{
private:
    WinLayer();
    ~WinLayer();
    virtual bool init();
    void BackHome();
public:
    CREATE_FUNC(WinLayer);
private:
    cocos2d::ui::Scale9Sprite* FloorSprite;
    cocos2d::Menu* _menu;
    cocos2d::MenuItemImage* _okbtn;
    cocos2d::Sprite* FireIcon;
    cocos2d::Label* CostFireLabel;
    cocos2d::Sprite* WaterIcon;
    cocos2d::Label* CostWaterLabel;
    cocos2d::Sprite* ThunderIcon;
    cocos2d::Label* CostThunderLabel;
    cocos2d::Sprite* WindIcon;
    cocos2d::Label* CostWindLabel;
    ExperienceBar* expBar;
};

#endif /* WinLayer_h */
