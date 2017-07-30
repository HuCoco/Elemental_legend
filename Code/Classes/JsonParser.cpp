//
//  JsonParser.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/10.
//
//

#include "JsonParser.h"
#include "cocos2d.h"
JsonParser* JsonParser::_instance = nullptr;

JsonParser::JsonParser()
{
    
}

JsonParser::~JsonParser()
{
    
}

JsonParser* JsonParser::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new JsonParser;
    }
    return _instance;
}

std::vector<CHAPTER_INFO_DATA>* JsonParser::GetChapterData()
{
    std::string path = cocos2d::FileUtils::getInstance()->getStringFromFile(CHAPTER_JSON);
    //CCLOG("%s",path.c_str());
    
    rapidjson::Document d;
    
    d.Parse<rapidjson::kParseDefaultFlags>(path.c_str());
    
    if (d.HasParseError()) {
        CCLOG("GetParseError %s\n",d.GetParseError());
        return nullptr;
    }
    
    std::vector<CHAPTER_INFO_DATA>* pRet = new std::vector<CHAPTER_INFO_DATA>;
    
    if(d.IsObject())
    {
        if(d.HasMember(CHAPTER_1))
        {
            if(d[CHAPTER_1].IsObject())
            {
                rapidjson::Value& object = d[CHAPTER_1];
                CHAPTER_INFO_DATA data;
                data.ChapterTitle = object[CHAPTER_TITLE].GetString();
                data.ChapterInfo = object[CHAPTER_INFO].GetString();
                pRet->push_back(data);
            }
        }
        if(d.HasMember(CHAPTER_2))
        {
            if(d[CHAPTER_2].IsObject())
            {
                rapidjson::Value& object = d[CHAPTER_2];
                CHAPTER_INFO_DATA data;
                data.ChapterTitle = object[CHAPTER_TITLE].GetString();
                data.ChapterInfo = object[CHAPTER_INFO].GetString();
                pRet->push_back(data);
            }
        }
        if(d.HasMember(CHAPTER_3))
        {
            if(d[CHAPTER_3].IsObject())
            {
                rapidjson::Value& object = d[CHAPTER_3];
                CHAPTER_INFO_DATA data;
                data.ChapterTitle = object[CHAPTER_TITLE].GetString();
                data.ChapterInfo = object[CHAPTER_INFO].GetString();
                pRet->push_back(data);
            }
        }
        if(d.HasMember(CHAPTER_4))
        {
            if(d[CHAPTER_4].IsObject())
            {
                rapidjson::Value& object = d[CHAPTER_4];
                CHAPTER_INFO_DATA data;
                data.ChapterTitle = object[CHAPTER_TITLE].GetString();
                data.ChapterInfo = object[CHAPTER_INFO].GetString();
                pRet->push_back(data);
            }
        }
        if(d.HasMember(CHAPTER_5))
        {
            if(d[CHAPTER_5].IsObject())
            {
                rapidjson::Value& object = d[CHAPTER_5];
                CHAPTER_INFO_DATA data;
                data.ChapterTitle = object[CHAPTER_TITLE].GetString();
                data.ChapterInfo = object[CHAPTER_INFO].GetString();
                pRet->push_back(data);
            }
        }
        return pRet;
    }
    
    return nullptr;
}


std::vector<GATE_POS_DATA>* JsonParser::GetGatePosData(int _gate)
{
    std::string file;
    if(_gate == 1)
    {
        file = MAP_1_GATE_POS_JSON;
    }
    else if(_gate == 2)
    {
        file = MAP_2_GATE_POS_JSON;
    }
    std::string path = cocos2d::FileUtils::getInstance()->getStringFromFile(file);
    
    //CCLOG("%s",path.c_str());
    
    rapidjson::Document d;
    
    d.Parse<rapidjson::kParseDefaultFlags>(path.c_str());
    
    if (d.HasParseError()) {
        CCLOG("GetParseError %s\n",d.GetParseError());
        return nullptr;
    }
    
    std::vector<GATE_POS_DATA>* pRet = new std::vector<GATE_POS_DATA>;
    
    if(d.IsObject())
    {
        std::string Key;
        for(int i = 1 ;i<=20;i++)
        {
            Key = cocos2d::StringUtils::format(GATE__NUM,i);
            if(d.HasMember(Key.c_str()))
            {
                if(d[Key.c_str()].IsObject())
                {
                    rapidjson::Value& object = d[Key.c_str()];
                    GATE_POS_DATA data;
                    data.InWhichMap = object[WHICH_MAP].GetInt();
                    data.WidthOdd = object[POS_X].GetInt();
                    data.HeightOdd = object[POX_Y].GetInt();
                    pRet->push_back(data);
                }
            }
        }
        return pRet;
    }
    
    
    return nullptr;
}

