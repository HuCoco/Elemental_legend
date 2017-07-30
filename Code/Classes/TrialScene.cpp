//
//  TrialScene.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/18.
//
//

#include "TrialScene.h"
#include "TopStateBar.h"
#include "TrialLayer.h"

TrialScene::TrialScene()
{
    
}

TrialScene::~TrialScene()
{
    
}

bool TrialScene::init()
{
    if(!cocos2d::Scene::init())
    {
        return false;
    }
    TrialLayer* layer = TrialLayer::create();
    this->addChild(layer);
    
    TopStateBar* topstatebar = TopStateBar::create();
    this->addChild(topstatebar);
    
    return true;
}