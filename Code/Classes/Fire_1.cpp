//
//  Fire_1.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/4.
//
//

#include "Fire_1.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"
#include "AttrSystem.h"
Fire_1::Fire_1()
{
    _touchMax = 1;
    _NeedRes = 0;
}



Fire_1::~Fire_1()
{
    
}

bool Fire_1::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
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
    cocos2d::Vec2 _endPos = BattleSystem::getInstance()->getMonster()->getPosition();
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/fire_particle_pilst.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(_pos);
    float tagLength = sqrtf(powf(_pos.x-_endPos.x,2)+powf(_pos.y-_endPos.y,2));
    float time = tagLength / 800.0f;
    cocos2d::MoveTo* _aMoveTo = cocos2d::MoveTo::create(time, _endPos);
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes);
    AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_FIRE_FLY_01);
    int damage = BattleSystem::getInstance()->getPlayer()->getState()->GetAttack();
    cocos2d::CallFunc* _aCallback = cocos2d::CallFunc::create([=]
                                                              {
                                                                  _particleAnimation->setDuration(0.8f);
                                                                  _particleAnimation->setLife(0.5f);
                                                                  _particleAnimation->setLifeVar(1.0f);
                                                                  _particleAnimation->setSpeed(120.0f);
                                                                  _particleAnimation->setSpeedVar(80.0f);
                                                                  _particleAnimation->setRadialAccel(0.0f);
                                                                  _particleAnimation->setRadialAccel(0.0f);
                                                                  ResourceSystem::getInstance()->UpdateResourceBar(MONSTER,HEALTH, REDUCE,BattleSystem::getInstance()->getMonster()->GetRealDamage(damage));
                                                                  AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_FIRE_BOOM_01);
                                                              }
                                                              );
    cocos2d::Sequence* _aSeq = cocos2d::Sequence::create(_aMoveTo,_aCallback, NULL);
    _tag->addChild(_particleAnimation);
    _particleAnimation->runAction(_aSeq);
    return true;
}

