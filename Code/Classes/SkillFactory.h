//
//  SkillFactory.h
//  NewGame
//
//  Created by 胡可 on 15/10/4.
//
//

#ifndef SkillFactory_h
#define SkillFactory_h

#include <stdio.h>
#include "BaseSkill.h"
enum SKILL_PLAYER_TYPE
{
    ST_FIRE,
    ST_WIND,
    ST_WATER,
    ST_THUNDER,
    ST_MAGIC
};

enum SKILL_MONSTER_TYPE
{
    ST_ATTACK,
    ST_DEFENCE,
    ST_SPECIAL
};

class SkillFactory
{
private:
    SkillFactory();
    ~SkillFactory();
public:
    static SkillFactory* getInstance();
    BaseSkill* create(SKILL_PLAYER_TYPE,int);
    BaseSkill* create(SKILL_MONSTER_TYPE,int);
private:
    static SkillFactory* _instance;
};

#endif /* SkillFactory_h */
