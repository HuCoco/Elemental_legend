//
//  Fire_2.h
//  NewGame
//
//  Created by 胡可 on 15/10/5.
//
//

#ifndef Fire_2_h
#define Fire_2_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Fire_2
:public PlayerBaseSkill
{
public:
    Fire_2();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Fire_2();
private:
    static int rate_current;
    int rate_static;
};
#endif /* Fire_2_h */
