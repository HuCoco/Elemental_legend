//
//  Special_6.h
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
// 减速：怪物会使元素滚动速度减慢

#ifndef Special_6_h
#define Special_6_h


#include "MonsterBaseSkill.h"

class Special_6
:public MonsterBaseSkill
{
public:
    Special_6();
    ~Special_6();
    virtual void Cast(cocos2d::Node* _tag);
private:
    int BaseSpeed;
    bool isCheck;
};
#endif /* Special_6_h */
