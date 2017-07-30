//
//  Wind_4.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Wind_4_h
#define Wind_4_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Wind_4
:public PlayerBaseSkill
{
public:
    Wind_4();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Wind_4();
private:
    static bool isCheck;
    //int atk;
};
#endif /* Wind_4_h */
