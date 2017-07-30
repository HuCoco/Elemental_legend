//
//  AttrBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#include "AttrBar.h"
#include "XMLParser.h"
#include "PlayerConfig.h"
AttrBar::AttrBar()
{
    level = 0;
}

AttrBar::~AttrBar()
{
    
}

AttrBar* AttrBar::create(ATTR_TYPE _type)
{
    AttrBar* pRet = new AttrBar;
    if(pRet && pRet->init(_type))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool AttrBar::init(ATTR_TYPE _type)
{
    if(!cocos2d::Node::init())
    {
        return false;
    }
    type = _type;
    
    level = AttrSystem::getInstance()->GetAttrNum(type);
    
    cocos2d::Size visiblesize = cocos2d::Director::getInstance()->getVisibleSize();
    _floor = cocos2d::ui::Scale9Sprite::create("UI/attr_floor.png");
    _floor->setContentSize(cocos2d::Size(visiblesize.width*0.9,80));
    this->addChild(_floor);
    
    _addBtn = cocos2d::MenuItemImage::create("UI/attr_add.png","UI/attr_add.png",std::bind(&AttrBar::AddLevel,this,1));
    _addBtn->setPosition(_floor->getContentSize().width - _addBtn->getContentSize().width,_floor->getContentSize().height/2);
    
    std::string valuedstr = cocos2d::StringUtils::format("+%d",(int)AttrSystem::getInstance()->AddRealAttr(type));
    _valueData = cocos2d::Label::createWithTTF(valuedstr, "fonts/black.ttf", 40);
    _valueData->setPosition(_floor->getContentSize()/2);
    _floor->addChild(_valueData);
    
    std::string pointstr = cocos2d::StringUtils::format("%d",AttrSystem::getInstance()->GetAttrNum(type));
    _pointData = cocos2d::Label::createWithTTF(pointstr, "fonts/black.ttf", 40);
    _pointData->setAnchorPoint(cocos2d::Vec2(1,0.5f));
    _pointData->setPosition(_addBtn->getPositionX() - _addBtn->getContentSize().width ,_floor->getContentSize().height/2);
    _floor->addChild(_pointData);
    
    TitleInit();
    _icon->setPosition(_floor->getContentSize().width*0.05f,_floor->getContentSize().height/2);
    _floor->addChild(_icon);
    _title->setPosition(_floor->getContentSize().width*0.25f,_floor->getContentSize().height/2);
    _floor->addChild(_title);
    
    _menu = cocos2d::Menu::create(_addBtn,NULL);
    _menu->setPosition(0,0);
    _floor->addChild(_menu);
    
    return true;
}



void AttrBar::AddLevel(int _level)
{
    if(AttrSystem::getInstance()->GetARRTNUM() == 0)
    {
        return;
    }
    AttrSystem::getInstance()->SetATTRNUM(AttrSystem::getInstance()->GetARRTNUM()-1);
    level+=_level;
    AttrSystem::getInstance()->SetAttr(type, level);
    std::string valuedstr = cocos2d::StringUtils::format("+%d",(int)AttrSystem::getInstance()->AddRealAttr(type));
    std::string pointstr = cocos2d::StringUtils::format("%d",AttrSystem::getInstance()->GetAttrNum(type));
    _valueData->setString(valuedstr);
    _pointData->setString(pointstr);
    AttrSystem::getInstance()->Save();
}



void AttrBar::Reset()
{
    AttrSystem::getInstance()->SetATTRNUM(AttrSystem::getInstance()->GetARRTNUM() + level);
    level = 0;
    AttrSystem::getInstance()->SetAttr(type, level);
    std::string valuedstr = cocos2d::StringUtils::format("+%d",(int)AttrSystem::getInstance()->AddRealAttr(type));
    std::string pointstr = cocos2d::StringUtils::format("%d",AttrSystem::getInstance()->GetAttrNum(type));
    _valueData->setString(valuedstr);
    _pointData->setString(pointstr);
    AttrSystem::getInstance()->Save();
}

void AttrBar::TitleInit()
{
    std::string titlestr;
    std::string iconpath;
    switch (type) {
        case ATTR_ATK:
            titlestr = "攻击";
            iconpath = "UI/atk_bar.png";
            break;
        case ATTR_DEF:
            titlestr = "防御";
            iconpath = "UI/def_bar.png";
            break;
        case ATTR_HEALTH:
            titlestr = "生命值";
            iconpath = "UI/health_bar.png";
            break;
        case ATTR_MAGIC:
            titlestr = "魔力值";
            iconpath = "UI/magic_bar.png";
            break;
        case ATTR_REHP:
            titlestr = "生命恢复";
            iconpath = "UI/rehp_bar.png";
            break;
        case ATTR_REMP:
            titlestr = "魔力恢复";
            iconpath = "UI/remp_bar.png";
            break;
        case ATTR_BUFFTIME:
            titlestr = "增益时间";
            iconpath = "UI/time_bar.png";
            break;
        case ATTR_SHIELD:
            titlestr = "护盾值";
            iconpath = "UI/sheild_bar.png";
            break;
        case ATTR_SPEED:
            titlestr = "速度";
            iconpath = "UI/speed_bar.png";
            break;
        default:
            break;
    }
    _title = cocos2d::Label::createWithTTF(titlestr, "fonts/black.ttf", 40);
    _icon = cocos2d::Sprite::create(iconpath);
}