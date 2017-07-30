//
//  XMLParser.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/30.
//
//

#include "XMLParser.h"
typedef cocos2d::UserDefault COCOS_XML;
namespace Parser {
    
    XML* XML::_instance = new XML;
    
    XML::XML()
    {
        
    }
    
    XML::~XML()
    {
        
    }
    
    XML* XML::getInstance()
    {
        return _instance;
    }
    
    bool XML::isCreated()
    {
        return COCOS_XML::getInstance()->getBoolForKey("CREATED",false);
    }
    
    void XML::Create()
    {
        EquipmentInit();
        BackPackInit();
        COCOS_XML::getInstance()->setBoolForKey("CREATED", true);
        COCOS_XML::getInstance()->setIntegerForKey("GUIDE_COMPLETE", 0);
        COCOS_XML::getInstance()->setIntegerForKey("LEVEL", 1);
        COCOS_XML::getInstance()->setIntegerForKey("EXP", 0);
        COCOS_XML::getInstance()->setIntegerForKey("HEALTH",0);
        COCOS_XML::getInstance()->setIntegerForKey("MAGIC", 0);
        COCOS_XML::getInstance()->setIntegerForKey("SHEILD",0);
        COCOS_XML::getInstance()->setIntegerForKey("ATK", 0);
        COCOS_XML::getInstance()->setIntegerForKey("DEF", 0);
        COCOS_XML::getInstance()->setIntegerForKey("BUFFTIME", 0);
        COCOS_XML::getInstance()->setIntegerForKey("REMP",0);
        COCOS_XML::getInstance()->setIntegerForKey("REHP", 0);
        COCOS_XML::getInstance()->setIntegerForKey("SPEED", 0);
        COCOS_XML::getInstance()->setIntegerForKey("T_FIRE", 1);
        COCOS_XML::getInstance()->setIntegerForKey("T_WATER", 1);
        COCOS_XML::getInstance()->setIntegerForKey("T_THUNDER", 1);
        COCOS_XML::getInstance()->setIntegerForKey("T_WIND", 1);
        COCOS_XML::getInstance()->setIntegerForKey("COST_FIRE", 0);
        COCOS_XML::getInstance()->setIntegerForKey("COST_WIND", 0);
        COCOS_XML::getInstance()->setIntegerForKey("COST_WATER", 0);
        COCOS_XML::getInstance()->setIntegerForKey("COST_THUNDER",0);
        COCOS_XML::getInstance()->setIntegerForKey("COST_MAGIC",0 );
        COCOS_XML::getInstance()->setIntegerForKey("MISSION_ONE", 0);
        COCOS_XML::getInstance()->setIntegerForKey("MISSION_TWO", 0);
        COCOS_XML::getInstance()->setIntegerForKey("MISSION_THREE", 0);
        COCOS_XML::getInstance()->setIntegerForKey("MISSION_ONE_VALUE", 0);
        COCOS_XML::getInstance()->setIntegerForKey("MISSION_TWO_VALUE", 0);
        COCOS_XML::getInstance()->setIntegerForKey("MISSION_THREE_VALUE", 0);
        COCOS_XML::getInstance()->setIntegerForKey("COIN", 10000);
        COCOS_XML::getInstance()->setIntegerForKey("DIAMONDS", 10000);
        COCOS_XML::getInstance()->setIntegerForKey("COMPLETE_GATE", 0);
        COCOS_XML::getInstance()->setFloatForKey("BM_SWITCH", 1.0f);
        COCOS_XML::getInstance()->setFloatForKey("EM_SWITCH", 1.0f);
        COCOS_XML::getInstance()->setFloatForKey("BGM_VALUE", 1.0f);
        COCOS_XML::getInstance()->setFloatForKey("EM_VALUE", 1.0f);
        COCOS_XML::getInstance()->setIntegerForKey("FIRE_LIST", 0);
        COCOS_XML::getInstance()->setIntegerForKey("WATER_LIST",0);
        COCOS_XML::getInstance()->setIntegerForKey("THUNDER_LIST", 0);
        COCOS_XML::getInstance()->setIntegerForKey("WIND_LIST", 0);
        COCOS_XML::getInstance()->setIntegerForKey("COMPLETE_CHAPTER", 1);
        COCOS_XML::getInstance()->setIntegerForKey("CHAPTER_NOW", 1);
        COCOS_XML::getInstance()->setIntegerForKey("Trial", 1);
        COCOS_XML::getInstance()->setBoolForKey("FirstGame", true);
    }
    
    
    
