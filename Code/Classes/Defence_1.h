//
//  Defence_1.h
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//  怪物施放此技能后，增加30%的防御力，持续5秒

#ifndef Defence_1_h
#define Defence_1_h


#include "MonsterBaseSkill.h"

class Defence_1
:public MonsterBaseSkill
{
public:
    Defence_1();
    ~Defence_1();
    virtual void Cast(cocos2d::Node* _tag);
private:
    bool isCheck;
    
};
#endif /* Defence_1_h */
