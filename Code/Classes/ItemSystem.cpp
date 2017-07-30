//
//  ItemSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/16.
//
//

#include "ItemSystem.h"
#include "XMLParser.h"
ItemSystem* ItemSystem::_instance = nullptr;

ItemSystem::ItemSystem()
{
    srand((int)time(NULL));
}

ItemSystem::~ItemSystem()
{
    
}

ItemSystem* ItemSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new ItemSystem;
    }
    return _instance;
}

//[物品编号][物品稀有度][契合部位][物品属性][物品属性][何种套装][标示码]
std::string ItemSystem::GetItemStringByItemData(ITEM_DATA* _data)
{
    std::string pRet;
    std::string part1 = "["+cocos2d::StringUtils::format("%d",_data->itemNo)+"]";
    std::string part2 = "["+cocos2d::StringUtils::format("%d",_data->_itemlevel)+"]";
    std::string part3 = "["+cocos2d::StringUtils::format("%d",_data->_Ele)+"]";
    std::string part4 = "["+cocos2d::StringUtils::format("%d,%d",_data->attr1._type,_data->attr1._value)+"]";
    std::string part5 = "["+cocos2d::StringUtils::format("%d,%d",_data->attr2._type,_data->attr2._value)+"]";
    std::string part6 = "["+cocos2d::StringUtils::format("%d",_data->_suit)+"]";
    std::string part7 = "["+cocos2d::StringUtils::format("%d",_data->ItemCode)+"]";
    
    pRet = part1 + part2 + part3 + part4 + part5 + part6 + part7;
    return pRet;
}

ATTR_VALUE_DATA* ItemSystem::ParseAttrByAttrString(const std::string &attrstr)
{
    ATTR_VALUE_DATA* pRet = new ATTR_VALUE_DATA;
    std::vector<std::string> strpool;
    strpool.push_back(std::string());
    int strlen = static_cast<int>(attrstr.length());
    for(int i = 0 ; i < strlen ; i++)
    {
        switch (attrstr[i]) {
            case ',':
                strpool.push_back(std::string());
                break;
            default:
                strpool.back() += attrstr.at(i);
                break;
        }
    }
    
    pRet->_type = static_cast<ATTR_TYPE>(std::atoi(strpool.at(0).c_str()));
    pRet->_value = std::atoi(strpool.at(1).c_str());
    
    return pRet;
}

ITEM_DATA* ItemSystem::ParseItemDataByItemString(const std::string& _itemstr)
{
    ITEM_DATA *pRet = new ITEM_DATA;
    std::vector<std::string> strpool;
    int strlen = static_cast<int>(_itemstr.length());
    for(int i = 0 ; i < strlen ; i++)
    {
        switch (_itemstr[i]) {
            case '[':
                strpool.push_back(std::string());
                break;
            case ']':
                continue;
            default:
                strpool.back() += _itemstr.at(i);
                break;
        }
    }
    //
    pRet->itemNo = std::atoi(strpool.at(0).c_str());
    pRet->_itemlevel = static_cast<ITEM_LEVEL_LIST>(std::atoi(strpool.at(1).c_str()));
    pRet->_Ele = static_cast<ITEM_ELEMENT>(std::atoi(strpool.at(2).c_str()));
    ATTR_VALUE_DATA* attrvalue = ParseAttrByAttrString(strpool.at(3));
    pRet->attr1._type = attrvalue->_type;
    pRet->attr1._value = attrvalue->_value;
    delete attrvalue;
    
    
    ATTR_VALUE_DATA* attrvalue2 = ParseAttrByAttrString(strpool.at(4));
    pRet->attr2._type = attrvalue2->_type;
    pRet->attr2._value = attrvalue2->_value;
    delete attrvalue2;
    
    pRet->_suit = static_cast<SUIT_LIST>(std::atoi(strpool.at(5).c_str()));
    ITEM_BASE_DATA* Temp2 = JsonParser::getInstance()->GetItenBaseData(cocos2d::StringUtils::format("Item#%d",pRet->itemNo));
    pRet->name = Temp2->name;
    pRet->info = Temp2->info;
    pRet->ItemCode = std::atoi(strpool.at(6).c_str());
    delete Temp2;
    return pRet;
}





