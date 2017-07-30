//
//  Wind_2.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#include "Wind_2.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"
#include "AttrSystem.h"
Wind_2::Wind_2()
{
    _touchMax = 1;
    _NeedRes = 2;
}



Wind_2::~Wind_2()
{
    
}

bool Wind_2::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
{
    _NeedRes = AttrSystem::getInstance()->GetBaseAttr(ATTR_TYPE::ATTR_MAGIC)*0.01f * (1 - BattleSystem::getInstance()->getPlayer()->GetReduceMagic());
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
    AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_WIND_01);
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/wind_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(_pos);
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes);
    if(TouchTimes > 5)
    {
        TouchTimes = 5;
    }
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER,SHEILD, ADD, AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SHIELD)*TouchTimes/15);

                            
    _tag->addChild(_particleAnimation);
    return true;
} 