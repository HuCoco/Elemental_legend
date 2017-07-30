//
//  ChestBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/4.
//
//

#include "ChestBar.h"
#include "ChestLayer.h"
#include "UISystem.h"
ChestBar::ChestBar()
{
    
}

ChestBar::~ChestBar()
{
    
}

bool ChestBar::init()
{
    if(!cocos2d::Node::init())
    {
        return false;
    }
    _touchEvent = TOUCH_NOTHING_IN_CHEST;
    
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(false);
    _touchListener->onTouchBegan = CC_CALLBACK_2(ChestBar::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(ChestBar::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(ChestBar::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener,this);
    
    cocos2d::Size floorSize = cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width,cocos2d::Director::getInstance()->getVisibleSize().height/16*5);
    sliverChest = cocos2d::Sprite::create("UI/sliverbox.png");
    sliverChest->setScale(2);
    sliverChest->setPosition(floorSize.width/16*5,floorSize.height/2);
    this->addChild(sliverChest);
    
    sliverIcon = cocos2d::Sprite::create("UI/topstatebar_coin.png");
    sliverIcon->setPosition(sliverChest->getPositionX() - sliverIcon->getContentSize().width, floorSize.height/6);
    this->addChild(sliverIcon);
    
    sliverLabel = cocos2d::Label::createWithTTF("100", "fonts/black.ttf", 40);
    sliverLabel->setColor(cocos2d::Color3B(0,0,0));
    sliverLabel->setPosition(sliverChest->getPositionX()+ sliverIcon->getContentSize().width/2,floorSize.height/6);
    this->addChild(sliverLabel);
    
    goldenChest = cocos2d::Sprite::create("UI/goldenbox.png");
    goldenChest->setScale(2);
    goldenChest->setPosition(floorSize.width/16*11,floorSize.height/2);
    this->addChild(goldenChest);
    
    goldenIcon = cocos2d::Sprite::create("UI/topstatebar_diamonds.png");
    goldenIcon->setPosition(goldenChest->getPositionX() - goldenIcon->getContentSize().width/2, floorSize.height/6);
    this->addChild(goldenIcon);
    
    goldenLabel = cocos2d::Label::createWithTTF("10", "fonts/black.ttf", 40);
    goldenLabel->setColor(cocos2d::Color3B(0,0,0));
    goldenLabel->setPosition(goldenChest->getPositionX()+ goldenIcon->getContentSize().width/2,floorSize.height/6);
    this->addChild(goldenLabel);
    
    return true;
}

bool ChestBar::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(!UISystem::getInstance()->getBottomStateBarControl())
    {
        return false;
    }
    cocos2d::Point touchPoint = this->convertToNodeSpace(_touch->getLocation());
    if(sliverChest->getBoundingBox().containsPoint(touchPoint))
    {
        _touchEvent = TOUCH_SLIVER_CHEST;

        return true;
    }
    else if (goldenChest->getBoundingBox().containsPoint(touchPoint))
    {
        _touchEvent = TOUCH_GOLDEN_CHEST;

        return true;
    }
    return false;
}

void ChestBar::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    _touchEvent = TOUCH_NOTHING_IN_CHEST;
}

void ChestBar::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(_touchEvent == TOUCH_GOLDEN_CHEST)
    {
        ChestLayer* pRet = ChestLayer::create(CHEST_TYPE::GOLDEN);
        this->getParent()->getParent()->addChild(pRet);
        UISystem::getInstance()->setBottomStateBarControl(false);
        UISystem::getInstance()->setMapCanControl(false);
        UISystem::getInstance()->setTopStateBarControl(false);
    }
    else if(_touchEvent == TOUCH_SLIVER_CHEST)
    {
        ChestLayer* pRet = ChestLayer::create(CHEST_TYPE::SLIVER);
        this->getParent()->getParent()->addChild(pRet);
        UISystem::getInstance()->setBottomStateBarControl(false);
        UISystem::getInstance()->setMapCanControl(false);
        UISystem::getInstance()->setTopStateBarControl(false);
    }
}