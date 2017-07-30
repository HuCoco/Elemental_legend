//
//  ItemInfoLayer.h
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#ifndef ItemInfoLayer_h
#define ItemInfoLayer_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ItemSystem.h"
#include "AttrSystem.h"

enum ITEM_SHOW_METHOD
{
    NORMAL_SHOW,
    COMPARE_SHOW
};

class ItemBar;
class ItemInfoLayer
:public cocos2d::Layer
{
private:
    ItemInfoLayer();
    ~ItemInfoLayer();
    virtual bool init(ITEM_DATA*,bool,ITEM_SHOW_METHOD);
    std::string getAttrStr(ATTR_TYPE);
    void BackCallBack();
    void GetCallBack();
    void PutCallBack(bool);
    void PayCallBack();
    cocos2d::Color3B getColorByLevel(ITEM_LEVEL_LIST);
    cocos2d::Label* getItemEle(ITEM_ELEMENT,int);
    void NormalShow();
    void CompareShow(ITEM_DATA*);
public:
    static ItemInfoLayer* create(ITEM_DATA*,bool = true,ITEM_SHOW_METHOD = NORMAL_SHOW);
    void SetThisItemBar(ItemBar*);
private:
    cocos2d::MenuItemImage* backBtn;
    ITEM_DATA* data;
    ItemBar* itembar;
    
};

#endif /* ItemInfoLayer_h */
