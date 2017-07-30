//
//  Sand2.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#include "Sand2.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
#include "AttrSystem.h"
Sand2::Sand2()
{
    isBuff = false;
    times =  0;
}

Sand2::~Sand2()
{
    
}

void Sand2::Cast(int touchtime, ELEMENT_TYPE _type,cocos2d::Node* _tag)
{
    if(_type == ELEMENT_TYPE::ET_WATER)
    {
        if(isBuff == false)
        {
            times++;
            if(times >= 3)
            {
                isBuff = true;
            }
        }
        else
        {
            isBuff = false;
            times = 0;
            ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, HEALTH, ADD, AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REHP)*3);
        }
    }
    else if(_type == ELEMENT_TYPE::ET_FIRE)
    {
        if(isBuff)
        {
            isBuff = false;
            times = 0;
            BattleSystem::getInstance()->getPlayer()->getState()->UpdateAttack(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_ATK));
            _tag->scheduleOnce(std::bind([=]
                                         {
                                             BattleSystem::getInstance()->getPlayer()->getState()->UpdateAttack(-AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_ATK));
                                         }),3,"FireBuff");
        }
        times = 0;
    }
    else if(_type == ELEMENT_TYPE::ET_WIND)
    {
        if(isBuff)
        {
            isBuff = false;
            times = 0;
            ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, SHEILD, ADD, AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SHIELD)/2);
        }
        times = 0;
    }
    else if(_type == ELEMENT_TYPE::ET_THUNDER)
    {
        if(isBuff)
        {
            isBuff = false;
            times = 0;
            ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, BUFFTIME, ADD, AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_BUFFTIME)/2);
        }
        times = 0;
    }
    else if(_type == ELEMENT_TYPE::ET_MAGIC)
    {
        if(isBuff)
        {
            isBuff = false;
            times = 0;
            ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, ADD, AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REMP)*3);
        }
        times = 0;
    }
}