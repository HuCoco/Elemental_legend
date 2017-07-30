//
//  Sand2.h
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#ifndef Sand2_h
#define Sand2_h

#include "BaseItemEffects.h"

class Sand2
:public BaseItemEffects
{
public:
    Sand2();
    ~Sand2();
    virtual void Cast(int,ELEMENT_TYPE,cocos2d::Node*);
private:
    bool isBuff;
    int times;
};

#endif /* Sand2_h */
