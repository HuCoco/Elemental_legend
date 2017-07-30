//
//  ExperienceSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/21.
//
//

#include "ExperienceSystem.h"
#include "XMLParser.h"
#include "CsvParser.h"
ExperienceSystem* ExperienceSystem::_instance = nullptr;

ExperienceSystem::ExperienceSystem()
{
    UpdateData();
}

ExperienceSystem::~ExperienceSystem()
{
    
}

ExperienceSystem* ExperienceSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new ExperienceSystem;
    }
    return _instance;
}

void ExperienceSystem::UpdateData()
{
    
    NowExp = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::EXP);
    MaxExp = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::LEVEL);
    if(MaxExp > 10)
    {
        MaxExp = 10;
    }
}

bool ExperienceSystem::AddExp()
{
    ++NowExp;
    if(NowExp == MaxExp)
    {
        Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::LEVEL, Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::LEVEL)+1);
        NowExp = 0;
        Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::EXP, NowExp);
        UpdateData();
        return true;
    }
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::EXP, NowExp);
    UpdateData();
    return false;
}


