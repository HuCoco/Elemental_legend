//
//  BottomStateBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/11.
//
//

#ifndef BottomStateBar_h
#define BottomStateBar_h

#include "cocos2d.h"
#include "SliderBar.h"
#include <cocos-ext.h>
enum BOTTOM_STATE_BAR_TOUCH_EVENT
{
    Y_MOVE,
    X_MOVE,
    NONE_MOVE
};

struct PAGES_NODE
{
    cocos2d::Node* page;
    std::string pageName;
};


class BottomStateBar
:public cocos2d::Layer
{
private:
    BottomStateBar();
    ~BottomStateBar();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    void Open();
    void Close();
    void emSwitch();
    void bmSwitch();
    void MoveCompent(float _offx);
    void MoveEnd();
    void GotoTrial();
public:
    CREATE_FUNC(BottomStateBar);
private:
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    cocos2d::ui::Scale9Sprite* _floor;
    SliderBar* _embtn;
    SliderBar* _bmbtn;
    cocos2d::Menu* _menu;
    cocos2d::Label* _developer;
    cocos2d::Label* _edition;
    cocos2d::Label* _title;
    std::vector<PAGES_NODE> Pages;
    int NowPage;
private:
    BOTTOM_STATE_BAR_TOUCH_EVENT _bsTouchEvent;
    cocos2d::Point NowTouchPoint;
    cocos2d::Point LastTouchPoint;
    bool isOpen;
};

#endif /* BottomStateBar_h */
