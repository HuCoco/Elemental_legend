//
//  GuideMsgBox.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/29.
//
//

#include "GuideMsgBox.h"
#include "GuideScene.h"
#include "HomeScene.h"
#include "XMLParser.h"
GuideMsgBox::GuideMsgBox()
{
    
}

GuideMsgBox::~GuideMsgBox()
{
    
}

bool GuideMsgBox::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite);

    _floor = cocos2d::ui::Scale9Sprite::create("UI/playerconfig_skillfloor.png");
    _floor->setContentSize(cocos2d::Size(visibleSize.width/9*5,visibleSize.width/3));
    _floor->setPosition(visibleSize.width/2,visibleSize.height/3*2);
    this->addChild(_floor);
    
    cocos2d::Label* Tips1 = cocos2d::Label::createWithTTF("是否进入新手指导?", "fonts/black.ttf", 40);
    Tips1->setColor(cocos2d::Color3B(0,0,0));
    Tips1->setDimensions(_floor->getContentSize().width/8*7,_floor->getContentSize().height/3*2);
    Tips1->setAlignment(cocos2d::TextHAlignment::CENTER);
    Tips1->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height/5*2);
    _floor->addChild(Tips1);
    
    
    okBtn = cocos2d::MenuItemImage::create("UI/ok_btn.png","UI/ok_btn.png",std::bind(&GuideMsgBox::OKCallback,this));
    okBtn->setPosition(_floor->getContentSize().width/15*4,_floor->getContentSize().height/6);
    noBtn = cocos2d::MenuItemImage::create("UI/no_btn.png","UI/no_btn.png",std::bind(&GuideMsgBox::NOCallback,this));
    noBtn->setPosition(_floor->getContentSize().width/15*11,_floor->getContentSize().height/6);
    
    _menu = cocos2d::Menu::create(okBtn,noBtn,NULL);
    _menu->setPosition(0,0);
    _floor->addChild(_menu);
    
    
    return true;
}

void GuideMsgBox::OKCallback()
{
    GuideScene* scene = GuideScene::create();
    cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.5f, scene);
    cocos2d::Director::getInstance()->replaceScene(fade);
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::FRISTGAME, false);
}


void GuideMsgBox::NOCallback()
{
    HomeScene* scene = HomeScene::create();
    cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.5f, scene);
    cocos2d::Director::getInstance()->replaceScene(fade);
    Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::FRISTGAME, false);
}


