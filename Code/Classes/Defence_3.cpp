//
//  Defence_3.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/16.
//
//

#include "Defence_3.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
Defence_3::Defence_3()
{
    _sName = "Defence_3";
    isCheck = false;
}


Defence_3::~Defence_3()
{
    
}

void Defence_3::Cast(cocos2d::Node *_tag)
{
    _tag->schedule(std::bind([=]
                             {
                                 if(isCheck == false)
                                 {
                                     isCheck = true;
                                     BattleSystem::getInstance()->getMonster()->getState()->UpdateDefence(10000);
                                     cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/def_particle_plist.plist");
                                     _particleAnimation->setAutoRemoveOnFinish(true);
                                     _particleAnimation->setPosition(BattleSystem::getInstance()->getMonster()->getPosition());
                                     _particleAnimation->setDuration(5.0f);
                                     _particleAnimation->setStartColor(cocos2d::Color4F(0.9f,0.9f,0.0f,0.0f));
                                     _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0,0,0));
                                     _particleAnimation->setEndColor(cocos2d::Color4F(0.9f,0.9f,0.0f,0.0f));
                                     _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,0));
                                     BattleSystem::getInstance()->getMonster()->AddParticleToLayer(_particleAnimation,-1);
                                     _tag->scheduleOnce(std::bind([=]
                                                                  {
                                                                      BattleSystem::getInstance()->getMonster()->getState()->UpdateDefence(-10000);
                                                                      isCheck = false;

                                                                  }), 5,"Defence");
                                 }
                             }),15, _sName);
}