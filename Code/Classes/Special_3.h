//
//  Special_3.h
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//  回复：每隔一段时间，怪物会回复已损失生命值的10%

#ifndef Special_3_h
#define Special_3_h


#include "MonsterBaseSkill.h"

class Special_3
:public MonsterBaseSkill
{
public:
    Special_3();
    ~Special_3();
    virtual void Cast(cocos2d::Node* _tag);
private:
    bool isCheck;
    
};
#endif /* Special_3_h */