std::vector<MISSION_DATA>* JsonParser::GetMissionData()
{
    std::string path = cocos2d::FileUtils::getInstance()->getStringFromFile(MISSION_JSON);
    //CCLOG("%s",path.c_str());
    
    rapidjson::Document d;
    
    d.Parse<rapidjson::kParseDefaultFlags>(path.c_str());
    
    if (d.HasParseError()) {
        CCLOG("GetParseError %s\n",d.GetParseError());
        return nullptr;
    }
    
    std::vector<MISSION_DATA>* pRet = new std::vector<MISSION_DATA>;
    
    if(d.IsObject())
    {
        std::string Key;
        for(int i = 1 ;i<=20;i++)
        {
            Key = cocos2d::StringUtils::format(MISSION__NUM,i);
            if(d.HasMember(Key.c_str()))
            {
                if(d[Key.c_str()].IsObject())
                {
                    rapidjson::Value& object = d[Key.c_str()];
                    MISSION_DATA data;
                    data.Cur = object[MISSION_CUR].GetString();
                    data.Info = object[MISSION_INFO].GetString();
                    data.Value = object[MISSION_VALUE].GetInt();
                    data.Tag = object[MISSSION_TAG].GetInt();
                    pRet->push_back(data);
                }
            }
        }
        
        return pRet;
    }
    
    return nullptr;
}

GATE_MONSTER_DATA* JsonParser::GetMonsterData(int _gate,int _num)
{
    std::string file;
    switch (_gate) {
        case 1:
            file = CHAPTER_1_GATE_JSON;
            break;
        case 2:
            file = CHAPTER_2_GATE_JSON;
            break;
        case 3:
            file = CHAPTER_3_GATE_JSON;
            break;
        case 4:
            file = CHAPTER_4_GATE_JSON;
            break;
        case 5:
            file = CHAPTER_5_GATE_JSON;
            break;
            
        default:
            break;
    }
    std::string path = cocos2d::FileUtils::getInstance()->getStringFromFile(file);
    //CCLOG("%s",path.c_str());
    
    rapidjson::Document d;
    
    d.Parse<rapidjson::kParseDefaultFlags>(path.c_str());
    CCLOG("here");
    if (d.HasParseError()) {
        CCLOG("GetParseError %s\n",d.GetParseError());
        return nullptr;
    }
        CCLOG("here");
    std::string MonsterKey = cocos2d::StringUtils::format(MONSTER__NUM,_num);
        CCLOG("%s",MonsterKey.c_str());
    if(d.IsObject())
    {
        if(d.HasMember(MonsterKey.c_str()))
        {
            if(d[MonsterKey.c_str()].IsObject())
            {
                rapidjson::Value& object = d[MonsterKey.c_str()];
                GATE_MONSTER_DATA* data = new GATE_MONSTER_DATA;
                data->Level = object[MONSTER_LEVEL].GetInt();
                CCLOG("%d",object[MONSTER_LEVEL].GetInt());
                data->Hp = object[MONSTER_HP].GetInt();
                data->ATK = object[MONSTER_ATK].GetInt();
                data->DEF = object[MONSTER_DEF].GetInt();
                data->ATKNUM = object[MONSTER_ATKNUM].GetInt();
                data->DEFNUM = object[MONSTER_DEFNUM].GetInt();
                data->SPEED = object[MONSTER_SPEED].GetInt();
                data->SPENUM1 = object[MONSTER_SPENUM1].GetInt();
                data->SPENUM2 = object[MONSTER_SPENUM2].GetInt();
                data->SPENUM3 = object[MONSTER_SPENUM3].GetInt();
                data->Name = object[MONSTER_NAME].GetString();
                data->Info = object[MONSTER_INFO].GetString();
                data->Type = object[MONSTER_TYPE].GetInt();
                
                return data;
            }
        }
        
    }
    return nullptr;
}

std::vector<PLAYER_SKILL_DATA>* JsonParser::GetPlayerSkillData(int _type)
{
    std::string file;
    switch (_type) {
        case SELECT_FIRE:
            file = FIRE_JSON;
            break;
        case SELECT_WATER:
            file = WATER_JSON;
            break;
        case SELECT_THUNDER:
            file = THUNDER_JSON;
            break;
        case SELECT_WIND:
            file = WIND_JSON;
            break;
    }
    std::string path = cocos2d::FileUtils::getInstance()->getStringFromFile(file);
    //CCLOG("%s",path.c_str());
    
    rapidjson::Document d;
    
    d.Parse<rapidjson::kParseDefaultFlags>(path.c_str());
    
    if (d.HasParseError()) {
        CCLOG("GetParseError %s\n",d.GetParseError());
        return nullptr;
    }
    
    std::string SkillKey;
    std::vector<PLAYER_SKILL_DATA>* pRet = new std::vector<PLAYER_SKILL_DATA>;
    if(d.IsObject())
    {
        for(int i = 1;i<=4;i++)
        {
            SkillKey = cocos2d::StringUtils::format(SKILL__NUM,i);
            if(d.HasMember(SkillKey.c_str()))
            {
                if(d[SkillKey.c_str()].IsObject())
                {
                    rapidjson::Value& object = d[SkillKey.c_str()];
                    PLAYER_SKILL_DATA data;
                    data.Name = object[PALYER_SKILL_NAME].GetString();
                    data.Cost = object[PALYER_SKILL_COST].GetString();
                    data.Info = object[PALYER_SKILL_INFO].GetString();
                    pRet->push_back(data);
                }
            }
        }
        return pRet;
    }
    return nullptr;
}

