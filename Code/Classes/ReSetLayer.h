//
//  ReSetLayer.h
//  NewGame
//
//  Created by 胡可 on 15/10/23.
//
//

#ifndef ReSetLayer_h
#define ReSetLayer_h

#include "cocos2d.h"
#include "AttrBar.h"
class ReSetLayer
:public cocos2d::Layer
{
private:
    ReSetLayer();
    ~ReSetLayer();
    virtual bool init(AttrBar* _bar,int _coin);
    void YesCallBack();
    void NoCallBack();
public:
    static ReSetLayer* create(AttrBar* _bar,int _coin);
private:
    cocos2d::Label* InfoLabel;
    cocos2d::MenuItemImage* _YesBtn;
    cocos2d::MenuItemImage* _NoBtn;
    AttrBar* _obj;
    int _value;
};

#endif /* ReSetLayer_h */
