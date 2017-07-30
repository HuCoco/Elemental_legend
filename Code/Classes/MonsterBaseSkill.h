//
//  MonsterBaseSkill.h
//  NewGame
//
//  Created by 胡可 on 15/10/9.
//
//

#ifndef MonsterBaseSkill_h
#define MonsterBaseSkill_h

#include "cocos2d.h"
#include "BaseSkill.h"
class MonsterBaseSkill
:public BaseSkill
{
public:
    MonsterBaseSkill();
    ~MonsterBaseSkill();
    virtual void Cast(cocos2d::Node* _tag);
protected:
    std::string _sName;
};
#endif /* MonsterBaseSkill_h */
