//
//  HomeScene.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/10.
//
//

#include "HomeScene.h"

HomeScene::HomeScene()
{
    
}


HomeScene::~HomeScene()
{
    
}


bool HomeScene::init()
{
    if(!cocos2d::Scene::init())
    {
        return false;
    }
    

    _mapbar = MapBar::create();
    this->addChild(_mapbar);

    _topstatebar = TopStateBar::create();
    this->addChild(_topstatebar);

    _bottomstatebar = BottomStateBar::create();
    this->addChild(_bottomstatebar);

    _chapterbar = ChapterBar::create();
    this->addChild(_chapterbar);

    _playstatebar = PlayStateBar::create();
    this->addChild(_playstatebar);
    return true;
}