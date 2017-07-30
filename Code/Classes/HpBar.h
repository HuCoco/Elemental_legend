//
//  HpBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/6.
//
//

#ifndef HpBar_h
#define HpBar_h


#include "ResourceBar.h"

class HpBar
:public ResourceBar
{
public:
    HpBar();
    RES_FUNC(HpBar);
    virtual int Add(int _data);
    virtual int Reduce(int _data);
protected:
    ~HpBar();
    virtual bool init(cocos2d::Vec2 _pos);

};
#endif /* HpBar_h */
