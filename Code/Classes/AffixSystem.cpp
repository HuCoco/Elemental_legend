//
//  AffixSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/22.
//
//

#include "AffixSystem.h"
#define FONT_SIZE 40
AffixSystem* AffixSystem::_instance = nullptr;

AffixSystem::AffixSystem()
{
    
}

AffixSystem::~AffixSystem()
{
    
}

AffixSystem* AffixSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new AffixSystem;
    }
    return _instance;
}

cocos2d::Label* AffixSystem::getAffix(AFFIX_TYPE _type, int _skill)
{
    cocos2d::Label* pRet = nullptr;
    if(_type == AFFIX_TYPE::AT_ATK)
    {
        switch (_skill) {
            case 1:
                break;
            case 2:
                pRet = cocos2d::Label::createWithTTF("吸魔", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(255,0,255));
                break;
            case 3:
                pRet = cocos2d::Label::createWithTTF("吸血", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(255,0,0));
                break;
            case 4:
                pRet = cocos2d::Label::createWithTTF("盛宴", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(255,60,0));
                break;
            case 5:
                pRet = cocos2d::Label::createWithTTF("暴击", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(255,255,0));
            default:
                break;
        }
    }
    else if(_type == AFFIX_TYPE::AT_DEF)
    {
        switch (_skill) {
            case 1:
                pRet = cocos2d::Label::createWithTTF("免伤", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(0,0,0));
                break;
            case 2:
                pRet = cocos2d::Label::createWithTTF("复苏", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(0,255,0));
                break;
            case 3:
                pRet = cocos2d::Label::createWithTTF("无敌", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(255,255,0));
                break;
            default:
                break;
        }
    }
    else if(_type == AFFIX_TYPE::AT_SPE)
    {
        switch (_skill) {
            case 1:
                pRet = cocos2d::Label::createWithTTF("反伤", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(200,200,0));
                break;
            case 2:
                pRet = cocos2d::Label::createWithTTF("轮墓", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(100,255,100));
                break;
            case 3:
                pRet = cocos2d::Label::createWithTTF("回复", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(0,255,66));
                break;
            case 4:
                pRet = cocos2d::Label::createWithTTF("噬魔", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(255,0,186));
                break;
            case 5:
                pRet = cocos2d::Label::createWithTTF("狂怒", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(255,132,0));
                break;
            case 6:
                pRet = cocos2d::Label::createWithTTF("减速", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(150,255,250));
                break;
            case 7:
                pRet = cocos2d::Label::createWithTTF("冰冻", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(0,255,240));
                break;
            case 8:
                pRet = cocos2d::Label::createWithTTF("坚韧", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(170,125,12));
                break;
            case 9:
                pRet = cocos2d::Label::createWithTTF("搏命", "fonts/black.ttf", FONT_SIZE);
                pRet->setColor(cocos2d::Color3B(170,0,0));
                break;
            default:
                break;
        }
    }
    return pRet;
}