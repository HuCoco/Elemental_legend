//
//  GameTopStateBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/15.
//
//

#include "GameTopStateBar.h"
#include "PauseLayer.h"
#include "AttrSystem.h"
#include "BattleSystem.h"
GameTopStateBar::GameTopStateBar()
{
    
}


GameTopStateBar::~GameTopStateBar()
{
    
}

bool GameTopStateBar::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    cocos2d::Size VisibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    _floor = cocos2d::ui::Scale9Sprite::create("UI/topstatebar_floor.png" );
    _floor->setContentSize(cocos2d::Size(VisibleSize.width,VisibleSize.width/9));
    _floor->setPosition(VisibleSize.width/2,VisibleSize.height - _floor->getContentSize().height/2);
    this->addChild(_floor);
    
    _pausebtn = cocos2d::MenuItemImage::create("UI/pause_btn.png","UI/pause_btn.png",std::bind(&GameTopStateBar::addPauseLayer,this));
    _pausebtn->setPosition(_floor->getContentSize().width - _pausebtn->getContentSize().width*0.6f,_floor->getContentSize().height/2);
    
    _menu = cocos2d::Menu::create(_pausebtn,NULL);
    _menu->setPosition(0,0);
    _floor->addChild(_menu);
    
    ConstATK = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_ATK);
    ConstDEF = AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_DEF);
    if(BattleSystem::getInstance()->getPlayer()->getState() != NULL)
    {
        NowATK = BattleSystem::getInstance()->getPlayer()->getState()->GetAttack();
        NowDEF = BattleSystem::getInstance()->getPlayer()->getState()->GetAttack();
    }
    AtkLabel = IconLabelBar::create("UI/atk_bar.png",false,ConstATK);
    AtkLabel->setPosition(AtkLabel->getContentSize().width*0.6f,_floor->getContentSize().height/2);
    _floor->addChild(AtkLabel);
    
    
    DefLabel = IconLabelBar::create("UI/def_bar.png",false,ConstDEF);
    DefLabel->setPosition(AtkLabel->getPositionX() + DefLabel->getContentSize().width*1.1f , _floor->getContentSize().height/2);
    _floor->addChild(DefLabel);
    
    
    
    this->schedule(std::bind(&GameTopStateBar::UpdatePlayState, this), "updatestate");
    return true;
}

void GameTopStateBar::addPauseLayer()
{
    if(this->getParent()->getChildByName("PauseLayer") == nullptr)
    {
        cocos2d::Director::getInstance()->pause();
        PauseLayer* layer = PauseLayer::create();
        this->getParent()->addChild(layer,4,"PauseLayer");
    }
}


void GameTopStateBar::UpdatePlayState()
{
    if(BattleSystem::getInstance()->getPlayer()->getState() == NULL)
    {
        return;
    }
    NowATK = BattleSystem::getInstance()->getPlayer()->getState()->GetAttack();
    NowDEF = BattleSystem::getInstance()->getPlayer()->getState()->GetDefence();
    
    AtkLabel->setValue(NowATK);
    DefLabel->setValue(NowDEF);
    if(NowATK > ConstATK)
    {
        AtkLabel->SetColor(ICON_LABEL_COLOR::ILC_RED);
    }
    else if(NowATK == ConstATK)
    {
        AtkLabel->SetColor(ICON_LABEL_COLOR::ILC_WHITE);
    }
    else if(NowATK < ConstATK)
    {
        AtkLabel->SetColor(ICON_LABEL_COLOR::ILC_GREEN);
    }

    
    if(NowDEF > ConstDEF)
    {
        DefLabel->SetColor(ICON_LABEL_COLOR::ILC_RED);
    }
    else if(NowDEF == ConstDEF)
    {
        DefLabel->SetColor(ICON_LABEL_COLOR::ILC_WHITE);
    }
    else if(NowDEF < ConstDEF)
    {
        DefLabel->SetColor(ICON_LABEL_COLOR::ILC_GREEN);
    }
    
    
}