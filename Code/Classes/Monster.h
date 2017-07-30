//
//  Monster.h
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#ifndef Monster_h
#define Monster_h

#include <stdio.h>
#include "BaseRole.h"

enum MONSTER_SKILL_NO
{
    SN_ATTACK
};

enum MONSTER_LIST
{

    OTHER,
    GATE_BOSS,
    CHAPTER_BOSS
};






class Monster
:public BaseRole
{
private:
    Monster();
    ~Monster();
    void AttackAnimateInit();
    void DeathAnimateInit();
    void StayAnimateInit();
public:
    static Monster* create(ROLE_STATE,int _type,bool _isGuide = false);
    static Monster* Trailcreate(ROLE_STATE,int _type);
    virtual bool init(ROLE_STATE,int _type,bool _isGuide = false);
    virtual bool TrialInit(ROLE_STATE,int _type);
    void Cast(cocos2d::Node* _tag);
    void ResetAttackCast(cocos2d::Node* _tag);
    void AddToLayer(cocos2d::Layer* _tag);
    inline int getAttackSpeed(){return AttackSpeed;}
    inline void setAttackSpeed(int _attackspeed){AttackSpeed = _attackspeed;}
    inline State* getInitState(){return InitStateData;}
    void AddParticleToLayer(ParticleSystem* _particle,int _c){_monsterPlayer->getParent()->addChild(_particle,_c);}
    cocos2d::Animate* GetAttackAnimate(){return AttackAnimate->clone();}
    cocos2d::Animate* GetDeathAnimate(){return DeathAnimate->clone();}
    cocos2d::RepeatForever* GetStayRepeat(){return StayRepeat->clone();}
    void RunAciton(cocos2d::Action *action){_monsterPlayer->runAction(action);}
    void StopAction(){_monsterPlayer->stopAllActions();}
public:
    inline cocos2d::Vec2 getPosition(){return _monsterPlayer->getPosition();}
    inline cocos2d::Vec2 getFootPos(){return Vec2(_monsterPlayer->getPositionX(),_monsterPlayer->getPositionY() - _monsterPlayer->getContentSize().height/2);}
    inline cocos2d::Size getMonsterSize(){return _monsterPlayer->getContentSize();}
    inline MONSTER_LIST getMonsterList(){return _monsterlist;}
    inline void setMonsterList(MONSTER_LIST _list){_monsterlist = _list;}
private:
    State* InitStateData;
    Sprite* _monsterPlayer;
    int AttackSpeed;
    cocos2d::Animate* AttackAnimate;
    cocos2d::Animate* DeathAnimate;
    cocos2d::Animate* StayAnimate;
    cocos2d::RepeatForever* StayRepeat;
    std::string filepath;
    MONSTER_LIST _monsterlist;
};


#endif /* Monster_h */
