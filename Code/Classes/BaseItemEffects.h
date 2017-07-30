//
//  BaseItemEffects.h
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#ifndef BaseItemEffects_h
#define BaseItemEffects_h

#include "BaseElement.h"

class BaseItemEffects
{
public:
    BaseItemEffects();
    ~BaseItemEffects();
    virtual void Cast(int,ELEMENT_TYPE,cocos2d::Node*);
};

#endif /* BaseItemEffects_h */
