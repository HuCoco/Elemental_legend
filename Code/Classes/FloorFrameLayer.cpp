//
//  FloorFrameLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/24.
//
//

#include "FloorFrameLayer.h"
#include "XMLParser.h"
FloorFrameLayer::FloorFrameLayer()
{
    
}

FloorFrameLayer::~FloorFrameLayer()
{
    
}

bool FloorFrameLayer::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    int ChapterNum = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::CHAPTER_NOW);
    char bkPath[20];
    sprintf(bkPath, "UI/chapter_%d.png",ChapterNum);
    cocos2d::Sprite* Bk = cocos2d::Sprite::create(bkPath);
    Bk->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height - Bk->getContentSize().height/2);
    this->addChild(Bk);
    
    
    
    _floor = cocos2d::ui::Scale9Sprite::create("UI/bk_floor.png");
    _floor->setInsetTop(30);
    _floor->setInsetBottom(20);
    _floor->setInsetLeft(20);
    _floor->setInsetRight(20);
    _floor->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width,cocos2d::Director::getInstance()->getVisibleSize().width));
    _floor->setPosition(_floor->getContentSize()/2);
    this->addChild(_floor);
    
    _frame = cocos2d::ui::Scale9Sprite::create("UI/bk_floorframe.png");
    _frame->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width/45*41,cocos2d::Director::getInstance()->getVisibleSize().width/90*81));
    _frame->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width/2,_frame->getContentSize().height/2);
    this->addChild(_frame);

    
    
    return true;
}