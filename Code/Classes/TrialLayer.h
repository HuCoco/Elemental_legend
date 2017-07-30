//
//  TrialLayer.h
//  NewGame
//
//  Created by 胡可 on 15/11/18.
//
//

#ifndef TrialLayer_h
#define TrialLayer_h

#include "cocos2d.h"
#include "cocos-ext.h"
class TrialLayer
:public cocos2d::Layer
{
private:
    TrialLayer();
    ~TrialLayer();
    virtual bool init();
    void GotoHomeScene();
    void TrailStart();
public:
    CREATE_FUNC(TrialLayer);
private:
    int TrialLevel;
    cocos2d::Label* TrialLevelLabel;
    
};

#endif /* TrialLayer_h */
