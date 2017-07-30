//
//  ChapterBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/6.
//
//

#include "ChapterBar.h"
#include "CsvParser.h"
#include "XMLParser.h"
#include "HomeScene.h"
#include "JsonParser.h"
ChapterBar::ChapterBar()
{
    
}

ChapterBar::~ChapterBar()
{
    
}

bool ChapterBar::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    _touchEvent = TOUCH_NOTING_IN_CHAPTER_BAR;
    _isOpen = false;
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(ChapterBar::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(ChapterBar::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(ChapterBar::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    
    cocos2d::Size VisibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    _floor = cocos2d::ui::Scale9Sprite::create("UI/Chapter_floor.png");
    _floor->setInsetBottom(10);
    _floor->setInsetTop(10);
    _floor->setInsetLeft(1);
    _floor->setInsetRight(14);
    _floor->setContentSize(cocos2d::Size(VisibleSize.width/3,VisibleSize.height/2));
    _floor->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    _floor->setPosition(-_floor->getContentSize().width,VisibleSize.height/2);
    this->addChild(_floor);
    cocos2d::Label* chaptertitle = cocos2d::Label::createWithTTF("章节选择","fonts/black.ttf",40);
    chaptertitle->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height - chaptertitle->getContentSize().height*0.8f);
    _floor->addChild(chaptertitle);

    std::vector<CHAPTER_INFO_DATA>* ChapterDataVector = JsonParser::getInstance()->GetChapterData();
    int NowChap = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::CHAPTER_NOW);
    int CompleteChap = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COMPLETE_CHAPTER);
    for(int i = 1;i<=5;i++)
    {
        CHAPTER_DATA Chap_1;
        Chap_1._chapterSpirte= cocos2d::ui::Scale9Sprite::create("UI/Chapter_part.png");
        Chap_1._chapterSpirte->setInsetBottom(14);
        Chap_1._chapterSpirte->setInsetTop(14);
        Chap_1._chapterSpirte->setInsetLeft(1);
        Chap_1._chapterSpirte->setInsetRight(35);
        Chap_1._chapterSpirte->setContentSize(cocos2d::Size(_floor->getContentSize().width*0.9f,_floor->getContentSize().height/6));
        Chap_1._chapterSpirte->setAnchorPoint(cocos2d::Vec2(0,0.5f));
        Chap_1._chapterSpirte->setPosition(0,_floor->getContentSize().height - Chap_1._chapterSpirte->getContentSize().height/2-70 - (Chap_1._chapterSpirte->getContentSize().height + 5) *(i-1));
        ChapterPool.push_back(Chap_1);
        _floor->addChild(ChapterPool.back()._chapterSpirte);
        cocos2d::Label* chapterNum = cocos2d::Label::createWithTTF(ChapterDataVector->at(i-1).ChapterTitle,"fonts/black.ttf",30);
        chapterNum->setPosition(Chap_1._chapterSpirte->getContentSize().width/2,Chap_1._chapterSpirte->getContentSize().height - chapterNum->getContentSize().height*0.8f);
        ChapterPool.back()._chapterSpirte->addChild(chapterNum);
        cocos2d::Label* chapterName = cocos2d::Label::createWithTTF(ChapterDataVector->at(i-1).ChapterInfo,"fonts/black.ttf",30);
        chapterName->setPosition(Chap_1._chapterSpirte->getContentSize().width/2, chapterNum->getContentSize().height*0.8f);
        ChapterPool.back()._chapterSpirte->addChild(chapterName);
        ChapterPool.back()._isOpen = true;
        if(NowChap == i)
        {
            chapterName->setColor(cocos2d::Color3B(255,255,0));
            chapterNum->setColor(cocos2d::Color3B(255,255,0));
        }
        else if(i > CompleteChap)
        {
            chapterName->setColor(cocos2d::Color3B(40,40,40));
            chapterNum->setOpacity(200);
            chapterNum->setColor(cocos2d::Color3B(40,40,40));
            chapterName->setOpacity(200);
            ChapterPool.back()._isOpen = false;
        }
    }
    return true;
}

void ChapterBar::Open()
{
    cocos2d::MoveTo* MoveOpen = cocos2d::MoveTo::create(0.2f, cocos2d::Vec2(0,cocos2d::Director::getInstance()->getVisibleSize().height/2));
    _floor->runAction(MoveOpen);
    _isOpen = true;
}

void ChapterBar::Close()
{
    cocos2d::MoveTo* MoveClose = cocos2d::MoveTo::create(0.2f, cocos2d::Vec2(-_floor->getContentSize().width,cocos2d::Director::getInstance()->getVisibleSize().height/2));
    _floor->runAction(MoveClose);
    _isOpen = false;
}

bool ChapterBar::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    NowPoint = _touch->getLocation();
    if(NowPoint.x < 50 && NowPoint.y > _floor->getPositionY() - _floor->getContentSize().height/2 && NowPoint.y < _floor->getPositionY() + _floor->getContentSize().height/2)
    {
        _touchEvent = TOUCH_MOVE_IN_CHAPTER_BAR;
        LastPoint = NowPoint;
        return true;
    }
    else if(_floor->getBoundingBox().containsPoint(NowPoint) && _isOpen == true)
    {
        _touchEvent = TOUCH_CHAPTER;
        LastPoint = NowPoint;
        return true;
    }
    return false;
}


void ChapterBar::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    _touchEvent = TOUCH_MOVE_IN_CHAPTER_BAR;
    NowPoint = _touch->getLocation();
    if(_touchEvent == TOUCH_MOVE_IN_CHAPTER_BAR)
    {
        float lengthVar = NowPoint.x - LastPoint.x;
        float NextPosX = _floor->getPositionX() + lengthVar;
        if(NextPosX > 0)
        {
            NextPosX = 0;
        }
        _floor->setPositionX(NextPosX);
    }
    LastPoint = NowPoint;
}

void ChapterBar::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(_touchEvent == TOUCH_MOVE_IN_CHAPTER_BAR)
    {
        if(_floor->getPositionX() < -_floor->getContentSize().width/2)
        {
            Close();
        }
        else if(_floor->getPositionX() >= -_floor->getContentSize().width/2)
        {
            Open();
        }
    }
    else if(_touchEvent == TOUCH_CHAPTER)
    {
        for (int i = 0;i<ChapterPool.size(); i++)
        {
            if(ChapterPool.at(i)._chapterSpirte->getBoundingBox().containsPoint(_floor->convertToNodeSpace(_touch->getLocation())) && ChapterPool.at(i)._isOpen)
            {
                Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::CHAPTER_NOW, i+1);
                cocos2d::Director::getInstance()->resume();
                HomeScene* scene = HomeScene::create();
                cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.5f, scene);
                cocos2d::Director::getInstance()->replaceScene(fade);
                break;
            }
        }
    }
    _touchEvent = TOUCH_NOTING_IN_CHAPTER_BAR;
}