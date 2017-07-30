//
//  Special_9.h
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//  搏命：每隔一段时间，怪物的攻击力会提高10%，但防御力会降低10%

#ifndef Special_9_h
#define Special_9_h

#include "MonsterBaseSkill.h"

class Special_9
:public MonsterBaseSkill
{
public:
    Special_9();
    ~Special_9();
    virtual void Cast(cocos2d::Node* _tag);
private:
    bool isCheck;
    
};
#endif /* Attack_9_h */
