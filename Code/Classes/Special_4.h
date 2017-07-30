//
//  Special_4.h
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//  噬魔：玩家的魔法值越低，怪物的攻击力越高，最多提升100%

#ifndef Special_4_h
#define Special_4_h


#include "MonsterBaseSkill.h"
class Special_4
:public MonsterBaseSkill
{
public:
    Special_4();
    ~Special_4();
    virtual void Cast(cocos2d::Node* _tag);
private:
    int BaseAtk;
};
#endif /* Special_4_h */
