//
//  Special_4.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//

#include "Special_4.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Special_4::Special_4()
{
    _sName = "Special_4";
}


Special_4::~Special_4()
{
    
}

void Special_4::Cast(cocos2d::Node *_tag)
{

    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/def_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(BattleSystem::getInstance()->getMonster()->getPosition());
    _particleAnimation->setDuration(-1);
    _particleAnimation->setStartColor(cocos2d::Color4F(0.0f,0.2f,1.0f,0.0f));
    _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0,0,0));
    _particleAnimation->setEndColor(cocos2d::Color4F(0.2f,0.2f,1.0f,0.0f));
    _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,0));

    BattleSystem::getInstance()->getMonster()->AddParticleToLayer(_particleAnimation,-1);
    BaseAtk = BattleSystem::getInstance()->getMonster()->getState()->GetAttack();
    _tag->schedule(std::bind([=]
                             {
                                 float max =(float)BattleSystem::getInstance()->getPlayer()->getState()->GetMpMax();
                                 float now =(float)BattleSystem::getInstance()->getPlayer()->getState()->GetMP();
                                 float temp = 2.0f -  now / max;
                                 _particleAnimation->setSpeed(500*(temp-1.0f));
                                 int Atk = BaseAtk * temp;
                                 BattleSystem::getInstance()->getMonster()->getState()->SetAttack(Atk);
                             }), _sName);
}