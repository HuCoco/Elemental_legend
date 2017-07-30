//
//  BaseElement.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#include "BaseElement.h"
#include "ElementSystem.h"
BaseElement::BaseElement()
{

    ELEMENT_TYPE random = ElementSystem::getInstance()->getElementTypeByRandom();
    init(random);
}

BaseElement::BaseElement(ELEMENT_TYPE _type)
{
    init(_type);
}


BaseElement::~BaseElement()
{
    
}

void BaseElement::ReSetType()
{
    ELEMENT_TYPE random = ElementSystem::getInstance()->getElementTypeByRandom();
    switch (random) {
        case ET_FIRE:
            _ElmentSprite->setTexture("gs_fire.png");
            break;
        case ET_WIND:
            _ElmentSprite->setTexture("gs_wind.png");
            break;
        case ET_WATER:
            _ElmentSprite->setTexture("gs_water.png");
            break;
        case ET_THUNDER:
            _ElmentSprite->setTexture("gs_thunder.png");
            break;
        case ET_MAGIC:
            _ElmentSprite->setTexture("gs_magic.png");
            break;
        default:
            break;
    }
    _Type = random;
    _ElmentSprite->setOpacity(255);
}


bool BaseElement::init(ELEMENT_TYPE _type)
{
    switch (_type) {
        case ET_FIRE:
            _ElmentSprite = cocos2d::Sprite::create("gs_fire.png");
            break;
        case ET_WIND:
            _ElmentSprite = cocos2d::Sprite::create("gs_wind.png");
            break;
        case ET_WATER:
            _ElmentSprite = cocos2d::Sprite::create("gs_water.png");
            break;
        case ET_THUNDER:
            _ElmentSprite = cocos2d::Sprite::create("gs_thunder.png");
            break;
        case ET_MAGIC:
            _ElmentSprite = cocos2d::Sprite::create("gs_magic.png");
            break;
        default:
            break;
    }
    _Type = _type;
    return true;
}

void BaseElement::AddToParent(cocos2d::Node *_parent)
{
    _parent->addChild(_ElmentSprite);
}

void BaseElement::setPosition(cocos2d::Vec2 _pos)
{
    _ElmentSprite->setPosition(_pos);
}

void BaseElement::initPosition(int i)
{
    cocos2d::Size _SpriteSize = _ElmentSprite->getContentSize();
    _ElmentSprite->setPosition(cocos2d::Vec2((i % 4 ) * _SpriteSize.width + _SpriteSize.width/2 + 40,(i/4) * _SpriteSize.height + _SpriteSize.height/2 + 16));
}

void BaseElement::SetTag(int i)
{
    _ElmentSprite->setTag(i);
}

bool BaseElement::OverButton()
{
    bool Temp = false;
    if(_ElmentSprite->getPosition().y < -_ElmentSprite->getContentSize().height/2)
    {
        Temp = true;
    }
    return Temp;
}

void BaseElement::Reback(cocos2d::Vec2 _top)
{
    cocos2d::Vec2 pos;
    pos.x = _top.x;
    pos.y = _top.y + _ElmentSprite->getContentSize().height + 20;
    _ElmentSprite->setPosition(pos);
}

void BaseElement::AddToTouchListen(cocos2d::EventDispatcher* _eventdispatcher, cocos2d::EventListenerTouchOneByOne* _listener)
{
    _eventdispatcher->addEventListenerWithSceneGraphPriority(_listener->clone(), this->_ElmentSprite);
}