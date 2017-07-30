//
//  Attack_1.h
//  NewGame
//
//  Created by 胡可 on 15/10/9.
//
//  普通攻击

#ifndef Attack_1_h
#define Attack_1_h


#include "MonsterBaseSkill.h"

class Attack_1
:public MonsterBaseSkill
{
public:
    Attack_1();
    ~Attack_1();
    virtual void Cast(cocos2d::Node* _tag);
    
};

#endif /* Attack_1_h */
