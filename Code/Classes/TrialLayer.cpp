//
//  TrialLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/18.
//
//

#include "TrialLayer.h"
#include "HomeScene.h"
#include "TrailGameScene.h"
#include "XMLParser.h"
TrialLayer::TrialLayer()
{
    TrialLevel = Parser::XML::getInstance()->GetTrailTop();
}

TrialLayer::~TrialLayer()
{
    
}

bool TrialLayer::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    cocos2d::Size visiblesize = cocos2d::Director::getInstance()->getVisibleSize();

    
    cocos2d::Menu* TrialMenu = cocos2d::Menu::create();
    
    cocos2d::MenuItemImage* TrialFloor = cocos2d::MenuItemImage::create("UI/Trial_floor.png","UI/Trial_floor.png",std::bind(&TrialLayer::GotoHomeScene,this));
    TrialFloor->setPosition(visiblesize.width/2,TrialFloor->getContentSize().height/2);
    TrialMenu->addChild(TrialFloor);
    
    cocos2d::MenuItemImage* TrialStone = cocos2d::MenuItemImage::create("UI/Trial_stone.png","UI/Trial_stone.png",std::bind(&TrialLayer::GotoHomeScene,this));
    TrialStone->setPosition(visiblesize.width/2,200);
    cocos2d::MoveBy* moveby = cocos2d::MoveBy::create(1.0f, cocos2d::Vec2(0,-20));
    cocos2d::Sequence* Seq = cocos2d::Sequence::create(moveby->clone(),moveby->reverse(), NULL);
    cocos2d::RepeatForever* Repeat = cocos2d::RepeatForever::create(Seq);
    TrialStone->runAction(Repeat);
    
    TrialMenu->addChild(TrialStone);
    TrialMenu->setPosition(0,0);
    this->addChild(TrialMenu);
    
    
    cocos2d::MenuItemImage* TrialFrame = cocos2d::MenuItemImage::create("UI/Trial_frame.png","UI/Trial_frame.png",std::bind(&TrialLayer::TrailStart,this));
    TrialFrame->setPosition(visiblesize/2);
    TrialMenu->addChild(TrialFrame);
    
    cocos2d::RotateBy* Rotate = cocos2d::RotateBy::create(5.0f, 180);
    cocos2d::RepeatForever* RotateRepeat = cocos2d::RepeatForever::create(Rotate);
    TrialFrame->runAction(RotateRepeat);
    
    std::string levelstr = cocos2d::StringUtils::format("%d",TrialLevel);
    TrialLevelLabel = cocos2d::Label::createWithTTF(levelstr, "fonts/black.ttf", 100);
    TrialLevelLabel->setColor(cocos2d::Color3B(255,0,0));
    TrialLevelLabel->setPosition(visiblesize/2);
    this->addChild(TrialLevelLabel);
    
    
    return true;
}

void TrialLayer::GotoHomeScene()
{
    HomeScene* scene = HomeScene::create();
    cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.2f, scene);
    cocos2d::Director::getInstance()->replaceScene(fade);
}

void TrialLayer::TrailStart()
{
    TrailGameScene* scene = TrailGameScene::create();
    cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.2f, scene);
    cocos2d::Director::getInstance()->replaceScene(fade);
}