//
//  MpBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/6.
//
//


#include "MpBar.h"
#include "BattleSystem.h"
MpBar::MpBar()
{
    _max = BattleSystem::getInstance()->getPlayer()->getState()->GetMpMax();
    _current = _max;
    BarSize.width = cocos2d::Director::getInstance()->getVisibleSize().width/45*44;
    BarSize.height = cocos2d::Director::getInstance()->getVisibleSize().width/30;
}

MpBar::~MpBar()
{
    
}


//MpBar* MpBar::create(cocos2d::Vec2 _pos)
//{
//    MpBar* pRet = new MpBar;
//    if(pRet && pRet->init(_pos))
//    {
//        return pRet;
//    }
//    else
//    {
//        delete pRet;
//        pRet = nullptr;
//        return nullptr;
//    }
//}


bool MpBar::init(cocos2d::Vec2 _pos)
{

    Bar1 = cocos2d::ui::Scale9Sprite::create("resourcebar.png");
    Bar1->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    Bar1->setContentSize(BarSize);
    Bar1->setColor(cocos2d::Color3B(144,107,211));
    Bar1->setPosition(cocos2d::Vec2(_pos.x - Bar1->getContentSize().width/2,_pos.y));
    
    
    std::string datachar = cocos2d::StringUtils::format("%d / %d",_current,_max);
    Bar2 = cocos2d::Label::createWithTTF(datachar, "fonts/arial.ttf", 30);
    Bar2->setColor(cocos2d::Color3B(255,255,255));
    Bar2->setPosition(cocos2d::Vec2(_pos));
    return true;
}

int MpBar::Add(int _data)
{
    BattleSystem::getInstance()->getPlayer()->getState()->UpdateMP(_data);
    _current+=_data;
    if(_current > _max)
    {
        _current = _max;
    }
    std::string datachar = cocos2d::StringUtils::format("%d / %d",_current,_max);
    Bar2->setString(datachar);
    
    
    cocos2d::Size NowSize;
    NowSize.width = BarSize.width * ( (float)_current /(float) _max );
    NowSize.height = BarSize.height;
    Bar1->setContentSize(cocos2d::Size(NowSize));
    return 0;
}


int MpBar::Reduce(int _data)
{
    BattleSystem::getInstance()->getPlayer()->getState()->UpdateMP(-_data);
    _current-=_data;
    if(_current < 0)
    {
        _current = 0;
    }
    std::string datachar = cocos2d::StringUtils::format("%d / %d",_current,_max);
    Bar2->setString(datachar);
    
    cocos2d::Size NowSize;
    NowSize.width = BarSize.width * ((float) _current /(float) _max );
    NowSize.height = BarSize.height;
    Bar1->setContentSize(cocos2d::Size(NowSize));
    return 0;
}