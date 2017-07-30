//
//  MapBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#ifndef MapBar_h
#define MapBar_h


#include "cocos2d.h"
#include "GateBar.h"

enum MAP_TOUCH_EVENT
{
    TOUCH_NOTHING_IN_MAP,
    TOUCH_MAP,
    TOUCH_GATE
};


class MapBar
:public cocos2d::Layer
{
private:
    MapBar();
    ~MapBar();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    void LeaveTopAndBack();
    void LeaveBottomAndBack();
public:
    CREATE_FUNC(MapBar);
private:
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    std::vector<cocos2d::Sprite*> MapPool;
    std::vector<GateBar*> GateBarPool;
    MAP_TOUCH_EVENT _MapEvent;
    cocos2d::Point LastPoint;
    cocos2d::Point NowPoint;
    int TouchGateNum;
};

#endif /* MapBar_h */
