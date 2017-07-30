//
//  SkillFactory.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/4.
//
//

#include "SkillFactory.h"
#include "Fire_1.h"
#include "Fire_2.h"
#include "Fire_3.h"
#include "Fire_4.h"
#include "Fire_5.h"
#include "Thunder_1.h"
#include "Thunder_2.h"
#include "Thunder_3.h"
#include "Thunder_4.h"
#include "Thunder_5.h"
#include "Wind_1.h"
#include "Wind_2.h"
#include "Wind_3.h"
#include "Wind_4.h"
#include "Wind_5.h"
#include "Water_1.h"
#include "Water_2.h"
#include "Water_3.h"
#include "Water_4.h"
#include "Water_5.h"
#include "Attack_1.h"
#include "Attack_2.h"
#include "Attack_3.h"
#include "Attack_4.h"
#include "Attack_5.h"
#include "Defence_1.h"
#include "Defence_2.h"
#include "Defence_3.h"
#include "Special_1.h"
#include "Special_2.h"
#include "Special_3.h"
#include "Special_4.h"
#include "Special_5.h"
#include "Special_6.h"
#include "Special_7.h"
#include "Special_8.h"
#include "Special_9.h"
#include "Magic.h"




SkillFactory* SkillFactory::_instance = new SkillFactory;

SkillFactory::SkillFactory()
{
    
}


SkillFactory::~SkillFactory()
{
    
}

SkillFactory* SkillFactory::getInstance()
{
    return _instance;
}

BaseSkill* SkillFactory::create(SKILL_PLAYER_TYPE _type, int _num)
{
    BaseSkill* pRet;
    switch (_type) {
        case ST_FIRE:
        {
            switch (_num) {
                case 1:
                    pRet = new Fire_1;
                    break;
                case 2:
                    pRet = new Fire_2;
                    break;
                case 3:
                    pRet = new Fire_3;
                    break;
                case 4:
                    pRet = new Fire_4;
                    break;
                case 5:
                    pRet = new Fire_5;
                default:
                    break;
            }
        }
            break;
        case ST_THUNDER:
        {
            switch (_num) {
                case 1:
                    pRet = new Thunder_1;
                    break;
                case 2:
                    pRet = new Thunder_2;
                    break;
                case 3:
                    pRet = new Thunder_3;
                    break;
                case 4:
                    pRet = new Thunder_4;
                    break;
                case 5:
                    pRet = new Thunder_5;
                    break;
                default:
                    break;
            }
        }
            break;
        case ST_WATER:
        {
            switch (_num) {
                case 1:
                    pRet = new Water_1;
                    break;
                case 2:
                    pRet = new Water_2;
                    break;
                case 3:
                    pRet = new Water_3;
                    break;
                case 4:
                    pRet = new Water_4;
                    break;
                case 5:
                    pRet = new Water_5;
                    break;
                default:
                    break;
            }
        }
            break;
        case ST_WIND:
        {
            switch (_num) {
                case 1:
                    pRet = new Wind_1;
                    break;
                case 2:
                    pRet = new Wind_2;
                    break;
                case 3:
                    pRet = new Wind_3;
                    break;
                case 4:
                    pRet = new Wind_4;
                    break;
                case 5:
                    pRet = new Wind_5;
                    break;
                default:
                    break;
            }
        }
            break;
        case ST_MAGIC:
        {
            pRet = new Magic;
        }
        default:
            break;
    }
    return pRet;
}

BaseSkill* SkillFactory::create(SKILL_MONSTER_TYPE _type, int _num)
{
    BaseSkill* pRet;
    switch (_type) {
        case ST_ATTACK:
        {
            switch (_num) {
                case 1:
                    pRet = new Attack_1;
                    break;
                case 2:
                    pRet = new Attack_2;
                    break;
                case 3:
                    pRet = new Attack_3;
                    break;
                case 4:
                    pRet = new Attack_4;
                    break;
                case 5:
                    pRet = new Attack_5;
                    break;
                default:
                    break;
            }
        }
            break;
        case ST_DEFENCE:
        {
            switch (_num) {
                case 1:
                    pRet = new Defence_1;
                    break;
                case 2:
                    pRet = new Defence_2;
                    break;
                case 3:
                    pRet = new Defence_3;
                    break;

                default:
                    break;
            }
        }
            break;
        case ST_SPECIAL:
        {
            switch (_num) {
                case 1:
                    pRet = new Special_1;
                    break;
                case 2:
                    pRet = new Special_2;
                    break;
                case 3:
                    pRet = new Special_3;
                    break;
                case 4:
                    pRet = new Special_4;
                    break;
                case 5:
                    pRet = new Special_5;
                    break;
                case 6:
                    pRet = new Special_6;
                    break;
                case 7:
                    pRet = new Special_7;
                    break;
                case 8:
                    pRet = new Special_8;
                    break;
                case 9:
                    pRet = new Special_9;
                    break;
                default:
                    break;
            }
        }        default:
            break;
    }

    return pRet;
}


