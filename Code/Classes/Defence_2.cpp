//
//  Defence_2.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//

#include "Defence_2.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Defence_2::Defence_2()
{
    _sName = "Defence_2";
    isCheck = false;
}


Defence_2::~Defence_2()
{
    
}

void Defence_2::Cast(cocos2d::Node *_tag)
{
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/def_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(BattleSystem::getInstance()->getMonster()->getPosition());
    _particleAnimation->setDuration(-1);
    _particleAnimation->setStartColor(cocos2d::Color4F(0.1f,0.75f,0,0.0f));
    _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0,0,0));
    _particleAnimation->setEndColor(cocos2d::Color4F(0.1f,0.75f,0,0.0f));
    _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,0));
    BattleSystem::getInstance()->getMonster()->AddParticleToLayer(_particleAnimation,-1);
    _tag->schedule(std::bind([=]
                             {
                                 if(BattleSystem::getInstance()->getMonster()->getState()->GetHP() < BattleSystem::getInstance()->getMonster()->getState()->GetHpMax()/3)
                                 {
                                     ResourceSystem::getInstance()->UpdateResourceBar(MONSTER, HEALTH, ADD, BattleSystem::getInstance()->getMonster()->getState()->GetHpMax()*0.005f);
                                     _particleAnimation->setLife(0.5f);
                                 }
                                 _particleAnimation->setLife(0.0f);
                             }), 1, _sName);
}