//
//  BackpackSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/16.
//
//

#include "BackpackSystem.h"
#include "XMLParser.h"
#include "ItemSystem.h"
BackpackSystem* BackpackSystem::_instance = nullptr;

BackpackSystem::BackpackSystem()
{
    
}

BackpackSystem::~BackpackSystem()
{
    
}

BackpackSystem* BackpackSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new BackpackSystem;
    }
    return _instance;
}


std::vector<ItemBar*>* BackpackSystem::BackpackInit()
{
    Backpack = new std::vector<ItemBar*>;
    for(int i = 0 ; i < 42 ; i++)
    {
        std::string itemstr = Parser::XML::getInstance()->GetBackpackData(i);
        if(itemstr == "")
        {
            ItemBar* item = ItemBar::create(new ITEM_DATA());
            item->retain();
            Backpack->push_back(item);
        }
        else
        {
            ItemBar* item = ItemBar::create(ItemSystem::getInstance()->ParseItemDataByItemString(itemstr));
            item->retain();
            Backpack->push_back(item);
        }
    }
    return Backpack;
}

ITEM_DATA* BackpackSystem::GetNewItem(GET_ITEM_METHOD _method)
{
    BackpackInit();
    int pos = -1;
    for(int i = 0 ; i < 42 ;i++)
    {
        if(Backpack->at(i)->getData()->itemNo == -1)
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
    {
        return nullptr;
    }
    ITEM_DATA* pRet = ItemSystem::getInstance()->CreateItem(_method);
    Parser::XML::getInstance()->SetBackpackData(ItemSystem::getInstance()->GetItemStringByItemData(pRet),pos);
    return pRet;
}

int BackpackSystem::CleanItem(ItemBar * _item)
{
    for(int i = 0 ; i < 42 ; i++)
    {
        if(Backpack->at(i)->getData()->itemNo == -1)
        {
            continue;
        }
        if(Backpack->at(i)->getData()->ItemCode == _item->getData()->ItemCode)
        {
            Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COIN, Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COIN) + ItemSystem::getInstance()->GetItemCoin(_item->getData()));
            _item->getParent()->removeChild(_item);
            Parser::XML::getInstance()->SetBackpackData("", i);
            Backpack->at(i)->getData()->Clean();
        }
    }
    return 0;
}



