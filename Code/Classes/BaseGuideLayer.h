//
//  BaseGuideLayer.h
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#ifndef BaseGuideLayer_h
#define BaseGuideLayer_h


//
#define CREATE_FUNC_RETAIN(__TYPE__) \
static __TYPE__* create() \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->init()) \
{ \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}
//





#include "cocos2d.h"
#include <cocos-ext.h>

class GuideSystem;
class BaseGuideLayer
:public cocos2d::Layer
{
protected:
    BaseGuideLayer();
    ~BaseGuideLayer();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    void AddTouchTips(cocos2d::Vec2 pos = cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().width/10));
    void ResetTouchTips();
public:
    CREATE_FUNC_RETAIN(BaseGuideLayer);
    void setParent(std::vector<BaseGuideLayer*>* _parents,int _num,GuideSystem* _system);
protected:
    cocos2d::ui::Scale9Sprite* ShadowImage;
    cocos2d::Label* TouchTipsLabel;
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    bool CanTouch;
    std::vector<BaseGuideLayer*>* Parent;
    GuideSystem* System;
    int thisNum;
};


#endif /* BaseGuideLayer_h */
