//
//  GateBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#ifndef GateBar_h
#define GateBar_h


#include "cocos2d.h"

enum GATE_STATE_TYPE
{
    GATE_COMPLETED,
    GATE_UNCOMPLETED,
    GATE_CANT_GET
};


class GateBar
:public cocos2d::MenuItemImage
{
private:
    GateBar();
    ~GateBar();
    virtual bool init(int _gate,GATE_STATE_TYPE _statetype);
    
public:
    static GateBar* create(int _gate,GATE_STATE_TYPE _statetype);
    void AddGateConfig();
private:
    int GateNum;
    GATE_STATE_TYPE _type;
};

#endif /* GateBar_h */