ITEM_LEVEL_LIST ItemSystem::GetLevelRandom1()
{
    ITEM_LEVEL_LIST pRet;
    int Random = rand()%100;
    if(Random < 60)
    {
        pRet = ITEM_LEVEL_LIST::NORMAL_ITEM;
    }
    else if(Random >= 60 && Random < 95)
    {
        pRet = ITEM_LEVEL_LIST::EXCELLENT_ITEM;
    }
    else if(Random >= 95 && Random < 98)
    {
        pRet = ITEM_LEVEL_LIST::EPIC_ITEM;
    }
    else if(Random >= 98 && Random < 99)
    {
        pRet = ITEM_LEVEL_LIST::SUIT_ITEM;
    }
    else if(Random >= 99 && Random < 100)
    {
        pRet = ITEM_LEVEL_LIST::LEGEND_ITEM;
    }
    return pRet;
}

ITEM_LEVEL_LIST ItemSystem::GetLevelRandom2()
{
    ITEM_LEVEL_LIST pRet;
    int Random = rand()%100;
    if(Random < 80)
    {
        pRet = ITEM_LEVEL_LIST::EXCELLENT_ITEM;
    }
    else if(Random >= 80 && Random < 98)
    {
        pRet = ITEM_LEVEL_LIST::EPIC_ITEM;
    }
    else if(Random >= 98 && Random < 99)
    {
        pRet = ITEM_LEVEL_LIST::SUIT_ITEM;
    }
    else if(Random >= 99 && Random < 100)
    {
        pRet = ITEM_LEVEL_LIST::LEGEND_ITEM;
    }
    return pRet;
}

ITEM_LEVEL_LIST ItemSystem::GetLevelRandom3()
{
    ITEM_LEVEL_LIST pRet;
    int Random = rand()%100;
    if(Random < 80)
    {
        pRet = ITEM_LEVEL_LIST::EPIC_ITEM;
    }
    else if(Random >= 80 && Random < 95)
    {
        pRet = ITEM_LEVEL_LIST::SUIT_ITEM;
    }
    else if(Random >= 95 && Random < 100)
    {
        pRet = ITEM_LEVEL_LIST::LEGEND_ITEM;
    }
    return pRet;
}

ITEM_DATA* ItemSystem::CreateFireItem()
{
    ITEM_DATA* pRet = new ITEM_DATA;
    ATTR_TYPE list[4] = { ATTR_TYPE::ATTR_HEALTH , ATTR_MAGIC , ATTR_ATK , ATTR_REMP };
    int Random = rand()%4;
    int Random2 = rand()%4;
    while (Random2 == Random) {
        Random2 = rand()%4;
    }
    pRet->attr1._type = list[Random];
    pRet->attr2._type = list[Random2];
    
    return pRet;
}

ITEM_DATA* ItemSystem::CreateWaterItem()
{
    ITEM_DATA* pRet = new ITEM_DATA;
    ATTR_TYPE list[4] = { ATTR_TYPE::ATTR_HEALTH , ATTR_MAGIC , ATTR_REHP , ATTR_DEF };
    int Random = rand()%4;
    int Random2 = rand()%4;
    while (Random2 == Random) {
        Random2 = rand()%4;
    }
    pRet->attr1._type = list[Random];
    pRet->attr2._type = list[Random2];
    
    return pRet;
}

ITEM_DATA* ItemSystem::CreateWindItem()
{
    ITEM_DATA* pRet = new ITEM_DATA;
    ATTR_TYPE list[4] = { ATTR_TYPE::ATTR_HEALTH , ATTR_MAGIC , ATTR_SHIELD , ATTR_DEF };
    int Random = rand()%4;
    int Random2 = rand()%4;
    while (Random2 == Random) {
        Random2 = rand()%4;
    }
    pRet->attr1._type = list[Random];
    pRet->attr2._type = list[Random2];
    
    return pRet;
}

