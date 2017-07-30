//
//  Monster.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#include "Monster.h"

Monster::Monster()
{
    
}


Monster::~Monster()
{
    
}

Monster* Monster::Trailcreate(ROLE_STATE _statedata, int _type)
{
    Monster* pRet = new Monster;
    if(pRet && pRet->TrialInit(_statedata,_type))
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

bool Monster::TrialInit(ROLE_STATE _statedata, int _type)
{
    filepath = cocos2d::StringUtils::format("monster/monster%d.png",_type);
    StayAnimateInit();
    AttackAnimateInit();
    DeathAnimateInit();
    
    StateData = State::create(_statedata);
    InitStateData = State::create(_statedata);
    _monsterPlayer = Sprite::create(filepath,cocos2d::Rect(0,0,240,240));
    if(_monsterPlayer == nullptr)
    {
        CCLOG("null");
    }
    _monsterPlayer->setPosition(Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/10*9 - _monsterPlayer->getContentSize().height/2 - 10);
    _monsterPlayer->retain();
    SkillManagerData = SkillManager::Trailcreate(MONSTER);
    if(SkillManagerData->getPoolSize() <= 3)
    {
        _monsterlist = MONSTER_LIST::OTHER;
    }
    else if(SkillManagerData->getPoolSize() == 4)
    {
        _monsterlist = MONSTER_LIST::GATE_BOSS;
    }
    else if(SkillManagerData->getPoolSize() == 5)
    {
        _monsterlist = MONSTER_LIST::CHAPTER_BOSS;
    }
    return true;
}


Monster* Monster::create(ROLE_STATE _statedata,int _type,bool _isGuide)
{
    Monster* pRet = new Monster;
    if(pRet && pRet->init(_statedata,_type,_isGuide))
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


bool Monster::init(ROLE_STATE _statedata,int _type,bool _isGuide)
{
    if(!BaseRole::init())
    {
        return false;
    }
    filepath = cocos2d::StringUtils::format("monster/monster%d.png",_type);
    StayAnimateInit();
    AttackAnimateInit();
    DeathAnimateInit();
    
    StateData = State::create(_statedata);
    InitStateData = State::create(_statedata);
    _monsterPlayer = Sprite::create(filepath,cocos2d::Rect(0,0,240,240));
    if(_monsterPlayer == nullptr)
    {
        CCLOG("null");
    }
    _monsterPlayer->setPosition(Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/10*9 - _monsterPlayer->getContentSize().height/2 - 10);
    _monsterPlayer->retain();
    SkillManagerData = SkillManager::create(MONSTER,_isGuide);
    if(SkillManagerData->getPoolSize() <= 3)
    {
        _monsterlist = MONSTER_LIST::OTHER;
    }
    else if(SkillManagerData->getPoolSize() == 4)
    {
        _monsterlist = MONSTER_LIST::GATE_BOSS;
    }
    else if(SkillManagerData->getPoolSize() == 5)
    {
        _monsterlist = MONSTER_LIST::CHAPTER_BOSS;
    }
    return true;
}

void Monster::StayAnimateInit()
{
    cocos2d::Animation* animation = cocos2d::Animation::create();
    cocos2d::Vector<cocos2d::SpriteFrame*> FramePool;
    cocos2d::SpriteFrame* pRet;
    for(int i = 0;i<4;i++)
    {
        pRet = cocos2d::SpriteFrame::create(filepath, cocos2d::Rect(240*i,0,240,240));
        FramePool.pushBack(pRet);
    }
    animation = cocos2d::Animation::createWithSpriteFrames(FramePool);
    animation->setDelayPerUnit(0.6f / 4.0f);
    animation->setRestoreOriginalFrame(true);
    StayAnimate = cocos2d::Animate::create(animation);
    StayAnimate->retain();
    StayRepeat = cocos2d::RepeatForever::create(StayAnimate);
    StayRepeat->retain();
}

void Monster::AttackAnimateInit()
{
    cocos2d::Animation* animation = cocos2d::Animation::create();
    cocos2d::Vector<cocos2d::SpriteFrame*> FramePool;
    cocos2d::SpriteFrame* pRet;
    for(int i = 0;i<4;i++)
    {
        pRet = cocos2d::SpriteFrame::create(filepath, cocos2d::Rect(240*i,240,240,240));
        FramePool.pushBack(pRet);
    }
    animation = cocos2d::Animation::createWithSpriteFrames(FramePool);
    animation->setDelayPerUnit(0.3f / 4.0f);
    animation->setRestoreOriginalFrame(true);
    AttackAnimate = cocos2d::Animate::create(animation);
    AttackAnimate->retain();
}

void Monster::DeathAnimateInit()
{
    cocos2d::Animation* animation = cocos2d::Animation::create();
    cocos2d::Vector<cocos2d::SpriteFrame*> FramePool;
    cocos2d::SpriteFrame* pRet;
    for(int i = 0;i<4;i++)
    {
        pRet = cocos2d::SpriteFrame::create(filepath, cocos2d::Rect(240*i,480,240,240));
        FramePool.pushBack(pRet);
    }
    animation = cocos2d::Animation::createWithSpriteFrames(FramePool);
    animation->setDelayPerUnit(0.4f / 4.0f);
    animation->setRestoreOriginalFrame(false);
    DeathAnimate = cocos2d::Animate::create(animation);
    DeathAnimate->retain();
}

void Monster::AddToLayer(cocos2d::Layer *_tag)
{
    _tag->addChild(_monsterPlayer);
}



void Monster::Cast(cocos2d::Node* _tag)
{
    for(int i = 0 ; i < SkillManagerData->getPoolSize();i++)
    {
        static_cast<MonsterBaseSkill*>(SkillManagerData->SelectSkill(i))->Cast(_tag);
    }
}

void Monster::ResetAttackCast(cocos2d::Node *_tag)
{
    static_cast<MonsterBaseSkill*>(SkillManagerData->SelectSkill(0))->Cast(_tag);
}
