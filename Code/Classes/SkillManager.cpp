//
//  SkillManager.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/26.
//
//

#include "SkillManager.h"
#include "SkillFactory.h"
#include "GameSystem.h"
#include "XMLParser.h"
#include "JsonParser.h"
#include "TrailSystem.h"
#include "Fire_1.h"
#include "BattleSystem.h"
SkillManager::SkillManager()
{
    
}

SkillManager::~SkillManager()
{
    
}

SkillManager* SkillManager::create(ROLE_TYPE _type,bool _isGuide)
{
    SkillManager* pRet = new SkillManager;
    if(_isGuide == false)
    {
        if(pRet && pRet->init(_type))
        {
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }
    else
    {
        if(pRet && pRet->GuideInit(_type))
        {
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }
}

SkillManager* SkillManager::Trailcreate(ROLE_TYPE _type)
{
    SkillManager* pRet = new SkillManager;
    if(pRet && pRet->Trailinit(_type))
    {
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool SkillManager::Trailinit(ROLE_TYPE _type)
{
    if(_type == ROLE_TYPE::MONSTER)
    {
        int _gate = TrialSystem::getInstance()->getGate();
        GATE_MONSTER_DATA* _gmData = JsonParser::getInstance()->GetTrailData(_gate);
        
        //ATTACK
        int _attack_no = _gmData->ATKNUM;
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_ATTACK, _attack_no));
        //DEFENCE
        int _defence_no = _gmData->DEFNUM;
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_DEFENCE, _defence_no));
        //SPECIAL
        int _special_no1 = _gmData->SPENUM1;
        if(_special_no1 != 0)
        {
            SkillPool.push_back(SkillFactory::getInstance()->create(ST_SPECIAL, _special_no1));
        }
        
        
        int _special_no2 = _gmData->SPENUM2;
        if(_special_no2 != 0)
        {
            SkillPool.push_back(SkillFactory::getInstance()->create(ST_SPECIAL, _special_no2));
        }
        
        
        int _special_no3 = _gmData->SPENUM3;
        if(_special_no3 != 0)
        {
            SkillPool.push_back(SkillFactory::getInstance()->create(ST_SPECIAL, _special_no3));
        }
        return true;
    }
    return false;
}

bool SkillManager::init(ROLE_TYPE _type)
{
    if(_type == ROLE_TYPE::PLAYER)
    {
        //FIRE
        int _fire_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_FIRE);
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_FIRE, _fire_no));
        //THUNDER
        int _thunder_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_THUNDER);
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_THUNDER, _thunder_no));
        //WIND
        int _wind_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_WIND);
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_WIND, _wind_no));
        //WATER
        int _water_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_WATER);
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_WATER, _water_no));
        //MAGIC
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_MAGIC,0));
        return true;
    }
    else if(_type == ROLE_TYPE::MONSTER)
    {
        int _gate = GameSystem::getInsatance()->getGate();
        int chapter = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::CHAPTER_NOW);
        GATE_MONSTER_DATA* _gmData = JsonParser::getInstance()->GetMonsterData(chapter,_gate);
        
        //ATTACK
        int _attack_no = _gmData->ATKNUM;
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_ATTACK, _attack_no));
        //DEFENCE
        int _defence_no = _gmData->DEFNUM;
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_DEFENCE, _defence_no));
        //SPECIAL
        int _special_no1 = _gmData->SPENUM1;
        if(_special_no1 != 0)
        {
            SkillPool.push_back(SkillFactory::getInstance()->create(ST_SPECIAL, _special_no1));
        }
        
        
        int _special_no2 = _gmData->SPENUM2;
        if(_special_no2 != 0)
        {
            SkillPool.push_back(SkillFactory::getInstance()->create(ST_SPECIAL, _special_no2));
        }
        
        
        int _special_no3 = _gmData->SPENUM3;
        if(_special_no3 != 0)
        {
            SkillPool.push_back(SkillFactory::getInstance()->create(ST_SPECIAL, _special_no3));
        }
        return true;
    }
    return false;
}

bool SkillManager::GuideInit(ROLE_TYPE _type)
{
    if(_type == ROLE_TYPE::PLAYER)
    {
        //FIRE
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_FIRE, 1));
        //THUNDER
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_THUNDER, 1));
        //WIND
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_WIND, 1));
        //WATER
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_WATER, 1));
        //MAGIC
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_MAGIC,0));
        return true;
    }
    else if(_type == ROLE_TYPE::MONSTER)
    {
        //ATTACK
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_ATTACK, 1));
        //DEFENCE
        SkillPool.push_back(SkillFactory::getInstance()->create(ST_DEFENCE, 1));
        return true;
    }
    return false;
}


BaseSkill* SkillManager::SelectSkill(int _no)
{
    return SkillPool.at(_no);
}