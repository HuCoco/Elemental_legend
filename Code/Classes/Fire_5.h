//
//  Fire_5.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Fire_5_h
#define Fire_5_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Fire_5
:public PlayerBaseSkill
{
public:
    Fire_5();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Fire_5();
};
#endif /* Fire_5_h */
