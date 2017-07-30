//
//  PauseLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/15.
//
//

#include "PauseLayer.h"
#include "HomeScene.h"

PauseLayer::PauseLayer()
{
    
}


PauseLayer::~PauseLayer()
{
    
}

bool PauseLayer::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite);
    
    _homebtn = cocos2d::MenuItemImage::create("UI/home_btn.png","UI/home_btn.png",std::bind(&PauseLayer::GoToHomeScene,this));
    _homebtn->setPosition(visibleSize.width/2,visibleSize.height/2 + _homebtn->getContentSize().height);
    
    _resumebtn = cocos2d::MenuItemImage::create("UI/resume_btn.png","UI/resume_btn.png",std::bind(&PauseLayer::ResumeGame,this));
    _resumebtn->setPosition(visibleSize.width/2,visibleSize.height/2 - _resumebtn->getContentSize().height);
    
    _menu = cocos2d::Menu::create(_homebtn,_resumebtn,NULL);
    _menu->setPosition(0,0);
    this->addChild(_menu);
    
    return true;
}

void PauseLayer::GoToHomeScene()
{
    cocos2d::Director::getInstance()->resume();
    HomeScene* scene = HomeScene::create();
    cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.5f, scene);
    cocos2d::Director::getInstance()->replaceScene(fade);
}


void PauseLayer::ResumeGame()
{
    this->getParent()->removeChild(this);
    cocos2d::Director::getInstance()->resume();
    
}