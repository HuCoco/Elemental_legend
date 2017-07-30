//
//  GateConfig.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#include "GateConfig.h"
#include "GameScene.h"
#include "GameSystem.h"
#include "JsonParser.h"
#include "AffixSystem.h"
#include "XMLParser.h"
#include "DynamicAttrSystem.h"
GateConfig::GateConfig()
{
    
}


GateConfig::~GateConfig()
{
    
}

bool GateConfig::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite);
    
    _floor = cocos2d::ui::Scale9Sprite::create("UI/mission_info_floor.png");
    _floor->setInsetLeft(20);
    _floor->setInsetRight(20);
    _floor->setInsetTop(20);
    _floor->setInsetBottom(20);
    _floor->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width/9*7,cocos2d::Director::getInstance()->getVisibleSize().width/9*7));
    _floor->setPosition(visibleSize.width/2,visibleSize.height/2);
    this->addChild(_floor);
    
    _startbtn = cocos2d::MenuItemImage::create("UI/start_btn.png","UI/start_btn.png",std::bind(&GateConfig::GoToGameScene,this));
    _startbtn->setPosition(_floor->getContentSize().width/3,_startbtn->getContentSize().height);
    
    _backbtn = cocos2d::MenuItemImage::create("UI/back_btn.png","UI/back_btn.png",std::bind(&GateConfig::Back,this));
    _backbtn->setPosition(_floor->getContentSize().width/3*2,_startbtn->getContentSize().height);
    
    _menu = cocos2d::Menu::create(_startbtn,_backbtn,NULL);
    _menu->setPosition(0,0);
    _floor->addChild(_menu);
    
    
    return true;
}

void GateConfig::GoToGameScene()
{
    GameSystem::getInsatance()->setGate(GateNum);
    GameScene* scene = GameScene::create();
    cocos2d::TransitionTurnOffTiles* fade = cocos2d::TransitionTurnOffTiles::create(0.5f, scene);
    cocos2d::Director::getInstance()->replaceScene(fade);
}

void GateConfig::Back()
{
    this->getParent()->removeChild(this);
}

void GateConfig::InitData(int _gate)
{
    GateNum = _gate;
    DynamicAttrSystem::getInstance()->upDateMonster(_gate);
    int pLevel = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::LEVEL);

    HealthBar = IconLabelBar::create("UI/health_bar.png",false,DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_HEALTH, pLevel));
    HealthBar->setPosition(_floor->getContentSize().width/4*3,_floor->getContentSize().height/20*7);
    _floor->addChild(HealthBar);
    
    AtkBar = IconLabelBar::create("UI/atk_bar.png",false,DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_AKT, pLevel));
    AtkBar->setPosition(_floor->getContentSize().width/4,_floor->getContentSize().height/20*7);
    _floor->addChild(AtkBar);
    
    DefBar = IconLabelBar::create("UI/def_bar.png",false,DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_DEF, pLevel));
    DefBar->setPosition(_floor->getContentSize().width/4,_floor->getContentSize().height/20*5);
    _floor->addChild(DefBar);
    
    SpeedBar = IconLabelBar::create("UI/speed_bar.png",false,DynamicAttrSystem::getInstance()->GetMonsterData(DYNAMIC_MONSTER_ATTR_LIST::DYN_MONSTER_SPEED, pLevel));
    SpeedBar->setPosition(_floor->getContentSize().width/4*3,_floor->getContentSize().height/20*5);
    _floor->addChild(SpeedBar);
    
    int _atk = DynamicAttrSystem::getInstance()->getMonsterAffixSkill(MONSTER_AFFIX_LIST::MONSTER_ATK_AFFIX);
    cocos2d::Label* AtkLabel = AffixSystem::getInstance()->getAffix(AFFIX_TYPE::AT_ATK, _atk);
    if(AtkLabel != nullptr)
    {
        AffixPool.push_back(AtkLabel);
    }
    
    int _def = DynamicAttrSystem::getInstance()->getMonsterAffixSkill(MONSTER_AFFIX_LIST::MONSTER_DEF_AFFIX);
    cocos2d::Label* DefLabel = AffixSystem::getInstance()->getAffix(AFFIX_TYPE::AT_DEF, _def);
    if(DefLabel != nullptr)
    {
        AffixPool.push_back(DefLabel);
    }
    int _spe1 = DynamicAttrSystem::getInstance()->getMonsterAffixSkill(MONSTER_AFFIX_LIST::MONSTER_SPE_AFFIX_1);
    cocos2d::Label* Spe1Label = AffixSystem::getInstance()->getAffix(AFFIX_TYPE::AT_SPE, _spe1);
    if(Spe1Label != nullptr)
    {
        AffixPool.push_back(Spe1Label);
    }
    
    int _spe2 = DynamicAttrSystem::getInstance()->getMonsterAffixSkill(MONSTER_AFFIX_LIST::MONSTER_SPE_AFFIX_2);
    cocos2d::Label* Spe2Label = AffixSystem::getInstance()->getAffix(AFFIX_TYPE::AT_SPE, _spe2);
    if(Spe2Label != nullptr)
    {
        AffixPool.push_back(Spe2Label);
    }
    
    int _spe3 = DynamicAttrSystem::getInstance()->getMonsterAffixSkill(MONSTER_AFFIX_LIST::MONSTER_SPE_AFFIX_3);
    cocos2d::Label* Spe3Label = AffixSystem::getInstance()->getAffix(AFFIX_TYPE::AT_SPE, _spe3);
    if(Spe3Label != nullptr)
    {
        AffixPool.push_back(Spe3Label);
    }
    
    int poolsize = (int)AffixPool.size();
    
    for(int i = 0 ; i < poolsize ; i++)
    {
        AffixPool.at(i)->setPosition(_floor->getContentSize().width/(poolsize+1)*(i+1),_floor->getContentSize().height/20*9);
        _floor->addChild(AffixPool.at(i));
    }
    
    _name = cocos2d::Label::createWithTTF(DynamicAttrSystem::getInstance()->getMonsterName(), "fonts/black.ttf", 60);
    _name->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height - _name->getContentSize().height*0.75f);
    _floor->addChild(_name);
    _info = cocos2d::Label::createWithTTF(DynamicAttrSystem::getInstance()->getMonsterInfo(), "fonts/black.ttf", 32);
    _info->setDimensions(_floor->getContentSize().width*0.85f,_floor->getContentSize().height/3);
    _info->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height/20*13);
    _info->setHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    _floor->addChild(_info);
    
    
    
    
    
    
}