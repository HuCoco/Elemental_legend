//
//  ElementSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/9.
//
//

#include "ElementSystem.h"

ElementSystem* ElementSystem::_instance = nullptr;

ElementSystem::ElementSystem()
{
    
    NowState = ELEMENT_TYPE::ET_UNKOWN;
    _oddsFire = 20;
    _oddsThunder = 20;
    _oddsWater = 20;
    _oddsWind = 20;
    _oddsMagic = 20;
    UpdateSet();
}

ElementSystem::~ElementSystem()
{
    
}

void ElementSystem::UpdateSet()
{
    _Set1 = _oddsFire;
    _Set2 = _Set1 + _oddsThunder;
    _Set3 = _Set2 + _oddsWater;
    _Set4 = _Set3 + _oddsWind;
    _Set5 = _Set4 + _oddsMagic;
}

void ElementSystem::Init()
{
    
    _oddsFire = 20;
    _oddsThunder = 20;
    _oddsWater = 20;
    _oddsWind = 20;
    _oddsMagic = 20;
}


void ElementSystem::UpdateOdds(ELEMENT_TYPE _type)
{
    if(NowState == _type)
    {
        return;
    }
    Init();
    int temp = 3;
    _oddsFire -= temp;
    _oddsThunder -= temp;
    _oddsWater -= temp;
    _oddsWind -= temp;
    _oddsMagic -= temp;
    switch (_type) {
        case ET_FIRE:
            _oddsFire += temp * 5;
            break;
        case ET_THUNDER:
            _oddsThunder += temp * 5;
            break;
        case ET_WATER:
            _oddsWater += temp * 5;
            break;
        case ET_WIND:
            _oddsWind += temp * 5;
            break;
        case ET_MAGIC:
            _oddsMagic += temp * 5;
            break;
        default:
            break;
    }
    NowState = _type;
    UpdateSet();
}

ELEMENT_TYPE ElementSystem::getElementTypeByRandom()
{
    int Random = rand()%100;
    if(Random < _Set1)
    {
        return ET_FIRE;
    }
    else if(Random >= _Set1 && Random < _Set2)
    {
        return ET_THUNDER;
    }
    else if(Random >= _Set2 && Random < _Set3)
    {
        return ET_WATER;
    }
    else if(Random >= _Set3 && Random < _Set4)
    {
        return ET_WIND;
    }
    else if (Random >= _Set4 && Random < _Set5)
    {
        return ET_MAGIC;
    }
    return ET_UNKOWN;
}


ElementSystem* ElementSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new ElementSystem;
    }
    return _instance;
}