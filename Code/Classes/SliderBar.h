//
//  SliderBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/26.
//
//

#ifndef SliderBar_h
#define SliderBar_h


#include "cocos2d.h"
#include <cocos-ext.h>

enum SLIDER_TOUCH_EVENT
{
    TOUCH_NOTHING_IN_SLIDER,
    TOUCH_SLIDER_ICON,
    TOUCH_SLIDER_BOTTON
};

enum SLIDER_BAR_TYPE
{
    TYPE_UNKOWN,
    BACKGROUND_MUSIC,
    EFFICTIVE_MUSIC
};


class SliderBar
:public cocos2d::Node
{
private:
    SliderBar();
    ~SliderBar();
    virtual bool init(const std::string& _onfliepath,
                      const std::string& _offfliepath,
                      const std::string& _sliderbtn,
                      const std::string& _sliderpath,
                      int width = cocos2d::Director::getInstance()->getVisibleSize().width*0.6f,
                      int height = 30);
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    float UpdateSliderProgress();
    void SetOdd(float);
    float GetOdd();
public:
    static SliderBar* create(const std::string& _onfliepath,
                             const std::string& _offfliepath,
                             const std::string& _sliderbtn,
                             const std::string& _sliderpath,
                             int width = cocos2d::Director::getInstance()->getVisibleSize().width*0.6f,
                             int height = 30);
    void SetState(bool _s);
    void SetSliderBarType(SLIDER_BAR_TYPE);
    inline bool getState(){return _switch;}
private:
    bool _switch;
    cocos2d::Sprite* StateSprite;
    std::string StateOn;
    std::string StateOff;
    cocos2d::Sprite* SliderBtn;
    cocos2d::ui::Scale9Sprite* SliderFloor;
    cocos2d::ui::Scale9Sprite* SliderProgress;
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    SLIDER_TOUCH_EVENT _SliderEvent;
    SLIDER_BAR_TYPE _SliderType;
    cocos2d::Point LastPoint;
    cocos2d::Point NowPoint;
};

#endif /* SliderBar_h */
