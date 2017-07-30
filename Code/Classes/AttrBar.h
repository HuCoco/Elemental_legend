//
//  AttrBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#ifndef AttrBar_h
#define AttrBar_h


#include "cocos2d.h"
#include "cocos-ext.h"
#include "AttrSystem.h"
class AttrBar
:public cocos2d::Node
{
private:
    AttrBar();
    ~AttrBar();
    virtual bool init(ATTR_TYPE _type);
    void TitleInit();
public:
    static AttrBar* create(ATTR_TYPE _type);
    void AddLevel(int _level = 1);
    void Reset();
    inline int getlevel(){return level;}
    float GetHeight(){return _floor->getContentSize().height*1.1f;}

private:
    ATTR_TYPE type;
    int level;
    cocos2d::Label* _data;
    
    cocos2d::ui::Scale9Sprite* _floor;
    cocos2d::Sprite* _frame;
    cocos2d::Sprite* _icon;
    cocos2d::Label* _title;
    cocos2d::Label* _valueData;
    cocos2d::Label* _pointData;
    cocos2d::MenuItemImage* _addBtn;
    cocos2d::Menu* _menu;
    
    
    
   
};
#endif /* AttrBar_h */
