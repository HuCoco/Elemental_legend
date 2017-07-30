//
//  Thunder_2.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Thunder_2_h
#define Thunder_2_h

#include <stdio.h>
#include "PlayerBaseSkill.h"

class Thunder_2
:public PlayerBaseSkill
{
public:
    Thunder_2();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Thunder_2();
private:
    static bool isCheck;
};
#endif /* Thunder_2_h */
