//
//  Water_3.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef Water_3_h
#define Water_3_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Water_3
:public PlayerBaseSkill
{
public:
    Water_3();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Water_3();
private:
    bool isCheck;
    int _time;
    int timeMax;
};
#endif /* Water_3_h */
