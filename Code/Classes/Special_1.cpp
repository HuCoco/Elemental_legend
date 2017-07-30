//
//  Special_1.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//

#include "Special_1.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Special_1::Special_1()
{
    _sName = "Special_1";
    LastHp = 0;
    NowHp = 0;
    isCast = false;
}


Special_1::~Special_1()
{
    
}

void Special_1::Cast(cocos2d::Node *_tag)
{
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/spe_particle_plist.plist");
    cocos2d::Size monsterSize = BattleSystem::getInstance()->getMonster()->getMonsterSize();
    _particleAnimation->setStartRadius(monsterSize.width*0.5);
    _particleAnimation->setEndRadius(monsterSize.width*0.3f);
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(BattleSystem::getInstance()->getMonster()->getPosition());
    _particleAnimation->setDuration(-1);
    _particleAnimation->setStartColor(cocos2d::Color4F(1.0f,0.2f,0.2f,1.0f));
    _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0,0,0));
    _particleAnimation->setEndColor(cocos2d::Color4F(1.0f,0.8f,0.2f,1.0f));
    _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,0));
    _particleAnimation->setLife(0.5f);
    _particleAnimation->setTotalParticles(200);
    _particleAnimation->setStartSize(20);
    _particleAnimation->setStartSizeVar(5);
    _particleAnimation->setEndSize(20);
    _particleAnimation->setEndSizeVar(0);
    BattleSystem::getInstance()->getMonster()->AddParticleToLayer(_particleAnimation,-1);
    _tag->schedule(std::bind([=]
                             {
                                 NowHp = BattleSystem::getInstance()->getMonster()->getState()->GetHP();
                                 int temp = LastHp - NowHp < 0?0:LastHp - NowHp;
                                 ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, HEALTH, REDUCE,BattleSystem::getInstance()->getPlayer()->GetRealDamage(temp*0.05f));
                                 LastHp = NowHp;

                             }) ,_sName);
}