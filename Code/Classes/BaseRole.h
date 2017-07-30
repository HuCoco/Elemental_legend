//
//  BaseRole.h
//  NewGame
//
//  Created by 胡可 on 15/9/25.
//
//

#ifndef BaseRole_h
#define BaseRole_h

#include <stdio.h>
#include "cocos2d.h"
#include "State.h"
#include "SkillManager.h"
USING_NS_CC;

enum STATE_TYPE
{
    STT_LEVEL,
    STT_HEALTH,
    STT_MAGIC,
    STT_BUTTTIME,
    STT_SHEILD,
    STT_ATK,
    STT_DEF,
    STT_RHEALTH,
    STT_RMAGIC
};

class BaseRole
{
protected:
    BaseRole();
    ~BaseRole();
    int getProtectValue();
public:
    static BaseRole* create();
    virtual bool init();
    void AddState(STATE_TYPE _stt,int _data);
    void ReduceState(STATE_TYPE _stt,int _data);
    int GetRealDamage(int _damage);
public:
    inline State* getState(){return StateData;}
protected:
    State* StateData;
    SkillManager* SkillManagerData;
};


#endif /* BaseRole_h */
