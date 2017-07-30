//
//  ItemBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/16.
//
//

#include "ItemBar.h"

ItemBar::ItemBar()
{
    
}

ItemBar::~ItemBar()
{
    
}

void ItemBar::Clone(ITEM_DATA* _data)
{
    data->name = _data->name;
    data->info = _data->info;
    data->itemNo = _data->itemNo;
    data->attr1._type = _data->attr1._type;
    data->attr1._value = _data->attr1._value;
    data->attr2._type = _data->attr2._type;
    data->attr2._value = _data->attr2._value;
    data->_itemlevel = _data->_itemlevel;
    data->_Ele = _data->_Ele;
    data->_suit = _data->_suit;
}

ItemBar* ItemBar::create(ITEM_DATA* _data)
{
    ItemBar* pRet = new ItemBar;
    if(pRet && pRet->init(_data))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool ItemBar::init(ITEM_DATA* _data)
{
    if(!cocos2d::Node::init())
    {
        return false;
    }
    data = _data;
    std::string floorpath = cocos2d::StringUtils::format("UI/backpack_level%d.png",data->_itemlevel);
    
    floor = cocos2d::ui::Scale9Sprite::create(floorpath);
    floor->setContentSize(cocos2d::Size(100,100));
    this->addChild(floor);
    if(data->itemNo >= 0)
    {
        std::string iconpath = cocos2d::StringUtils::format("Item/Item#%d.png",data->itemNo);
        icon = cocos2d::Sprite::create(iconpath);
        this->addChild(icon);
    }
    return true;
    
}

bool ItemBar::isEmpty()
{
    if(data->itemNo < 0)
    {
        return true;
    }
    return false;
}