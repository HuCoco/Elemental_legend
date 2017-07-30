//
//  BattleSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#include "BattleSystem.h"
#include "XMLParser.h"
#include "JsonParser.h"
#include "AttrSystem.h"
#include "DynamicAttrSystem.h"
BattleSystem* BattleSystem::_instance = nullptr;
BattleSystem::BattleSystem()
{
    
}

BattleSystem::~BattleSystem()
{
    
}

bool BattleSystem::init(int _gate)
{
    //PLAYER
    AttrSystem::getInstance()->Update();
    ROLE_STATE _RoleData;
    _RoleData.Level = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::LEVEL);
    _RoleData.HealthPoint_Max = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_HEALTH);
    _RoleData.MagicPoint_Max = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_MAGIC);
    _RoleData.BuffTime_Max = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_BUFFTIME);
    _RoleData.ShieldValue_Max = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SHIELD);
    _RoleData.AttackValue = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_ATK);
    _RoleData.DefenceValue = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_DEF);
    _RoleData.RecoverHealthPointPerSecond = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REHP);
    _RoleData.RecoverMagicPointPerSecond = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REMP);
    _brPlayer = Player::create(_RoleData);
    //MONSTER
    DynamicAttrSystem::getInstance()->upDateMonster(_gate);
    ROLE_STATE _MonsterData;
    _MonsterData.Level = 0;
    _MonsterData.HealthPoint_Max = DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_HEALTH, _RoleData.Level);
    _MonsterData.MagicPoint_Max = 0;
    _MonsterData.BuffTime_Max = 0;
    _MonsterData.ShieldValue_Max = 0;
    _MonsterData.AttackValue = DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_AKT, _RoleData.Level);
    _MonsterData.DefenceValue = DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_DEF, _RoleData.Level);
    _MonsterData.RecoverHealthPointPerSecond = 0;
    _MonsterData.RecoverMagicPointPerSecond = 0;
    int Type = DynamicAttrSystem::getInstance()->GetMonsterType();
    _brMonster = Monster::create(_MonsterData,Type);
    _brMonster->setAttackSpeed(DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_SPEED, _RoleData.Level));
    
    return true;
}

bool BattleSystem::GuideInit()
{
    //PLAYER
    //AttrSystem::getInstance()->Update();
    ROLE_STATE _RoleData;
    _RoleData.Level = 1;
    _RoleData.HealthPoint_Max = 100;
    _RoleData.MagicPoint_Max = 200;
    _RoleData.BuffTime_Max = 10;
    _RoleData.ShieldValue_Max = 50;
    _RoleData.AttackValue = 20;
    _RoleData.DefenceValue = 30;
    _RoleData.RecoverHealthPointPerSecond = 3;
    _RoleData.RecoverMagicPointPerSecond = 3;
    _brPlayer = Player::create(_RoleData,true);
    //MONSTER
    ROLE_STATE _MonsterData;
    _MonsterData.Level = 1;
    _MonsterData.HealthPoint_Max = 400;
    _MonsterData.MagicPoint_Max = 0;
    _MonsterData.BuffTime_Max = 0;
    _MonsterData.ShieldValue_Max = 0;
    _MonsterData.AttackValue = 5;
    _MonsterData.DefenceValue = 10;
    _MonsterData.RecoverHealthPointPerSecond = 0;
    _MonsterData.RecoverMagicPointPerSecond = 0;
    
    _brMonster = Monster::create(_MonsterData,0,true);
    _brMonster->setAttackSpeed(2);
    
    return true;
}


bool BattleSystem::TrailInit()
{
    //PLAYER
    AttrSystem::getInstance()->Update();
    ROLE_STATE _RoleData;
    _RoleData.Level = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::LEVEL);
    _RoleData.HealthPoint_Max = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_HEALTH);
    _RoleData.MagicPoint_Max = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_MAGIC);
    _RoleData.BuffTime_Max = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_BUFFTIME);
    _RoleData.ShieldValue_Max = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SHIELD);
    _RoleData.AttackValue = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_ATK);
    _RoleData.DefenceValue = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_DEF);
    _RoleData.RecoverHealthPointPerSecond = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REHP);
    _RoleData.RecoverMagicPointPerSecond = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REMP);
    _brPlayer = Player::create(_RoleData);
    //MONSTER
    
    int level = Parser::XML::getInstance()->GetTrailTop();
    DynamicAttrSystem::getInstance()->upDataMonsterInTrail();
    ROLE_STATE _MonsterData;
    _MonsterData.Level = 0;
    _MonsterData.HealthPoint_Max = DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_HEALTH,level);
    _MonsterData.MagicPoint_Max = 0;
    _MonsterData.BuffTime_Max = 0;
    _MonsterData.ShieldValue_Max = 0;
    _MonsterData.AttackValue = DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_AKT,level);
    _MonsterData.DefenceValue = DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_DEF,level);
    _MonsterData.RecoverHealthPointPerSecond = 0;
    _MonsterData.RecoverMagicPointPerSecond = 0;
    int Type = DynamicAttrSystem::getInstance()->GetMonsterType();
    _brMonster = Monster::Trailcreate(_MonsterData, Type);
    _brMonster->setAttackSpeed(DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_SPEED,level));
    
    return true;
}

int BattleSystem::getTouchMax(PLAYER_SKILL_NO _sno)
{
    return _brPlayer->getTouchMax(_sno);
}

bool BattleSystem::PlayerCastSkill(PLAYER_SKILL_NO _sno, cocos2d::Layer *_tag, cocos2d::Vec2 _pos, int& _num)
{
    return _brPlayer->SelectSkill(_sno,_tag,_pos,_num);
}

void BattleSystem::MonsterCastSkill(MONSTER_SKILL_NO _sno,cocos2d::Layer* _tag)
{
    _brMonster->Cast(_tag);
}

BattleSystem* BattleSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new BattleSystem;
    }
    return _instance;
}