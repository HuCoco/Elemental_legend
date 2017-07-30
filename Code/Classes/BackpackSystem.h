//
//  BackpackSystem.h
//  NewGame
//
//  Created by 胡可 on 15/11/16.
//
//

#ifndef BackpackSystem_h
#define BackpackSystem_h

#include "AttrSystem.h"
#include "ItemSystem.h"
#include "cocos2d.h"
#include "ItemBar.h"



class BackpackSystem
{
private:
    BackpackSystem();
    ~BackpackSystem();

    int GetEmptyPos();
public:
    static BackpackSystem* getInstance();
    int CleanItem(ItemBar*);

    std::vector<ItemBar*>* BackpackInit();
    ITEM_DATA* GetNewItem(GET_ITEM_METHOD);
private:
    static BackpackSystem* _instance;
    std::vector<ItemBar*>* Backpack;
};

#endif /* BackpackSystem_h */
