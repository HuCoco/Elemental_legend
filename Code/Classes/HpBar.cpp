//
//  HpBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/6.
//
//

#include "HpBar.h"
#include "BattleSystem.h"
HpBar::HpBar()
{
    _max = BattleSystem::getInstance()->getPlayer()->getState()->GetHpMax();
    _current = _max;
    BarSize.width = cocos2d::Director::getInstance()->getVisibleSize().width/45*44;
    BarSize.height = cocos2d::Director::getInstance()->getVisibleSize().width/30;
}

HpBar::~HpBar()
{
    
}


//HpBar* HpBar::create(cocos2d::Vec2 _pos)
//{
//    HpBar* pRet = new HpBar;
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


bool HpBar::init(cocos2d::Vec2 _pos)
{
    Bar1 = cocos2d::ui::Scale9Sprite::create("resourcebar.png");
    Bar1->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    Bar1->setContentSize(BarSize);
    Bar1->setColor(cocos2d::Color3B(102,217,239));
    Bar1->setPosition(cocos2d::Vec2(_pos.x - Bar1->getContentSize().width/2,_pos.y));
    
    
    std::string datachar = cocos2d::StringUtils::format("%d / %d",_current,_max);
    Bar2 = cocos2d::Label::createWithTTF(datachar, "fonts/arial.ttf", 30);
    Bar2->setColor(cocos2d::Color3B(255,255,255));
    Bar2->setPosition(cocos2d::Vec2(_pos));
    return true;
}

int HpBar::Add(int _data)
{
    BattleSystem::getInstance()->getPlayer()->getState()->UpdateHP(_data);
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


int HpBar::Reduce(int _data)
{
    BattleSystem::getInstance()->getPlayer()->getState()->UpdateHP(-_data);
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