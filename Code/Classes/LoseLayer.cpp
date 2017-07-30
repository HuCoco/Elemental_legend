//
//  LoseLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/20.
//
//

#include "LoseLayer.h"
#include "HomeScene.h"
#include "GameSystem.h"
#include "RecordSystem.h"
#include "ExperienceSystem.h"
#include "MissionSystem.h"
#include "GameConfigSystem.h"
LoseLayer::LoseLayer()
{
    
}


LoseLayer::~LoseLayer()
{
    
}

ELEMENT_TYPE LoseLayer::GetMin(int _n1, int _n2, int _n3, int _n4)
{
    int Array[4] = {_n1,_n2,_n3,_n4};
    int MinNum = 0;
    for(int i = 1 ;i <=3;i++)
    {
        if(Array[MinNum] > Array[i])
        {
            MinNum = i;
        }
    }
    return ELEMENT_TYPE(MinNum+1);
}



bool LoseLayer::init()
{
    GameConfigSystem::getInstance()->SetGameSpeed(0);
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite);
    
    cocos2d::Sprite* LoseTitle = cocos2d::Sprite::create("UI/failed.png");
    LoseTitle->setPosition(visibleSize.width/2,visibleSize.height/5*4);
    this->addChild(LoseTitle);
    

    
    _okbtn = cocos2d::MenuItemImage::create("UI/ok_btn.png", "UI/ok_btn.png", std::bind(&LoseLayer::BackHome, this));
    _okbtn->setPosition(visibleSize.width/2,visibleSize.height/5);

    _menu = cocos2d::Menu::create(_okbtn,NULL);
    _menu->setPosition(0,0);
    this->addChild(_menu);

    
    MissionSystem::getInstance()->Update(MISSION_TYPE::USED_FIRE_300,RecordSystem::getInstance()->GetThisGameRecord(ELEMENT_TYPE::ET_FIRE));
    MissionSystem::getInstance()->Update(MISSION_TYPE::USED_WATER_300,RecordSystem::getInstance()->GetThisGameRecord(ELEMENT_TYPE::ET_WATER));
    MissionSystem::getInstance()->Update(MISSION_TYPE::USED_WIND_300,RecordSystem::getInstance()->GetThisGameRecord(ELEMENT_TYPE::ET_WIND));
    MissionSystem::getInstance()->Update(MISSION_TYPE::USED_THUNDER_300,RecordSystem::getInstance()->GetThisGameRecord(ELEMENT_TYPE::ET_THUNDER));
    
    
    MissionSystem::getInstance()->isCompletedMission();
    


    
    RecordSystem::getInstance()->AddAllDataToMainData();
    RecordSystem::getInstance()->SaveMainData();
    
    
    

//    
    
    
    return true;
}

void LoseLayer::BackHome()
{
    HomeScene* scene = HomeScene::create();
    cocos2d::TransitionCrossFade* fade = cocos2d::TransitionCrossFade::create(0.5f, scene);
    cocos2d::Director::getInstance()->replaceScene(fade);
}