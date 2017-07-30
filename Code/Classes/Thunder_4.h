//
//  Thunder_4.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Thunder_4_h
#define Thunder_4_h

#include <stdio.h>
#include "PlayerBaseSkill.h"

class Thunder_4
:public PlayerBaseSkill
{
public:
    Thunder_4();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Thunder_4();
private:
    bool isCheck;
};
#endif /* Thunder_4_h */
