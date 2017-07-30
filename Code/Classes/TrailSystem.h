//
//  TrailSystem.h
//  NewGame
//
//  Created by 胡可 on 15/11/18.
//
//

#ifndef TrailSystem_h
#define TrailSystem_h

#include <stdio.h>
#include "cocos2d.h"
#include "MaskNode.h"
class TrialSystem
{
private:
    TrialSystem();
    ~TrialSystem();
public:
    static TrialSystem* getInstance();
    void SetConfig(cocos2d::Scene* _tag);
    void GetReady();
    void LOSE();
    void WIN();
public:
    inline void SetLifeState(bool _life){ReLfie = _life;}
    inline void setGate(int _gate){gate = _gate;}
    inline int getGate(){return gate;}
private:
    static TrialSystem* _instance;
    cocos2d::Scene* Tag;
    MaskNode* Mask;
    bool ReLfie;
    bool LifeUsed;
    int gate;
};

#endif /* TrailSystem_h */
