//
//  GateBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#include "GateBar.h"
#include "GateConfig.h"

GateBar::GateBar()
{
    
}

GateBar::~GateBar()
{
    
}

bool GateBar::init(int _gate,GATE_STATE_TYPE _statetype)
{
    if(!cocos2d::MenuItemImage::init())
    {
        return false;
    }
    GateNum = _gate;
    
    initWithNormalImage("UI/gate_floor.png", "UI/gate_floor.png", "UI/gate_floor_no.png", std::bind(&GateBar::AddGateConfig,this));
    ;    //this->setColor(cocos2d::Color3B(0,0,0));
    char gatechar[10];
    sprintf(gatechar,"%d",GateNum);
    //cocos2d::Label* GateLabel = cocos2d::Label::createWithTTF(gatechar, "fonts/arial.ttf", 80);
    //GateLabel->setColor(cocos2d::Color3B(0,0,0));
    //GateLabel->setPosition(this->getContentSize()/2);
    //this->addChild(GateLabel);
    cocos2d::Sprite* gateIcon;
    if(_statetype == GATE_UNCOMPLETED)
    {
        gateIcon = cocos2d::Sprite::create("UI/gate_boss.png");
        gateIcon->setPosition(this->getContentSize().width/2,this->getPositionY() + gateIcon->getContentSize().height);
        this->addChild(gateIcon);
    }
    else if(_statetype == GATE_COMPLETED)
    {
        gateIcon = cocos2d::Sprite::create("UI/gate_complete.png");
        gateIcon->setPosition(this->getContentSize().width/2,this->getPositionY() + gateIcon->getContentSize().height);
        this->addChild(gateIcon);
    }
    if(_statetype == GATE_CANT_GET)
    {
        this->unselected();
    }
    _type = _statetype;
    return true;
}

void GateBar::AddGateConfig()
{

    if(this->getParent()->getParent()->getParent()->getChildByName("gateconfig") || _type == GATE_CANT_GET)
    {
        return;
    }
    

    GateConfig* pRet = GateConfig::create();
    pRet->InitData(GateNum);
    this->getParent()->getParent()->getParent()->addChild(pRet,2,"gateconfig");
}

GateBar* GateBar::create(int _gate,GATE_STATE_TYPE _statetype)
{
    GateBar* pRet = new GateBar;
    if(pRet && pRet->init(_gate,_statetype))
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