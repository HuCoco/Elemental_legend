//
//  WindConfig.h
//  NewGame
//
//  Created by 胡可 on 15/10/11.
//
//

#ifndef WindConfig_h
#define WindConfig_h


#include "TalentConfig.h"

class WindConfig
:public TalentConfig
{
protected:
    WindConfig();
    ~WindConfig();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
public:
    CREATE_FUNC(WindConfig);
};
#endif /* WindConfig_h */
