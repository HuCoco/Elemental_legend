//
//  BtBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/7.
//
//

#include "BtBar.h"
#include "BattleSystem.h"
BtBar::BtBar()
{
    _max = BattleSystem::getInstance()->getPlayer()->getState()->GetBtMax();
    _current = 0;
    BarSize.width = cocos2d::Director::getInstance()->getVisibleSize().width/30;
    BarSize.height = cocos2d::Director::getInstance()->getVisibleSize().height/2;
}

BtBar::~BtBar()
{
    
}


//BtBar* BtBar::create(cocos2d::Vec2 _pos)
//{
//    BtBar* pRet = new BtBar;
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


bool BtBar::init(cocos2d::Vec2 _pos)
{
    Bar1 = cocos2d::ui::Scale9Sprite::create("resourcebar.png");
    Bar1->setAnchorPoint(cocos2d::Vec2(0.5f,0));
    Bar1->setContentSize(cocos2d::Size(BarSize.width,0));
    Bar1->setColor(cocos2d::Color3B(245,201,45));
    Bar1->setPosition(cocos2d::Vec2(_pos.x ,_pos.y- Bar1->getContentSize().height/2));
    
    
    Bar2 = nullptr;
    return true;
}

int BtBar::Add(int _data)
{
    BattleSystem::getInstance()->getPlayer()->getState()->UpdateBT(_data);
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


int BtBar::Reduce(int _data)
{
    BattleSystem::getInstance()->getPlayer()->getState()->UpdateBT(-_data);
    _current-=_data;
    if(_current < 0)
    {
        _current = 0;
    }
    
    
    cocos2d::Size NowSize;
    NowSize.height = BarSize.height * ((float) _current /(float) _max );
    NowSize.width = BarSize.width;
    Bar1->setContentSize(cocos2d::Size(NowSize));
    return 0;
}