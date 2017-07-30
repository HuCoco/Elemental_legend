//
//  Attack_4.h
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//

#ifndef Attack_4_h
#define Attack_4_h


#include "MonsterBaseSkill.h"

class Attack_4
:public MonsterBaseSkill
{
public:
    Attack_4();
    ~Attack_4();
    virtual void Cast(cocos2d::Node* _tag);
    
};
#endif /* Attack_4_h */
