//
//  GuideMsgBox.h
//  NewGame
//
//  Created by 胡可 on 15/10/29.
//
//

#ifndef GuideMsgBox_h
#define GuideMsgBox_h

#include <cocos-ext.h>
#include "cocos2d.h"

class GuideMsgBox
:public cocos2d::Layer
{
private:
    GuideMsgBox();
    ~GuideMsgBox();
    virtual bool init();
    void OKCallback();
    void NOCallback();
public:
    CREATE_FUNC(GuideMsgBox);
private:
    cocos2d::Menu* _menu;
    cocos2d::MenuItemImage* okBtn;
    cocos2d::MenuItemImage* noBtn;
    cocos2d::ui::Scale9Sprite* _floor;
};

#endif /* GuideMsgBox_h */
