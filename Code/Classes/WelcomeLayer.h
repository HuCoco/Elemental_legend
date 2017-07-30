//
//  WelcomeLayer.h
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#ifndef WelcomeLayer_h
#define WelcomeLayer_h

#include <stdio.h>
#include "cocos2d.h"

class WelcomeLayer
:public cocos2d::Layer
{
private:
    WelcomeLayer();
    ~WelcomeLayer();
    virtual bool init();
    void StartGameBtnCallBack();
public:
    CREATE_FUNC(WelcomeLayer);
private:
    cocos2d::Sprite* BackgroundImageSprite;
    cocos2d::MenuItemImage* StartGameBtn;
    cocos2d::Menu* _menu;
};


#endif /* WelcomeLayer_h */
