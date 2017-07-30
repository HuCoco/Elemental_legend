//
//  Magic.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/9.
//
//

#include "Magic.h"
#include "ResourceSystem.h"
#include "AttrSystem.h"
#include "BattleSystem.h"
Magic::Magic()
{
    //_touchMax = 1;
}



Magic::~Magic()
{
    
}

bool Magic::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
{
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/magic_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(_pos);
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER,MAGIC, ADD, BattleSystem::getInstance()->getPlayer()->getState()->GetReMp());
    _tag->addChild(_particleAnimation);
    return true;
}