//
//  BottomStateBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/11.
//
//

#include "BottomStateBar.h"
#include "AudioSystem.h"
#include "UISystem.h"
#include "SliderBar.h"
#include "ChestBar.h"
#include "TrialScene.h"
BottomStateBar::BottomStateBar()
{
    _bsTouchEvent = NONE_MOVE;
    isOpen = false;
    NowPage = 0;
}

BottomStateBar::~BottomStateBar()
{
    
}

bool BottomStateBar::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    cocos2d::Size VisibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(BottomStateBar::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(BottomStateBar::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(BottomStateBar::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);

    
    _floor = cocos2d::ui::Scale9Sprite::create("UI/bottomstatebar_floor.png");
    _floor->setInsetRight(26);
    _floor->setInsetLeft(26);
    _floor->setInsetBottom(10);
    _floor->setInsetTop(30);


    
    
    _floor->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width,cocos2d::Director::getInstance()->getVisibleSize().height/16*5));
    _floor->setPosition(VisibleSize.width/2,-_floor->getContentSize().height/10*3);
    this->addChild(_floor);
    cocos2d::ui::Scale9Sprite* _titleSprite = cocos2d::ui::Scale9Sprite::create("UI/bottom_title.png");
    _titleSprite->setContentSize(cocos2d::Size(_floor->getContentSize().width*0.75f,_floor->getContentSize().height/4));
    _titleSprite->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height - _titleSprite->getContentSize().height/2);
    _floor->addChild(_titleSprite);
    _title = cocos2d::Label::createWithTTF("更多内容","fonts/black.ttf", 60);
    _title->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height - _title->getContentSize().height/2 - 10);
    _title->setColor(cocos2d::Color3B(235,198,96));
    _floor->addChild(_title);
    
    _bmbtn = SliderBar::create("UI/bmusic_on.png", "UI/bmusic_off.png","UI/slider_btn.png", "UI/slider_floor.png");
    _bmbtn->SetSliderBarType(SLIDER_BAR_TYPE::BACKGROUND_MUSIC);
    _bmbtn->SetState(AudioSystem::getInstance()->GetBMSwitch());
    _bmbtn->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width/2,_floor->getContentSize().height/5*3);
    
    
    _embtn = SliderBar::create("UI/emusic_on.png", "UI/emusic_off.png","UI/slider_btn.png", "UI/slider_floor.png");
    _embtn->SetSliderBarType(SLIDER_BAR_TYPE::EFFICTIVE_MUSIC);
    _embtn->SetState(AudioSystem::getInstance()->GetEMSwitch());
    _embtn->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width/2,_floor->getContentSize().height/10*3 - 15);

    PAGES_NODE Page4;
    Page4.pageName = "试练之地";
    Page4.page = cocos2d::Node::create();
    
    cocos2d::Menu* TrialMenu = cocos2d::Menu::create();
    
    cocos2d::MenuItemImage* TrialFloor = cocos2d::MenuItemImage::create("UI/Trial_floor.png","UI/Trial_floor.png",std::bind(&BottomStateBar::GotoTrial,this));
    TrialFloor->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height/4);
    TrialMenu->addChild(TrialFloor);
    
    cocos2d::MenuItemImage* TrialStone = cocos2d::MenuItemImage::create("UI/Trial_stone.png","UI/Trial_stone.png",std::bind(&BottomStateBar::GotoTrial,this));
    TrialStone->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height/2);
    cocos2d::MoveBy* moveby = cocos2d::MoveBy::create(1.0f, cocos2d::Vec2(0,-20));
    cocos2d::Sequence* Seq = cocos2d::Sequence::create(moveby->clone(),moveby->reverse(), NULL);
    cocos2d::RepeatForever* Repeat = cocos2d::RepeatForever::create(Seq);
    TrialStone->runAction(Repeat);
    
    TrialMenu->addChild(TrialStone);
    TrialMenu->setPosition(0,0);
    Page4.page->addChild(TrialMenu);
    Pages.push_back(Page4);
    Pages.back().page->setPositionX(cocos2d::Director::getInstance()->getVisibleSize().width*0);
    _floor->addChild(Pages.back().page);
    
    PAGES_NODE Page3;
    Page3.pageName = "开宝箱";
    Page3.page = ChestBar::create();
    Pages.push_back(Page3);
    Pages.back().page->setPositionX(cocos2d::Director::getInstance()->getVisibleSize().width*1);
    _floor->addChild(Pages.back().page);
    
    PAGES_NODE Page1;
    Page1.pageName = "音量设置";
    Page1.page = cocos2d::Node::create();
    Pages.push_back(Page1);
    Pages.back().page->addChild(_bmbtn);
    Pages.back().page->addChild(_embtn);
    Pages.back().page->setPositionX(cocos2d::Director::getInstance()->getVisibleSize().width*2);
    _floor->addChild(Pages.back().page);
    

    
    _developer = cocos2d::Label::createWithTTF("开发者 - 胡 可", "fonts/black.ttf", 64);
    _developer->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height/5*3);
    _developer->setColor(cocos2d::Color3B(37,37,37));

    _edition = cocos2d::Label::createWithTTF("版本号 - alpha 1.0", "fonts/black.ttf", 64);
    _edition->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height/10*3-15);
    _edition->setColor(cocos2d::Color3B(37,37,37));


    
    PAGES_NODE Page2;
    Page2.pageName = "版本信息";
    Page2.page = cocos2d::Node::create();
    Pages.push_back(Page2);
    Pages.back().page->addChild(_developer);
    Pages.back().page->addChild(_edition);
    Pages.back().page->setPositionX(cocos2d::Director::getInstance()->getVisibleSize().width*3);
    _floor->addChild(Pages.back().page);
    

    
    
    

    
    
    AudioSystem::getInstance()->MusicOn();
    
    CCLOG("MpaBar is OK");
    return true;
}

