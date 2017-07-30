//
//  WelcomeLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#include "WelcomeLayer.h"
#include "HomeScene.h"
#include "GuideScene.h"
#include "XMLParser.h"
#include "GuideMsgBox.h"
#include "JsonParser.h"
WelcomeLayer::WelcomeLayer()
{
    
}

WelcomeLayer::~WelcomeLayer()
{
    
}

bool WelcomeLayer::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    cocos2d::Sprite* name = cocos2d::Sprite::create("GameName.png");
    name->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/5*4);
    this->addChild(name,1);
    
    
    BackgroundImageSprite = cocos2d::Sprite::create("bk.png");
    BackgroundImageSprite->setPosition(cocos2d::Director::getInstance()->getVisibleSize()/2);
    this->addChild(BackgroundImageSprite);
    
    StartGameBtn = cocos2d::MenuItemImage::create("UI/gamestart_btn.png","UI/gamestart_btn.png",std::bind(&WelcomeLayer::StartGameBtnCallBack,this));
    StartGameBtn->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/4);
    _menu = cocos2d::Menu::create(StartGameBtn,nullptr);
    _menu->setPosition(0,0);
    this->addChild(_menu);
    


    return true;
}


void WelcomeLayer::StartGameBtnCallBack()
{
    if(!Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::FRISTGAME))
    {
        cocos2d::Director::getInstance()->resume();
        HomeScene* scene = HomeScene::create();
        cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.5f, scene);
        cocos2d::Director::getInstance()->replaceScene(fade);
    }
    else
    {
        GuideMsgBox* box = GuideMsgBox::create();
        this->addChild(box,2);
    }
}