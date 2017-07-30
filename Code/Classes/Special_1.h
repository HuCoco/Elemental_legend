//
//  Special_1.h
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//  反伤：怪物受到的伤害会返还`20%`给玩家

#ifndef Special_1_h
#define Special_1_h


#include "MonsterBaseSkill.h"
class Special_1
:public MonsterBaseSkill
{
public:
    Special_1();
    ~Special_1();
    virtual void Cast(cocos2d::Node* _tag);
private:
    int LastHp;
    int NowHp;
    bool isCast;
    
};
#endif /* Special_1_h */
