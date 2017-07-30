//
//  BattleSystem.
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#ifndef BattleSystem_h
#define BattleSystem_h


#include "Player.h"
#include "Monster.h"
#include "SkillFactory.h"

class BattleSystem
{
public:
     BattleSystem();
    ~BattleSystem();

public:
    Player* getPlayer() {return _brPlayer;}
    Monster* getMonster(){return _brMonster;}
   
public:
    bool PlayerCastSkill(PLAYER_SKILL_NO _sno,cocos2d::Layer* _tag,cocos2d::Vec2 _pos,int& _num);
    void MonsterCastSkill(MONSTER_SKILL_NO _sno,cocos2d::Layer* _tag);
    int getTouchMax(PLAYER_SKILL_NO _sno);
    bool init(int _gate);
    bool GuideInit();
    bool TrailInit();
    static BattleSystem* getInstance();
private:
    static BattleSystem* _instance;
    Player* _brPlayer;
    Monster* _brMonster;
};




#endif /* BattleSystem_h */
