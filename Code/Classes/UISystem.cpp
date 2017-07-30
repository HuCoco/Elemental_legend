//
//  UISystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#include "UISystem.h"
UISystem* UISystem::_instance = nullptr;
UISystem::UISystem()
{
    _TopStateBarControl = true;
    _BottomStateBarControl = true;
    _BottomStateCanMove = true;
    _MapCanControl = true;
    _ItemLayerOpen = false;
}

UISystem::~UISystem()
{
    
}

UISystem* UISystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new UISystem;
    }
    return _instance;
}

void UISystem::OpenTopStateBar()
{
    _BottomStateBarControl = false;
}

void UISystem::CloseTopStateBar()
{
    _BottomStateBarControl = true;
}

void UISystem::OpenBottomStateBar()
{
    _TopStateBarControl = false;
}

void UISystem::CloseBottomStateBar()
{
    _TopStateBarControl = true;
}

void UISystem::OpenPlayerConfig()
{
    _TopStateBarControl = false;
    _BottomStateBarControl = false;
}

void UISystem::ClosePlayerConfig()
{
    _TopStateBarControl = true;
    _BottomStateBarControl = true;
}