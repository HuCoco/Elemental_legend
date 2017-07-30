//
//  Water_2.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#include "Water_2.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"
#include "AttrSystem.h"
Water_2::Water_2()
{
    _touchMax = 1;
    _NeedRes = 2;
}



Water_2::~Water_2()
{
    
}

bool Water_2::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
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
    AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_WATER_01);
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/water_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(_pos);
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes);
    float odd = (float)BattleSystem::getInstance()->getPlayer()->getState()->GetHP() / (float)BattleSystem::getInstance()->getPlayer()->getState()->GetHpMax();
    int ReHp = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REHP) *(2.0f - odd);
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER,HEALTH, ADD, ReHp);
    _tag->addChild(_particleAnimation);
    return true;
}