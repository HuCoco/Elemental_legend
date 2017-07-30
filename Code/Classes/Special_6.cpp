//
//  Special_6.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/25.
//
//

#include "Special_6.h"
#include "BattleSystem.h"
#include "ResourceSystem.h"
#include "GameSystem.h"
#include "AttrSystem.h"
#include "GameConfigSystem.h"
Special_6::Special_6()
{
    _sName = "Special_6";
    isCheck = false;
}


Special_6::~Special_6()
{
    
}

void Special_6::Cast(cocos2d::Node *_tag)
{

    _tag->schedule(std::bind([=]
                             {
                                 if(isCheck == false)
                                 {
                                     isCheck = true;

                                     GameConfigSystem::getInstance()->SetGameSpeed(GameConfigSystem::getInstance()->GetGameSpeed());
                                     _tag->scheduleOnce(std::bind([=]
                                                                  {
                                                                      GameConfigSystem::getInstance()->SetGameSpeed(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_SPEED));
                                                                      isCheck = false;
                                                                  }), 4,"IceSlow");
                                 }
                             }),15, _sName);
    
}