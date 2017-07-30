//
//  IconLabelBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/22.
//
//

#include "IconLabelBar.h"
#include "UISystem.h"
IconLabelBar::IconLabelBar()
{
    _buytype = NO_BUY;
}


IconLabelBar::~IconLabelBar()
{
    
}

IconLabelBar* IconLabelBar::create(const std::string &_iconfliepath,bool _isadd ,int _value,int _width,int _height)
{
    IconLabelBar* pRet = new IconLabelBar;
    if(pRet && pRet->init(_iconfliepath,_isadd ,_value,_width,_height))
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

bool IconLabelBar::init(const std::string &_iconfliepath,bool _isadd, int _value,int _width,int _height)
{
    if(!cocos2d::ui::Scale9Sprite::init())
    {
        return false;
    }
    
    initWithFile("UI/topstatebar_numberfloor.png");
    this->setInsetBottom(22);
    this->setInsetLeft(19.25f);
    this->setInsetTop(22);
    this->setInsetRight(19.25f);
    this->setContentSize(cocos2d::Size(_width,_height));
    
    
    Icon = cocos2d::Sprite::create(_iconfliepath);
    Icon->setPosition(cocos2d::Vec2(Icon->getContentSize().width/3,this->getContentSize().height/2));
    this->addChild(Icon);
    
    value = _value;
    std::string coinchar = cocos2d::StringUtils::format("%d",value);
    ValueLabel = cocos2d::Label::createWithTTF(coinchar, "fonts/arial.ttf", 32);
    ValueLabel->setPosition(this->getContentSize().width/2 ,this->getContentSize().height/2);
    this->addChild(ValueLabel);
    ValueLabel->setColor(cocos2d::Color3B(255,255,255));
    
    if(_isadd)
    {
        cocos2d::MenuItemImage* AddBar = cocos2d::MenuItemImage::create("UI/add_bar.png","UI/add_bar.png",std::bind(&IconLabelBar::AddBuyLayer,this));
        AddBar->setPosition(this->getContentSize().width - AddBar->getContentSize().width/2,this->getContentSize().height/2);
        
        cocos2d::Menu* menu = cocos2d::Menu::create(AddBar,NULL);
        menu->setPosition(0,0);
        this->addChild(menu);
    }
    
    
    
    
    return true;
}

void IconLabelBar::setValue(int _value)
{
    value = _value;
    std::string valuechar = cocos2d::StringUtils::format("%d",value);
    ValueLabel->setString(valuechar);
}

void IconLabelBar::SetColor(ICON_LABEL_COLOR _color)
{
    switch (_color) {
        case ILC_WHITE:
            ValueLabel->setColor(cocos2d::Color3B(255,255,255));
            break;
        case ILC_GREEN:
            ValueLabel->setColor(cocos2d::Color3B(24,159,14));
            break;
        case ILC_RED:
            ValueLabel->setColor(cocos2d::Color3B(255,0,0));
            break;
        default:
            break;
    }
}


void IconLabelBar::AddBuyLayer()
{
    if(this->getParent()->getChildByName("buy"))
    {
        return;
    }
    BuyLayer* pRet;
    switch (_buytype) {
        case B_COIN:
            pRet = BuyLayer::create(BUY_TYPE::B_COIN);
            this->getParent()->getParent()->addChild(pRet,6,"buy");
            UISystem::getInstance()->OpenPlayerConfig();
            break;
        case B_DIAMOND:
            pRet = BuyLayer::create(BUY_TYPE::B_DIAMOND);
            this->getParent()->getParent()->addChild(pRet,6,"buy");
            UISystem::getInstance()->OpenPlayerConfig();
            break;
        case B_TOOLS:
            pRet = BuyLayer::create(BUY_TYPE::B_TOOLS);
            this->getParent()->getParent()->addChild(pRet,6,"buy");
            UISystem::getInstance()->OpenPlayerConfig();
            break;
        default:
            break;
    }

}

void IconLabelBar::SetBuyType(BUY_TYPE _type)
{
    _buytype = _type;
}

