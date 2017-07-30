//
//  TopStateBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/10.
//
//

#include "TopStateBar.h"
#include "XMLParser.h"
#include "PlayerConfig.h"
#include "BaseMissionBar.h"
#include "UISystem.h"
#include "IconLabelBar.h"
#include "MissionSystem.h"

TopStateBar::TopStateBar()
{
    
}

TopStateBar::~TopStateBar()
{
    
}

bool TopStateBar::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(TopStateBar::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(TopStateBar::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(TopStateBar::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    _tsTouchEvent = TOP_STATE_BAR_TOUCH_EVENT::TOUCH_NOTHING;
    
    cocos2d::Size VisibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    FloorSprite = cocos2d::ui::Scale9Sprite::create("UI/topstatebar_floor.png");
    //    FloorSprite->setInsetLeft(30);
    //    FloorSprite->setInsetRight(30);
    //    FloorSprite->setInsetBottom(30);
    //    FloorSprite->setInsetTop(30);
    FloorSprite->setContentSize(cocos2d::Size(VisibleSize.width,VisibleSize.height/4));
    FloorSprite->setPosition(cocos2d::Vec2(VisibleSize.width/2,VisibleSize.height + FloorSprite->getContentSize().height/4));
    this->addChild(FloorSprite);
    
    LevelFrameSprite = cocos2d::Sprite::create("UI/topstatebar_levelframe.png");
    LevelFrameSprite->setPosition(cocos2d::Vec2(VisibleSize.width/2,FloorSprite->getContentSize().height/10));
    FloorSprite->addChild(LevelFrameSprite);
    

    
    CoinBar = IconLabelBar::create("UI/topstatebar_coin.png",true);
    CoinBar->setPosition(cocos2d::Vec2(FloorSprite->getContentSize().height/10 + CoinBar->getContentSize().width/2,FloorSprite->getContentSize().height/10+10));
    CoinBar->SetBuyType(B_COIN);
    FloorSprite->addChild(CoinBar);
    
    
    DiamondsBar = IconLabelBar::create("UI/topstatebar_diamonds.png",true);
    DiamondsBar->setPosition(cocos2d::Vec2(FloorSprite->getContentSize().width - FloorSprite->getContentSize().height/10 - DiamondsBar->getContentSize().width+ CoinBar->getContentSize().width/2,FloorSprite->getContentSize().height/10+10));
    FloorSprite->addChild(DiamondsBar);
    
    
    cocos2d::ui::Scale9Sprite* Mission1Sprite = cocos2d::ui::Scale9Sprite::create("UI/topstatebar_missionfloor.png");
    Mission1Sprite->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width/18*5,cocos2d::Director::getInstance()->getVisibleSize().width/18*5));
    Mission1Sprite->setPosition(cocos2d::Vec2(FloorSprite->getContentSize().width/5,FloorSprite->getContentSize().height/4 + Mission1Sprite->getContentSize().height/2+10));
    Mission1Sprite->setColor(cocos2d::Color3B(47,47,47));
    FloorSprite->addChild(Mission1Sprite);
    MissionFloorPool.push_back(Mission1Sprite);
    
    cocos2d::ui::Scale9Sprite* Mission2Sprite = cocos2d::ui::Scale9Sprite::create("UI/topstatebar_missionfloor.png");
    Mission2Sprite->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width/18*5,cocos2d::Director::getInstance()->getVisibleSize().width/18*5));
    Mission2Sprite->setPosition(cocos2d::Vec2(FloorSprite->getContentSize().width/2,FloorSprite->getContentSize().height/4 + Mission2Sprite->getContentSize().height/2+10));
    Mission2Sprite->setColor(cocos2d::Color3B(47,47,47));
    FloorSprite->addChild(Mission2Sprite);
    
    MissionFloorPool.push_back(Mission2Sprite);
    cocos2d::ui::Scale9Sprite* Mission3Sprite = cocos2d::ui::Scale9Sprite::create("UI/topstatebar_missionfloor.png");
    Mission3Sprite->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width/18*5,cocos2d::Director::getInstance()->getVisibleSize().width/18*5));
    Mission3Sprite->setPosition(cocos2d::Vec2(FloorSprite->getContentSize().width/5*4,FloorSprite->getContentSize().height/4+ Mission3Sprite->getContentSize().height/2+10));
    Mission3Sprite->setColor(cocos2d::Color3B(47,47,47));
    FloorSprite->addChild(Mission3Sprite);
    MissionFloorPool.push_back(Mission3Sprite);
    
    
    MissionSystem::getInstance()->Read();
    
    int MissionNum = 0;
    for(int i = 0;i<3;i++)
    {
        for(int j = MissionNum; j <3;j++)
        {
            if(MissionSystem::getInstance()->GetMissionData(j)._MissionType == MISSION_TYPE::NO_MISSION)
            {
                continue;
            }
            else
            {
                BaseMissionBar* pRet = BaseMissionBar::create();
                pRet->setPosition(MissionFloorPool.at(i)->getPosition());
                pRet->InitMissionData(MissionSystem::getInstance()->GetMissionData(j)._MissionType,MissionSystem::getInstance()->GetMissionData(j)._MissionValue);
                FloorSprite->addChild(pRet);
                MissionBarPool.push_back(pRet);
                MissionNum = j+1;
                break;
            }
        }
    }
    
    
    
    
    
    
    this->schedule(std::bind(&TopStateBar::UpdateCur,this), "updatecur");
    
    return true;
}

