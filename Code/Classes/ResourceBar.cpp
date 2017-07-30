//
//  ResourceBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#include "ResourceBar.h"


ResourceBar::ResourceBar()
{
    
}


ResourceBar::~ResourceBar()
{
    
}




void ResourceBar::AddToLayer(cocos2d::Layer *_tag)
{
    _tag->addChild(Bar1);
    if(Bar2 == nullptr)
    {
        return;
    }
    _tag->addChild(Bar2);
}

bool ResourceBar::init(cocos2d::Vec2 _pos)
{
    

    
    return true;
}

int ResourceBar::Add(int _data)
{
    return 0;
}

int ResourceBar::Reduce(int _data)
{
    
}