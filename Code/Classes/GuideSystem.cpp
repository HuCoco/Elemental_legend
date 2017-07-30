//
//  GuideSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#include "GuideSystem.h"
#include "FloorFrameLayer.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"
#include "GameTopStateBar.h"
#include "GameConfigSystem.h"
#include "GuideLayerHeader.h"
#include "ElementTipsBar.h"
GuideSystem* GuideSystem::_instance = nullptr;


GuideSystem::GuideSystem()
{
    isRun = false;
}


GuideSystem::~GuideSystem()
{
    
}


GuideSystem* GuideSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new GuideSystem;
    }
    return _instance;
}

void GuideSystem::SetConfig(cocos2d::Scene *_tag)
{
    Tag = _tag;
}

void GuideSystem::GetReady()
{
    isRun = true;
    
    EffectLayer = cocos2d::Layer::create();
    Tag->addChild(EffectLayer,2);
    

    
    //    cocos2d::Sprite* bgSprite = cocos2d::Sprite::create("bk.png");
    //    bgSprite->setPosition(bgSprite->getContentSize().width/2,bgSprite->getContentSize().height/2);
    //    bgLayer->addChild(bgSprite,0);
    
    Mask = MaskNode::create(GUIDE_INIT);
    
    Mask->setPosition(0,0);
    Tag->addChild(Mask,1);
    Mask->Test(EffectLayer);

    TipsBar = ElementTipsBar::create();
    TipsBar->AddToLayer(EffectLayer);
    GameConfigSystem::getInstance()->SetGameSpeed(0);
    //GameTopStateBar* _gametopstatebar = GameTopStateBar::create();
    //Tag->addChild(_gametopstatebar,2);
    //Mask->GuideRun();
    InitGuideData();
    Tag->addChild(GuideLayerPool->at(0),0);
}
void GuideSystem::run()
{
    Mask->GuideRun();
    Tag->schedule(std::bind([=]
                            {
                                if(BattleSystem::getInstance()->getMonster()->getState()->GetHP()<=0)
                                {
                                    GameConfigSystem::getInstance()->SetGameSpeed(0);
                                    this->Win();
                                }
                            }),"WIN");
}

void GuideSystem::Win()
{
    Tag->unscheduleAllCallbacks();
    Mask->SetOver(true);
    
    int size = (int)Tag->getChildren().size();
    for(int i = 0 ; i < size ; i++)
    {
        Tag->getChildren().at(i)->unscheduleAllCallbacks();
    }
    cocos2d::CallFunc* CallBack = cocos2d::CallFunc::create(std::bind([=]
                                                                      {
                                                                          GuideWinLayer* pRet = GuideWinLayer::create();
                                                                          Tag->addChild(pRet,6);
                                                                          
                                                                      }));
    cocos2d::DelayTime* Wait = cocos2d::DelayTime::create(0.5f);
    cocos2d::Sequence* Seq = cocos2d::Sequence::create(BattleSystem::getInstance()->getMonster()->GetDeathAnimate(),Wait,CallBack, NULL);
    BattleSystem::getInstance()->getMonster()->StopAction();
    BattleSystem::getInstance()->getMonster()->RunAciton(Seq);
    isRun = false;
}

void GuideSystem::InitGuideData()
{
    GuideLayerPool = new std::vector<BaseGuideLayer*>;
    
    WelcomeGuideLayer* g1 = WelcomeGuideLayer::create();
    g1->setParent(GuideLayerPool, (int)GuideLayerPool->size(),this);
    GuideLayerPool->push_back(g1);
    
    GameInterfaceGuideLayer* g2 = GameInterfaceGuideLayer::create();
    g2->setParent(GuideLayerPool, (int)GuideLayerPool->size(),this);
    GuideLayerPool->push_back(g2);
}

void GuideSystem::AddResourceBar()
{
    ResourceSystem::getInstance()->Init(EffectLayer);
}

void GuideSystem::AddFloorFrame()
{
    cocos2d::Layer* bgLayer = FloorFrameLayer::create();
    Tag->addChild(bgLayer,0);
}

void GuideSystem::AddMonster()
{
    BattleSystem::getInstance()->getMonster()->AddToLayer(EffectLayer);
}

void GuideSystem::AddElement()
{
    Mask->GuideAddElement();
}

void GuideSystem::AddTopStatrBar()
{
    GameTopStateBar* _gametopstatebar = GameTopStateBar::create();
    EffectLayer->addChild(_gametopstatebar);
}