//
//  Thunder_5.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Thunder_5_h
#define Thunder_5_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Thunder_5
:public PlayerBaseSkill
{
public:
    Thunder_5();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Thunder_5();
private:
    bool isCheck;
};
#endif /* Thunder_5_h */
