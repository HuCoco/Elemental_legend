//
//  Water_5.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Water_5_h
#define Water_5_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Water_5
:public PlayerBaseSkill
{
public:
    Water_5();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Water_5();
};
#endif /* Water_5_h */
