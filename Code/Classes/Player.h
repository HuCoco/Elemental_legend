//
//  Player.h
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include "cocos2d.h"
#include "BaseRole.h"
#include "SkillManager.h"

enum PLAYER_SKILL_NO
{
    SN_FIRE,
    SN_THUNDER,
    SN_WIND,
    SN_WATER,
    SN_MAGIC
};


class Player
:public BaseRole
{
private:
    Player();
    ~Player();
public:
    static Player* create(ROLE_STATE,bool _isGuide = false);
    virtual bool init(ROLE_STATE,bool _isGuide = false);
    bool SelectSkill(PLAYER_SKILL_NO _sno,cocos2d::Layer* _tag,cocos2d::Vec2 _pos,int& _num);
    int getTouchMax(PLAYER_SKILL_NO _sno);
public:
    inline int GetReduceElement(){return ReduceCastElement;}
    inline void SetReduceElement(int _data){ReduceCastElement = _data;}
    inline float GetReduceMagic(){return ReduceCastMagic;}
    inline void SetReduceMagic(float _data){ReduceCastMagic = _data;}
private:
    int ReduceCastElement;
    float ReduceCastMagic;

};
#endif /* Player_h */
