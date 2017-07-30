//
//  LoseLayer.h
//  NewGame
//
//  Created by 胡可 on 15/10/20.
//
//

#ifndef LoseLayer_h
#define LoseLayer_h


#include "cocos2d.h"
#include "ExperienceBar.h"
#include "BaseElement.h"
class LoseLayer
:public cocos2d::Layer
{
private:
    LoseLayer();
    ~LoseLayer();
    virtual bool init();
    void BackHome();
    ELEMENT_TYPE GetMin(int _n1,int _n2,int _n3,int _n4);
public:
    CREATE_FUNC(LoseLayer);
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
#endif /* LoseLayer_h */
