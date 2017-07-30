//
//  BuyBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/24.
//
//

#ifndef BuyBar_h
#define BuyBar_h


#include "cocos2d.h"
#include <cocos-ext.h>

enum BUY_SOMETHING
{
    BUY_COIN,
    BUY_DIAMOND
};


class BuyBar
:public cocos2d::ui::Scale9Sprite
{
private:
    BuyBar();
    ~BuyBar();
    virtual bool init(BUY_SOMETHING,int);
public:
    static BuyBar* create(BUY_SOMETHING,int);
private:
    BUY_SOMETHING _buyWhat;
    int Value;
};

#endif /* BuyBar_h */