    void XML::UpdateData(Parser::USER_DATA_TYPE _type,int _value)
    {
        switch (_type) {
            case LEVEL:
                COCOS_XML::getInstance()->setIntegerForKey("LEVEL", _value);
                break;
            case EXP:
                COCOS_XML::getInstance()->setIntegerForKey("EXP", _value);
                break;
            case HEALTH:
                COCOS_XML::getInstance()->setIntegerForKey("HEALTH",_value);
                break;
            case MAGIC:
                COCOS_XML::getInstance()->setIntegerForKey("MAGIC", _value);
                break;
            case SHEILD:
                COCOS_XML::getInstance()->setIntegerForKey("SHEILD",_value);
                break;
            case ATK:
                COCOS_XML::getInstance()->setIntegerForKey("ATK", _value);
                break;
            case DEF:
                COCOS_XML::getInstance()->setIntegerForKey("DEF", _value);
                break;
            case BUFFTIME:
                COCOS_XML::getInstance()->setIntegerForKey("BUFFTIME",_value);
                break;
            case SPEED:
                COCOS_XML::getInstance()->setIntegerForKey("SPEED",_value);
                break;
            case REHP:
                COCOS_XML::getInstance()->setIntegerForKey("REHP",_value);
                break;
            case REMP:
                COCOS_XML::getInstance()->setIntegerForKey("REMP",_value);
                break;
            case TALENT_FIRE:
                COCOS_XML::getInstance()->setIntegerForKey("T_FIRE", _value);
                break;
            case TALENT_WATER:
                COCOS_XML::getInstance()->setIntegerForKey("T_WATER", _value);
                break;
            case TALENT_THUNDER:
                COCOS_XML::getInstance()->setIntegerForKey("T_THUNDER", _value);
                break;
            case TALENT_WIND:
                COCOS_XML::getInstance()->setIntegerForKey("T_WIND", _value);
                break;
            case COIN:
                COCOS_XML::getInstance()->setIntegerForKey("COIN", _value);
                break;
            case DIAMONDS:
                COCOS_XML::getInstance()->setIntegerForKey("DIAMONDS", _value);
                break;
            case COST_FIRE:
                COCOS_XML::getInstance()->setIntegerForKey("COST_FIRE", _value);
                break;
            case COST_MAGIC:
                COCOS_XML::getInstance()->setIntegerForKey("COST_MAGIC", _value);
                break;
            case COST_THUNDER:
                COCOS_XML::getInstance()->setIntegerForKey("COST_THUNDER", _value);
                break;
            case COST_WATER:
                COCOS_XML::getInstance()->setIntegerForKey("COST_WATER", _value);
                break;
            case COST_WIND:
                COCOS_XML::getInstance()->setIntegerForKey("COST_WIND", _value);
                break;
            case COMPLETE_GATE:
                COCOS_XML::getInstance()->setIntegerForKey("COMPLETE_GATE", _value);
                break;
            case GUIDE_COMPLETED:
                COCOS_XML::getInstance()->setIntegerForKey("GUIDE_COMPLETE", _value);
                break;
            case COMPLETE_CHAPTER:
                COCOS_XML::getInstance()->setIntegerForKey("COMPLETE_CHAPTER", _value);
                break;
            case CHAPTER_NOW:
                COCOS_XML::getInstance()->setIntegerForKey("CHAPTER_NOW", _value);
                break;
            case FRISTGAME:
                COCOS_XML::getInstance()->setBoolForKey("FirstGame", _value);
                break;
            default:
                break;
        }
    }
    
