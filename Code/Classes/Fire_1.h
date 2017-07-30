//
//  Fire_1.h
//  NewGame
//
//  Created by 胡可 on 15/10/4.
//
//

#ifndef Fire_1_h
#define Fire_1_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Fire_1
:public PlayerBaseSkill
{
public:
    Fire_1();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Fire_1();
};

#endif /* Fire_1_h */
