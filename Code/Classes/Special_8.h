//
//  Special_8.h
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//  坚韧：每隔一段时间，怪物的防御力会提高10%，但攻击力会降低10%

#ifndef Special_8_h
#define Special_8_h


#include "MonsterBaseSkill.h"

class Special_8
:public MonsterBaseSkill
{
public:
    Special_8();
    ~Special_8();
    virtual void Cast(cocos2d::Node* _tag);
private:
    bool isCheck;
    
};
#endif /* Attack_8_h */
