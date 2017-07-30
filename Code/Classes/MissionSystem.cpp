//
//  MissionSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/22.
//
//

#include "MissionSystem.h"
#include "BaseMissionBar.h"
#include "XMLParser.h"
#include "JsonParser.h"
MissionSystem* MissionSystem::_instance = nullptr;

MissionSystem::MissionSystem()
{
    Read();
}

MissionSystem::~MissionSystem()
{
    
}

MissionSystem* MissionSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new MissionSystem;
    }
    return _instance;
}

void MissionSystem::Read()
{
    std::vector<MISSION_DATA>* MissionVector = JsonParser::getInstance()->GetMissionData();
    for(int i = 0 ; i < 3 ; i++)
    {
        _MissionArray[i]._MissionType = (MISSION_TYPE)Parser::XML::getInstance()->GetMission((Parser::MISSION_DATA_TYPE)i);
        _MissionArray[i]._MissionValue = Parser::XML::getInstance()->GetMissionValue((Parser::MISSION_DATA_TYPE)i);
        if(_MissionArray[i]._MissionType == MISSION_TYPE::NO_MISSION)
        {
            _MissionArray[i]._MissionCompletedValue = 0;
        }
        else
        {
            _MissionArray[i]._MissionCompletedValue = MissionVector->at((int)(_MissionArray[i]._MissionType)-1).Tag;
        }
    }
}

void MissionSystem::Update(MISSION_TYPE _type,int _addValue)
{
    for(int i = 0 ; i < 3 ; i++)
    {
        if(_MissionArray[i]._MissionType == _type)
        {
            _MissionArray[i]._MissionValue += _addValue;
            Parser::XML::getInstance()->SetMissionValue((Parser::MISSION_DATA_TYPE)i, _MissionArray[i]._MissionValue);
        }
    }
}

void MissionSystem::isCompletedMission()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        if(_MissionArray[i]._MissionType == MISSION_TYPE::NO_MISSION)
        {
            continue;
        }
        else
        {
            if(_MissionArray[i]._MissionValue >= _MissionArray[i]._MissionCompletedValue)
            {
                std::vector<MISSION_DATA>* MissionVector = JsonParser::getInstance()->GetMissionData();
                std::string Cur = MissionVector->at(i).Cur;
                int curValue = MissionVector->at(i).Value;
                if(Cur == "C")
                {
                    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COIN, Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COIN)+curValue);
                }
                else if(Cur == "D")
                {
                    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::DIAMONDS,Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::DIAMONDS)+ curValue);
                }
                
                Parser::XML::getInstance()->SetMission((Parser::MISSION_DATA_TYPE)i, MISSION_TYPE::NO_MISSION);
                Parser::XML::getInstance()->SetMissionValue((Parser::MISSION_DATA_TYPE)i, 0);
            }
        }
    }
    Read();
}

bool MissionSystem::GetNewMission()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        if(_MissionArray[i]._MissionType == MISSION_TYPE::NO_MISSION)
        {
            MISSION_TYPE Random = (MISSION_TYPE)(rand()%4+1);
            Parser::XML::getInstance()->SetMission((Parser::MISSION_DATA_TYPE)i, Random);
            Parser::XML::getInstance()->SetMissionValue((Parser::MISSION_DATA_TYPE)i, 0);
            Read();
            return true;
        }
    }
    return false;
}

