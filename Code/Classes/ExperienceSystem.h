//
//  ExperienceSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/21.
//
//

#ifndef ExperienceSystem_h
#define ExperienceSystem_h

class ExperienceSystem
{
private:
    ExperienceSystem();
    ~ExperienceSystem();
public:
    static ExperienceSystem* getInstance();
    void UpdateData();
    int getNowExp(){return NowExp;}
    int getMaxExp(){return MaxExp;}
    bool AddExp();
private:
    static ExperienceSystem* _instance;
    int NowExp;
    int MaxExp;
};




#include <stdio.h>





#endif /* ExperienceSystem_h */
