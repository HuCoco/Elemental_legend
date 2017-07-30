//
//  Special_2.h
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//  轮墓：持续期间，怪物如果受到伤害则会回复相应的生命值

#ifndef Special_2_h
#define Special_2_h


#include "MonsterBaseSkill.h"
class Special_2
:public MonsterBaseSkill
{
public:
    Special_2();
    ~Special_2();
    virtual void Cast(cocos2d::Node* _tag);
private:
    bool isCheck;
    int LastHp;
    int NowHp;
    
};
#endif /* Special_2_h */
