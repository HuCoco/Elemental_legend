//
//  AudioSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#include "AudioSystem.h"
#include "XMLParser.h"
#include <SimpleAudioEngine.h>

AudioSystem* AudioSystem::_instance = nullptr;

AudioSystem::AudioSystem()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(FIRE_FLY_01);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(FIRE_BOOM_01);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(WATER_01);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(THUNDER_01);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(WIND_01);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(MONSTER_ATTACK_01);
    _emSwitch = Parser::XML::getInstance()->GetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::EM_SWITCH);
    _bmSwitch = Parser::XML::getInstance()->GetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::BM_SWITCH);
    isOn = false;
    
}

AudioSystem::~AudioSystem()
{
    
}

AudioSystem* AudioSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new AudioSystem;
    }
    return _instance;
}

void AudioSystem::BackgroundMusicSwitch(MUSIC_SWITCH _switch)
{
    if(!isOn)
    {
        return;
    }
    if(_switch == TURN_OFF)
    {
        _bmSwitch = false;
        Parser::XML::getInstance()->SetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::BM_SWITCH, 0.0f);
    }
    else if(_switch == TURN_ON)
    {
        _bmSwitch = true;
        Parser::XML::getInstance()->SetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::BM_SWITCH, 1.0f);
    }
}

void AudioSystem::EffectiveMusicSwitch(MUSIC_SWITCH _switch)
{
    
    if(!isOn)
    {
        return;
    }
    if(_switch == TURN_OFF)
    {
        _emSwitch = false;
        Parser::XML::getInstance()->SetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::EM_SWITCH, 0.0f);
    }
    else if(_switch == TURN_ON)
    {
        _emSwitch = true;
        Parser::XML::getInstance()->SetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::EM_SWITCH, 0.0f);
    }
}


void AudioSystem::SetBMusicVolume(float _value)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(_value);
    Parser::XML::getInstance()->SetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::BGM_VOLUME, _value);
}

float AudioSystem::GetBMusicVolume()
{
    return CocosDenshion::SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
}

void AudioSystem::SetEMusicVolume(float _value)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(_value);
    Parser::XML::getInstance()->SetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::EM_VOLUME, _value);
}

float AudioSystem::GetEMusicVolume()
{
    return CocosDenshion::SimpleAudioEngine::getInstance()->getEffectsVolume();
}

void AudioSystem::PlayEffectAudio(EFFECT_AUDIO_LIST _list)
{
    switch (_list) {
        case EFFECT_FIRE_FLY_01:
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(FIRE_FLY_01);
            break;
        case EFFECT_FIRE_BOOM_01:
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(FIRE_BOOM_01);
            break;
        case EFFECT_THUNDER_01:
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(THUNDER_01);
            break;
        case EFFECT_WATER_01:
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(WATER_01);
            break;
        case EFFECT_WIND_01:
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(WIND_01);
            break;
        case EFFECT_MONSTER_ATTACK_01:
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(MONSTER_ATTACK_01);
            break;

        default:
            break;
    }
}

