//
//  ResourceBar.h
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#ifndef ResourceBar_h
#define ResourceBar_h


#include "cocos2d.h"
#include "cocos-ext.h"

//创建宏
#define RES_FUNC(__TYPE__) \
static __TYPE__* create(cocos2d::Vec2 _pos) \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->init(_pos)) \
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


enum RESOURCE_TYPE
{
    HEALTH,     //生命值
    MAGIC,      //魔法值
    BUFFTIME,   //增益时间
    SHEILD      //护盾
};

class ResourceBar
{
public:
    ResourceBar();
    RES_FUNC(ResourceBar);
    void AddToLayer(cocos2d::Layer* _tag);
    virtual int Add(int);
    virtual int Reduce(int);
protected:
    ~ResourceBar();
    virtual bool init(cocos2d::Vec2 _pos);
protected:
    cocos2d::ui::Scale9Sprite* Bar1;
    cocos2d::Label* Bar2;
    int _max;
    int _current;
    cocos2d::Size BarSize;
};

#endif /* ResourceBar_h */
