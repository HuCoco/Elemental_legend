//
//  Water_2.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Water_2_h
#define Water_2_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Water_2
:public PlayerBaseSkill
{
public:
    Water_2();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Water_2();
};
#endif /* Water_2_h */
