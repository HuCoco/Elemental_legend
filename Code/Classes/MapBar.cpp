//
//  MapBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#include "MapBar.h"
#include "XMLParser.h"
#include "CsvParser.h"
#include "UISystem.h"
#include "JsonParser.h"


MapBar::MapBar()
{
    
}

MapBar::~MapBar()
{
    
}

bool MapBar::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    _MapEvent = TOUCH_NOTHING_IN_MAP;
    
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(MapBar::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(MapBar::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(MapBar::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    
    
    int GateNow = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::CHAPTER_NOW);
    int Complete = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COMPLETE_GATE) - (GateNow-1)*20;
    
    std::string Map1path = cocos2d::StringUtils::format("map/map%d_1.jpg",GateNow);
    std::string Map2path = cocos2d::StringUtils::format("map/map%d_2.jpg",GateNow);
    
    std::vector<GATE_POS_DATA>* GatePosVector = JsonParser::getInstance()->GetGatePosData(GateNow);
    
    
    cocos2d::Sprite* Map1 = cocos2d::Sprite::create(Map1path);
    //delete Map1path;
    Map1->setPosition(Map1->getContentSize().width/2,Map1->getContentSize().height/2);
    MapPool.push_back(Map1);
    this->addChild(Map1,1);
    cocos2d::Menu* _menu1 = cocos2d::Menu::create();
    _menu1->setPosition(0,0);
    Map1->addChild(_menu1);
    cocos2d::Sprite* Map2 = cocos2d::Sprite::create(Map2path);
    //delete Map2path;
    Map2->setPosition(Map1->getPositionX(),Map1->getPositionY() +Map1->getContentSize().height/2+ Map2->getContentSize().height/2);
    MapPool.push_back(Map2);
    this->addChild(Map2);
    cocos2d::Menu* _menu2 = cocos2d::Menu::create();
    _menu2->setPosition(0,0);
    Map2->addChild(_menu2);
    for(int i = 1 ; i <= 20 ;i++)
    {
        int _width = GatePosVector->at(i - 1 ).WidthOdd;
        int _height = GatePosVector->at(i - 1).HeightOdd;
        float _oddw = float(_width)/100.0f;
        float _oddh = float(_height)/100.0f;
        GateBar* pRet;
        if(i > Complete+1)
        {
            pRet = GateBar::create(i,GATE_CANT_GET);
        }
        else if(i == Complete+1)
        {
            pRet = GateBar::create(i,GATE_UNCOMPLETED);
        }
        else if(i <= Complete)
        {
            pRet = GateBar::create(i, GATE_COMPLETED);
        }

        if(i <= 10)
        {
            pRet->setPosition(Map1->getContentSize().width*_oddw,Map1->getContentSize().height*_oddh);
            _menu1->addChild(pRet);
        }
        else
        {
            pRet->setPosition(Map2->getContentSize().width*_oddw,Map2->getContentSize().height*_oddh);
            _menu2->addChild(pRet);
        }
        GateBarPool.push_back(pRet);
    }
    
    return true;
}

bool MapBar::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(!UISystem::getInstance()->getMapCanControl())
    {
        return false;
    }
    
    NowPoint = _touch->getLocation();
    LastPoint = NowPoint;
    _MapEvent = TOUCH_MAP;
    
    return true;
}

void MapBar::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    _MapEvent = TOUCH_MAP;
    if(_MapEvent == TOUCH_MAP)
    {
        NowPoint = _touch->getLocation();
        float LengthY = NowPoint.y - LastPoint.y;
        if(MapPool.at(0)->getPositionY() + LengthY > MapPool.at(0)->getContentSize().height/2 || MapPool.back()->getPositionY() + LengthY < MapPool.back()->getContentSize().height/2)
        {
            return;
        }
        for(int i = 0 ; i < MapPool.size();i++)
        {
            MapPool.at(i)->setPositionY(MapPool.at(i)->getPositionY() + LengthY);
        }
        LastPoint = NowPoint;
    }
}

void MapBar::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(_MapEvent == TOUCH_MAP)
    {
        if(MapPool.at(0)->getPositionY() > cocos2d::Director::getInstance()->getVisibleSize().height/2)
        {
            //cocos2d::log("%f",MapPool.at(0)->getPositionY());
            LeaveBottomAndBack();
        }
        else if(MapPool.back()->getPositionY() < cocos2d::Director::getInstance()->getVisibleSize().height/2)
        {
            //cocos2d::log("%f",MapPool.at(0)->getPositionY());
            LeaveTopAndBack();
        }
    }
    _MapEvent = TOUCH_NOTHING_IN_MAP;
}


void MapBar::LeaveTopAndBack()
{
    float length = cocos2d::Director::getInstance()->getVisibleSize().height/2 - MapPool.back()->getPositionY();
    cocos2d::MoveBy* BackAction = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(0,length));
    for(int i = 0 ; i < MapPool.size();i++)
    {
        MapPool.at(i)->runAction(BackAction->clone());
    }
}

void MapBar::LeaveBottomAndBack()
{
    float length = cocos2d::Director::getInstance()->getVisibleSize().height/2 - MapPool.at(0)->getPositionY();
    cocos2d::MoveBy* BackAction = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(0,length));
    for(int i = 0 ; i < MapPool.size();i++)
    {
        MapPool.at(i)->runAction(BackAction->clone());
    }
}