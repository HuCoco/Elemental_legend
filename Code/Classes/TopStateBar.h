//
//  TopStateBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/10.
//
//

#ifndef TopStateBar_h
#define TopStateBar_h


#include "cocos2d.h"
#include <cocos-ext.h>
#include "PlayerConfig.h"
#include "IconLabelBar.h"
#include "BaseMissionBar.h"
enum TOP_STATE_BAR_TOUCH_EVENT
{
    TOUCH_LEVEL,
    TOUCH_FLOOR,
    TOUCH_NOTHING
};



class TopStateBar
:public cocos2d::Layer
{
public:
    CREATE_FUNC(TopStateBar);
private:
    TopStateBar();
    ~TopStateBar();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    void Open();
    void Close();
    void UpdateCur();
private:
    TOP_STATE_BAR_TOUCH_EVENT _tsTouchEvent;
    cocos2d::Point NowTouchPoint;
    cocos2d::Point LastTouchPoint;
    bool isOpenPlayerConfig;
private:
    cocos2d::ui::Scale9Sprite* FloorSprite;
    
    cocos2d::Sprite* LevelFrameSprite;
    cocos2d::Label* LevelLabel;
    
    IconLabelBar* CoinBar;
    IconLabelBar* DiamondsBar;
    
    //PlayerConfig* _playerconfig;
    
    std::vector<cocos2d::ui::Scale9Sprite*> MissionFloorPool;
    std::vector<BaseMissionBar*> MissionBarPool;
    
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    
};

#endif /* TopStateBar_h */
