//
//  PlayStateBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/7.
//
//

#include "PlayStateBar.h"
#include "AttrSystem.h"
#include "XMLParser.h"

PlayStateBar::PlayStateBar()
{
    
}

PlayStateBar::~PlayStateBar()
{
    
}

bool PlayStateBar::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    _isOpen = false;
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(PlayStateBar::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(PlayStateBar::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(PlayStateBar::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    
    cocos2d::Size VisibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    _floor = cocos2d::ui::Scale9Sprite::create("UI/player_state_floor.png");
    _floor->setInsetBottom(10);
    _floor->setInsetTop(10);
    _floor->setInsetLeft(14);
    _floor->setInsetRight(1);
    _floor->setContentSize(cocos2d::Size(VisibleSize.width/3,VisibleSize.height/5*2));
    _floor->setAnchorPoint(cocos2d::Vec2(1,0.5f));
    _floor->setPosition(VisibleSize.width + _floor->getContentSize().width,VisibleSize.height/2);
    this->addChild(_floor);

    cocos2d::Label* statetitle = cocos2d::Label::createWithTTF("人物属性","fonts/black.ttf",40);
    statetitle->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height - statetitle->getContentSize().height*0.8f);
    _floor->addChild(statetitle);

    LvBar = IconLabelBar::create("UI/lv_bar.png",false,Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::LEVEL),_floor->getContentSize().width*0.8f);
    LvBar->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height - statetitle->getContentSize().height - LvBar->getContentSize().height-10);
    _floor->addChild(LvBar);
    
    AtkBar = IconLabelBar::create("UI/atk_bar.png",false,AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_ATK),_floor->getContentSize().width*0.8f);
    AtkBar->setPosition(_floor->getContentSize().width/2,LvBar->getPositionY() - (AtkBar->getContentSize().height*2) * 1);
    _floor->addChild(AtkBar);
    
    DefBar = IconLabelBar::create("UI/def_bar.png",false,AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_DEF),_floor->getContentSize().width*0.8f);
    DefBar->setPosition(_floor->getContentSize().width/2,LvBar->getPositionY() - (AtkBar->getContentSize().height *2) * 2);
    _floor->addChild(DefBar);
    
    HealthBar = IconLabelBar::create("UI/health_bar.png",false,AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_HEALTH),_floor->getContentSize().width*0.8f);
    HealthBar->setPosition(_floor->getContentSize().width/2,LvBar->getPositionY() - (AtkBar->getContentSize().height *2) * 3);
    _floor->addChild(HealthBar);
    
    MagicBar = IconLabelBar::create("UI/magic_bar.png",false,AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_MAGIC),_floor->getContentSize().width*0.8f);
    MagicBar->setPosition(_floor->getContentSize().width/2,LvBar->getPositionY() - (AtkBar->getContentSize().height *2) * 4);
    _floor->addChild(MagicBar);
    
    SheildBar = IconLabelBar::create("UI/sheild_bar.png",false,AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SHIELD),_floor->getContentSize().width*0.8f);
    SheildBar->setPosition(_floor->getContentSize().width/2,LvBar->getPositionY() - (AtkBar->getContentSize().height *2) * 5);
    _floor->addChild(SheildBar);
    
    SpeedBar = IconLabelBar::create("UI/speed_bar.png",false,AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SPEED),_floor->getContentSize().width*0.8f);
    SpeedBar->setPosition(_floor->getContentSize().width/2,LvBar->getPositionY() - (AtkBar->getContentSize().height *2) * 6);
    _floor->addChild(SpeedBar);
    
    RehpBar = IconLabelBar::create("UI/rehp_bar.png",false,AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REHP),_floor->getContentSize().width*0.8f);
    RehpBar->setPosition(_floor->getContentSize().width/2,LvBar->getPositionY() - (AtkBar->getContentSize().height  *2) * 7);
    _floor->addChild(RehpBar);
    
    RempBar = IconLabelBar::create("UI/remp_bar.png",false,AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REMP),_floor->getContentSize().width*0.8f);
    RempBar->setPosition(_floor->getContentSize().width/2,LvBar->getPositionY() - (AtkBar->getContentSize().height *2) * 8);
    _floor->addChild(RempBar);
    
    TimeBar = IconLabelBar::create("UI/time_bar.png",false,AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_BUFFTIME),_floor->getContentSize().width*0.8f);
    TimeBar->setPosition(_floor->getContentSize().width/2,LvBar->getPositionY() - (AtkBar->getContentSize().height  *2) * 9);
    _floor->addChild(TimeBar);
    
    
    this->schedule(std::bind(&PlayStateBar::updateStateData,this), "updatestatedata");
    return true;
}

