//
//  Thunder_5.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#include "Thunder_5.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"
#include "GameSystem.h"
#include "AttrSystem.h"
Thunder_5::Thunder_5()
{
    _touchMax = 1;
    _NeedRes = 2;
    isCheck = false;
}



Thunder_5::~Thunder_5()
{
    
}

bool Thunder_5::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
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
    AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_THUNDER_01);
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/thunder_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setStartColor(cocos2d::Color4F(1,1,1,1));
    _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0,0,0));
    _particleAnimation->setEndColor(cocos2d::Color4F(0,0.5f,1,1));
    _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,0));
    _particleAnimation->setPosition(_pos);
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes);
    if(TouchTimes > 5)
    {
        TouchTimes = 5;
    }
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER,BUFFTIME, ADD, AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_BUFFTIME)*_num/6);
    if(!isCheck)
    {
        GameSystem::getInsatance()->SetLifeState(true);
        isCheck = true;
        _tag->schedule(std::bind([=]
                                 {
                                     ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, BUFFTIME, REDUCE, 1);
                                     
                                     if(BattleSystem::getInstance()->getPlayer()->getState()->GetBT() <= 0)
                                     {
                                         isCheck = false;
                                         _tag->unschedule("ThunderCheck");
                                         GameSystem::getInsatance()->SetLifeState(false);
                                     }
                                     
                                 }), 1,"ThunderCheck");
    }
    _tag->addChild(_particleAnimation);
    return true;
}