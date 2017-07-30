//
//  Wind_1.h
//  NewGame
//
//  Created by 胡可 on 15/10/7.
//
//

#ifndef Wind_1_h
#define Wind_1_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Wind_1
:public PlayerBaseSkill
{
public:
    Wind_1();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Wind_1();
};
#endif /* Wind_1_h */
