//
//  Thunder_3.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Thunder_3_h
#define Thunder_3_h

#include <stdio.h>
#include "PlayerBaseSkill.h"

class Thunder_3
:public PlayerBaseSkill
{
public:
    Thunder_3();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Thunder_3();
private:
    bool isCheck;
};
#endif /* Thunder_3_h */
