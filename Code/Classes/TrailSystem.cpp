//
//  TrailSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/18.
//
//

#include "TrailSystem.h"
#include "BattleSystem.h"
#include "MaskNode.h"
#include "MyLog.h"
#include "GameTopStateBar.h"
#include "WinLayer.h"
#include "LoseLayer.h"
#include "AttrSystem.h"
#include "FloorFrameLayer.h"
#include "GameConfigSystem.h"
#include "XMLParser.h"
TrialSystem* TrialSystem::_instance = nullptr;

TrialSystem::TrialSystem()
{
    LifeUsed = false;
    ReLfie = false;
}


TrialSystem::~TrialSystem()
{
    
}


TrialSystem* TrialSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new TrialSystem;
    }
    return _instance;
}

void TrialSystem::SetConfig(cocos2d::Scene *_tag)
{
    Tag = _tag;
}

void TrialSystem::GetReady()
{
    LifeUsed = false;
    ReLfie = false;
    
    
    
    cocos2d::Layer* EffectLayer = cocos2d::Layer::create();
    Tag->addChild(EffectLayer,1);
    
    cocos2d::Layer* bgLayer = FloorFrameLayer::create();
    Tag->addChild(bgLayer,0);
    
    //    cocos2d::Sprite* bgSprite = cocos2d::Sprite::create("bk.png");
    //    bgSprite->setPosition(bgSprite->getContentSize().width/2,bgSprite->getContentSize().height/2);
    //    bgLayer->addChild(bgSprite,0);
    
    Mask = MaskNode::create(TRAIL_INIT);
    
    Mask->setPosition(0,0);
    Tag->addChild(Mask,0);
    Mask->Test(EffectLayer);
    Mask->Run();
    ResourceSystem::getInstance()->Init(EffectLayer);
    BattleSystem::getInstance()->getMonster()->AddToLayer(EffectLayer);
    GameConfigSystem::getInstance()->SetGameSpeed(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SPEED));
    GameTopStateBar* _gametopstatebar = GameTopStateBar::create();
    Tag->addChild(_gametopstatebar,2);
    
    Tag->schedule(std::bind([=]
                            {
                                if(BattleSystem::getInstance()->getPlayer()->getState()->GetHP()<=0)
                                {
                                    this->LOSE();
                                }
                            }),"LOSE");
    
    Tag->schedule(std::bind([=]
                            {
                                if(BattleSystem::getInstance()->getMonster()->getState()->GetHP()<=0)
                                {
                                    this->WIN();
                                }
                            }),"WIN");
    
}


void TrialSystem::LOSE()
{
    if(ReLfie == true && LifeUsed == false)
    {
        ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, HEALTH, ADD, BattleSystem::getInstance()->getPlayer()->getState()->GetHpMax()*0.3f);
        LifeUsed = true;
        return;
    }
    Tag->unscheduleAllCallbacks();
    Mask->SetOver(true);
    int size = (int)Tag->getChildren().size();
    for(int i = 0 ; i < size ; i++)
    {
        Tag->getChildren().at(i)->unscheduleAllCallbacks();
    }
    LoseLayer* pRet = LoseLayer::create();
    Tag->addChild(pRet,6);
    MyLog::getInstance()->log("lose");
}

void TrialSystem::WIN()
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
                                                                          WinLayer* pRet = WinLayer::create();
                                                                          Tag->addChild(pRet,6);
                                                                          MyLog::getInstance()->log("win");
                                                                      }));
    cocos2d::DelayTime* Wait = cocos2d::DelayTime::create(0.5f);
    cocos2d::Sequence* Seq = cocos2d::Sequence::create(BattleSystem::getInstance()->getMonster()->GetDeathAnimate(),Wait,CallBack, NULL);
    BattleSystem::getInstance()->getMonster()->StopAction();
    BattleSystem::getInstance()->getMonster()->RunAciton(Seq);
    Parser::XML::getInstance()->SetTrailTop(Parser::XML::getInstance()->GetTrailTop()+1);
    
}