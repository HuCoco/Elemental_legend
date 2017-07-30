//
//  Fire_2.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/5.
//
//

#include "Fire_2.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"
#include "AttrSystem.h"
int Fire_2::rate_current = 20;

Fire_2::Fire_2()
{
    _touchMax = 3;
    _NeedRes = 5;
    srand((int)time(NULL));
    rate_static = 20;
    
}

Fire_2::~Fire_2()
{
    
}

bool Fire_2::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
{
    _NeedRes = AttrSystem::getInstance()->GetBaseAttr(ATTR_TYPE::ATTR_MAGIC)*0.02f * (1 - BattleSystem::getInstance()->getPlayer()->GetReduceMagic());
    TouchTimes = _num;
    if(TouchTimes == 1)
    {
        int NeedMagic = BattleSystem::getInstance()->getPlayer()->getState()->GetMpMax()*CHANGE_MAGIC_VALUE + _NeedRes;
        if(BattleSystem::getInstance()->getPlayer()->getState()->GetMP() >= NeedMagic)
        {
            ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, NeedMagic - _NeedRes);
        }
        else
        {
            return false;
        }
    }
    if(BattleSystem::getInstance()->getPlayer()->getState()->GetMP() < _NeedRes)
    {
        return false;
    }
    cocos2d::Vec2 _endPos = cocos2d::Vec2(BattleSystem::getInstance()->getMonster()->getPosition());
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/fire_particle_pilst.plist");
    int damage = BattleSystem::getInstance()->getPlayer()->getState()->GetAttack();
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(_pos);
    _particleAnimation->setStartColor(cocos2d::Color4F(1,0,0,1));
    _particleAnimation->setEndColor(cocos2d::Color4F(0.5f,0.225f,0.25f,1));
    _particleAnimation->setEndColorVar(cocos2d::Color4F(1,0,0,1));
    ResourceSystem::getInstance ()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes);
    float tagLength = sqrtf(powf(_pos.x-_endPos.x,2)+powf(_pos.y-_endPos.y,2));
    float time = tagLength / 800.0f;
    cocos2d::MoveTo* _aMoveTo = cocos2d::MoveTo::create(time, _endPos);
    AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_FIRE_FLY_01);
    cocos2d::CallFunc* _aCallback = cocos2d::CallFunc::create([=]
                                                              {
                                                                  _particleAnimation->setDuration(0.8f);
                                                                  _particleAnimation->setLife(0.5f);
                                                                  _particleAnimation->setLifeVar(0.5f);
                                                                  _particleAnimation->setSpeed(120.0f);
                                                                  _particleAnimation->setSpeedVar(80.0f);
                                                                  ResourceSystem::getInstance()->UpdateResourceBar(MONSTER,HEALTH, REDUCE, BattleSystem::getInstance()->getMonster()->GetRealDamage(damage));
                                                                  AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_FIRE_BOOM_01);
                                                              }
                                                              );
    cocos2d::Sequence* _aSeq = cocos2d::Sequence::create(_aMoveTo,_aCallback, NULL);
    _tag->addChild(_particleAnimation);
    _particleAnimation->runAction(_aSeq->clone());
    
    if((rand()%100)<rate_current)
    {
        AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_FIRE_FLY_01);
        rate_current = rate_static;
        _tag->scheduleOnce(std::bind([=]
                                 {
                                     cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/fire_particle_pilst.plist");
                                     _particleAnimation->setAutoRemoveOnFinish(true);
                                     _particleAnimation->setPosition(_pos);
                                     _particleAnimation->setStartColor(cocos2d::Color4F(1,0,0,1));
                                     _particleAnimation->setEndColor(cocos2d::Color4F(0.75f,0.5f,0.5f,1));
                                     _particleAnimation->setEndColorVar(cocos2d::Color4F(1,0,0,0.5f));
                                     //ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes);
                                     cocos2d::MoveTo* _aMoveTo = cocos2d::MoveTo::create(time, _endPos);
                                     cocos2d::CallFunc* _aCallback = cocos2d::CallFunc::create([=]
                                                                                               {
                                                                                                   _particleAnimation->setDuration(0.8f);
                                                                                                   _particleAnimation->setLife(0.5f);
                                                                                                   _particleAnimation->setLifeVar(0.5f);
                                                                                                   _particleAnimation->setSpeed(120.0f);
                                                                                                   _particleAnimation->setSpeedVar(80.0f);
                                                                                                   ResourceSystem::getInstance()->UpdateResourceBar(MONSTER,HEALTH, REDUCE, BattleSystem::getInstance()->getMonster()->GetRealDamage(damage));
                                                                                               }
                                                                                               );
                                     cocos2d::Sequence* _aSeq = cocos2d::Sequence::create(_aMoveTo,_aCallback, NULL);
                                     _tag->addChild(_particleAnimation);
                                     _particleAnimation->runAction(_aSeq->clone());
                                 }),0.4f ,"Fire_2");
    }
    else
    {
        rate_current += 20;
    }
    
    
    
    return true;
}