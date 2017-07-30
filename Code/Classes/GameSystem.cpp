//
//  GameSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/9.
//
//

#include "GameSystem.h"
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
GameSystem* GameSystem::_instance = nullptr;

GameSystem::GameSystem()
{
    LifeUsed = false;
    ReLfie = false;
    isRun = false;
}


GameSystem::~GameSystem()
{
    
}

GameSystem* GameSystem::getInsatance()
{
    if(_instance == nullptr)
    {
        _instance = new GameSystem;
    }
    return _instance;
}

void GameSystem::SetConfig(cocos2d::Scene *_tag)
{
    Tag = _tag;
}

void GameSystem::GetReady()
{
    isRun = true;
    
    LifeUsed = false;
    ReLfie = false;
    

    
    cocos2d::Layer* EffectLayer = cocos2d::Layer::create();
    Tag->addChild(EffectLayer,1);
    
    cocos2d::Layer* bgLayer = FloorFrameLayer::create();
    Tag->addChild(bgLayer,0);
    
//    cocos2d::Sprite* bgSprite = cocos2d::Sprite::create("bk.png");
//    bgSprite->setPosition(bgSprite->getContentSize().width/2,bgSprite->getContentSize().height/2);
//    bgLayer->addChild(bgSprite,0);
    
    Mask = MaskNode::create();
    TipsBar = ElementTipsBar::create();
    TipsBar->AddToLayer(EffectLayer);
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



void GameSystem::LOSE()
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
    isRun = false;
}

void GameSystem::WIN()
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
    if(GameSystem::getInsatance()->getGate() > Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COMPLETE_GATE))
    {
        Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COMPLETE_GATE, GameSystem::getInsatance()->getGate());
    }
    
    if(GameSystem::getInsatance()->getGate() == 20)
    {
        Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COMPLETE_CHAPTER, 2);
        //BUG
    }
    isRun = false;
}
