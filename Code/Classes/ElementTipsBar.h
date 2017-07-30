//
//  ElementTipsBar.h
//  NewGame
//
//  Created by 胡可 on 15/12/2.
//
//

#ifndef ElementTipsBar_h
#define ElementTipsBar_h

#include "cocos2d.h"
#include "BaseElement.h"

class ElementTipsBar
:public cocos2d::Node
{
private:
    ElementTipsBar();
    ~ElementTipsBar();
    virtual bool init();
public:
    CREATE_FUNC(ElementTipsBar);
    void ChangeIcon(ELEMENT_TYPE);
    void SetTouchTimes(int);
    cocos2d::Size GetSize();
    void AddToLayer(cocos2d::Node* _tag);
private:
    cocos2d::Sprite* ElementIcon;
    cocos2d::Label* TouchTimes;
    ELEMENT_TYPE _type;
    
};

#endif /* ElementTipsBar_h */
