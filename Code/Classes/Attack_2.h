//
//  Attack_2.h
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
// 吸血：怪物每次攻击会吸取20%的伤害值的生命值。

#ifndef Attack_2_h
#define Attack_2_h


#include "MonsterBaseSkill.h"

class Attack_2
:public MonsterBaseSkill
{
public:
    Attack_2();
    ~Attack_2();
    virtual void Cast(cocos2d::Node* _tag);
    
};

#endif /* Attack_2_h */
