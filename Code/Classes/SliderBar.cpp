//
//  SliderBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/26.
//
//

#include "SliderBar.h"
#include "UISystem.h"
#include "XMLParser.h"
#include "AudioSystem.h"
SliderBar::SliderBar()
{
    
}


SliderBar::~SliderBar()
{
    
}

SliderBar* SliderBar::create(const std::string& _onfliepath,
                             const std::string& _offfliepath,
                             const std::string& _sliderbtn,
                             const std::string& _sliderpath,
                             int width,
                             int height)
{
    SliderBar* pRet = new SliderBar;
    if(pRet && pRet->init(_onfliepath, _offfliepath, _sliderbtn, _sliderpath,width,height))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

void SliderBar::SetSliderBarType(SLIDER_BAR_TYPE _type)
{
    _SliderType = _type;
    if(_SliderType == BACKGROUND_MUSIC)
    {
        SetOdd(Parser::XML::getInstance()->GetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::BGM_VOLUME));
    }
    else if(_SliderType == EFFICTIVE_MUSIC)
    {
        SetOdd(Parser::XML::getInstance()->GetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::EM_VOLUME));
    }
}

bool SliderBar::init(const std::string& _onfliepath,
                     const std::string& _offfliepath,
                     const std::string& _sliderbtn,
                     const std::string& _sliderpath,
                     int width,
                     int height)
{
    if(!cocos2d::Node::init())
    {
        return false;
    }
    
    
    _switch = true;
    
    _SliderEvent = TOUCH_NOTHING_IN_SLIDER;
    
    StateOn = _onfliepath;
    StateOff = _offfliepath;
    
    StateSprite = cocos2d::Sprite::create(StateOn);
    
    
    SliderFloor = cocos2d::ui::Scale9Sprite::create(_sliderpath);
    SliderFloor->setColor(cocos2d::Color3B(80,50,0));
    SliderFloor->setContentSize(cocos2d::Size(width,height));
    SliderFloor->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    

    
    SliderProgress = cocos2d::ui::Scale9Sprite::create(_sliderpath);
    SliderProgress->setContentSize(cocos2d::Size(width,height));
    SliderProgress->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    
    
    SliderBtn = cocos2d::Sprite::create(_sliderbtn);
    
    float len = StateSprite->getContentSize().width + SliderProgress->getContentSize().width;
    
    
    StateSprite->setPosition(-len/2,0);
    SliderFloor->setPosition(StateSprite->getPosition().x + 35 + StateSprite->getContentSize().width/2,StateSprite->getPosition().y);
    SliderProgress->setPosition(SliderFloor->getPosition());
    SliderBtn->setPosition(SliderProgress->getPositionX() + SliderProgress->getContentSize().width,SliderProgress->getPositionY());
    
    
    this->addChild(StateSprite,0,1);
    this->addChild(SliderFloor);
    this->addChild(SliderProgress);
    this->addChild(SliderBtn,0,2);
    
    
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->onTouchBegan = CC_CALLBACK_2(SliderBar::onTouchBegan, this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(SliderBar::onTouchMoved, this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(SliderBar::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener->clone(), StateSprite);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener->clone(), SliderBtn);
    
    
    
    
    
    
    return true;
}

bool SliderBar::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    cocos2d::Sprite* TagSprite = static_cast<cocos2d::Sprite*>(_event->getCurrentTarget());
    cocos2d::Rect rect = cocos2d::Rect(0,0,TagSprite->getContentSize().width,TagSprite->getContentSize().height);
    cocos2d::Point _touchPoint = TagSprite->convertToNodeSpace(_touch->getLocation());
    if(rect.containsPoint(_touchPoint))
    {
        UISystem::getInstance()->setBottomStateCanMove(false);
        UISystem::getInstance()->setMapCanControl(false);
        if(TagSprite->getTag() == 1)
        {
            _SliderEvent = TOUCH_SLIDER_ICON;
            return true;
        }
        else if(TagSprite->getTag() == 2)
        {
            _SliderEvent = TOUCH_SLIDER_BOTTON;
            NowPoint = _touch->getLocation();
            LastPoint = NowPoint;
            return true;
        }
    }
    return false;
}

void SliderBar::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(_SliderEvent == TOUCH_SLIDER_BOTTON)
    {
        
        NowPoint = _touch->getLocation();
        float MoveOffX = NowPoint.x - LastPoint.x;
        if(SliderBtn->getPositionX() + MoveOffX > SliderFloor->getPositionX() + SliderFloor->getContentSize().width)
        {
            SliderBtn->setPositionX(SliderFloor->getPositionX() + SliderFloor->getContentSize().width);
        }
        else if(SliderBtn->getPositionX() + MoveOffX < SliderFloor->getPositionX())
        {
            SliderBtn->setPositionX(SliderFloor->getPositionX());
        }
        else if(SliderBtn->getPositionX() + MoveOffX >= SliderFloor->getPositionX() && SliderBtn->getPositionX() + MoveOffX <= SliderFloor->getPositionX() + SliderFloor->getContentSize().width)
        {
            SliderBtn->setPositionX(SliderBtn->getPositionX()+MoveOffX);
        }
        UpdateSliderProgress();
        LastPoint = NowPoint;
    }
}


void SliderBar::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(_SliderEvent == TOUCH_SLIDER_ICON)
    {
        SetState(!getState());
    }
    if(_SliderType == BACKGROUND_MUSIC)
    {
        AudioSystem::getInstance()->SetBMusicVolume(GetOdd());
    }
    else if(_SliderType == EFFICTIVE_MUSIC)
    {
        AudioSystem::getInstance()->SetEMusicVolume(GetOdd());
    }
    UISystem::getInstance()->setBottomStateCanMove(true);
    UISystem::getInstance()->setMapCanControl(true);
    _SliderEvent = TOUCH_NOTHING_IN_SLIDER;
}



void SliderBar::SetState(bool _s)
{
    if(_switch == _s)
    {
        return;
    }
    _switch = _s;
    if(_switch)
    {
        StateSprite->setTexture(StateOn);
    }
    else
    {
        StateSprite->setTexture(StateOff);
        SliderBtn->setPositionX(SliderFloor->getPositionX());
        UpdateSliderProgress();
    }
    if(_SliderType == BACKGROUND_MUSIC)
    {
        Parser::XML::getInstance()->SetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::BM_SWITCH, _s);
    }
    else if(_SliderType == EFFICTIVE_MUSIC)
    {
        Parser::XML::getInstance()->SetSystemData(Parser::SYSTEM_OPTION_SETTING_TYPE::EM_SWITCH, _s);
    }
}

float SliderBar::UpdateSliderProgress()
{
    float length = SliderBtn->getPositionX() - SliderFloor->getPositionX();
    if(length == 0)
    {
        SetState(false);
    }
    else
    {
        SetState(true);
    }
    SliderProgress->setContentSize(cocos2d::Size(length,SliderProgress->getContentSize().height));
    return length;
}

void SliderBar::SetOdd(float _value)
{
    float LengthMax = SliderFloor->getContentSize().width;
    float length = LengthMax * _value;
    SliderBtn->setPositionX(SliderFloor->getPositionX() + length);
    SliderProgress->setContentSize(cocos2d::Size(length,SliderProgress->getContentSize().height));
}

float SliderBar::GetOdd()
{
    float LengthMax = SliderFloor->getContentSize().width;
    float length = SliderBtn->getPositionX() - SliderFloor->getPositionX();
    return length / LengthMax;
}
