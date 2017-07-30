//
//  Attack_1.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/9.
//
//

#include "Attack_1.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Attack_1::Attack_1()
{
    _sName = "Attack_1";
}


Attack_1::~Attack_1()
{
    
}

void Attack_1::Cast(cocos2d::Node *_tag)
{
    _tag->unschedule(_sName);
    _tag->schedule(std::bind([=]
                            {
                                BattleSystem::getInstance()->getMonster()->StopAction();
                                cocos2d::CallFunc* CallBack = cocos2d::CallFunc::create(std::bind([]
                                                                                                  {
                                                                                                      ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, HEALTH, REDUCE,BattleSystem::getInstance()->getPlayer()->GetRealDamage(BattleSystem::getInstance()->getMonster()->getState()->GetAttack()));
                                                                                                      AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_MONSTER_ATTACK_01);
                                                                                                      BattleSystem::getInstance()->getMonster()->RunAciton(BattleSystem::getInstance()->getMonster()->GetStayRepeat());
                                                                                                  }));
                                cocos2d::Sequence* Seq = cocos2d::Sequence::create(BattleSystem::getInstance()->getMonster()->GetAttackAnimate(),CallBack,NULL);
                                BattleSystem::getInstance()->getMonster()->RunAciton(Seq);
                            }), BattleSystem::getInstance()->getMonster()->getAttackSpeed(), _sName);
}