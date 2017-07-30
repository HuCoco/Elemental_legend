//
//  BaseElement.h
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#ifndef BaseElement_h
#define BaseElement_h


#include "cocos2d.h"

enum ELEMENT_TYPE
{
    ET_UNKOWN,
    ET_FIRE,
    ET_WIND,
    ET_WATER,
    ET_THUNDER,
    ET_MAGIC
};

class BaseElement
{
public:
    BaseElement();
    BaseElement(ELEMENT_TYPE _type);
    ~BaseElement();
    void AddToParent(cocos2d::Node* _parent);
    void setPosition(cocos2d::Vec2);
    void initPosition(int);
    inline cocos2d::Vec2 getPosition(){ return _ElmentSprite->getPosition();}
    bool OverButton();
    void Reback(cocos2d::Vec2 _top);
    void AddToTouchListen(cocos2d::EventDispatcher*,cocos2d::EventListenerTouchOneByOne*);
    void SetTag(int);
    void ReSetType();
    void SetOpacity(int _data){_ElmentSprite->setOpacity(_data);}
    ELEMENT_TYPE getElementType(){return _Type;}
protected:
    virtual bool init(ELEMENT_TYPE _type);
    
protected:
    ELEMENT_TYPE _Type;
   cocos2d::Sprite* _ElmentSprite;
};

#endif /* BaseElement_h */
