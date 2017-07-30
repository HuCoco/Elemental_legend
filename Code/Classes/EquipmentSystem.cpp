//
//  EquipmentSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#include "EquipmentSystem.h"
#include "BackpackSystem.h"
#include "ItemSystem.h"
#include "XMLParser.h"

EquipmentSystem* EquipmentSystem::_instance = nullptr;

EquipmentSystem::EquipmentSystem()
{
    
}

EquipmentSystem::~EquipmentSystem()
{
    
}

ITEM_DATA* EquipmentSystem::GetEquipmentDataByPos(int Pos)
{
    return &EquipmentManager[Pos];
}

void EquipmentSystem::EquipmentInit()
{
    for(int i = 0 ; i < 5 ; i++)
    {
        std::string EquStr = Parser::XML::getInstance()->GetEquipmentData(i);
        if(EquStr == "")
        {
            continue;
        }
        ITEM_DATA* pRet  = ItemSystem::getInstance()->ParseItemDataByItemString(EquStr);
        EquipmentManager[i].Clone(pRet);
        delete pRet;
    }
}

void EquipmentSystem::GetUpEquipment(ITEM_DATA * _data)
{
    int pos = (int)_data->_Ele;
    Parser::XML::getInstance()->SetEquipmentData(ItemSystem::getInstance()->GetItemStringByItemData(_data),pos);
    EquipmentManager[pos].Clone(_data);
}

void EquipmentSystem::PutDownEquipment(ITEM_DATA * _data)
{
    int pos = (int)_data->_Ele;
    Parser::XML::getInstance()->SetEquipmentData("",pos);
    EquipmentManager[pos].Clean();
}

EquipmentSystem* EquipmentSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new EquipmentSystem;
    }
    return _instance;
}

TOTAL_ATTR_DATA* EquipmentSystem::getTotalAttr()
{
    TOTAL_ATTR_DATA* pRet = new TOTAL_ATTR_DATA;
    for(int i = 0 ; i < 9 ; i++)
    {
        ATTR_VALUE_DATA data;
        data._type = (ATTR_TYPE)i;
        pRet->data.push_back(data);
    }

    for(int i = 0 ; i < 5 ; i++)
    {
        if(EquipmentManager[i].itemNo < 0)
        {
            continue;
        }
        pRet->data.at(EquipmentManager[i].attr1._type)._value += EquipmentManager[i].attr1._value;
        pRet->data.at(EquipmentManager[i].attr2._type)._value += EquipmentManager[i].attr2._value;
    }

    return pRet;
}


std::vector<ITEM_EFFECTS_DATA>* EquipmentSystem::GetItemEffectsData()
{
    std::vector<ITEM_EFFECTS_DATA>* Temp = new std::vector<ITEM_EFFECTS_DATA>;
    for(int i = 0 ; i < 5 ; i++)
    {
        if(EquipmentManager[i]._suit == NO_SUIT)
        {
            continue;
        }
        int size = (int)Temp->size();
        bool isHave = false;
        int pos = -1;
        for(int j = 0 ; j < size;j++)
        {
            if(Temp->at(j)._suit == EquipmentManager[i]._suit)
            {
                isHave = true;
                pos = j;
            }
        }
        if(isHave)
        {
            Temp->at(pos).number++;
        }
        else
        {
            ITEM_EFFECTS_DATA data;
            data._suit = EquipmentManager[i]._suit;
            data.number = 1;
            Temp->push_back(data);
        }
        
    }
    return Temp;
}