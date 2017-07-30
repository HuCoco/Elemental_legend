//
//  SuitSystem.h
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#ifndef SuitSystem_h
#define SuitSystem_h

#include "ItemSystem.h"
#include "BaseItemEffects.h"
#include "EquipmentSystem.h"
struct SUIT_STR_INFO
{
    std::string suit = "套装效果";
    std::string info1;
    std::string info2;
};

class SuitSystem
{
private:
    SuitSystem();
    ~SuitSystem();
public:
    static SuitSystem* getInstance();
    SUIT_STR_INFO getSuitInfo(SUIT_LIST);
    void ItemEffectInit(std::vector<ITEM_EFFECTS_DATA>*);
    void createEffect(ITEM_EFFECTS_DATA);
    void CastEffects(int,ELEMENT_TYPE,cocos2d::Node*);
private:
    static SuitSystem* _instance;
    std::vector<BaseItemEffects*> EffectsPool;
};

#endif /* SuitSystem_h */
