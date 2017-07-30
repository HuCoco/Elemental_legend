//
//  Thunder_1.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/7.
//
//

#include "Thunder_1.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"
#include "GameSystem.h"
#include "AttrSystem.h"
#include "GameConfigSystem.h"
Thunder_1::Thunder_1()
{
    _touchMax = 1;
    _NeedRes = 2;
    isCheck = false;
}



Thunder_1::~Thunder_1()
{
    
}

bool Thunder_1::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
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
    AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_THUNDER_01);
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/thunder_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(_pos);
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes);
    if(TouchTimes > 5)
    {
        TouchTimes = 5;
    }

    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER,BUFFTIME, ADD, AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_BUFFTIME)/6);
    GameConfigSystem::getInstance()->SetGameSpeed(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SPEED)+2);
    if(!isCheck)
    {
        isCheck = true;
        _tag->schedule(std::bind([=]
                                 {
                                     ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, BUFFTIME, REDUCE, 1);

                                     if(BattleSystem::getInstance()->getPlayer()->getState()->GetBT() <= 0)
                                     {
                                         isCheck = false;
                                         _tag->unschedule("ThunderCheck");
                                         GameConfigSystem::getInstance()->SetGameSpeed(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SPEED));
                                     }

                                 }), 1,"ThunderCheck");
    }
    _tag->addChild(_particleAnimation);
    return true;
}