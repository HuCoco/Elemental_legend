//
//  ItemSystem.h
//  NewGame
//
//  Created by 胡可 on 15/11/16.
//
//

#ifndef ItemSystem_h
#define ItemSystem_h
#include "AttrSystem.h"
#include "JsonParser.h"
enum ITEM_LEVEL_LIST
{
    NORMAL_ITEM,
    EXCELLENT_ITEM,
    EPIC_ITEM,
    SUIT_ITEM,
    LEGEND_ITEM
};

struct ATTR_VALUE_DATA
{
    ATTR_TYPE _type;
    int _value = 0;
};

enum SUIT_LIST
{
    NO_SUIT,
    SAND
};

enum ITEM_ELEMENT
{
    ITEM_FIRE,
    ITEM_WATER,
    ITEM_WIND,
    ITEM_THUNDER,
    ITEM_MAGIC
};

struct ITEM_DATA
{
    std::string name = "";
    std::string info = "";
    int itemNo = -1;
    ITEM_LEVEL_LIST _itemlevel = NORMAL_ITEM;
    ATTR_VALUE_DATA attr1;
    ATTR_VALUE_DATA attr2;
    SUIT_LIST _suit = NO_SUIT;
    ITEM_ELEMENT _Ele;
    int ItemCode = -1;
    void Clone(ITEM_DATA* _data)
    {
        name = _data->name;
        info = _data->info;
        itemNo = _data->itemNo;
        _itemlevel = _data->_itemlevel;
        attr1._type = _data->attr1._type;
        attr1._value = _data->attr1._value;
        attr2._type = _data->attr2._type;
        attr2._value = _data->attr2._value;
        _suit = _data->_suit;
        _Ele = _data->_Ele;
        ItemCode = _data->ItemCode;
    }
    
    void Clean()
    {
        name = "";
        info = "";
        itemNo = -1;
        _itemlevel = ITEM_LEVEL_LIST::NORMAL_ITEM;
        attr1._type = ATTR_HEALTH;
        attr1._value = 0;
        attr2._type = ATTR_HEALTH;
        attr2._value = 0;
        _suit = SUIT_LIST::NO_SUIT;
        _Ele = ITEM_ELEMENT::ITEM_FIRE;
        ItemCode = -1;
    }
};

enum GET_ITEM_METHOD
{
    NORMAL,
    GET_EXCELLENT_ITEM_AL_LEAST,
    GET_EPIC_ITEM_ITEM_AL_LEAST
};



class ItemSystem
{
private:
    ItemSystem();
    ~ItemSystem();
    ITEM_DATA* CreateFireItem();
    ITEM_DATA* CreateWaterItem();
    ITEM_DATA* CreateWindItem();
    ITEM_DATA* CreateThunderItem();
    ITEM_DATA* CreateMagicItem();
    ITEM_LEVEL_LIST GetLevelRandom1();
    ITEM_LEVEL_LIST GetLevelRandom2();
    ITEM_LEVEL_LIST GetLevelRandom3();
    ATTR_VALUE_DATA* ParseAttrByAttrString(const std::string & attrstr);
public:
    static ItemSystem* getInstance();
    ITEM_DATA* CreateItem(GET_ITEM_METHOD);
    int GetItemCoin(ITEM_DATA*);
    std::string GetItemStringByItemData(ITEM_DATA*);
    ITEM_DATA* ParseItemDataByItemString(const std::string& _itemstr);  ////[物品编号][物品部位][物品稀有度][物品属性][物品属性][何种套装]
private:
    static ItemSystem* _instance;
};
#endif /* ItemSystem_h */
