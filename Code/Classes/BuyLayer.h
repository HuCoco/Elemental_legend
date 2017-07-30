//
//  BuyLayer.h
//  NewGame
//
//  Created by 胡可 on 15/10/24.
//
//

#ifndef BuyLayer_h
#define BuyLayer_h


#include "cocos2d.h"
#include <cocos-ext.h>
enum BUY_TYPE
{
    NO_BUY,
    B_COIN,
    B_DIAMOND,
    B_TOOLS
};



class BuyLayer
:public cocos2d::Layer
{
private:
    BuyLayer();
    ~BuyLayer();
    virtual bool init(BUY_TYPE);
    void BaseInit();
    void InitBuyCoin();
    void InitBuyDiamond();
    void InitBuyTools();
public:
    static BuyLayer* create(BUY_TYPE);
private:
    cocos2d::ui::Scale9Sprite* _floor;
    cocos2d::MenuItemImage* _closeBtn;
    cocos2d::MenuItemImage* _buyBtn;
    cocos2d::Menu* _menu;
};
#endif /* BuyLayer_h */
