//
//  TalentConfig.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/11.
//
//

#include "TalentConfig.h"
#include "PlayerConfig.h"
TalentConfig::TalentConfig()
{
    
}


TalentConfig::~TalentConfig()
{
    
}

bool TalentConfig::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(TalentConfig::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(TalentConfig::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(TalentConfig::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    _floor = cocos2d::ui::Scale9Sprite::create("UI/playerconfig_skillfloor.png");
    _floor->setContentSize(cocos2d::Size(visibleSize.width/9*7,visibleSize.width/9*7));
    _floor->setPosition(visibleSize.width/2,visibleSize.height/3*2);
    this->addChild(_floor);
    
    for(int i = 0;i < 4;i++)
    {
        cocos2d::Sprite* pRet = cocos2d::Sprite::create("UI/playerconfig_talentfloor.png");
        pRet->setPosition(_floor->getContentSize().width/5*(i+1),_floor->getContentSize().height/5*2);
        _talentfloorpool.push_back(pRet);
        _floor->addChild(_talentfloorpool.back());
    }
    
    
    _okbtn = cocos2d::MenuItemImage::create("UI/ok_btn.png", "UI/ok_btn.png", std::bind(&TalentConfig::close,this));
    _okbtn->setPosition(_floor->getContentSize().width/2,_floor->getContentSize().height/5);
    
    
    _menu = cocos2d::Menu::create(_okbtn,NULL);
    _menu->setPosition(0,0);
    _floor->addChild(_menu);
    

    
    return true;
}

void TalentConfig::ReSetScale()
{
    for(int i = 0;i < (int)_talentpool.size();i++)
    {
        _talentpool.at(i)._talent->setScale(1);
    }
}

void TalentConfig::close()
{
    //_eventDispatcher->removeEventListener(_touchListener);
    ((PlayerConfig*)this->getParent())->ReSetTalentList();
    this->getParent()->removeChild(this);

}

int TalentConfig::GetTalentDataByUsedData(int _used)
{
    int TelentData = 0;;
    int BaseUsedData[4] = {3200,800,200,50};
    for(int i = 0 ; i < 4 ; i++)
    {
        if(_used >= BaseUsedData[i])
        {
            TelentData = 4 - i;
            break;
        }
    }
    return TelentData;
}


void TalentConfig::AddToTag(cocos2d::Layer *_tag)
{
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    _tag->addChild(this,3);
}

bool TalentConfig::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    return true;
}

void TalentConfig::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}

void TalentConfig::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}