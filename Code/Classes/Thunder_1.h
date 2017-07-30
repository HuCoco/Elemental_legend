//
//  Thunder_1.h
//  NewGame
//
//  Created by 胡可 on 15/10/7.
//
//

#ifndef Thunder_1_h
#define Thunder_1_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Thunder_1
:public PlayerBaseSkill
{
public:
    Thunder_1();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Thunder_1();
private:
    bool isCheck;
};
#endif /* Thunder_1_h */