void BottomStateBar::GotoTrial()
{
    UISystem::getInstance()->CloseBottomStateBar();
    TrialScene* scene = TrialScene::create();
    cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.2f, scene);
    cocos2d::Director::getInstance()->replaceScene(fade);
}

void BottomStateBar::emSwitch()
{
    if(AudioSystem::getInstance()->GetEMSwitch())
    {
        AudioSystem::getInstance()->EffectiveMusicSwitch(MUSIC_SWITCH::TURN_OFF);
    }
    else if(!AudioSystem::getInstance()->GetEMSwitch())
    {
        AudioSystem::getInstance()->EffectiveMusicSwitch(MUSIC_SWITCH::TURN_ON);
    }
}

void BottomStateBar::bmSwitch()
{
    if(AudioSystem::getInstance()->GetEMSwitch())
    {
        AudioSystem::getInstance()->BackgroundMusicSwitch(MUSIC_SWITCH::TURN_OFF);
    }
    else if(!AudioSystem::getInstance()->GetEMSwitch())
    {
        AudioSystem::getInstance()->BackgroundMusicSwitch(MUSIC_SWITCH::TURN_ON);
    }
}

void BottomStateBar::MoveEnd()
{

    int MinLength = cocos2d::Director::getInstance()->getVisibleSize().width;
    int _no = -1;
    for(int i = 0 ; i < (int)Pages.size();i++)
    {
        if(std::abs( -Pages.at(i).page->getPositionX()) < std::abs(MinLength))
        {
            MinLength = -Pages.at(i).page->getPositionX();
            _no = i;
        }
    }
    cocos2d::MoveBy* MoveAction = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(MinLength,0));
    for(int i = 0 ; i < (int)Pages.size();i++)
    {
        Pages.at(i).page->runAction(MoveAction->clone());
    }
    NowPage = _no;
    _title->setString(Pages.at(NowPage).pageName);
    
    
    
}


