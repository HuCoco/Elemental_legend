//
//  Water_1.h
//  NewGame
//
//  Created by 胡可 on 15/10/7.
//
//

#ifndef Water_1_h
#define Water_1_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Water_1
:public PlayerBaseSkill
{
public:
    Water_1();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Water_1();
};
#endif /* Water_1_h */
