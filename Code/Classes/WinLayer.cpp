//
//  WinLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/20.
//
//

#include "WinLayer.h"
#include "HomeScene.h"
#include "GameSystem.h"
#include "RecordSystem.h"
#include "BattleSystem.h"
#include "ExperienceSystem.h"
#include "MissionSystem.h"
#include "XMLParser.h"
#include "GameConfigSystem.h"
#include "BackpackSystem.h"
WinLayer::WinLayer()
{
    
}


WinLayer::~WinLayer()
{
    
}

bool WinLayer::init()
{
    
    
    GameConfigSystem::getInstance()->SetGameSpeed(0);
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

    ExperienceBar* test = ExperienceBar::create();
    test->setPosition(visibleSize.width/2,visibleSize.height/5*3);
    this->addChild(test);
    
    //test->AddExp();
    int level = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::LEVEL);
    if(level >= 10 && level < 20)
    {
        if(BattleSystem::getInstance()->getMonster()->getMonsterList() >= MONSTER_LIST::GATE_BOSS)
        {
            test->AddExp();
        }
    }
    else if(level >= 20 )
    {
        if(BattleSystem::getInstance()->getMonster()->getMonsterList() >= MONSTER_LIST::CHAPTER_BOSS)
        {
            test->AddExp();
        }
    }
    else if(level < 10)
    {
        test->AddExp();
    }
    
    

    
    _okbtn = cocos2d::MenuItemImage::create("UI/ok_btn.png", "UI/ok_btn.png", std::bind(&WinLayer::BackHome, this));
    _okbtn->setPosition(visibleSize.width/2,visibleSize.height/5);

    _menu = cocos2d::Menu::create(_okbtn,NULL);
    _menu->setPosition(0,0);
    this->addChild(_menu);
    //
    //  任务处理逻辑
    //
    MissionSystem::getInstance()->Update(MISSION_TYPE::USED_FIRE_300,RecordSystem::getInstance()->GetThisGameRecord(ELEMENT_TYPE::ET_FIRE));
    MissionSystem::getInstance()->Update(MISSION_TYPE::USED_WATER_300,RecordSystem::getInstance()->GetThisGameRecord(ELEMENT_TYPE::ET_WATER));
    MissionSystem::getInstance()->Update(MISSION_TYPE::USED_WIND_300,RecordSystem::getInstance()->GetThisGameRecord(ELEMENT_TYPE::ET_WIND));
    MissionSystem::getInstance()->Update(MISSION_TYPE::USED_THUNDER_300,RecordSystem::getInstance()->GetThisGameRecord(ELEMENT_TYPE::ET_THUNDER));

    MissionSystem::getInstance()->isCompletedMission();
    cocos2d::Label* GetMission;
    if(rand()%100 <= 50)
    {
        
        if(MissionSystem::getInstance()->GetNewMission())
        {
            GetMission = cocos2d::Label::createWithTTF("恭喜你获得一个新任务快去查看吧！", "fonts/black.ttf", 30);

        }
        else
        {
            GetMission = cocos2d::Label::createWithTTF("任务列表已满，快去完成任务吧！", "fonts/black.ttf", 30);

        }
    }
    else
    {
        GetMission = cocos2d::Label::createWithTTF("这次没有找到合适你的任务，再继续找找吧！", "fonts/black.ttf", 30);

    }
    GetMission->setAlignment(cocos2d::TextHAlignment::CENTER);
    GetMission->setDimensions(visibleSize.width * 0.8f, visibleSize.height/20);
    GetMission->setPosition(visibleSize.width/2,visibleSize.height/5*2);
    this->addChild(GetMission);
    //
    // 结束
    //


    ITEM_DATA* item = BackpackSystem::getInstance()->GetNewItem((GET_ITEM_METHOD)BattleSystem::getInstance()->getMonster()->getMonsterList());
    if(item!=nullptr)
    {
        ItemBar* itembar = ItemBar::create(item);
        itembar->setPosition(visibleSize.width/2,visibleSize.height/10*3);
        this->addChild(itembar);
    }
    else
    {
        cocos2d::Label* itemLabel = cocos2d::Label::createWithTTF("背包满了，快去清理一下吧", "fonts/black.ttf", 30);
        itemLabel->setPosition(visibleSize.width/2,visibleSize.height/10*3);
        this->addChild(itemLabel);
    }
    
    RecordSystem::getInstance()->AddAllDataToMainData();
    RecordSystem::getInstance()->SaveMainData();
    
    
    
    return true;
}

void WinLayer::BackHome()
{
    HomeScene* scene = HomeScene::create();
    cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.5f, scene);
    cocos2d::Director::getInstance()->replaceScene(fade);
}