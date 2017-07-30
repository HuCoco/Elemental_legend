//
//  GameSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/9.
//
//

#ifndef GameSystem_h
#define GameSystem_h


#include "cocos2d.h"
#include "MaskNode.h"
#include "ElementTipsBar.h"
class GameSystem
{
private:
    GameSystem();
    ~GameSystem();
public:
    static GameSystem* getInsatance();
    void SetConfig(cocos2d::Scene* _tag);
    void GetReady();
    void LOSE();
    void WIN();
public:
    inline void SetLifeState(bool _life){ReLfie = _life;}
    inline void setGate(int _gate){gate = _gate;}
    inline int getGate(){return gate;}
    inline ElementTipsBar* GetTipsInstance(){return TipsBar;}
    inline bool isRunning(){return isRun;}
private:
    static GameSystem* _instance;
    cocos2d::Scene* Tag;
    MaskNode* Mask;
    ElementTipsBar* TipsBar;
    bool ReLfie;
    bool LifeUsed;
    int gate;
    bool isRun;
};

#endif /* GameSystem_h */
