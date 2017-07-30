//
//  ExperienceBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/21.
//
//

#ifndef ExperienceBar_h
#define ExperienceBar_h


#include "cocos2d.h"
#include <cocos-ext.h>

class ExperienceBar
:public cocos2d::Node
{
private:
    ExperienceBar();
    ~ExperienceBar();
    virtual bool init();
    void ExpBarInit();
public:
    static ExperienceBar* create();
    void AddExp();
private:
    std::vector<cocos2d::Sprite*>SkillSignPool;
    std::vector<cocos2d::Sprite*>PassPool;
    int NowExp;
    int MaxExp;

};

#endif /* ExperienceBar_h */
