//
//  Special_7.h
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//  冰冻：怪物会冻结元素

#ifndef Special_7_h
#define Special_7_h


#include "MonsterBaseSkill.h"

class Special_7
:public MonsterBaseSkill
{
public:
    Special_7();
    ~Special_7();
    virtual void Cast(cocos2d::Node* _tag);
private:
    int BaseSpeed;
    bool isCheck;
};
#endif /* Special_7_h */
