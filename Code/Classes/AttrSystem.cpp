//
//  AttrSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#include "AttrSystem.h"
#include "XMLParser.h"
#include "EquipmentSystem.h"
AttrSystem* AttrSystem::_instance = nullptr;

AttrSystem::AttrSystem()
{
    Update();
}

AttrSystem::~AttrSystem()
{
    
}


void AttrSystem::Update()
{
    _LEVEL = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::LEVEL);
    _ATK = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::ATK);
    _DEF = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::DEF);
    _HEALTH = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::HEALTH);
    _MAGIC = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::MAGIC);
    _SHIELD = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::SHEILD);
    _REHP = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::REHP);
    _REMP = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::REMP);
    _SPEED = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::SPEED);
    _BUFFTIME = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::BUFFTIME);
    _ATTR_NUM = (Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::LEVEL)-1)*5 - _ATK - _DEF - _HEALTH - _MAGIC - _SHIELD - _REHP - _REMP - _SPEED - _BUFFTIME;
}

AttrSystem* AttrSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new AttrSystem;
    }
    return _instance;
}

float AttrSystem::GetRealAttr(ATTR_TYPE _type)
{
    EquipmentSystem::getInstance()->EquipmentInit();

    TOTAL_ATTR_DATA* data = EquipmentSystem::getInstance()->getTotalAttr();

    float pRet;
    switch (_type) {
        case ATTR_ATK:
            pRet = (20  + (_LEVEL - 1) * 10 + 5 * _ATK) * (float)(1.0f + (float)data->data.at(_type)._value/100.0f);
            break;
        case ATTR_DEF:
            pRet = (30  + (_LEVEL - 1) * 0  + 4  * _DEF) * (float)(1.0f + (float)data->data.at(_type)._value/100.0f);
            break;
        case ATTR_HEALTH:
            pRet = (200 + (_LEVEL - 1) * 100 + 25 * _HEALTH) * (float)(1.0f + (float)data->data.at(_type)._value/100.0f);
            break;
        case ATTR_MAGIC:
            pRet = (100 + (_LEVEL - 1) * 50 + 20 * _MAGIC) * (float)(1.0f + (float)data->data.at(_type)._value/100.0f);
            break;
        case ATTR_REHP:
            pRet = (10  + (_LEVEL - 1) * 5  + 2  * _REHP) * (float)(1.0f + (float)data->data.at(_type)._value/100.0f);
            break;
        case ATTR_REMP:
            pRet = (5   + (_LEVEL - 1) * 2  + 2  * _REMP) * (float)(1.0f + (float)data->data.at(_type)._value/100.0f);
            break;
        case ATTR_BUFFTIME:
            pRet = (10  + (_LEVEL - 1) * 1  + 2  * _BUFFTIME) * (float)(1.0f + (float)data->data.at(_type)._value/100.0f);
            break;
        case ATTR_SHIELD:
            pRet = (50  + (_LEVEL - 1) * 20 + 10 * _SHIELD) * (float)(1.0f + (float)data->data.at(_type)._value/100.0f);
            break;
        case ATTR_SPEED:
            pRet =  5   + _SPEED * 0.2;
            break;
        default:
            break;
    }
    delete data;
    return pRet;
}

float AttrSystem::GetBaseAttr(ATTR_TYPE _type)
{
    float pRet;
    switch (_type) {
        case ATTR_ATK:
            pRet = (20  + (_LEVEL - 1) * 10);
            break;
        case ATTR_DEF:
            pRet = (30  + (_LEVEL - 1));
            break;
        case ATTR_HEALTH:
            pRet = (200 + (_LEVEL - 1) * 100);
            break;
        case ATTR_MAGIC:
            pRet = (100 + (_LEVEL - 1) * 50);
            break;
        case ATTR_REHP:
            pRet = (10  + (_LEVEL - 1) * 5);
            break;
        case ATTR_REMP:
            pRet = (5   + (_LEVEL - 1) * 2);
            break;
        case ATTR_BUFFTIME:
            pRet = (10  + (_LEVEL - 1) * 1);
            break;
        case ATTR_SHIELD:
            pRet = (50  + (_LEVEL - 1) * 2);
            break;
        case ATTR_SPEED:
            pRet =  5;
            break;
        default:
            break;
    }
    return pRet;
}

float AttrSystem::AddRealAttr(ATTR_TYPE _type)
{
    float pRet;
    switch (_type) {
        case ATTR_ATK:
            pRet = 5*_ATK;
            break;
        case ATTR_DEF:
            pRet = 4 * _DEF;;
            break;
        case ATTR_HEALTH:
            pRet = 30 * _HEALTH;
            break;
        case ATTR_MAGIC:
            pRet = 20 * _MAGIC;
            break;
        case ATTR_REHP:
            pRet = 2*_REHP;
            break;
        case ATTR_REMP:
            pRet = 2*_REMP;
            break;
        case ATTR_BUFFTIME:
            pRet = 2*_BUFFTIME;
            break;
        case ATTR_SHIELD:
            pRet = 10 * _SHIELD;
            break;
        case ATTR_SPEED:
            pRet = 0.2f*_SPEED;
            break;
        default:
            break;
    }
    return pRet;
}

int AttrSystem::GetAttrNum(ATTR_TYPE _type)
{
    int pRet;
    switch (_type) {
        case ATTR_ATK:
            pRet = _ATK;
            break;
        case ATTR_DEF:
            pRet = _DEF;;
            break;
        case ATTR_HEALTH:
            pRet = _HEALTH;
            break;
        case ATTR_MAGIC:
            pRet = _MAGIC;
            break;
        case ATTR_REHP:
            pRet = _REHP;
            break;
        case ATTR_REMP:
            pRet = _REMP;
            break;
        case ATTR_BUFFTIME:
            pRet = _BUFFTIME;
            break;
        case ATTR_SHIELD:
            pRet = _SHIELD;
            break;
        case ATTR_SPEED:
            pRet = _SPEED;
            break;
        default:
            break;
    }
    return pRet;
}

void AttrSystem::SetAttr(ATTR_TYPE _type,int _value)
{
    switch (_type) {
        case ATTR_ATK:
            _ATK = _value;
            break;
        case ATTR_DEF:
            _DEF = _value;
            break;
        case ATTR_HEALTH:
            _HEALTH = _value;
            break;
        case ATTR_MAGIC:
            _MAGIC = _value;
            break;
        case ATTR_REHP:
            _REHP = _value;
            break;
        case ATTR_REMP:
            _REMP = _value;
            break;
        case ATTR_BUFFTIME:
            _BUFFTIME = _value;
            break;
        case ATTR_SHIELD:
            _SHIELD = _value;
            break;
        case ATTR_SPEED:
            _SPEED = _value;
            break;
        default:
            break;
    }
}

void AttrSystem::Save()
{
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::ATK, _ATK);
    
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::DEF, _DEF);
    
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::HEALTH, _HEALTH);
    
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::MAGIC, _MAGIC);
    
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::REHP, _REHP);
    
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::REMP, _REMP);
    
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::BUFFTIME, _BUFFTIME);
    
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::SHEILD, _SHIELD);
    
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::SPEED, _SPEED);

}