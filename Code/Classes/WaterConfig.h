//
//  WaterConfig.h
//  NewGame
//
//  Created by 胡可 on 15/10/11.
//
//

#ifndef WaterConfig_h
#define WaterConfig_h


#include "TalentConfig.h"

class WaterConfig
:public TalentConfig
{
protected:
    WaterConfig();
    ~WaterConfig();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
public:
    CREATE_FUNC(WaterConfig);
};
#endif /* WaterConfig_h */
