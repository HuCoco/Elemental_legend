//
//  AttrSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#ifndef AttrSystem_h
#define AttrSystem_h

#include <stdio.h>

enum ATTR_TYPE
{
    ATTR_ATK,
    ATTR_DEF,
    ATTR_HEALTH,
    ATTR_MAGIC,
    ATTR_SPEED,
    ATTR_REHP,
    ATTR_REMP,
    ATTR_SHIELD,
    ATTR_BUFFTIME
};





class AttrSystem
{
private:
    AttrSystem();
    ~AttrSystem();
public:
    static AttrSystem* getInstance();
    float GetRealAttr(ATTR_TYPE _type);
    float AddRealAttr(ATTR_TYPE _type);
    float GetBaseAttr(ATTR_TYPE _type);
    int GetAttrNum(ATTR_TYPE _type);
    void SetAttr(ATTR_TYPE _type,int _value);
    void Update();
    void Save();
public:
    inline void SetAKT(int _data){ _ATK = _data;}
    inline void SetDEF(int _data){ _DEF = _data;}
    inline void SetHEALTH(int _data){ _HEALTH = _data;}
    inline void SetMAGIC(int _data){ _MAGIC = _data;}
    inline void SetSPEED(int _data){ _SPEED = _data;}
    inline void SetREHP(int _data){ _REHP = _data;}
    inline void SetREMP(int _data){ _REMP = _data;}
    inline void SetSHIELD(int _data){ _SHIELD = _data;}
    inline void SetBUFFTIME(int _data){ _BUFFTIME = _data;}
    inline void SetATTRNUM(int _data){_ATTR_NUM = _data;}
    inline int GetAKT(){return _ATK;}
    inline int GetDEF(){return _DEF;}
    inline int GetHEALTH(){return _HEALTH;}
    inline int GetMAGIC(){return _MAGIC;}
    inline int GetSPEED(){return _SPEED;}
    inline int GetREHP(){return _REHP;}
    inline int GetREMP(){return _REMP;}
    inline int GetSHIELD(){return _SHIELD;}
    inline int GetBUFFTIME(){return _BUFFTIME;}
    inline int GetARRTNUM(){return _ATTR_NUM;}
private:
    static AttrSystem* _instance;
    int _ATK;
    int _DEF;
    int _HEALTH;
    int _MAGIC;
    int _SHIELD;
    int _SPEED;
    int _REHP;
    int _REMP;
    int _BUFFTIME;
    int _ATTR_NUM;
    int _LEVEL;
};





#endif /* AttrSystem_h */
