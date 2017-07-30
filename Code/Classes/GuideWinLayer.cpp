//
//  GuideWinLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/8.
//
//

#include "GuideWinLayer.h"
#include "HomeScene.h"
GuideWinLayer::GuideWinLayer()
{
    
}


GuideWinLayer::~GuideWinLayer()
{
    
}

bool GuideWinLayer::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(GuideWinLayer::onTouchBegan, this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(GuideWinLayer::onTouchMoved, this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(GuideWinLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    Cantouch = false;

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite);
    
    cocos2d::Sprite* TitleLight = cocos2d::Sprite::create("UI/prize_light.png");
    TitleLight->setPosition(visibleSize.width/2,visibleSize.height/5*4);
    TitleLight->setScale(5);
    TitleLight->setOpacity(200);
    this->addChild(TitleLight);
    
    cocos2d::RepeatForever* LightRepeatRotate = cocos2d::RepeatForever::create(cocos2d::RotateBy::create(5, 360));
    TitleLight->runAction(LightRepeatRotate);
    
    cocos2d::Sprite* WinTitle = cocos2d::Sprite::create("UI/win_title.png");
    WinTitle->setPosition(visibleSize.width/2,visibleSize.height/5*4);
    this->addChild(WinTitle);
    this->scheduleOnce(std::bind([=]
                                 {
                                     Cantouch = true;
                                     cocos2d::Label* TouchTipsLabel = cocos2d::Label::createWithTTF("点击屏幕正式开始游戏吧","fonts/black.ttf",40);
                                     TouchTipsLabel->setColor(cocos2d::Color3B(255,255,255));
                                     TouchTipsLabel->setPosition(cocos2d::Director::getInstance()->getVisibleSize()/2);
                                     TouchTipsLabel->setOpacity(0);
                                     this->addChild(TouchTipsLabel,0,"touchtips");
                                     cocos2d::FadeTo* TipsFadeIn = cocos2d::FadeTo::create(1.0f, 200);
                                     cocos2d::FadeTo* TipsFadeOut = cocos2d::FadeTo::create(1.0f, 50);
                                     cocos2d::Sequence* FadeSequence = cocos2d::Sequence::create(TipsFadeIn,TipsFadeOut, NULL);
                                     cocos2d::RepeatForever* FadeForever = cocos2d::RepeatForever::create(FadeSequence);
                                     TouchTipsLabel->runAction(FadeForever);
                                     
                                 }), 0.5f, "AddTouchTips");
    
    

    return true;
}

bool GuideWinLayer::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(!Cantouch)
    {
        return false;
    }
    return true;
}


void GuideWinLayer::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}

void GuideWinLayer::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    HomeScene* scene = HomeScene::create();
    cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.5f, scene);
    cocos2d::Director::getInstance()->replaceScene(fade);
}