    int XML::GetData(Parser::USER_DATA_TYPE _type)
    {
        int pRet = 0;
        switch (_type) {
            case LEVEL:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("LEVEL");
                break;
            case EXP:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("EXP");
                break;
            case HEALTH:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("HEALTH");
                break;
            case MAGIC:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("MAGIC");
                break;
            case SHEILD:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("SHEILD");
                break;
            case ATK:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("ATK");
                break;
            case DEF:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("DEF");
                break;
            case BUFFTIME:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("BUFFTIME");
                break;
            case SPEED:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("SPEED");
                break;
            case REHP:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("REHP");
                break;
            case REMP:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("REMP");
                break;
            case TALENT_FIRE:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("T_FIRE");
                break;
            case TALENT_WATER:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("T_WATER");
                break;
            case TALENT_THUNDER:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("T_THUNDER");
                break;
            case TALENT_WIND:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("T_WIND");
                break;
            case COIN:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("COIN");
                break;
            case DIAMONDS:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("DIAMONDS");
                break;
            case COST_FIRE:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("COST_FIRE");
                break;
            case COST_MAGIC:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("COST_MAGIC");
                break;
            case COST_THUNDER:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("COST_THUNDER");
                break;
            case COST_WATER:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("COST_WATER");
                break;
            case COST_WIND:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("COST_WIND");
                break;
            case COMPLETE_GATE:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("COMPLETE_GATE");
                break;
            case GUIDE_COMPLETED:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("GUIDE_COMPLETE");
                break;
            case COMPLETE_CHAPTER:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("COMPLETE_CHAPTER");
                break;
            case CHAPTER_NOW:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("CHAPTER_NOW");
                break;
            case FRISTGAME:
                pRet = COCOS_XML::getInstance()->getBoolForKey("FirstGame");
                break;
            default:
                break;
        }
        return pRet;
    }
    
    void XML::SetMission(Parser::MISSION_DATA_TYPE _datatype, MISSION_TYPE _type)
    {
        int MissionType = (int)_type;
        switch (_datatype)
        {
            case MISSION_ONE:
                COCOS_XML::getInstance()->setIntegerForKey("MISSION_ONE", MissionType);
                break;
            case MISSION_TWO:
                COCOS_XML::getInstance()->setIntegerForKey("MISSION_TWO", MissionType);
                break;
            case MISSION_THREE:
                COCOS_XML::getInstance()->setIntegerForKey("MISSION_THREE", MissionType);
                break;
            default:
                break;
        }
    }
    
    int XML::GetMission(Parser::MISSION_DATA_TYPE _datatype)
    {
        int MissionType = 0;
        switch (_datatype)
        {
            case MISSION_ONE:
                MissionType = COCOS_XML::getInstance()->getIntegerForKey("MISSION_ONE", 0);
                break;
            case MISSION_TWO:
                MissionType = COCOS_XML::getInstance()->getIntegerForKey("MISSION_TWO", 0);
                break;
            case MISSION_THREE:
                MissionType = COCOS_XML::getInstance()->getIntegerForKey("MISSION_THREE", 0);
                break;
            default:
                break;
        }
        return MissionType;
    }
    
    void XML::SetMissionValue(Parser::MISSION_DATA_TYPE _datatype, int _value)
    {
        switch (_datatype)
        {
            case MISSION_ONE:
                COCOS_XML::getInstance()->setIntegerForKey("MISSION_ONE_VALUE", _value);
                break;
            case MISSION_TWO:
                COCOS_XML::getInstance()->setIntegerForKey("MISSION_TWO_VALUE", _value);
                break;
            case MISSION_THREE:
                COCOS_XML::getInstance()->setIntegerForKey("MISSION_THREE_VALUE", _value);
                break;
            default:
                break;
        }
    }
    
    int XML::GetMissionValue(MISSION_DATA_TYPE _datatype)
    {
        int _value = 0;
        switch (_datatype)
        {
            case MISSION_ONE:
                _value = COCOS_XML::getInstance()->getIntegerForKey("MISSION_ONE_VALUE", 0);
                break;
            case MISSION_TWO:
                _value = COCOS_XML::getInstance()->getIntegerForKey("MISSION_TWO_VALUE", 0);
                break;
            case MISSION_THREE:
                _value = COCOS_XML::getInstance()->getIntegerForKey("MISSION_THREE_VALUE",0);
                break;
            default:
                break;
        }
        return _value;
    }
    