void TopStateBar::UpdateCur()
{
    CoinBar->setValue(Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COIN));
    DiamondsBar->setValue(Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::DIAMONDS));
}


void TopStateBar::Open()
{
    cocos2d::MoveTo* FloorMove = cocos2d::MoveTo::create(0.2f, cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height - FloorSprite->getContentSize().height/2));
    FloorSprite->runAction(FloorMove);
    UISystem::getInstance()->OpenTopStateBar();
    
}

void TopStateBar::Close()
{
    cocos2d::MoveTo* FloorMove = cocos2d::MoveTo::create(0.2f, cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height + FloorSprite->getContentSize().height/4));
    FloorSprite->runAction(FloorMove);
    UISystem::getInstance()->CloseTopStateBar();
    
}

bool TopStateBar::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(!UISystem::getInstance()->getTopStateBarControl())
    {
        return false;
    }
    cocos2d::Point _touchPoint = _touch->getLocation();
    cocos2d::Point _touchPointLevel = FloorSprite->convertToNodeSpace(_touch->getLocation());
    if(LevelFrameSprite->getBoundingBox().containsPoint(_touchPointLevel))
    {
        _tsTouchEvent = TOP_STATE_BAR_TOUCH_EVENT::TOUCH_LEVEL;
        return true;
    }
    else if(!LevelFrameSprite->getBoundingBox().containsPoint(_touchPoint) && FloorSprite->getBoundingBox().containsPoint(_touchPoint))
    {
        _tsTouchEvent = TOP_STATE_BAR_TOUCH_EVENT::TOUCH_FLOOR;
        LastTouchPoint = _touchPoint;
        return true;
    }
    return false;
}


void TopStateBar::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(_tsTouchEvent == TOP_STATE_BAR_TOUCH_EVENT::TOUCH_FLOOR)
    {
        NowTouchPoint = _touch->getLocation();
        float _dir = NowTouchPoint.y - LastTouchPoint.y;
        float NextPos = FloorSprite->getPositionY() + _dir;
        
        if(NextPos < cocos2d::Director::getInstance()->getVisibleSize().height - FloorSprite->getContentSize().height/2)
        {
            NextPos = cocos2d::Director::getInstance()->getVisibleSize().height - FloorSprite->getContentSize().height/2;
        }
        else if(NextPos > cocos2d::Director::getInstance()->getVisibleSize().height + FloorSprite->getContentSize().height/4)
        {
            NextPos = cocos2d::Director::getInstance()->getVisibleSize().height + FloorSprite->getContentSize().height/4;
        }
        
        LastTouchPoint = NowTouchPoint;
        FloorSprite->setPositionY(NextPos);
        
    }
}

void TopStateBar::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    switch (_tsTouchEvent) {
        case TOUCH_FLOOR:
        {
            if(FloorSprite->getPositionY() > cocos2d::Director::getInstance()->getVisibleSize().height)
            {
                Close();
            }
            else if(FloorSprite->getPositionY() <= cocos2d::Director::getInstance()->getVisibleSize().height)
            {
                Open();
            }
            
        }
            break;
        case TOUCH_LEVEL:
        {
            if(this->getChildByName("PlayerConfig") == nullptr && LevelFrameSprite->getBoundingBox().containsPoint(FloorSprite->convertToNodeSpace(_touch->getLocation())))
            {
                PlayerConfig* _playerconfig = PlayerConfig::create();
                _playerconfig->AddToTag(this->getParent());
                UISystem::getInstance()->OpenPlayerConfig();
            }
        }
            break;
        default:
            break;
    }
    _tsTouchEvent = TOUCH_NOTHING;
}


