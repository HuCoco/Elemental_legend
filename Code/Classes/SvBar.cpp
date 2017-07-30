//
//  SvBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/7.
//
//

#include "SvBar.h"
#include "BattleSystem.h"
SvBar::SvBar()
{
    _max = BattleSystem::getInstance()->getPlayer()->getState()->GetSvMax();
    _current = 0;
    BarSize.width = cocos2d::Director::getInstance()->getVisibleSize().width/30;
    BarSize.height = cocos2d::Director::getInstance()->getVisibleSize().height/2;
}

SvBar::~SvBar()
{
    
}


//SvBar* SvBar::create(cocos2d::Vec2 _pos)
//{
//    SvBar* pRet = new SvBar;
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


bool SvBar::init(cocos2d::Vec2 _pos)
{
    Bar1 = cocos2d::ui::Scale9Sprite::create("resourcebar.png");
    Bar1->setAnchorPoint(cocos2d::Vec2(0.5f,0));
    Bar1->setContentSize(cocos2d::Size(BarSize.width,0));
    Bar1->setColor(cocos2d::Color3B(134,134,134));
    Bar1->setPosition(cocos2d::Vec2(_pos.x ,_pos.y- Bar1->getContentSize().height));
    
    Bar2 = nullptr;
    return true;
}

int SvBar::Add(int _data)
{
    BattleSystem::getInstance()->getPlayer()->getState()->UpdateSV(_data);
    _current+=_data;
    if(_current > _max)
    {
        _current = _max;
    }
    cocos2d::Size NowSize;
    NowSize.height = BarSize.height * ( (float)_current / (float)_max );
    NowSize.width = BarSize.width;
    Bar1->setContentSize(cocos2d::Size(NowSize));
    return 0;
}


int SvBar::Reduce(int _data)
{
    BattleSystem::getInstance()->getPlayer()->getState()->UpdateSV(-_data);
    int over = 0;
    _current-=_data;
    if(_current < 0)
    {
        over = -_current;
        _current = 0;
    }
    cocos2d::Size NowSize;
    NowSize.height = BarSize.height * ((float) _current /(float) _max );
    NowSize.width = BarSize.width;
    Bar1->setContentSize(cocos2d::Size(NowSize));
    return over;
}