    void XML::SetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE _type,float _value)
    {
        switch (_type)
        {
            case BM_SWITCH:
                COCOS_XML::getInstance()->setFloatForKey("BM_SWITCH", _value);
                break;
            case EM_SWITCH:
                COCOS_XML::getInstance()->setFloatForKey("EM_SWITCH", _value);
                break;
            case BGM_VOLUME:
                COCOS_XML::getInstance()->setFloatForKey("BGM_VALUE", _value);
                break;
            case EM_VOLUME:
                COCOS_XML::getInstance()->setFloatForKey("EM_VALUE", _value);
            default:
                break;
        }
    }
    
    float XML::GetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE _type)
    {
        float pRet = 0.0f;
        switch (_type) {
            case BM_SWITCH:
                pRet = COCOS_XML::getInstance()->getFloatForKey("BM_SWITCH",1.0f);
                break;
            case EM_SWITCH:
                pRet = COCOS_XML::getInstance()->getFloatForKey("EM_SWITCH",1.0f);
                break;
            case BGM_VOLUME:
                pRet = COCOS_XML::getInstance()->getFloatForKey("BGM_VALUE",1.0f);
                break;
            case EM_VOLUME:
                pRet = COCOS_XML::getInstance()->getFloatForKey("EM_VALUE",1.0f);
                break;
            default:
                break;
        }
        return pRet;
    }

    void XML::SetTalentGetListData(Parser::TALENT_GET_LIST _list, int _value)
    {
        switch (_list) {
            case T_FIRE:
                COCOS_XML::getInstance()->setIntegerForKey("FIRE_LIST", _value);
                cocos2d::log("fire_%d",_value);
                break;
            case T_THUNDER:
                COCOS_XML::getInstance()->setIntegerForKey("WATER_LIST", _value);
                cocos2d::log("thunder_%d",_value);
                break;
            case T_WATER:
                COCOS_XML::getInstance()->setIntegerForKey("THUNDER_LIST", _value);
                cocos2d::log("water_%d",_value);
                break;
            case T_WIND:
                COCOS_XML::getInstance()->setIntegerForKey("WIND_LIST", _value);
                cocos2d::log("wind_%d",_value);
                break;
            default:
                break;
        }
    }
    
    int XML::GetTalentGetListData(Parser::TALENT_GET_LIST _list)
    {
        int pRet = 0;
        switch (_list) {
            case T_FIRE:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("FIRE_LIST");
                break;
            case T_THUNDER:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("WATER_LIST");
                break;
            case T_WATER:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("THUNDER_LIST");
                break;
            case T_WIND:
                pRet = COCOS_XML::getInstance()->getIntegerForKey("WIND_LIST");
                break;
            default:
                break;
        }
        return pRet;
    }
    
    std::string XML::GetBackpackData(int pos)
    {
        std::string key = cocos2d::StringUtils::format(BACKPACK_POS,pos);
        return COCOS_XML::getInstance()->getStringForKey(key.c_str(),"");
        
    }
    
    void XML::SetBackpackData(const std::string _itemstr, int pos)
    {
        std::string key = cocos2d::StringUtils::format(BACKPACK_POS,pos);
        COCOS_XML::getInstance()->setStringForKey(key.c_str(), _itemstr);
    }
    
    void XML::BackPackInit()
    {
        for(int i = 0 ; i < 42 ; i++)
        {
            std::string key = cocos2d::StringUtils::format(BACKPACK_POS,i);
            COCOS_XML::getInstance()->setStringForKey(key.c_str(),"");
        }
    }
    
    void XML::SetEquipmentData(const std::string _itemstr,int pos)
    {
        std::string key = cocos2d::StringUtils::format(EQUIPMENT_POS,pos);
        COCOS_XML::getInstance()->setStringForKey(key.c_str(), _itemstr);
    }
    std::string XML::GetEquipmentData(int pos)
    {
        std::string key = cocos2d::StringUtils::format(EQUIPMENT_POS,pos);
        return COCOS_XML::getInstance()->getStringForKey(key.c_str(),"");
        
    }
    
    void XML::EquipmentInit()
    {
        for(int i = 0 ; i < 5 ; i++)
        {
            std::string key = cocos2d::StringUtils::format(EQUIPMENT_POS,i);
            COCOS_XML::getInstance()->setStringForKey(key.c_str(),"");
        }
    }
    
    int XML::GetItemCode()
    {
        int pRet = COCOS_XML::getInstance()->getIntegerForKey("ItemCode", 0);
        COCOS_XML::getInstance()->setIntegerForKey("ItemCode", pRet+1);
        return pRet;
    }
    
    int XML::GetTrailTop()
    {
        return COCOS_XML::getInstance()->getIntegerForKey("Trial", 1);
    }
    
    void XML::SetTrailTop(int _level)
    {
        COCOS_XML::getInstance()->setIntegerForKey("Trial", _level);
    }
}


