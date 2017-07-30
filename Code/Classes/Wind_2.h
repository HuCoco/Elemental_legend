//
//  Wind_2.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Wind_2_h
#define Wind_2_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Wind_2
:public PlayerBaseSkill
{
public:
    Wind_2();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Wind_2();
};
#endif /* Wind_2_h */
