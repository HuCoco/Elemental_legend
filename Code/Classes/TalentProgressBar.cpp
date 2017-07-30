//
//  TalentProgressBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/21.
//
//

#include "TalentProgressBar.h"


TalentProgressBar::TalentProgressBar()
{
    
}


TalentProgressBar::~TalentProgressBar()
{
    
}

TalentProgressBar* TalentProgressBar::create(ELEMENT_TYPE _type, int _progress)
{
    TalentProgressBar* pRet = new TalentProgressBar;
    if(pRet && pRet->init(_type, _progress))
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

bool TalentProgressBar::init(ELEMENT_TYPE _type, int _progress)
{
    if(!cocos2d::ui::Scale9Sprite::init())
    {
        return false;
    }
    initWithFile("resourcebar.png");
    int _max = 6400;
    for(int i = 0 ; i < 4 ;i++)
    {
        if(_progress < 100 * pow(2, 2*i))
        {
            _max = 100 * pow(2,2*i);
            break;
        }
    }
    _odd = (float)_progress / (float)_max;
    
    cocos2d::Color3B _color;
    switch (_type) {
        case ET_FIRE:
            _color = cocos2d::Color3B(255,0,0);
            break;
        case ET_THUNDER:
            _color = cocos2d::Color3B(255,255,0);
            break;
        case ET_WATER:
            _color = cocos2d::Color3B(0,125,255);
            break;
        case ET_WIND:
            _color = cocos2d::Color3B(200,200,200);
            break;
            
        default:
            break;
    }
    this->setColor(_color);
    this->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    
    
    return true;
}

void TalentProgressBar::InitData()
{
    cocos2d::Size _barSize = cocos2d::Size(this->getParent()->getContentSize().width*0.9f * _odd,20);
    this->setContentSize(_barSize);
    this->setPositionX(this->getParent()->getContentSize().width*0.05f);
}