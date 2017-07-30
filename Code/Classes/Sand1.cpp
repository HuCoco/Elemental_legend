//
//  Sand1.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#include "Sand1.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
#include "AttrSystem.h"
Sand1::Sand1()
{

}

Sand1::~Sand1()
{
    
}

void Sand1::Cast(int touchtime, ELEMENT_TYPE _type,cocos2d::Node* _tag)
{

    if(BattleSystem::getInstance()->getPlayer()->getState()->GetHP() < BattleSystem::getInstance()->getPlayer()->getState()->GetHpMax()/2)
    {
        ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, HEALTH, ADD, AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REHP)/10);
    }
}