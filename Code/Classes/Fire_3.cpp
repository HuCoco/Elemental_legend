//
//  Fire_3.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/5.
//
//

#include "Fire_3.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"
#include "AttrSystem.h"
Fire_3::Fire_3()
{
    _touchMax = 5;
    _NeedRes = 2;
}

Fire_3::~Fire_3()
{
    
}

bool Fire_3::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
{
    _NeedRes = AttrSystem::getInstance()->GetBaseAttr(ATTR_TYPE::ATTR_MAGIC)*0.03f * (1 - BattleSystem::getInstance()->getPlayer()->GetReduceMagic());
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
    _particleAnimation->setStartColor(cocos2d::Color4F(1,0.675f,0,1));
    _particleAnimation->setEndColor(cocos2d::Color4F(1,1,0.5f,1));
    _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,1.0f));
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes);
    AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_FIRE_FLY_01);
    int damage = BattleSystem::getInstance()->getMonster()->GetRealDamage(BattleSystem::getInstance()->getPlayer()->getState()->GetAttack());
    if(TouchTimes%3 == 0 && TouchTimes != 0)
    {
        damage += BattleSystem::getInstance()->getMonster()->getState()->GetHP()*0.03f;
        _particleAnimation->setStartColor(cocos2d::Color4F(1,0,1,1));
        _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0.5,0,1));
        _particleAnimation->setEndColor(cocos2d::Color4F(1,0,0,1));
        _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,1.0f));
    }
    float tagLength = sqrtf(powf(_pos.x-_endPos.x,2)+powf(_pos.y-_endPos.y,2));
    float time = tagLength / 800.0f;
    cocos2d::MoveTo* _aMoveTo = cocos2d::MoveTo::create(time, _endPos);
    cocos2d::CallFunc* _aCallback = cocos2d::CallFunc::create([=]
                                                              {
                                                                  _particleAnimation->setDuration(1.2f);
                                                                  _particleAnimation->setLife(1.0F);
                                                                  _particleAnimation->setLifeVar(1.0f);
                                                                  _particleAnimation->setSpeed(120.0f);
                                                                  _particleAnimation->setSpeedVar(80.0f);
                                                                  _particleAnimation->setRadialAccel(0.0f);
                                                                  _particleAnimation->setRadialAccel(0.0f);
                                                                  ResourceSystem::getInstance()->UpdateResourceBar(MONSTER, HEALTH, REDUCE, damage);
                                                                  AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_FIRE_BOOM_01);
                                                              }
                                                              );
    cocos2d::Sequence* _aSeq = cocos2d::Sequence::create(_aMoveTo,_aCallback, NULL);
    _tag->addChild(_particleAnimation);
    _particleAnimation->runAction(_aSeq);
    return true;
}