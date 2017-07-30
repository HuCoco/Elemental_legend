//
//  ItemBar.h
//  NewGame
//
//  Created by 胡可 on 15/11/16.
//
//

#ifndef ItemBar_h
#define ItemBar_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ItemSystem.h"
class ItemBar
:public cocos2d::Node
{
private:
    ItemBar();
    ~ItemBar();
    virtual bool init(ITEM_DATA*);
public:
    static ItemBar* create(ITEM_DATA*);
    void Clone(ITEM_DATA*);
    bool isEmpty();
    ITEM_DATA* getData(){return data;}
private:
    cocos2d::ui::Scale9Sprite* floor;
    cocos2d::Sprite* icon;
    ITEM_DATA* data;
};

#endif /* ItemBar_h */
