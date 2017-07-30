//
//  SuitBar.h
//  NewGame
//
//  Created by 胡可 on 15/11/15.
//
//

#ifndef SuitBar_h
#define SuitBar_h


#include "cocos2d.h"
#include "cocos-ext.h"
#include "ItemBar.h"

class SuitBar
:public cocos2d::Node
{
private:
    SuitBar();
    ~SuitBar();
    virtual bool init();
    void TouchCallBack(int _tag);
    void SuitInit();
    void FloorInit();
    void L1Aciton();
    void L2Aciton();
    void L3Action();
    void L4Aciion();
    void L5Aciton();

public:
    CREATE_FUNC(SuitBar);
    void HaloRunAction();
private:
    cocos2d::Sprite* OuterHalo;
    cocos2d::Sprite* InnerHalo;
    std::vector<cocos2d::MenuItemImage*> floorPool;
    std::vector<ItemBar*>* SuitPool;
};

#endif /* SuitBar_h */
