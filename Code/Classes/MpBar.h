//
//  MpBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/6.
//
//

#ifndef MpBar_h
#define MpBar_h


#include "ResourceBar.h"
class MpBar
:public ResourceBar
{
public:
    MpBar();
    RES_FUNC(MpBar);
    virtual int Add(int _data);
    virtual int Reduce(int _data);
protected:
    ~MpBar();
    virtual bool init(cocos2d::Vec2 _pos);
    
};
#endif /* MpBar_h */
