//
//  Fire_3.h
//  NewGame
//
//  Created by 胡可 on 15/10/5.
//
//

#ifndef Fire_3_h
#define Fire_3_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Fire_3
:public PlayerBaseSkill
{
public:
    Fire_3();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Fire_3();
};
#endif /* Fire_3_h */
