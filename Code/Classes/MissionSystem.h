//
//  MissionSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/22.
//
//

#ifndef MissionSystem_h
#define MissionSystem_h


#include "BaseMissionBar.h"


struct MissionData
{
    MISSION_TYPE _MissionType;
    int _MissionValue;
    int _MissionCompletedValue;
};


class MissionSystem
{
private:
    MissionSystem();
    ~MissionSystem();
public:
    static MissionSystem* getInstance();
    void Read();
    MissionData GetMissionData(int _no) const {return _MissionArray[_no];}
    void Update(MISSION_TYPE _type,int _addValue = 1);
    void isCompletedMission();
    bool GetNewMission();
private:
    static MissionSystem* _instance;
    MissionData _MissionArray[3];
};


#endif /* MissionSystem_h */
