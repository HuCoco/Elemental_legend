//
//  ElementTipsBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/12/2.
//
//

#include "ElementTipsBar.h"


ElementTipsBar::ElementTipsBar()
{
    
}

ElementTipsBar::~ElementTipsBar()
{
    
}

bool ElementTipsBar::init()
{
    if(!cocos2d::Node::init())
    {
        return false;
    }
    _type = ELEMENT_TYPE::ET_UNKOWN;
    ElementIcon = cocos2d::Sprite::create("gs_fire.png");
    ElementIcon->setScale(0.35f);
    ElementIcon->setOpacity(0);
    this->addChild(ElementIcon);
    
    TouchTimes = cocos2d::Label::createWithTTF("0", "fonts/black.ttf", 40);
    TouchTimes->setPosition(GetSize().width/2 + TouchTimes->getContentSize().width/2,0);
    TouchTimes->setColor(cocos2d::Color3B(0,0,0));
    TouchTimes->setOpacity(0);
    this->addChild(TouchTimes);
    
    return true;
}

void ElementTipsBar::AddToLayer(cocos2d::Node *_tag)
{
    this->setPosition(GetSize().width/2 + 5 , cocos2d::Director::getInstance()->getVisibleSize().width + GetSize().height/2 + 5);
    _tag->addChild(this);
}

cocos2d::Size ElementTipsBar::GetSize()
{
    return ElementIcon->getContentSize()*0.35f;
}

void ElementTipsBar::ChangeIcon(ELEMENT_TYPE _type)
{
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/tips_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(0,0);
    switch (_type) {
        case ET_UNKOWN:
            ElementIcon->setOpacity(0);
            TouchTimes->setOpacity(0);
            break;
        case ET_FIRE:
            ElementIcon->setTexture("gs_fire.png");
            ElementIcon->setOpacity(255);
            TouchTimes->setOpacity(255);
            _particleAnimation->setStartColor(cocos2d::Color4F(1,1,0,1));
            _particleAnimation->setEndColor(cocos2d::Color4F(1,0,0,1));
            break;
        case ET_WATER:
            ElementIcon->setTexture("gs_water.png");
            ElementIcon->setOpacity(255);
            TouchTimes->setOpacity(255);
            _particleAnimation->setStartColor(cocos2d::Color4F(0,1,1,1));
            _particleAnimation->setEndColor(cocos2d::Color4F(0,0.5f,1,1));
            break;
        case ET_WIND:
            ElementIcon->setTexture("gs_wind.png");
            ElementIcon->setOpacity(255);
            TouchTimes->setOpacity(255);
            _particleAnimation->setStartColor(cocos2d::Color4F(1,1,1,1));
            _particleAnimation->setEndColor(cocos2d::Color4F(1,1,1,1));
            break;
        case ET_THUNDER:
            ElementIcon->setTexture("gs_thunder.png");
            ElementIcon->setOpacity(255);
            TouchTimes->setOpacity(255);
            _particleAnimation->setStartColor(cocos2d::Color4F(1,1,0.8f,1));
            _particleAnimation->setEndColor(cocos2d::Color4F(1,1,0,1));
            break;
        case ET_MAGIC:
            ElementIcon->setTexture("gs_magic.png");
            ElementIcon->setOpacity(255);
            TouchTimes->setOpacity(255);
            _particleAnimation->setStartColor(cocos2d::Color4F(1,0.55f,1,1));
            _particleAnimation->setEndColor(cocos2d::Color4F(1,0,1,1));
            break;
        default:
            break;
    }
    this->addChild(_particleAnimation);
    SetTouchTimes(1);
}

void ElementTipsBar::SetTouchTimes(int _data)
{
    std::string datastr = cocos2d::StringUtils::format("%d",_data);
    TouchTimes->setString(datastr);
    TouchTimes->setPosition(GetSize().width/2 + TouchTimes->getContentSize().width/2,0);
}