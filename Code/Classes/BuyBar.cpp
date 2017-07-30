//
//  BuyBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/24.
//
//

#include "BuyBar.h"

BuyBar::BuyBar()
{
    
}


BuyBar::~BuyBar()
{
    
}


BuyBar* BuyBar::create(BUY_SOMETHING _what, int _value)
{
    BuyBar* pRet = new BuyBar;
    if(pRet && pRet->init(_what, _value))
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



bool BuyBar::init(BUY_SOMETHING _what, int _value)
{
    if(!cocos2d::ui::Scale9Sprite::init())
    {
        return false;
    }
    
    initWithFile("UI/buy_bar.png");
    this->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width/9*7,cocos2d::Director::getInstance()->getVisibleSize().height/8));
    
    
    _buyWhat = _what;
    Value = _value;
    
    
    
    return true;
}