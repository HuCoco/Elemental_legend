//
//  TrailGameScene.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/18.
//
//

#include "TrailGameScene.h"
#include "TrailSystem.h"
TrailGameScene::TrailGameScene()
{
    
}

TrailGameScene::~TrailGameScene()
{
    
}

bool TrailGameScene::init()
{
    if(!cocos2d::Scene::init())
    {
        return false;
    }
    
    TrialSystem::getInstance()->SetConfig(this);
    TrialSystem::getInstance()->GetReady();
    return true;
    
}


