//
//  WelcomeGuideLayer.hpp
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#ifndef WelcomeGuideLayer_hpp
#define WelcomeGuideLayer_hpp

#include "BaseGuideLayer.h"

class WelcomeGuideLayer
:public BaseGuideLayer
{
private:
    WelcomeGuideLayer();
    ~WelcomeGuideLayer();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);

public:
    CREATE_FUNC_RETAIN(WelcomeGuideLayer);
};

#endif /* WelcomeGuideLayer_hpp */
