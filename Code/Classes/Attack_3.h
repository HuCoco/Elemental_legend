//
//  Attack_3.h
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//  吸魔：怪物每次攻击会减少玩家5%伤害的魔法值

#ifndef Attack_3_h
#define Attack_3_h


#include "MonsterBaseSkill.h"

class Attack_3
:public MonsterBaseSkill
{
public:
    Attack_3();
    ~Attack_3();
    virtual void Cast(cocos2d::Node* _tag);
    
};

#endif /* Attack_3_h */
