//
//  Wind_5.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Wind_5_h
#define Wind_5_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Wind_5
:public PlayerBaseSkill
{
public:
    Wind_5();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Wind_5();
private:
    static bool isCheck;
};
#endif /* Wind_5_h */
