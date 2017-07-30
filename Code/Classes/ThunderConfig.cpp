//
//  ThunderConfig.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/11.
//
//

#include "ThunderConfig.h"
#include "CsvParser.h"
#include "XMLParser.h"
#include "RecordSystem.h"
#include "TalentProgressBar.h"

ThunderConfig::ThunderConfig()
{
    
}

ThunderConfig::~ThunderConfig()
{
    
}

bool ThunderConfig::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(ThunderConfig::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(ThunderConfig::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(ThunderConfig::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite);
    
    _floor = cocos2d::ui::Scale9Sprite::create("UI/playerconfig_skillfloor.png");
    _floor->setContentSize(cocos2d::Size(visibleSize.width/9*7,visibleSize.width/9*7));
    _floor->setPosition(visibleSize.width/2,visibleSize.height/3*2);
    this->addChild(_floor);
    
    for(int i = 0;i < 4;i++)
    {
        cocos2d::Sprite* pRet = cocos2d::Sprite::create("UI/playerconfig_talentfloor.png");
        pRet->setPosition(_floor->getContentSize().width/5*(i+1),_floor->getContentSize().height/10*3);
        _talentfloorpool.push_back(pRet);
        _floor->addChild(_talentfloorpool.back());
    }
    
    
    _okbtn = cocos2d::MenuItemImage::create("UI/ok_btn.png", "UI/ok_btn.png", std::bind(&ThunderConfig::close,this));
    _okbtn->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height/10);
    
    
    _menu = cocos2d::Menu::create(_okbtn,NULL);
    _menu->setPosition(0,0);
    _floor->addChild(_menu);
    
    
    
    
    int TelentData = GetTalentDataByUsedData(Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COST_THUNDER));
    
    for(int i = 0 ; i < TelentData ; i++)
    {
        std::string path = cocos2d::StringUtils::format("skillicon/thunderskillicon_%d.png",i+1);
        TALENT_INFO pRet;
        pRet.Num = i+1;
        pRet._talent = cocos2d::Sprite::create(path);
        pRet._talent->setPosition(_talentfloorpool.at(i)->getPosition());
        _talentpool.push_back(pRet);
        _floor->addChild(_talentpool.back()._talent);
    }
    
    SkillVector = JsonParser::getInstance()->GetPlayerSkillData(SELECT_THUNDER);
    
    int thunder_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_THUNDER);
    if(thunder_no == 1)
    {
        thunder_no = 2;
    }
    _name = cocos2d::Label::createWithTTF(SkillVector->at(thunder_no-2).Name, "fonts/black.ttf", 60);
    _name->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height/20*17);
    //_talentpool.at(thunder_no-1)->setScale(1.2f);
    _floor->addChild(_name);
    
    _cost = cocos2d::Label::createWithTTF(SkillVector->at(thunder_no-2).Cost, "fonts/black.ttf", 40);
    _cost->setPosition(_name->getPositionX(),_name->getPositionY() - _name->getContentSize().height);
    _cost->setColor(cocos2d::Color3B(77,163,244));
    _floor->addChild(_cost);
    
    _introduction = cocos2d::Label::createWithTTF(SkillVector->at(thunder_no-2).Info, "fonts/black.ttf", 32);
    _introduction->setAnchorPoint(cocos2d::Vec2(0.5f,1));
    _introduction->setPosition(_floor->getContentSize().width/2,_cost->getPositionY() - _cost->getContentSize().height);
    
    _introduction->setDimensions(500, 210);
    _introduction->setHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    _floor->addChild(_introduction);
    
    if(Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_THUNDER) == 1)
    {
        _name->setString("未选择天赋");
        _cost->setString("------");
        _introduction->setString("");
    }
    thunder_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_THUNDER);
    for(int i = 0 ; i < (int)_talentpool.size();i++)
    {
        if(thunder_no - 1 == _talentpool.at(i).Num)
        {
            _talentpool.at(i)._talent->setScale(1.2f);
        }
    }
    
    int Used_data = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COST_THUNDER);
    std::string usedstr = cocos2d::StringUtils::format("当前已使用 %d 次雷元素",Used_data);
    cocos2d::Label* UsedLabel = cocos2d::Label::createWithTTF(usedstr, "fonts/black.ttf", 50);
    UsedLabel->setAlignment(cocos2d::TextHAlignment::CENTER);
    UsedLabel->setWidth(visibleSize.width*0.9f);
    UsedLabel->setPosition(visibleSize.width/2,visibleSize.height/3);
    this->addChild(UsedLabel);
    
    int NextTelentNeed = 100 * pow(4, TelentData)/2 - Used_data;
    std::string usedtipsstr = cocos2d::StringUtils::format("解锁新天赋还需使用 %d 次雷元素",NextTelentNeed);
    cocos2d::Label* UsedtipsLabel = cocos2d::Label::createWithTTF(usedtipsstr, "fonts/black.ttf", 45);
    UsedtipsLabel->setPosition(UsedLabel->getPositionX(),UsedLabel->getPositionY() - UsedLabel->getContentSize().height/2 - UsedtipsLabel->getContentSize().height);
    UsedtipsLabel->setAlignment(cocos2d::TextHAlignment::CENTER);
    UsedtipsLabel->setWidth(visibleSize.width*0.9f);
    this->addChild(UsedtipsLabel);
    
    
    return true;
}


bool ThunderConfig::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    return true;
}

void ThunderConfig::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}

void ThunderConfig::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    for(int i = 0 ; i < (int)_talentpool.size();i++)
    {
        if(_talentpool.at(i)._talent->getBoundingBox().containsPoint(_floor->convertToNodeSpace(_touch->getLocation())))
        {
            ReSetScale();
            _talentpool.at(i)._talent->setScale(1.2f);
            _name->setString(SkillVector->at(_talentpool.at(i).Num-1).Name);
            _introduction->setString(SkillVector->at(_talentpool.at(i).Num-1).Info);
            _cost->setString(SkillVector->at(_talentpool.at(i).Num-1).Cost);
            Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::TALENT_THUNDER, _talentpool.at(i).Num+1);
        }
    }
}