void PlayStateBar::updateStateData()
{
    AttrSystem::getInstance()->Update();
    LvBar->setValue(Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::LEVEL));
    AtkBar->setValue(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_ATK));
    DefBar->setValue(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_DEF));
    HealthBar->setValue(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_HEALTH));
    MagicBar->setValue(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_MAGIC));
    SheildBar->setValue(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SHIELD));
    SpeedBar->setValue(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SPEED));
    RehpBar->setValue(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REHP));
    RempBar->setValue(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_REMP));
    TimeBar->setValue(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_BUFFTIME));
}

void PlayStateBar::Open()
{
    cocos2d::MoveTo* MoveOpen = cocos2d::MoveTo::create(0.2f, cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width,cocos2d::Director::getInstance()->getVisibleSize().height/2));
    _floor->runAction(MoveOpen);
    _isOpen = true;
}

void PlayStateBar::Close()
{
    cocos2d::MoveTo* MoveClose = cocos2d::MoveTo::create(0.2f, cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width+_floor->getContentSize().width,cocos2d::Director::getInstance()->getVisibleSize().height/2));
    _floor->runAction(MoveClose);
    _isOpen = false;
}
bool PlayStateBar::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    NowPoint = _touch->getLocation();
    if(NowPoint.x > cocos2d::Director::getInstance()->getVisibleSize().width - 50 && NowPoint.y > _floor->getPositionY() - _floor->getContentSize().height/2 && NowPoint.y < _floor->getPositionY() + _floor->getContentSize().height/2)
    {
        //_touchEvent = TOUCH_MOVE_IN_CHAPTER_BAR;
        LastPoint = NowPoint;
        return true;
    }
    else if(_floor->getBoundingBox().containsPoint(NowPoint) && _isOpen == true)
    {
        //_touchEvent = TOUCH_CHAPTER;
        LastPoint = NowPoint;
        return true;
    }
    return false;
}


void PlayStateBar::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    //_touchEvent = TOUCH_MOVE_IN_CHAPTER_BAR;
    NowPoint = _touch->getLocation();
    float lengthVar = NowPoint.x - LastPoint.x;
    float NextPosX = _floor->getPositionX() + lengthVar;
    if(NextPosX < cocos2d::Director::getInstance()->getVisibleSize().width)
    {
        NextPosX = cocos2d::Director::getInstance()->getVisibleSize().width;
    }
    _floor->setPositionX(NextPosX);
    LastPoint = NowPoint;
}


void PlayStateBar::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{

        if(_floor->getPositionX() > cocos2d::Director::getInstance()->getVisibleSize().width + _floor->getContentSize().width/2)
        {
            Close();
        }
        else if(_floor->getPositionX() <= cocos2d::Director::getInstance()->getVisibleSize().width + _floor->getContentSize().width/2)
        {
            Open();
        }

//    else if(_touchEvent == TOUCH_CHAPTER)
//    {
//        for (int i = 0;i<ChapterPool.size(); i++)
//        {
//            if(ChapterPool.at(i)._chapterSpirte->getBoundingBox().containsPoint(_floor->convertToNodeSpace(_touch->getLocation())) && ChapterPool.at(i)._isOpen)
//            {
//                Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::CHAPTER_NOW, i+1);
//                cocos2d::Director::getInstance()->resume();
//                HomeScene* scene = HomeScene::create();
//                cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.5f, scene);
//                cocos2d::Director::getInstance()->replaceScene(fade);
//                break;
//            }
//        }
//    }
//    _touchEvent = TOUCH_NOTING_IN_CHAPTER_BAR;
}