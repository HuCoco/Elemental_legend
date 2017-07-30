//
//  LoadingScene.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/8.
//
//

#include "LoadingScene.h"
#include "LoadingLayer.h"
LoadingScene::LoadingScene()
{
    
}

LoadingScene::~LoadingScene()
{
    
}

bool LoadingScene::init()
{
    if(!cocos2d::Scene::init())
    {
        return false;
    }
    LoadingLayer* layer = LoadingLayer::create();
    this->addChild(layer);
    
    return true;
    
}


