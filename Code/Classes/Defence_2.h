//
//  Defence_2.h
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//  复苏：当怪物的血量低于`30%`时，会每秒回复`2%`的生命值

#ifndef Defence_2_h
#define Defence_2_h


#include "MonsterBaseSkill.h"

class Defence_2
:public MonsterBaseSkill
{
public:
    Defence_2();
    ~Defence_2();
    virtual void Cast(cocos2d::Node* _tag);
private:
    bool isCheck;
    
};
#endif /* Defence_2_h */
