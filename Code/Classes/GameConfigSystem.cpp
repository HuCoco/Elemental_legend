//
//  GameConfigSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#include "GameConfigSystem.h"

GameConfigSystem* GameConfigSystem::_instance = nullptr;

GameConfigSystem::GameConfigSystem()
{
    
}


GameConfigSystem::~GameConfigSystem()
{
    
}


GameConfigSystem* GameConfigSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new GameConfigSystem;
    }
    return _instance;
}