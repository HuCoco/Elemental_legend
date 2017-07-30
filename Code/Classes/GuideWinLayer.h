//
//  GuideWinLayer.h
//  NewGame
//
//  Created by 胡可 on 15/11/8.
//
//

#ifndef GuideWinLayer_h
#define GuideWinLayer_h

#include "cocos2d.h"
class GuideWinLayer
:public cocos2d::Layer
{
private:
    GuideWinLayer();
    ~GuideWinLayer();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
public:
    CREATE_FUNC(GuideWinLayer);
private:
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    bool Cantouch;
};
#endif /* GuideWinLayer_h */
