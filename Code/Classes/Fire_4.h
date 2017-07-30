//
//  Fire_4.h
//  NewGame
//
//  Created by 胡可 on 15/10/5.
//
//

#ifndef Fire_4_h
#define Fire_4_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
class Fire_4
:public PlayerBaseSkill
{
public:
    Fire_4();
    virtual bool Cast(cocos2d::Layer* _tag,const cocos2d::Vec2 _pos,int& _num);
    ~Fire_4();
private:
    float _addBuff;
    bool BuffRun;
    int bufftime;
};
#endif /* Fire_4_h */
