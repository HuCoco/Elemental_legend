//
//  LoadingLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/8.
//
//

#include "LoadingLayer.h"
#include "ViceHomeScene.h"
LoadingLayer::LoadingLayer()
{
    
}

LoadingLayer::~LoadingLayer()
{
    
}

bool LoadingLayer::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    cocos2d::Sprite* copyright = cocos2d::Sprite::create("copyright.png");
    copyright->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width/2,copyright->getContentSize().height/2 + 10);
    this->addChild(copyright);
    
    
    cocos2d::Sprite* LOGO = cocos2d::Sprite::create("company_logo.png");
    LOGO->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/5*3);
    LOGO->setOpacity(0);
    this->addChild(LOGO);
    cocos2d::CallFunc* callback = cocos2d::CallFunc::create(std::bind([=]
                                                                      {
                                                                          ViceHomeScene* scene = ViceHomeScene::create();
                                                                          cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.1f, scene);
                                                                          cocos2d::Director::getInstance()->replaceScene(fade);
                                                                      }));

    LOGO->runAction(cocos2d::Sequence::create(cocos2d::FadeIn::create(2.0f),
                                              cocos2d::DelayTime::create(2.0f),
                                              cocos2d::FadeOut::create(2.0f),
                                              callback,
                                              NULL));
    return true;
}


void LoadingLayer::StartGameBtnCallBack()
{

}