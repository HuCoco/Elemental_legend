//
//  GuideScene.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#include "GuideScene.h"
#include "GuideSystem.h"
GuideScene::GuideScene()
{
    
}

GuideScene::~GuideScene()
{
    
}

bool GuideScene::init()
{
    if(!cocos2d::Scene::init())
    {
        return false;
    }

    GuideSystem::getInstance()->SetConfig(this);
    GuideSystem::getInstance()->GetReady();
    return true;
    
}


