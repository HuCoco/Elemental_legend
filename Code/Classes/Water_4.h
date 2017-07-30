//
//  Water_4.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Water_4_h
#define Water_4_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Water_4
:public PlayerBaseSkill
{
public:
    Water_4();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Water_4();
private:
    static bool isCheck;
    static int _time;
    int timeMax;
};
#endif /* Water_4_h */
