//
//  DynamicAttrSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/15.
//
//

#include "DynamicAttrSystem.h"
#include "TrailSystem.h"
#include "XMLParser.h"
DynamicAttrSystem* DynamicAttrSystem::_instance = nullptr;

DynamicAttrSystem::DynamicAttrSystem()
{
    srand((int)time(NULL));
}

DynamicAttrSystem::~DynamicAttrSystem()
{
    
}


DynamicAttrSystem* DynamicAttrSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new DynamicAttrSystem;
    }
    return _instance;
}

void DynamicAttrSystem::upDateMonster(int _gate)
{
    int chapter = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::CHAPTER_NOW);
    _mData = JsonParser::getInstance()->GetMonsterData(chapter,_gate);
}

void DynamicAttrSystem::upDataMonsterInTrail()
{
    int Random = rand()%3;
    TrialSystem::getInstance()->setGate(Random);
    _mData = JsonParser::getInstance()->GetTrailData(Random);
}

int DynamicAttrSystem::GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST _list,int _pLevel)
{
    switch (_list)
    {
        case DYN_MONSTER_AKT:
            return _mData->ATK + (_mData->ATK * 0.8f)*(_pLevel-1);
            break;
        case DYN_MONSTER_HEALTH:
            return _mData->Hp + (_mData->Hp * 0.8f)*(_pLevel-1);
            break;
        case DYN_MONSTER_DEF:
            return _mData->DEF;
            break;
        case DYN_MONSTER_SPEED:
            return _mData->SPEED;
            break;
        default:
            break;
    }
}

int DynamicAttrSystem::GetMonsterType()
{
    return _mData->Type;
}

int DynamicAttrSystem::getMonsterAffixSkill(MONSTER_AFFIX_LIST _list)
{
    switch (_list)
    {
        case MONSTER_ATK_AFFIX:
            return _mData->ATKNUM;
            break;
        case MONSTER_DEF_AFFIX:
            return _mData->DEFNUM;
            break;
        case MONSTER_SPE_AFFIX_1:
            return _mData->SPENUM1;
            break;
        case MONSTER_SPE_AFFIX_2:
            return _mData->SPENUM2;
            break;
        case MONSTER_SPE_AFFIX_3:
            return _mData->SPENUM3;
            break;
        default:
            break;
    }
}