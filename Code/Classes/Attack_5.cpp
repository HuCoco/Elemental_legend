//
//  Attack_5.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//

#include "Attack_5.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"

Attack_5::Attack_5()
{
    _sName = "Attack_5";
}


Attack_5::~Attack_5()
{
    
}

void Attack_5::Cast(cocos2d::Node *_tag)
{
        _tag->unschedule(_sName);
    _tag->schedule(std::bind([=]
                             {
                                 BattleSystem::getInstance()->getMonster()->StopAction();
                                 cocos2d::CallFunc* CallBack = cocos2d::CallFunc::create(std::bind([]
                                                                                                   {
                                                                                                       AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_MONSTER_ATTACK_01);
                                                                                                       if(rand()%100 < 20)
                                                                                                       {
                                                                                                           ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, HEALTH, REDUCE,BattleSystem::getInstance()->getPlayer()->GetRealDamage(BattleSystem::getInstance()->getMonster()->getState()->GetAttack())*1.5f);
                                                                                                       }
                                                                                                       else
                                                                                                       {
                                                                                                           ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, HEALTH, REDUCE,BattleSystem::getInstance()->getPlayer()->GetRealDamage(BattleSystem::getInstance()->getMonster()->getState()->GetAttack()));
                                                                                                       }
                                                                                                       BattleSystem::getInstance()->getMonster()->RunAciton(BattleSystem::getInstance()->getMonster()->GetStayRepeat());
                                                                                                   }));

                                 
                                 cocos2d::Sequence* Seq = cocos2d::Sequence::create(BattleSystem::getInstance()->getMonster()->GetAttackAnimate(),CallBack, NULL);
                                 BattleSystem::getInstance()->getMonster()->RunAciton(Seq);
                             }), BattleSystem::getInstance()->getMonster()->getAttackSpeed(), _sName);
}