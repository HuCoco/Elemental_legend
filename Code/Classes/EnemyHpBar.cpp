//
//  EnemyHpBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/7.
//
//

#include "EnemyHpBar.h"
#include "BattleSystem.h"
EnemyHpBar::EnemyHpBar()
{
    _max = BattleSystem::getInstance()->getMonster()->getState()->GetHpMax();
    _current = _max;
    BarSize.width = cocos2d::Director::getInstance()->getVisibleSize().width/45*44;
    BarSize.height = cocos2d::Director::getInstance()->getVisibleSize().width/30;
}

EnemyHpBar::~EnemyHpBar()
{
    
}



bool EnemyHpBar::init(cocos2d::Vec2 _pos)
{
    Bar1 = cocos2d::ui::Scale9Sprite::create("resourcebar.png");
    Bar1->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    Bar1->setContentSize(BarSize);
    Bar1->setColor(cocos2d::Color3B(253,90,93));
    Bar1->setPosition(cocos2d::Vec2(_pos.x - Bar1->getContentSize().width/2,_pos.y));
    
    
    std::string datachar = cocos2d::StringUtils::format("%d / %d",_current,_max);
    Bar2 = cocos2d::Label::createWithTTF(datachar, "fonts/arial.ttf", 30);
    Bar2->setColor(cocos2d::Color3B(255,255,255));
    Bar2->setPosition(cocos2d::Vec2(_pos));
    return true;
}

int EnemyHpBar::Add(int _data)
{
    BattleSystem::getInstance()->getMonster()->getState()->UpdateHP(_data);
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


int EnemyHpBar::Reduce(int _data)
{
    BattleSystem::getInstance()->getMonster()->getState()->UpdateHP(-_data);
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