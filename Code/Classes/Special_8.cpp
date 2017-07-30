//
//  Special_8.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//

#include "Special_8.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Special_8::Special_8()
{
    _sName = "Special_8";
    isCheck = false;
}


Special_8::~Special_8()
{
    
}

void Special_8::Cast(cocos2d::Node *_tag)
{
    int BaseAtk = BattleSystem::getInstance()->getMonster()->getState()->GetAttack();
    int BaseDef = BattleSystem::getInstance()->getPlayer()->getState()->GetDefence();
    _tag->schedule(std::bind([=]
                             {
                                 BattleSystem::getInstance()->getMonster()->getState()->UpdateAttack(-BaseAtk*1);
                                 BattleSystem::getInstance()->getMonster()->getState()->UpdateDefence(BaseDef*1);
                                 
                             }), 10, _sName);
}