
//
//  Fire_5.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#include "Fire_5.h"
#include "ResourceSystem.h"
#include <math.h>
#include "AttrSystem.h"
#include "BattleSystem.h"
Fire_5::Fire_5()
{
    _touchMax = 5;
    _NeedRes = 2;
}

Fire_5::~Fire_5()
{
    
}

bool Fire_5::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
{
    _NeedRes = AttrSystem::getInstance()->GetBaseAttr(ATTR_TYPE::ATTR_MAGIC)*0.01f * (1 - BattleSystem::getInstance()->getPlayer()->GetReduceMagic())* pow(1.2f, _num>5?5:_num);
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
    AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_FIRE_FLY_01);

    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes);
    int MonsterHpMax = BattleSystem::getInstance()->getMonster()->getState()->GetHpMax();
    int MonsterHpNow = BattleSystem::getInstance()->getMonster()->getState()->GetHP();
    float Hpodd = (float)MonsterHpNow/(float)MonsterHpMax;
    int damage;
    if(Hpodd > 0.5f)
    {
        damage = BattleSystem::getInstance()->getPlayer()->getState()->GetAttack();
        _particleAnimation->setStartColor(cocos2d::Color4F(0,1,0,1));
        _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0.5f,0,1));
        _particleAnimation->setEndColor(cocos2d::Color4F(0,0.5f,0,1));
        _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,1));
    }
    else if(Hpodd <= 0.5f)
    {
        damage = BattleSystem::getInstance()->getPlayer()->getState()->GetAttack()*2;
        ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, HEALTH, REDUCE,AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_HEALTH)*0.03 );
        _particleAnimation->setStartColor(cocos2d::Color4F(0,1,0,1));
        _particleAnimation->setStartColorVar(cocos2d::Color4F(1,0,0,1));
        _particleAnimation->setEndColor(cocos2d::Color4F(1,0,0,1));
        _particleAnimation->setEndColorVar(cocos2d::Color4F(1,0,0,1));
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
                                                                  ResourceSystem::getInstance()->UpdateResourceBar(MONSTER, HEALTH, REDUCE,  BattleSystem::getInstance()->getMonster()->GetRealDamage(damage));
                                                                  AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_FIRE_BOOM_01);
                                                              }
                                                              );
    cocos2d::Sequence* _aSeq = cocos2d::Sequence::create(_aMoveTo,_aCallback, NULL);
    _tag->addChild(_particleAnimation);
    _particleAnimation->runAction(_aSeq);
    return true;
}