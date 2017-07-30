//
//  BaseGuideLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#include "BaseGuideLayer.h"
#include "GuideSystem.h"
BaseGuideLayer::BaseGuideLayer()
{
    
}


BaseGuideLayer::~BaseGuideLayer()
{
    
}

bool BaseGuideLayer::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    CanTouch = false;
    
    ShadowImage = cocos2d::ui::Scale9Sprite::create("UI/shadow.png");
    ShadowImage->setPosition(cocos2d::Director::getInstance()->getVisibleSize()/2);
    this->addChild(ShadowImage);
    
    
    return true;
}

void BaseGuideLayer::AddTouchTips(cocos2d::Vec2 pos)
{
    this->scheduleOnce(std::bind([=]
                                 {
                                     CanTouch = true;
                                     TouchTipsLabel = cocos2d::Label::createWithTTF("点击屏幕继续","fonts/black.ttf",40);
                                     TouchTipsLabel->setColor(cocos2d::Color3B(255,255,255));
                                     TouchTipsLabel->setPosition(pos);
                                     TouchTipsLabel->setOpacity(0);
                                     this->addChild(TouchTipsLabel,0,"touchtips");
                                     cocos2d::FadeTo* TipsFadeIn = cocos2d::FadeTo::create(1.0f, 200);
                                     cocos2d::FadeTo* TipsFadeOut = cocos2d::FadeTo::create(1.0f, 50);
                                     cocos2d::Sequence* FadeSequence = cocos2d::Sequence::create(TipsFadeIn,TipsFadeOut, NULL);
                                     cocos2d::RepeatForever* FadeForever = cocos2d::RepeatForever::create(FadeSequence);
                                     
                                     TouchTipsLabel->runAction(FadeForever);
                                     
                                 }), 0.5f, "AddTouchTips");

}

void BaseGuideLayer::ResetTouchTips()
{
    CanTouch = false;
    this->removeChildByName("touchtips");
}


void BaseGuideLayer::setParent(std::vector<BaseGuideLayer *> *_parents, int _num, GuideSystem *_system)
{
    Parent = _parents;
    thisNum = _num;
    System = _system;
}

bool BaseGuideLayer::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(!CanTouch)
    {
        return false;
    }
    
    return true;
}


void BaseGuideLayer::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}

void BaseGuideLayer::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}