//
//  Wind_3.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Wind_3_h
#define Wind_3_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Wind_3
:public PlayerBaseSkill
{
public:
    Wind_3();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Wind_3();
private:
    static bool isCheck;
};
#endif /* Wind_3_h */
