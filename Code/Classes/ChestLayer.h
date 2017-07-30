//
//  ChestLayer.h
//  NewGame
//
//  Created by 胡可 on 15/11/4.
//
//

#ifndef ChestLayer_h
#define ChestLayer_h

#include <stdio.h>
#include "cocos2d.h"

enum CHEST_TYPE
{
    GOLDEN,
    SLIVER
};

enum PRIZE_LIST
{
    ONE_TICKET,
    THREE_TICKET,
    FIVE_TICKET,
    FIFTH_COIN,
    TWO_HURDENT_COIN,
    FIVE_HURDEND_COIN,  
    THREE_DIAMONDS,
    TEN_DIAMONDS
};







class ChestLayer
:public cocos2d::Layer
{
private:
    ChestLayer();
    ~ChestLayer();
    virtual bool init(CHEST_TYPE);
    void BaseInit();
    void GoldenInit();
    void SliverInit();
    void FailInit(CHEST_TYPE);
    void GetGoldenPrize();
    void GetSliverPrize();
    void Close();
public:
    static ChestLayer* create(CHEST_TYPE);
private:
    std::string _chestfile;
    std::string _chestopenfile;
    cocos2d::Sprite* _chestlight;
    cocos2d::Sprite* _chest;
    cocos2d::Sprite* _light;
    cocos2d::Sprite* _prize;
    cocos2d::MenuItemImage* _okBtn;
    cocos2d::Menu* _menu;
    cocos2d::Label* _info;
    PRIZE_LIST _prizeData;
};

#endif /* ChestLayer_h */
