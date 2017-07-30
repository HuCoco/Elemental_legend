//
//  XMLParser.h
//  NewGame
//
//  Created by 胡可 on 15/9/30.
//
//

#ifndef XMLParser_h
#define XMLParser_h


#include "cocos2d.h"
#include "BaseMissionBar.h"
#define BACKPACK_POS "Backpack#%d"
#define EQUIPMENT_POS "Equipment#%d"
namespace Parser {
    
    enum USER_DATA_TYPE
    {
        LEVEL,
        EXP,
        HEALTH,
        MAGIC,
        SHEILD,
        ATK,
        DEF,
        REHP,
        REMP,
        BUFFTIME,
        SPEED,
        COIN,
        DIAMONDS,
        TALENT_FIRE,
        TALENT_WATER,
        TALENT_WIND,
        TALENT_THUNDER,
        COST_FIRE,
        COST_WIND,
        COST_WATER,
        COST_THUNDER,
        COST_MAGIC,
        COMPLETE_GATE,
        COMPLETE_CHAPTER,
        CHAPTER_NOW,
        GUIDE_COMPLETED,
        FRISTGAME
    };
    
    enum MISSION_DATA_TYPE
    {
        MISSION_ONE,
        MISSION_TWO,
        MISSION_THREE,
    };
    
    enum SYSTEM_OPTION_SETTING_TYPE
    {
        BGM_VOLUME,
        EM_VOLUME,
        BM_SWITCH,
        EM_SWITCH
    };
    
    enum TALENT_GET_LIST
    {
        T_FIRE,
        T_WATER,
        T_THUNDER,
        T_WIND
    };
    
    
    class XML
    {
    private:
        XML();
        ~XML();
        void BackPackInit();
    public:
        static XML* getInstance();
        bool isCreated();
        void Create();
        void UpdateData(USER_DATA_TYPE,int);
        int GetData(USER_DATA_TYPE);
        int GetMission(MISSION_DATA_TYPE);
        void SetMission(MISSION_DATA_TYPE,MISSION_TYPE);
        int GetMissionValue(MISSION_DATA_TYPE);
        void SetMissionValue(MISSION_DATA_TYPE,int);
        void SetSystemData(SYSTEM_OPTION_SETTING_TYPE,float);
        float GetSystemData(SYSTEM_OPTION_SETTING_TYPE);
        int GetTalentGetListData(TALENT_GET_LIST);
        void SetTalentGetListData(TALENT_GET_LIST,int);
        void SetBackpackData(const std::string _itemstr,int pos);
        std::string GetBackpackData(int pos);
        void SetEquipmentData(const std::string _itemstr,int pos);
        std::string GetEquipmentData(int pos);
        void EquipmentInit();
        int GetItemCode();
        int GetTrailTop();
        void SetTrailTop(int);
    private:
        static XML* _instance;
    };
}

#endif /* XMLParser_h */
