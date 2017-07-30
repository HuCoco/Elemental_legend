
//
//  BaseFire.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/4.
//
//

#include "PlayerBaseSkill.h"

PlayerBaseSkill::PlayerBaseSkill()
{
    _touchMax = 1;
    TouchTimes = 0;
}



PlayerBaseSkill::~PlayerBaseSkill()
{
    
}


bool PlayerBaseSkill::Cast(cocos2d::Layer* _tag,cocos2d::Vec2 _pos,int& _num)
{
    return true;
}

