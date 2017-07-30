//
//  State.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/25.
//
//

#include "State.h"
#include "MyLog.h"
#include "ExperienceSystem.h"
State::State()
{
    
}

State::~State()
{
    
}

bool State::init(ROLE_STATE _rState)
{
    Level = _rState.Level;
    HealthPoint_Max = _rState.HealthPoint_Max;
    MagicPoint_Max = _rState.MagicPoint_Max;
    BuffTime_Max = _rState.BuffTime_Max;
    ShieldValue_Max = _rState.ShieldValue_Max;
    AttackValue = _rState.AttackValue;
    DefenceValue = _rState.DefenceValue;
    RecoverHealthPointPerSecond = _rState.RecoverHealthPointPerSecond;
    RecoverMagicPointPerSecond = _rState.RecoverMagicPointPerSecond;
    
    HealthPoint_Current = HealthPoint_Max;
    MagicPoint_Current = MagicPoint_Max;
    BuffTime_Current = 0.0f;
    ShieldValue_Current = 0.0f;
    return true;
}

State* State::create(ROLE_STATE _rState)
{
    State* pRet = new State;
    if(pRet && pRet->init(_rState))
    {
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

void State::UpdateLevel(int _level)
{
    Level += _level;
    MyLog::getInstance()->log("当前等级设置为%d", _level);
}

void State::UpdateHP(int _fHp)
{
    HealthPoint_Current += _fHp;
    if(HealthPoint_Current > HealthPoint_Max)
    {
        HealthPoint_Current = HealthPoint_Max;
    }
    else if(HealthPoint_Current < 0)
    {
        HealthPoint_Current = 0;
    }
    MyLog::getInstance()->log("当前生命值更新为%d",HealthPoint_Current);
}

void State::UpdateMP(int _fMp)
{
    MagicPoint_Current += _fMp;
    if(MagicPoint_Current > MagicPoint_Max)
    {
        MagicPoint_Current = MagicPoint_Max;
    }
    else if(MagicPoint_Current < 0)
    {
        MagicPoint_Current = 0;
    }
    MyLog::getInstance()->log("当前魔法值更新为%d",MagicPoint_Current);
}

void State::UpdateSV(int _fSv)
{
    ShieldValue_Current += _fSv;
    if(ShieldValue_Current > ShieldValue_Max)
    {
        ShieldValue_Current = ShieldValue_Max;
    }
    else if(ShieldValue_Current < 0)
    {
        ShieldValue_Current = 0;
    }
    MyLog::getInstance()->log("当前护盾值更新为%d",ShieldValue_Current);
}

void State::UpdateBT(int _fBt)
{
    BuffTime_Current += _fBt;
    if(BuffTime_Current > BuffTime_Max)
    {
        BuffTime_Current = BuffTime_Max;
    }
    else if(BuffTime_Current < 0)
    {
        BuffTime_Current = 0;
    }
    MyLog::getInstance()->log("增益技能时间更新为%d",BuffTime_Current);
}

void State::UpdateAttack(int _iAttack)
{
    AttackValue += _iAttack;
    MyLog::getInstance()->log("攻击力更新为%d",AttackValue);
}

void State::SetAttack(int _iAttack)
{
    AttackValue = _iAttack;
    MyLog::getInstance()->log("攻击力更新为%d",AttackValue);
}

void State::UpdateDefence(int _iDefence)
{
    DefenceValue += _iDefence;
    MyLog::getInstance()->log("攻击力更新为%d",DefenceValue);
}

void State::UpdateReHp(int _fReHp)
{
    RecoverHealthPointPerSecond += _fReHp;
    MyLog::getInstance()->log("生命回复更新为%d",RecoverHealthPointPerSecond);
}

void State::UpdateReMp(int _fReMp)
{
    RecoverMagicPointPerSecond += _fReMp;
    MyLog::getInstance()->log("法力回复更新为%d",RecoverMagicPointPerSecond);
}
