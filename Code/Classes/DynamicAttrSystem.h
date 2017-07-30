//
//  DynamicAttrSystem.h
//  NewGame
//
//  Created by 胡可 on 15/11/15.
//
//

#ifndef DynamicAttrSystem_h
#define DynamicAttrSystem_h

#include <stdio.h>
#include "JsonParser.h"
enum DYNAMIC_MONSTER_ATTR_LIST
{
    DYN_MONSTER_HEALTH,
    DYN_MONSTER_AKT,
    DYN_MONSTER_SPEED,
    DYN_MONSTER_DEF
};

enum MONSTER_AFFIX_LIST
{
    MONSTER_ATK_AFFIX,
    MONSTER_DEF_AFFIX,
    MONSTER_SPE_AFFIX_1,
    MONSTER_SPE_AFFIX_2,
    MONSTER_SPE_AFFIX_3
};



class DynamicAttrSystem
{
private:
    DynamicAttrSystem();
    ~DynamicAttrSystem();
public:
    static DynamicAttrSystem* getInstance();
    int getMonsterAffixSkill(MONSTER_AFFIX_LIST);
    void upDateMonster(int _gate);
    void upDataMonsterInTrail();
    int GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST,int);
    int GetMonsterType();
    std::string getMonsterName(){return _mData->Name;}
    std::string getMonsterInfo(){return _mData->Info;}
private:
    static DynamicAttrSystem* _instance;
    GATE_MONSTER_DATA* _mData;
    int level;
};

#endif /* DynamicAttrSystem_h */
