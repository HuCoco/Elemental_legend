//
//  Special_7.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//

#include "Special_7.h"
#include "ResourceSystem.h"
#include "GameSystem.h"
#include "GameConfigSystem.h"
#include "AttrSystem.h"
Special_7::Special_7()
{
    _sName = "Special_7";
    isCheck = false;
}


Special_7::~Special_7()
{
    
}

void Special_7::Cast(cocos2d::Node *_tag)
{
    _tag->schedule(std::bind([=]
                             {
                                 if(isCheck == false)
                                 {
                                     isCheck = true;
                                     GameConfigSystem::getInstance()->SetGameSpeed(0);
                                     _tag->scheduleOnce(std::bind([=]
                                                                  {
                                                                      GameConfigSystem::getInstance()->SetGameSpeed(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SPEED));
                                                                      isCheck = false;
                                                                  }), 2,"IceCold");
                                 }
                             }),15, _sName);
    
}