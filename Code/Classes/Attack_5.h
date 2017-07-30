//
//  Attack_5.h
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//  暴击：怪物的攻击有`15%`的概率造成`200%`的伤害


#ifndef Attack_5_h
#define Attack_5_h


#include "MonsterBaseSkill.h"

class Attack_5
:public MonsterBaseSkill
{
public:
    Attack_5();
    ~Attack_5();
    virtual void Cast(cocos2d::Node* _tag);
    
};


#endif /* Attack_5_h */
