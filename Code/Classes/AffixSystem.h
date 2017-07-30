//
//  AffixSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/22.
//
//

#ifndef AffixSystem_h
#define AffixSystem_h


#include "cocos2d.h"

enum AFFIX_TYPE
{
    AT_ATK,
    AT_DEF,
    AT_SPE
};


class AffixSystem
{
private:
    AffixSystem();
    ~AffixSystem();
public:
    static AffixSystem* getInstance();
    cocos2d::Label* getAffix(AFFIX_TYPE _type,int _skill);
private:
    static AffixSystem* _instance;
};


#endif /* AffixSystem_h */