void BottomStateBar::MoveCompent(float _offx)
{
//    //Part1
//    _embtn->setPositionX(_embtn->getPositionX() + _offx);
//    _bmbtn->setPositionX(_bmbtn->getPositionX() + _offx);
//    //Part2
//    _developer->setPositionX(_developer->getPositionX() + _offx);
//    _edition->setPositionX(_edition->getPositionX() + _offx);
    
    for(int i = 0 ; i < (int)Pages.size();i++)
    {
        Pages.at(i).page->setPositionX(Pages.at(i).page->getPositionX() + _offx);
    }
    
}

void BottomStateBar::Open()
{
    cocos2d::MoveTo* FloorMove = cocos2d::MoveTo::create(0.2f, cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,_floor->getContentSize().height/2));
    _floor->runAction(FloorMove);
    isOpen = true;
    UISystem::getInstance()->OpenBottomStateBar();
    _title->setString(Pages.at(NowPage).pageName);
}

void BottomStateBar::Close()
{
    cocos2d::MoveTo* FloorMove = cocos2d::MoveTo::create(0.2f, cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,-_floor->getContentSize().height/10*3));
    _floor->runAction(FloorMove);
    isOpen =false;
    UISystem::getInstance()->CloseBottomStateBar();
    _title->setString("更多内容");
}

bool BottomStateBar::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(!UISystem::getInstance()->getBottomStateBarControl() || !UISystem::getInstance()->getBottomStateCanMove())
    {
        return false;
    }
    if(_bsTouchEvent == BOTTOM_STATE_BAR_TOUCH_EVENT::NONE_MOVE)
    {
        cocos2d::Point _touchPoint = _touch->getLocation();
        if(_floor->getBoundingBox().containsPoint(_touchPoint))
        {
            LastTouchPoint = _touchPoint;
            return true;
        }
    }
    return false;
}


void BottomStateBar::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(_bsTouchEvent == BOTTOM_STATE_BAR_TOUCH_EVENT::NONE_MOVE)
    {
        if((int)std::abs(_touch->getLocation().y -LastTouchPoint.y) > 20)
        {
            _bsTouchEvent = BOTTOM_STATE_BAR_TOUCH_EVENT::Y_MOVE;
        }
        else if((int)std::abs(_touch->getLocation().x -LastTouchPoint.x) > 20 && isOpen == true)
        {
            _bsTouchEvent = BOTTOM_STATE_BAR_TOUCH_EVENT::X_MOVE;
        }
    }
    else if(_bsTouchEvent == BOTTOM_STATE_BAR_TOUCH_EVENT::Y_MOVE)
    {
        NowTouchPoint = _touch->getLocation();
        float _dir = NowTouchPoint.y - LastTouchPoint.y;
        float NextPos = _floor->getPositionY() + _dir;
    
        if(NextPos < -_floor->getContentSize().height/10*3)
        {
            NextPos = -_floor->getContentSize().height/10*3;
        }
        else if(NextPos > _floor->getContentSize().height/2)
        {
            NextPos = _floor->getContentSize().height/2;
        }
        LastTouchPoint = NowTouchPoint;
        _floor->setPositionY(NextPos);
    }
    else if(_bsTouchEvent == BOTTOM_STATE_BAR_TOUCH_EVENT::X_MOVE)
    {
        NowTouchPoint = _touch->getLocation();
        float _dir = NowTouchPoint.x - LastTouchPoint.x;
        MoveCompent(_dir);
        LastTouchPoint = NowTouchPoint;
    }


}

void BottomStateBar::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(_bsTouchEvent == BOTTOM_STATE_BAR_TOUCH_EVENT::Y_MOVE)
    {
        if(_floor->getPositionY() > _floor->getContentSize().height/16)
        {
            Open();
        }
        else if(_floor->getPositionY() <= _floor->getContentSize().height/16)
        {
            Close();
        }
    }
    else if(_bsTouchEvent == BOTTOM_STATE_BAR_TOUCH_EVENT::X_MOVE)
    {
        MoveEnd();
    }
    _bsTouchEvent = BOTTOM_STATE_BAR_TOUCH_EVENT::NONE_MOVE;
}

