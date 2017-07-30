//
//  Special_2.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//

#include "Special_2.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Special_2::Special_2()
{
    _sName = "Special_2";
    isCheck = false;
    LastHp = 0;
    NowHp = 0;
}


Special_2::~Special_2()
{
    
}

void Special_2::Cast(cocos2d::Node *_tag)
{
    _tag->schedule(std::bind([=]
                             {
                                 if(isCheck == false)
                                 {
                                     isCheck = true;
                                     cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/spe_particle_plist.plist");
                                     cocos2d::Size monsterSize = BattleSystem::getInstance()->getMonster()->getMonsterSize();
                                     _particleAnimation->setStartRadius(monsterSize.width*0.75f);
                                     _particleAnimation->setEndRadius(monsterSize.width*0.1f);
                                     _particleAnimation->setAutoRemoveOnFinish(true);
                                     _particleAnimation->setPosition(BattleSystem::getInstance()->getMonster()->getPosition());
                                     _particleAnimation->setDuration(10);
                                     _particleAnimation->setStartColor(cocos2d::Color4F(0.0f,1.0f,0.2f,0.0f));
                                     _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0,0,0));
                                     _particleAnimation->setEndColor(cocos2d::Color4F(0.2f,1.0f,0.2f,0.0f));
                                     _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,0));
                                     BattleSystem::getInstance()->getMonster()->AddParticleToLayer(_particleAnimation,-1);
                                     _tag->schedule(std::bind([=]
                                                              {
                                                                  NowHp = BattleSystem::getInstance()->getMonster()->getState()->GetHP();
                                                                  int temp = LastHp - NowHp < 0?0:LastHp - NowHp;
                                                                  ResourceSystem::getInstance()->UpdateResourceBar(MONSTER, HEALTH, ADD, temp*2.0f);
                                                                  LastHp = NowHp;
                                                                  
                                                              }),"specialrehp");

                                 }
                                 else if(isCheck == true)
                                 {
                                     isCheck = false;
                                     NowHp = 0;
                                     LastHp = 0;
                                     _tag->unschedule("specialrehp");
                                 }
                             }), 10 ,_sName);
}