//
//  GuideSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#ifndef GuideSystem_h
#define GuideSystem_h


#include "MaskNode.h"
#include "ElementTipsBar.h"
class BaseGuideLayer;
class GuideSystem
{
private:
    GuideSystem();
    ~GuideSystem();
    void Win();
public:
    static GuideSystem* getInstance();
    void SetConfig(cocos2d::Scene* _tag);
    void GetReady();
    void InitGuideData();
    void AddResourceBar();
    void AddTopStatrBar();
    void AddFloorFrame();
    void AddMonster();
    void AddElement();
    void run();
    inline ElementTipsBar* GetTipsInstance(){return TipsBar;}
    inline bool isRunning(){return isRun;}
private:
    static GuideSystem* _instance;
    cocos2d::Scene* Tag;
    MaskNode* Mask;
    int Speed;
    std::vector<BaseGuideLayer*>* GuideLayerPool;
    cocos2d::Layer* EffectLayer;
    ElementTipsBar* TipsBar;
    bool isRun;
};

#endif /* GuideSystem_h */
