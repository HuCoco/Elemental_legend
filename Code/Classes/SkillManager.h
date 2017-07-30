//
//  SkillManager.h
//  NewGame
//
//  Created by 胡可 on 15/9/26.
//
//

#ifndef SkillManager_h
#define SkillManager_h

#include <stdio.h>
#include "PlayerBaseSkill.h"
#include "MonsterBaseSkill.h"
#include "BaseSkill.h"
#include "cocos2d.h"
#include "ResourceSystem.h"

class SkillManager
{
private:
    SkillManager();
    ~SkillManager();

public:
    static SkillManager* create(ROLE_TYPE,bool _isGuide = false);
    bool init(ROLE_TYPE);
    static SkillManager* Trailcreate(ROLE_TYPE);
    bool Trailinit(ROLE_TYPE);
    bool GuideInit(ROLE_TYPE);
    BaseSkill* SelectSkill(int);
    int getPoolSize(){return (int)SkillPool.size();}
private:
    std::vector<BaseSkill*> SkillPool;

};


#endif /* SkillManager_h */
