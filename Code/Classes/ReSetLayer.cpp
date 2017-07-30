//
//  ReSetLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/23.
//
//

#include "ReSetLayer.h"
#include "XMLParser.h"
ReSetLayer::ReSetLayer()
{
    
}


ReSetLayer::~ReSetLayer()
{
    
}

ReSetLayer* ReSetLayer::create(AttrBar *_bar, int _coin)
{
    ReSetLayer* pRet = new ReSetLayer;
    if(pRet && pRet->init(_bar, _coin))
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


bool ReSetLayer::init(AttrBar *_bar, int _coin)
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    
    
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite);
//
    _obj = _bar;
    _value = _coin;
    int NowCoin = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COIN);
    if(NowCoin >= _value)
    {
    
        char infochar[100];
        sprintf(infochar, "重置当前属性需要花费%d金币，是否需要重置？" ,_coin);
        InfoLabel = cocos2d::Label::createWithTTF(infochar,"fonts/black.ttf",70);
        InfoLabel->setDimensions(this->getContentSize().width * 0.8, this->getContentSize().height/2);
        InfoLabel->setAlignment(cocos2d::TextHAlignment::CENTER);
        InfoLabel->setPosition(this->getContentSize()/2);
        this->addChild(InfoLabel);
//
        _YesBtn = cocos2d::MenuItemImage::create("UI/ok_btn.png", "UI/ok_btn.png", std::bind(&ReSetLayer::YesCallBack, this));
        _YesBtn->setPosition(this->getContentSize().width/4,this->getContentSize().height/3);
    
        _NoBtn = cocos2d::MenuItemImage::create("UI/no_btn.png", "UI/no_btn.png", std::bind(&ReSetLayer::NoCallBack, this));
        _NoBtn->setPosition(this->getContentSize().width/4*3,this->getContentSize().height/3);
    
        Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COIN, NowCoin - _value);
    
        cocos2d::Menu* menu = cocos2d::Menu::create(_YesBtn,_NoBtn,NULL);
        menu->setPosition(0,0);
        this->addChild(menu);
    }
    else
    {
        InfoLabel = cocos2d::Label::createWithTTF("金币不足无法重置，快去赚些金币吧！","fonts/black.ttf",70);
        InfoLabel->setDimensions(this->getContentSize().width * 0.8, this->getContentSize().height/2);
        InfoLabel->setAlignment(cocos2d::TextHAlignment::CENTER);
        InfoLabel->setPosition(this->getContentSize()/2);
        this->addChild(InfoLabel);

        _NoBtn = cocos2d::MenuItemImage::create("UI/ok_btn.png", "UI/ok_btn.png", std::bind(&ReSetLayer::NoCallBack, this));
        _NoBtn->setPosition(this->getContentSize().width/2,this->getContentSize().height/3);
        
        
        
        cocos2d::Menu* menu = cocos2d::Menu::create(_NoBtn,NULL);
        menu->setPosition(0,0);
        this->addChild(menu);
    }
    return true;
}

void ReSetLayer::YesCallBack()
{
    _obj->Reset();
    NoCallBack();
}

void ReSetLayer::NoCallBack()
{
    this->getParent()->removeChild(this);
}