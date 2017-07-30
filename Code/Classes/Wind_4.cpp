//
//  Wind_4.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#include "Wind_4.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"
#include "AttrSystem.h"
bool Wind_4::isCheck = false;

Wind_4::Wind_4()
{
    _touchMax = 1;
    _NeedRes = 2;
}



Wind_4::~Wind_4()
{
    
}

bool Wind_4::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
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
    AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_WIND_01);
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/wind_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setStartColor(cocos2d::Color4F(1,0,0,1));
    _particleAnimation->setStartColorVar(cocos2d::Color4F(0,0,0,0));
    _particleAnimation->setEndColor(cocos2d::Color4F(1,0.5f,0,1));
    _particleAnimation->setEndColorVar(cocos2d::Color4F(0,0,0,0));
    _particleAnimation->setPosition(_pos);
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes  );
    if(TouchTimes > 5)
    {
        TouchTimes = 5;
    }
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER,SHEILD, ADD, AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SHIELD)*TouchTimes/20);
    //atk = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_ATK);
    if(isCheck == false)
    {
        isCheck = true;
        BattleSystem::getInstance()->getPlayer()->getState()->UpdateAttack(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_ATK)*0.3f);
        _tag->schedule(std::bind([=]
                             {
                                 if(BattleSystem::getInstance()->getPlayer()->getState()->GetSV()<=0)
                                 {
                                     BattleSystem::getInstance()->getPlayer()->getState()->UpdateAttack(-AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_ATK)*0.3f);
                                     isCheck = false;
                                     _tag->unschedule("Wind_4");
                                 }
                             }),"Wind_4");
    }
    _tag->addChild(_particleAnimation);
    return true;
}