ITEM_DATA* ItemSystem::CreateThunderItem()
{
    ITEM_DATA* pRet = new ITEM_DATA;
    ATTR_TYPE list[4] = { ATTR_TYPE::ATTR_HEALTH , ATTR_MAGIC , ATTR_BUFFTIME , ATTR_ATK };
    int Random = rand()%4;
    int Random2 = rand()%4;
    while (Random2 == Random) {
        Random2 = rand()%4;
    }
    pRet->attr1._type = list[Random];
    pRet->attr2._type = list[Random2];
    
    return pRet;
}

ITEM_DATA* ItemSystem::CreateMagicItem()
{
    ITEM_DATA* pRet = new ITEM_DATA;
    ATTR_TYPE list[4] = { ATTR_TYPE::ATTR_HEALTH , ATTR_MAGIC , ATTR_REMP , ATTR_BUFFTIME };
    int Random = rand()%4;
    int Random2 = rand()%4;
    while (Random2 == Random) {
        Random2 = rand()%4;
    }
    pRet->attr1._type = list[Random];
    pRet->attr2._type = list[Random2];
    
    return pRet;
}

ITEM_DATA* ItemSystem::CreateItem(GET_ITEM_METHOD _method)
{
    ITEM_DATA* pRet = new ITEM_DATA;
    //
    //获取部位和属性类型
    //
    ITEM_DATA* Temp = new ITEM_DATA;
    ITEM_ELEMENT RandomEle = (ITEM_ELEMENT)(rand()%5);
    if(RandomEle == ITEM_ELEMENT::ITEM_FIRE)
    {
        Temp = CreateFireItem();
        pRet->_Ele = ITEM_FIRE;
    }
    else if(RandomEle == ITEM_ELEMENT::ITEM_WATER)
    {
        Temp = CreateWaterItem();
        pRet->_Ele = ITEM_WATER;
    }
    else if(RandomEle == ITEM_ELEMENT::ITEM_WIND)
    {
        Temp = CreateWindItem();
        pRet->_Ele = ITEM_WIND;
    }
    else if(RandomEle == ITEM_ELEMENT::ITEM_THUNDER)
    {
        Temp = CreateThunderItem();
        pRet->_Ele = ITEM_THUNDER;
    }
    else if(RandomEle == ITEM_ELEMENT::ITEM_MAGIC)
    {
        Temp =CreateMagicItem();
        pRet->_Ele = ITEM_MAGIC;
    }
    
    pRet->attr1._type = Temp->attr1._type;
    pRet->attr2._type = Temp->attr2._type;
    delete Temp;
    //
    //
    //
    
    //
    // 获取稀有度
    //
    switch (_method) {
        case NORMAL:
            pRet->_itemlevel = GetLevelRandom1();
            break;
        case GET_EXCELLENT_ITEM_AL_LEAST:
            pRet->_itemlevel = GetLevelRandom2();
            break;
        case GET_EPIC_ITEM_ITEM_AL_LEAST:
            pRet->_itemlevel = GetLevelRandom3();
            break;
        default:
            break;
    }
    int keyNum = pRet->_itemlevel;
    pRet->itemNo = keyNum;
    std::string _Key = cocos2d::StringUtils::format("Item#%d",keyNum);
    ITEM_BASE_DATA* Temp2 = JsonParser::getInstance()->GetItenBaseData(_Key);
    pRet->name = Temp2->name;
    pRet->info = Temp2->info;
    pRet->_suit = static_cast<SUIT_LIST>(Temp2->suit);
    pRet->attr1._value = rand()%(Temp2->max - Temp2->min) + Temp2->min;
    pRet->attr2._value = rand()%(Temp2->max - Temp2->min) + Temp2->min;
    //
    int code = Parser::XML::getInstance()->GetItemCode();
    pRet->ItemCode = code;
    
    return pRet;
}

int ItemSystem::GetItemCoin(ITEM_DATA * _data)
{
    int itemLevel = pow(4.0f, _data->_itemlevel);
    int CoinPart1 = _data->attr1._value * itemLevel;
    int CoinPart2 = _data->attr2._value * itemLevel;
    
    return CoinPart1 + CoinPart2;
}
