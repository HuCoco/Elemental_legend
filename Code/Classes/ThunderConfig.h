//
//  ThunderConfig.h
//  NewGame
//
//  Created by 胡可 on 15/10/11.
//
//

#ifndef ThunderConfig_h
#define ThunderConfig_h


#include "TalentConfig.h"

class ThunderConfig
:public TalentConfig
{
protected:
    ThunderConfig();
    ~ThunderConfig();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
public:
    CREATE_FUNC(ThunderConfig);
};
#endif /* ThunderConfig_h */
