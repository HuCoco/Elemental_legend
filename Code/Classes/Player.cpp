//
//  Player.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#include "Player.h"

Player::Player()
{
    
}

Player::~Player()
{
    
}

bool Player::init(ROLE_STATE _statedata,bool _isGuide)
{
    if(!BaseRole::init())
    {
        return false;
    }
    ReduceCastMagic = 0;
    ReduceCastElement = 0;
    StateData = State::create(_statedata);
    SkillManagerData = SkillManager::create(PLAYER,_isGuide);
    return true;
}

Player* Player::create(ROLE_STATE _statedata,bool _isGuide)
{
    Player* pRet = new Player();
    if(pRet && pRet->init(_statedata,_isGuide))
    {
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool Player::SelectSkill(PLAYER_SKILL_NO _sno, cocos2d::Layer *_tag, cocos2d::Vec2 _pos, int& _num)
{
    CCLOG("Skill:%d",(int)_sno);
    return static_cast<PlayerBaseSkill*>(SkillManagerData->SelectSkill((int)_sno))->Cast(_tag, _pos, _num);
};

int Player::getTouchMax(PLAYER_SKILL_NO _sno)
{
    return ((PlayerBaseSkill*)SkillManagerData->SelectSkill((int)_sno))->getTouchMax();
}