//
//  EquipmentSystem.h
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#ifndef EquipmentSystem_h
#define EquipmentSystem_h
#include "ItemSystem.h"

struct TOTAL_ATTR_DATA
{
    std::vector<ATTR_VALUE_DATA> data;
};

struct ITEM_EFFECTS_DATA
{
    SUIT_LIST _suit;
    int number;
};


class EquipmentSystem
{
private:
    EquipmentSystem();
    ~EquipmentSystem();
public:
    static EquipmentSystem* getInstance();
    void GetUpEquipment(ITEM_DATA*);
    void PutDownEquipment(ITEM_DATA*);
    void EquipmentInit();
    TOTAL_ATTR_DATA* getTotalAttr();
    std::vector<ITEM_EFFECTS_DATA>* GetItemEffectsData();
    ITEM_DATA* GetEquipmentDataByPos(int Pos);
private:
    static EquipmentSystem* _instance;
    ITEM_DATA EquipmentManager[5];
};

#endif /* EquipmentSystem_h */
