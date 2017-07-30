//
//  RecordSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/20.
//
//

#include "RecordSystem.h"
#include "XMLParser.h"
RecordSystem* RecordSystem::_instance = nullptr;

RecordSystem::RecordSystem()
{
    MainRecordData = new RecordData;
    ThisGameRcordData = new RecordData;
    ReadMainData();
    ThisGameRcordData->init();
}


RecordSystem::~RecordSystem()
{
    delete  MainRecordData;
    delete ThisGameRcordData;
}

RecordSystem* RecordSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new RecordSystem;
    }
    return _instance;
}

void RecordSystem::ReadMainData()
{
    MainRecordData->init(Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COST_FIRE),
                         Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COST_WIND),
                         Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COST_WATER),
                         Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COST_THUNDER),
                         Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COST_MAGIC));
}

void RecordSystem::SaveMainData()
{
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COST_FIRE, MainRecordData->CostFire);
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COST_WIND, MainRecordData->CostWind);
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COST_WATER, MainRecordData->CostWater);
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COST_THUNDER, MainRecordData->CostThunder);
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COST_MAGIC, MainRecordData->CostMagic);
    
}

void RecordSystem::AddAllDataToMainData()
{
    MainRecordData->AddToMainData(ThisGameRcordData);
}

void RecordSystem::AddData(ELEMENT_TYPE _type)
{
    switch (_type) {
        case ET_FIRE:
            ThisGameRcordData->AddFire();
            break;
        case ET_WIND:
            ThisGameRcordData->AddWind();
            break;
        case ET_WATER:
            ThisGameRcordData->AddWater();
            break;
        case ET_THUNDER:
            ThisGameRcordData->AddThunder();
            break;
        case ET_MAGIC:
            ThisGameRcordData->AddMagic();
            break;
        default:
            break;
    }
}

int RecordSystem::GetMainRecord(ELEMENT_TYPE _type)
{
    int pRet = 0;
    switch (_type) {
        case ET_FIRE:
            pRet = MainRecordData->CostFire;
            break;
        case ET_WIND:
            pRet = MainRecordData->CostWind;
            break;
        case ET_WATER:
            pRet = MainRecordData->CostWater;
            break;
        case ET_THUNDER:
            pRet = MainRecordData->CostThunder;
            break;
        case ET_MAGIC:
            pRet = MainRecordData->CostMagic;
            break;
        default:
            break;
    }
    return pRet;
}

int RecordSystem::GetThisGameRecord(ELEMENT_TYPE _type)
{
    int pRet = 0;
    switch (_type) {
        case ET_FIRE:
            pRet = ThisGameRcordData->CostFire;
            break;
        case ET_WIND:
            pRet = ThisGameRcordData->CostWind;
            break;
        case ET_WATER:
            pRet = ThisGameRcordData->CostWater;
            break;
        case ET_THUNDER:
            pRet = ThisGameRcordData->CostThunder;
            break;
        case ET_MAGIC:
            pRet = ThisGameRcordData->CostMagic;
            break;
        default:
            break;
    }
    return pRet;
}