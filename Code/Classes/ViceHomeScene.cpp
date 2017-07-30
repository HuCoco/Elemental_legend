//
//  ViceHomeScene.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/27.
//
//

#include "ViceHomeScene.h"
#include "WelcomeLayer.h"

ViceHomeScene::ViceHomeScene()
{
    
}

ViceHomeScene::~ViceHomeScene()
{
    
}

bool ViceHomeScene::init()
{
    if(!cocos2d::Scene::init())
    {
        return false;
    }
    WelcomeLayer* _welcomelayer = WelcomeLayer::create();
    this->addChild(_welcomelayer);
    
    return true;
    
}


