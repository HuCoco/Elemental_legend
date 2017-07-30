//
//  Defence_3.h
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
// 无敌：免疫一切伤害

#ifndef Defence_3_h
#define Defence_3_h


#include "MonsterBaseSkill.h"
class Defence_3
:public MonsterBaseSkill
{
public:
    Defence_3();
    ~Defence_3();
    virtual void Cast(cocos2d::Node* _tag);
private:
    bool isCheck;
    
};
#endif /* Defence_3_h */
