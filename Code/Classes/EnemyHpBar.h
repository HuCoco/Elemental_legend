//
//  EnemyHpBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/7.
//
//

#ifndef EnemyHpBar_h
#define EnemyHpBar_h


#include "ResourceBar.h"

class EnemyHpBar
:public ResourceBar
{
public:
    EnemyHpBar();
    RES_FUNC(EnemyHpBar);
    virtual int Add(int _data);
    virtual int Reduce(int _data);
protected:
    ~EnemyHpBar();
    virtual bool init(cocos2d::Vec2 _pos);
    
};
#endif /* EnemyHpBar_h */
