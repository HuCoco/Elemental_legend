//
//  WelcomeGuideLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#include "WelcomeGuideLayer.h"

WelcomeGuideLayer::WelcomeGuideLayer()
{
    
}


WelcomeGuideLayer::~WelcomeGuideLayer()
{
    
}

bool WelcomeGuideLayer::init()
{
    if(!BaseGuideLayer::init())
    {
        return false;
    }
    
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(WelcomeGuideLayer::onTouchBegan, this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(WelcomeGuideLayer::onTouchMoved, this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(WelcomeGuideLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    
    cocos2d::Label* Tips1 = cocos2d::Label::createWithTTF("欢迎来到新手指导，下面将会给大家介绍此游戏", "fonts/black.ttf", 60);
    Tips1->setDimensions(cocos2d::Director::getInstance()->getVisibleSize().width/8*7,cocos2d::Director::getInstance()->getVisibleSize().height/5);
    Tips1->setAlignment(cocos2d::TextHAlignment::CENTER);
    Tips1->setPosition(cocos2d::Director::getInstance()->getVisibleSize()/2);
    this->addChild(Tips1);
    
    AddTouchTips();
    
    
    return true;
}

bool WelcomeGuideLayer::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(!CanTouch)
    {
        return false;
    }
    
    this->getParent()->addChild(Parent->at(thisNum+1),5);
    this->getParent()->removeChild(this);
    return true;
    return true;
}


void WelcomeGuideLayer::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}

void WelcomeGuideLayer::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}