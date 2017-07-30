//
//  Special_5.h
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//  狂怒：怪物的生命值越低，其攻击力会提高，最多为50%

#ifndef Special_5_h
#define Special_5_h


#include "MonsterBaseSkill.h"
class Special_5
:public MonsterBaseSkill
{
public:
    Special_5();
    ~Special_5();
    virtual void Cast(cocos2d::Node* _tag);
private:
    int BaseAtk;
};
#endif /* Special_5_h */
