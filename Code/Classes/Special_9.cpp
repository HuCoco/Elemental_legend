//
//  Special_9.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//

#include "Special_9.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Special_9::Special_9()
{
    _sName = "Special_9";
    isCheck = false;
}


Special_9::~Special_9()
{
    
}

void Special_9::Cast(cocos2d::Node *_tag)
{
    int BaseAtk = BattleSystem::getInstance()->getMonster()->getState()->GetAttack();
    int BaseDef = BattleSystem::getInstance()->getPlayer()->getState()->GetDefence();
    _tag->schedule(std::bind([=]
                             {
                                 BattleSystem::getInstance()->getMonster()->getState()->UpdateAttack(BaseAtk*0.1f);
                                 BattleSystem::getInstance()->getMonster()->getState()->UpdateDefence(-BaseDef*0.1f);
                                 
                             }), 10, _sName);
}