//
//  PlayStateBar.h
//  NewGame
//
//  Created by 胡可 on 15/11/7.
//
//

#ifndef PlayStateBar_h
#define PlayStateBar_h


#include "cocos2d.h"
#include <cocos-ext.h>
#include "IconLabelBar.h"
class PlayStateBar
:public cocos2d::Layer
{
private:
    PlayStateBar();
    ~PlayStateBar();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    //virtual void onTouchCancelled(cocos2d::Touch* _touch,cocos2d::Event* _event);
    void Open();
    void Close();
    void updateStateData();
public:
    CREATE_FUNC(PlayStateBar);
private:
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    cocos2d::ui::Scale9Sprite* _floor;
    cocos2d::Point NowPoint;
    cocos2d::Point LastPoint;
    std::vector<IconLabelBar*> StatePool;
    bool _isOpen;
    IconLabelBar* LvBar;
    IconLabelBar* AtkBar;
    IconLabelBar* DefBar;
    IconLabelBar* HealthBar;
    IconLabelBar* MagicBar;
    IconLabelBar* SheildBar;
    IconLabelBar* SpeedBar;
    IconLabelBar* RehpBar;
    IconLabelBar* RempBar;
    IconLabelBar* TimeBar;
};
#endif /* PlayStateBar_h */
