//
//  BaseMissionBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#include "BaseMissionBar.h"
#include "JsonParser.h"
BaseMissionBar::BaseMissionBar()
{
    Value = 0;
}


BaseMissionBar::~BaseMissionBar()
{
    
}


bool BaseMissionBar::init()
{
    if(!cocos2d::ui::Scale9Sprite::init())
    {
        return false;
    }
    initWithFile("UI/topstatebar_missionfloor.png");
    this->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width/18*5,cocos2d::Director::getInstance()->getVisibleSize().width/18*5));
    return true;
}


void BaseMissionBar::InitMissionData(MISSION_TYPE _type,int _value)
{
    std::vector<MISSION_DATA>* MissionVector = JsonParser::getInstance()->GetMissionData();
    
    if(_type == MISSION_TYPE::NO_MISSION)
    {
        return;
    }
    
    Value = _value;
    
    int _mission = (int)(_type);
    
    _MissionInfo = cocos2d::Label::createWithTTF(MissionVector->at(_mission-1).Info, "fonts/black.ttf", 24);
    _MissionInfo->setDimensions(this->getContentSize().width * 0.8f, this->getContentSize().height/3);
    _MissionInfo->setHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    _MissionInfo->setPosition(this->getContentSize().width/2,this->getContentSize().height - _MissionInfo->getContentSize().height/3*2);
    this->addChild(_MissionInfo);
    _MissionInfo->setColor(cocos2d::Color3B(37,37,37));
    std::string valuestring = cocos2d::StringUtils::format("%d",MissionVector->at(_mission-1).Value);
    _MissionValue = cocos2d::Label::createWithTTF(valuestring, "fonts/black.ttf", 32);
    _MissionValue->setPosition(this->getContentSize().width/3*2,this->getContentSize().height/2);
    this->addChild(_MissionValue);
    _MissionValue->setColor(cocos2d::Color3B(37,37,37));
    std::string Cur = MissionVector->at(_mission-1).Cur;
    if(Cur == "C")
    {
        _MissionCurrencyIcon = cocos2d::Sprite::create("UI/topstatebar_coin.png");
        _MissionValue->setColor(cocos2d::Color3B(0,0,0));
    }
    else if(Cur == "D")
    {
        _MissionCurrencyIcon = cocos2d::Sprite::create("UI/topstatebar_diamonds.png");
        _MissionValue->setColor(cocos2d::Color3B(102,217,239));
    }
    _MissionCurrencyIcon->setPosition(this->getContentSize().width/3,this->getContentSize().height/2);
    this->addChild(_MissionCurrencyIcon);
    
    
    std::string valuechar = cocos2d::StringUtils::format("%d/%d",Value,MissionVector->at(_mission-1).Tag);
    _MissionProgress = cocos2d::Label::createWithTTF(valuechar ,"fonts/black.ttf", 32);
    _MissionProgress->setPosition(this->getContentSize().width/2,_MissionProgress->getContentSize().height);
    _MissionProgress->setColor(cocos2d::Color3B(37,37,37));
    this->addChild(_MissionProgress);
}