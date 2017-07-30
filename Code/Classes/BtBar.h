//
//  BtBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/7.
//
//

#ifndef BtBar_h
#define BtBar_h


#include "ResourceBar.h"
class BtBar
:public ResourceBar
{
public:
    BtBar();
    RES_FUNC(BtBar);
    virtual int Add(int _data);
    virtual int Reduce(int _data);
protected:
    ~BtBar();
    virtual bool init(cocos2d::Vec2 _pos);
    
};
#endif /* BtBar_h */
