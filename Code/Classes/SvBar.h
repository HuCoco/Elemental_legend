//
//  SvBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/7.
//
//

#ifndef SvBar_h
#define SvBar_h


#include "ResourceBar.h"
class SvBar
:public ResourceBar
{
public:
    SvBar();
    RES_FUNC(SvBar);
    virtual int Add(int _data);
    virtual int Reduce(int _data) ;
protected:
    ~SvBar();
    virtual bool init(cocos2d::Vec2 _pos);
    
};
#endif /* SvBar_h */