GATE_MONSTER_DATA* JsonParser::GetTrailData(int num)
{
    std::string path = cocos2d::FileUtils::getInstance()->getStringFromFile(TRAIL_JONS);
    //CCLOG("%s",path.c_str());
    
    rapidjson::Document d;
    
    d.Parse<rapidjson::kParseDefaultFlags>(path.c_str());
    CCLOG("here");
    if (d.HasParseError()) {
        CCLOG("GetParseError %s\n",d.GetParseError());
        return nullptr;
    };
    
    std::string MonsterKey = cocos2d::StringUtils::format(MONSTER__NUM,num);
    CCLOG("%s",MonsterKey.c_str());
    if(d.IsObject())
    {
        if(d.HasMember(MonsterKey.c_str()))
        {
            if(d[MonsterKey.c_str()].IsObject())
            {
                rapidjson::Value& object = d[MonsterKey.c_str()];
                GATE_MONSTER_DATA* data = new GATE_MONSTER_DATA;
                data->Level = object[MONSTER_LEVEL].GetInt();
                CCLOG("%d",object[MONSTER_LEVEL].GetInt());
                data->Hp = object[MONSTER_HP].GetInt();
                data->ATK = object[MONSTER_ATK].GetInt();
                data->DEF = object[MONSTER_DEF].GetInt();
                data->ATKNUM = object[MONSTER_ATKNUM].GetInt();
                data->DEFNUM = object[MONSTER_DEFNUM].GetInt();
                data->SPEED = object[MONSTER_SPEED].GetInt();
                data->SPENUM1 = object[MONSTER_SPENUM1].GetInt();
                data->SPENUM2 = object[MONSTER_SPENUM2].GetInt();
                data->SPENUM3 = object[MONSTER_SPENUM3].GetInt();
                data->Name = object[MONSTER_NAME].GetString();
                data->Info = object[MONSTER_INFO].GetString();
                data->Type = object[MONSTER_TYPE].GetInt();
                
                return data;
            }
        }
        
    }
    return nullptr;
}





std::vector<ATTR_DATA>* JsonParser::GetAttrData()
{
    std::string path = cocos2d::FileUtils::getInstance()->getStringFromFile(ATTR_JSON);
    //CCLOG("%s",path.c_str());
    
    rapidjson::Document d;
    
    d.Parse<rapidjson::kParseDefaultFlags>(path.c_str());
    
    if (d.HasParseError()) {
        CCLOG("GetParseError %s\n",d.GetParseError());
        return nullptr;
    }
    
    std::string AttrKey;
    std::vector<ATTR_DATA>* pRet = new std::vector<ATTR_DATA>;
    if(d.IsObject())
    {
        for(int i = 1;i<=9;i++)
        {
            AttrKey = cocos2d::StringUtils::format(ATTR__NUM,i);
            if(d.HasMember(AttrKey.c_str()))
            {
                
                ATTR_DATA data;
                data.attr = d[AttrKey.c_str()].GetString();
                pRet->push_back(data);
            }
        }
        return pRet;
    }
    return nullptr;
}

ITEM_BASE_DATA* JsonParser::GetItenBaseData(const std::string &_key)
{
    std::string path = cocos2d::FileUtils::getInstance()->getStringFromFile(ITEM_JSON);
    //CCLOG("%s",path.c_str());
    
    rapidjson::Document d;
    
    d.Parse<rapidjson::kParseDefaultFlags>(path.c_str());
    
    if (d.HasParseError()) {
        CCLOG("GetParseError %s\n",d.GetParseError());
        return nullptr;
    }
    
    ITEM_BASE_DATA* pRet = new ITEM_BASE_DATA;
    if(d.IsObject())
    {
        if(d.HasMember(_key.c_str()))
        {
            if(d[_key.c_str()].IsObject())
            {
                rapidjson::Value& object = d[_key.c_str()];
                pRet->name = object[ITEM_NAME].GetString();
                pRet->info = object[ITEM_INFO].GetString();
                pRet->suit = object[ITEM_SUIT].GetInt();
                pRet->min = object[ITEM_MIN].GetInt();
                pRet->max = object[ITEM_MAX].GetInt();
            }
        }
    }
    return pRet;
}



