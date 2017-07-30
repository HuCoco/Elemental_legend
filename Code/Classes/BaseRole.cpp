//
//  BaseRole.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/25.
//
//

#include "BaseRole.h"
#include "BattleSystem.h"

//Defence
/*
 0 --- 10
 10 --- 10
 20 --- 12
 30 --- 15
 40 --- 18
 50 --- 21
 60 --- 25
 70 --- 28
 80 --- 30
 90 --- 33
 100 --- 36
 110 --- 38
 120 --- 40
 130 --- 42
 140 --- 44
 150 --- 46
 160 --- 48
 170 --- 49
 180 --- 51
 190 --- 52
 200 --- 54
 210 --- 55
 220 --- 56
 230 --- 58
 240 --- 59
 250 --- 60
 260 --- 61
 270 --- 62
 280 --- 63
 290 --- 64
 300 --- 65
 310 --- 66
 320 --- 67
 330 --- 68
 340 --- 68
 350 --- 69
 360 --- 70
 370 --- 71
 380 --- 72
 390 --- 72
 400 --- 73
 410 --- 74
 420 --- 75
 430 --- 75
 440 --- 76
 450 --- 76
 460 --- 77
 470 --- 78
 480 --- 78
 490 --- 79
 500 --- 79
 510 --- 80
 520 --- 81
 530 --- 81
 540 --- 82
 550 --- 82
 560 --- 83
 570 --- 83
 580 --- 84
 590 --- 84
 600 --- 85


*/

BaseRole::BaseRole()
{
    
}


BaseRole::~BaseRole()
{
   
}


BaseRole* BaseRole::create()
{
    BaseRole* pRet = new BaseRole();
    if(pRet && pRet->init())
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

void BaseRole::AddState(STATE_TYPE _stt, int _data)
{
    switch (_stt) {
        case STT_HEALTH:
            StateData->UpdateHP(_data);
            break;
        case STT_MAGIC:
            StateData->UpdateMP(_data);
            break;
        case STT_BUTTTIME:
            StateData->UpdateBT(_data);
            break;
        case STT_SHEILD:
            StateData->UpdateSV(_data);
            break;
        case STT_ATK:
            StateData->UpdateAttack(_data);
            break;
        case STT_DEF:
            StateData->UpdateDefence(_data);
            break;
        case STT_RHEALTH:
            StateData->UpdateReHp(_data);
            break;
        case STT_RMAGIC:
            StateData->UpdateReMp(_data);
            break;
        case STT_LEVEL:
            StateData->UpdateLevel (_data);
            break;
            
        default:
            break;
    }
}

int BaseRole::GetRealDamage(int _damage)
{
    float _DefOdd = (100.0f - (10.0f*(log10((float)StateData->GetDefence()*(float)StateData->GetDefence()/200.0f + 10.0f)/log10(2))-23.0f))/100.0f;
    if(_DefOdd < 0)
    {
        _DefOdd = 0;
    }
    int realdamage = _damage * _DefOdd;
    if(StateData->GetDefence()>=10000)
    {
        realdamage = 0;
    }
    return realdamage;
}



bool BaseRole::init()
{
    return true;
}