//
//  BaseMissionBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef BaseMissionBar_h
#define BaseMissionBar_h


#include "cocos2d.h"
#include <cocos-ext.h>
enum MISSION_TYPE
{
    NO_MISSION,
    USED_FIRE_300,
    USED_WATER_300,
    USED_WIND_300,
    USED_THUNDER_300,
};


class BaseMissionBar
:public cocos2d::ui::Scale9Sprite
{
protected:
    BaseMissionBar();
    ~BaseMissionBar();
    virtual bool init();    
public:
    CREATE_FUNC(BaseMissionBar);
    virtual void InitMissionData(MISSION_TYPE,int _value= 0);

protected:
    cocos2d::Label* _MissionValue;
    cocos2d::Sprite* _MissionCurrencyIcon;
    cocos2d::Label* _MissionInfo;
    cocos2d::Label* _MissionProgress;
    int Value;
};

#endif /* BaseMissionBar_h */
