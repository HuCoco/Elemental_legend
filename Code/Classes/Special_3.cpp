//
//  Special_3.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//

#include "Special_3.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Special_3::Special_3()
{
    _sName = "Special_3";
    isCheck = false;
}


Special_3::~Special_3()
{
    
}

void Special_3::Cast(cocos2d::Node *_tag)
{
    _tag->schedule(std::bind([=]
                             {
                                 cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/re_particle_plist.plist");
                                 _particleAnimation->setAutoRemoveOnFinish(true);
                                 _particleAnimation->setPosition(BattleSystem::getInstance()->getMonster()->getPosition());
                                 _particleAnimation->setStartColor(cocos2d::Color4F(0,1.0f,0.0f,0));
                                 _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0,0,0));
                                 _particleAnimation->setEndColor(cocos2d::Color4F(0.0f,1.0f,1.0f,0));
                                 _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,0));
                                BattleSystem::getInstance()->getMonster()->AddParticleToLayer(_particleAnimation,-1);
                                 int HpMax = BattleSystem::getInstance()->getMonster()->getState()->GetHpMax();
                                 int Hp = BattleSystem::getInstance()->getMonster()->getState()->GetHP();
                                 int ReHp = (HpMax - Hp) * 0.1f;
                                 ResourceSystem::getInstance()->UpdateResourceBar(MONSTER, HEALTH, ADD, ReHp);
                                 
                             }), 10, _sName);
}