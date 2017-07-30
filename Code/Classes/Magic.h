//
//  Magic.h
//  NewGame
//
//  Created by 胡可 on 15/10/9.
//
//

#ifndef Magic_h
#define Magic_h

#include <stdio.h>
#include "PlayerBaseSkill.h"

class Magic
:public PlayerBaseSkill
{
public:
    Magic();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Magic();
};

#endif /* Magic_h */
