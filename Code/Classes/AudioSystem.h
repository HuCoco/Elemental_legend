//
//  AudioSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#ifndef AudioSystem_h
#define AudioSystem_h

//
// 音乐文件
#define FIRE_FLY_01 "audio/element_firefly_sound_01.wav"
#define FIRE_BOOM_01 "audio/element_fireboom_sound_01.wav"
#define WATER_01 "audio/element_water_sound_01.wav"
#define WIND_01 "audio/element_wind_sound_01.wav"
#define THUNDER_01 "audio/element_thunder_sound_01.wav"
#define MONSTER_ATTACK_01 "audio/monster_attack_sound_01.wav"

//
//

#include <stdio.h>

enum MUSIC_SWITCH
{
    TURN_OFF,
    TURN_ON
};

enum EFFECT_AUDIO_LIST
{
    EFFECT_FIRE_FLY_01,
    EFFECT_FIRE_BOOM_01,
    EFFECT_THUNDER_01,
    EFFECT_WATER_01,
    EFFECT_WIND_01,
    EFFECT_MONSTER_ATTACK_01
    
};

class AudioSystem
{
private:
    AudioSystem();
    ~AudioSystem();
public:
    static AudioSystem* getInstance();
    void BackgroundMusicSwitch(MUSIC_SWITCH _switch);
    void EffectiveMusicSwitch(MUSIC_SWITCH _switch);
    void SetEMusicVolume(float);
    float GetEMusicVolume();
    void SetBMusicVolume(float);
    float GetBMusicVolume();
public:
    void PlayEffectAudio(EFFECT_AUDIO_LIST);
public:
    inline bool GetBMSwitch(){return _bmSwitch;}
    inline bool GetEMSwitch(){return _emSwitch;}
    inline void MusicOn(){isOn = true;}
private:
    static AudioSystem* _instance;
    bool _bmSwitch;
    bool _emSwitch;
    bool isOn;
};


#endif /* AudioSystem_h */
