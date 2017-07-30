//
//  BaseFire.h
//  NewGame
//
//  Created by 胡可 on 15/10/4.
//
//

#ifndef PlayerBaseSkill_h
#define PlayerBaseSkill_h

#include "cocos2d.h"
#include "BaseSkill.h"
#include "AudioSystem.h"

#define CHANGE_MAGIC_VALUE 0.05f

class PlayerBaseSkill
:public BaseSkill
{
public:
    PlayerBaseSkill();
    virtual bool  Cast(cocos2d::Layer* _tag,cocos2d::Vec2 _pos,int& _num);
    ~PlayerBaseSkill();
    int getTouchMax(){return _touchMax;}
protected:
    int _touchMax;
    int _NeedRes;
    int _Cost;
    int TouchTimes;
};
#endif /* BaseFire_h */
