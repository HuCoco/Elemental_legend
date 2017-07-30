//
//  Sand1.h
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#ifndef Sand1_h
#define Sand1_h

#include "BaseItemEffects.h"

class Sand1
:public BaseItemEffects
{
public:
    Sand1();
    ~Sand1();
    virtual void Cast(int,ELEMENT_TYPE,cocos2d::Node*);
};

#endif /* Sand1_h */
