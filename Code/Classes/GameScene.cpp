//
//  GameScene.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/8.
//
//

#include "GameScene.h"
#include "ResourceSystem.h"
#include "MaskNode.h"
#include "CsvParser.h"
#include "XMLParser.h"
#include "BattleSystem.h"
#include "GameSystem.h"
#include "GameTopStateBar.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{
    
}

bool GameScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    
    
    GameSystem::getInsatance()->SetConfig(this);
    GameSystem::getInsatance()->GetReady();
    
    


    
    return true;
    
}