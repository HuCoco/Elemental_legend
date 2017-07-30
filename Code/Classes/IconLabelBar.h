//
//  IconLabelBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/22.
//
//

#ifndef IconLabelBar_h
#define IconLabelBar_h


#include "cocos2d.h"
#include <cocos-ext.h>
#include "BuyLayer.h"
enum ICON_LABEL_COLOR
{
    ILC_WHITE,
    ILC_RED,
    ILC_GREEN
};


class IconLabelBar
:public cocos2d::ui::Scale9Sprite
{
private:
    IconLabelBar();
    ~IconLabelBar();
    virtual bool init(const std::string& _iconfliepath,bool _isadd,int _value,int _width,int _height);
public:
    static IconLabelBar* create(const std::string& _iconfliepath,bool _isadd =false,int _value = 0,int _width = cocos2d::Director::getInstance()->getVisibleSize().width/3,int _height = cocos2d::Director::getInstance()->getVisibleSize().height/160*3 );
    void setValue(int _value);
    void SetColor(ICON_LABEL_COLOR _color);
    int getValue(){return value;}
    void AddBuyLayer();
    void SetBuyType(BUY_TYPE);
private:
    BUY_TYPE _buytype;
    int value;
    cocos2d::Sprite* Icon;
    cocos2d::Label* ValueLabel;
};



#endif /* IconLabelBar_h */
