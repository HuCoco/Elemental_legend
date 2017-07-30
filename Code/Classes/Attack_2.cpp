//
//  Attack_2.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//

#include "Attack_2.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Attack_2::Attack_2()
{
    _sName = "Attack_2";
}


Attack_2::~Attack_2()
{
    
}

void Attack_2::Cast(cocos2d::Node *_tag)
{
        _tag->unschedule(_sName);
    _tag->schedule(std::bind([=]
                             {
                                 BattleSystem::getInstance()->getMonster()->StopAction();
                                 cocos2d::CallFunc* CallBack = cocos2d::CallFunc::create(std::bind([]
                                                                                                   {
                                                                                                       AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_MONSTER_ATTACK_01);
                                                                                                       BattleSystem::getInstance()->getMonster()->RunAciton(BattleSystem::getInstance()->getMonster()->GetStayRepeat());
                                                                                                       ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, HEALTH, REDUCE, BattleSystem::getInstance()->getPlayer()->GetRealDamage(BattleSystem::getInstance()->getMonster()->getState()->GetAttack()));
                                                                                                       if(BattleSystem::getInstance()->getPlayer()->getState()->GetSV()!=0)
                                                                                                       {
                                                                                                           if(BattleSystem::getInstance()->getPlayer()->getState()->GetSV() < BattleSystem::getInstance()->getPlayer()->GetRealDamage(BattleSystem::getInstance()->getMonster()->getState()->GetAttack()))
                                                                                                           {
                                                                                                               int value = BattleSystem::getInstance()->getPlayer()->GetRealDamage(BattleSystem::getInstance()->getMonster()->getState()->GetAttack()) - BattleSystem::getInstance()->getPlayer()->getState()->GetSV();
                                                                                                               ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, BattleSystem::getInstance()->getPlayer()->GetRealDamage(value));
                                                                                                               
                                                                                                           }
                                                                                                           else if(BattleSystem::getInstance()->getPlayer()->getState()->GetSV() >= BattleSystem::getInstance()->getPlayer()->GetRealDamage(BattleSystem::getInstance()->getMonster()->getState()->GetAttack()))
                                                                                                           {
                                                                                                               return;
                                                                                                           }
                                                                                                       }
                                                                                                       else
                                                                                                       {
                                                                                                           ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, BattleSystem::getInstance()->getPlayer()->GetRealDamage(BattleSystem::getInstance()->getMonster()->getState()->GetAttack())*0.1f);
                                                                                                       }
                                                                                                       cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/re_particle_plist.plist");
                                                                                                       _particleAnimation->setAutoRemoveOnFinish(true);
                                                                                                       _particleAnimation->setPosition(BattleSystem::getInstance()->getMonster()->getFootPos());
                                                                                                       _particleAnimation->setStartColor(cocos2d::Color4F(0,0.5f,1.0f,0));
                                                                                                       _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0,0,0));
                                                                                                       _particleAnimation->setEndColor(cocos2d::Color4F(0.0f,0.5f,1.0f,0));
                                                                                                       _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,0));
                                                                                                       BattleSystem::getInstance()->getMonster()->AddParticleToLayer(_particleAnimation,2);

                                                                                                   }));
                                 cocos2d::Sequence* Seq = cocos2d::Sequence::create(BattleSystem::getInstance()->getMonster()->GetAttackAnimate(),CallBack, NULL);
                                 BattleSystem::getInstance()->getMonster()->RunAciton(Seq);
                             }), BattleSystem::getInstance()->getMonster()->getAttackSpeed(), _sName);
}