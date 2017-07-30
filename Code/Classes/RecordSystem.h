//
//  RecordSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/20.
//
//

#ifndef RecordSystem_h
#define RecordSystem_h


#include "BaseElement.h"
struct RecordData
{
    int CostFire;
    int CostWind;
    int CostThunder;
    int CostWater;
    int CostMagic;
    //初始化
    void init()
    {
        CostFire = 0;
        CostWater = 0;
        CostWind = 0;
        CostThunder = 0;
        CostMagic = 0;
    }
    
    void init(int _fire,int _wind,int _water,int _thunder,int _magic)
    {
        CostFire = _fire;
        CostWater = _wind;
        CostWind = _water;
        CostThunder = _thunder;
        CostMagic = _magic;
    }
    
    //数据汇总
    void AddToMainData(RecordData* _data)
    {
        CostFire += _data->CostFire;
        CostWind += _data->CostWind;
        CostWater += _data->CostWater;
        CostThunder += _data->CostThunder;
        CostMagic += _data->CostMagic;
        _data->init();
    }
    //数据变化
    void AddFire(){CostFire++;}
    void AddWater(){CostWater++;}
    void AddWind(){CostWind++;}
    void AddThunder(){CostThunder++;}
    void AddMagic(){CostMagic++;}
};


class RecordSystem
{
private:
    RecordSystem();
    ~RecordSystem();
    
public:
    static RecordSystem* getInstance();
    void AddData(ELEMENT_TYPE _type);
    void AddAllDataToMainData();
    void SaveMainData();
    void ReadMainData();
    int GetThisGameRecord(ELEMENT_TYPE _type);
    int GetMainRecord(ELEMENT_TYPE _type);
private:
    static RecordSystem* _instance;
    RecordData* MainRecordData;
    RecordData* ThisGameRcordData;
};

#endif /* RecordSystem_h */
