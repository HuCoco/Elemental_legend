//
//  ElementSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/9.
//
//

#ifndef ElementSystem_h
#define ElementSystem_h


#include "BaseElement.h"

class ElementSystem
{
private:
    ElementSystem();
    ~ElementSystem();
public:
    static ElementSystem* getInstance();
    void UpdateOdds(ELEMENT_TYPE _type);
    ELEMENT_TYPE getElementTypeByRandom();
private:
    void Init();
    static ElementSystem* _instance;
    void UpdateSet();
private:
    ELEMENT_TYPE NowState;
    //五种元素出现的概率，确保和为100
    int _oddsFire;
    int _oddsWater;
    int _oddsThunder;
    int _oddsWind;
    int _oddsMagic;
private:
    //概率集合
    int _Set1;
    int _Set2;
    int _Set3;
    int _Set4;
    int _Set5;
};




#endif /* ElementSystem_h */
