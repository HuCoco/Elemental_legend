//
//  ResourceSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/6.
//
//

#ifndef ResourceSystem_h
#define ResourceSystem_h


#include "HpBar.h"
#include "MpBar.h"
#include "SvBar.h"
#include "BtBar.h"
#include "EnemyHpBar.h"
enum RESOURCE_METHOD
{
    ADD,
    REDUCE
};

enum ROLE_TYPE
{
    MONSTER,
    PLAYER
};



class ResourceSystem
{
private:
    ResourceSystem();
    ~ResourceSystem();
public:
    static ResourceSystem* getInstance();
    void Init(cocos2d::Layer* _tag);
    void UpdateResourceBar(ROLE_TYPE _role,RESOURCE_TYPE _type,RESOURCE_METHOD _method,int _data);
private:
    static ResourceSystem* _instance;
    HpBar* _hpbar;
    MpBar* _mpbar;
    SvBar* _svbar;
    BtBar* _btbar;
    EnemyHpBar* _ehpbar;
private:
};

#endif /* ResourceSystem_h */
