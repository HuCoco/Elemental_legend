//
//  BuyLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/24.
//
//

#include "BuyLayer.h"
#include "UISystem.h"
#include "BuyBar.h"
BuyLayer::BuyLayer()
{
    
}

BuyLayer::~BuyLayer()
{
    
}

BuyLayer* BuyLayer::create(BUY_TYPE _type)
{
    BuyLayer* pRet = new BuyLayer;
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

bool BuyLayer::init(BUY_TYPE _type)
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    BaseInit();
    if(_type == BUY_TYPE::B_COIN)
    {
        this->InitBuyCoin();
    }
    else if(_type == BUY_TYPE::B_DIAMOND)
    {
        this->InitBuyDiamond();
    }
    else if(_type == B_TOOLS)
    {
        this->InitBuyTools();
    }
    return true;
}

void BuyLayer::BaseInit()
{
    //cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    //cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    //ShadowSprite->setPosition(visibleSize/2);
    //this->addChild(ShadowSprite);
    
    _floor = cocos2d::ui::Scale9Sprite::create("UI/buy_floor.png");
    _floor->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width/9*8,cocos2d::Director::getInstance()->getVisibleSize().height/16*13));
    _floor->setPosition(this->getContentSize()/2);
    this->addChild(_floor);
    
    _closeBtn = cocos2d::MenuItemImage::create("UI/playerconfig_close.png", "UI/playerconfig_close.png", std::bind([=]{this->getParent()->removeChild(this);UISystem::getInstance()->ClosePlayerConfig();}));
    _closeBtn->setPosition(_floor->getContentSize().width - _closeBtn->getContentSize().width/2,_floor->getContentSize().height - _closeBtn->getContentSize().height/2);
    
    _buyBtn = cocos2d::MenuItemImage::create("UI/buy_btn.png", "UI/buy_btn.png");
    _buyBtn->setPosition(_floor->getContentSize().width/2,_buyBtn->getContentSize().height);
    
    _menu = cocos2d::Menu::create(_closeBtn,_buyBtn,NULL);
    _menu->setPosition(0,0);
    _floor->addChild(_menu);
    
}

void BuyLayer::InitBuyCoin()
{
    BuyBar* pRet = BuyBar::create(BUY_SOMETHING::BUY_COIN, 1);
    pRet->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height/2);
    _floor->addChild(pRet);
    

}


void BuyLayer::InitBuyDiamond()
{
    BaseInit();
}

void BuyLayer::InitBuyTools()
{
    BaseInit();
}

