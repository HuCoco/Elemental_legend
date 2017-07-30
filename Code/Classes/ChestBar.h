//
//  ChestBar.h
//  NewGame
//
//  Created by 胡可 on 15/11/4.
//
//

#ifndef ChestBar_h
#define ChestBar_h

#include "cocos2d.h"
#include <cocos-ext.h>

enum CHEST_BAR_TOUCH_EVENT
{
    TOUCH_NOTHING_IN_CHEST,
    TOUCH_SLIVER_CHEST,
    TOUCH_GOLDEN_CHEST
};

class ChestBar
:public cocos2d::Node
{
private:
    ChestBar();
    ~ChestBar();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
public:
    CREATE_FUNC(ChestBar);
private:
    cocos2d::Sprite* sliverChest;
    cocos2d::Sprite* sliverIcon;
    cocos2d::Label* sliverLabel;
    cocos2d::Sprite* goldenChest;
    cocos2d::Sprite* goldenIcon;
    cocos2d::Label* goldenLabel;
    cocos2d::ui::Scale9Sprite* goldenBtn;
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    CHEST_BAR_TOUCH_EVENT _touchEvent;
    
};

#endif /* ChestBar_h */
