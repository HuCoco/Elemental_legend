//
//  Special_5.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//

#include "Special_5.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Special_5::Special_5()
{
    _sName = "Special_5";
}


Special_5::~Special_5()
{
    
}

void Special_5::Cast(cocos2d::Node *_tag)
{
    BaseAtk = BattleSystem::getInstance()->getMonster()->getState()->GetAttack();
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/def_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(BattleSystem::getInstance()->getMonster()->getPosition());
    _particleAnimation->setDuration(-1);
    _particleAnimation->setStartColor(cocos2d::Color4F(1.0f,0.2f,0.0f,0.0f));
    _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0,0,0));
    _particleAnimation->setEndColor(cocos2d::Color4F(1.0f,0.2f,0.0f,0.0f));
    _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,0));

    BattleSystem::getInstance()->getMonster()->AddParticleToLayer(_particleAnimation,-1);

    _tag->schedule(std::bind([=]
                             {
                                 float temp = 2 - ((float)BattleSystem::getInstance()->getMonster()->getState()->GetHP() / (float)BattleSystem::getInstance()->getMonster()->getState()->GetHpMax());
                                 int Atk = BaseAtk * temp/2;
                                 BattleSystem::getInstance()->getMonster()->getState()->SetAttack(Atk);
                                 _particleAnimation->setSpeed(500*(temp-1.0f));
                                 BattleSystem::getInstance()->getMonster()->getState()->SetAttack(Atk);
                             }), _sName);
}