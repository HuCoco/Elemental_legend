//
//  ResourceSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/6.
//
//

#include "ResourceSystem.h"
#include "BattleSystem.h"

ResourceSystem* ResourceSystem::_instance = nullptr;

ResourceSystem::ResourceSystem()
{
    
}

ResourceSystem::~ResourceSystem()
{
    
}

ResourceSystem* ResourceSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new ResourceSystem;
    }
    return _instance;
}

void ResourceSystem::Init(cocos2d::Layer *_tag)
{
    _hpbar = HpBar::create(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().width/30*29));
    _hpbar->AddToLayer(_tag);
    _mpbar = MpBar::create(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().width/30*28-8));
    _mpbar->AddToLayer(_tag);
    _svbar = SvBar::create(cocos2d::Vec2(20,0));
    _svbar->AddToLayer(_tag);
    _btbar = BtBar::create(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width - 20,0));
    _btbar->AddToLayer(_tag);
    _ehpbar = EnemyHpBar::create(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/10*9));
    _ehpbar->AddToLayer(_tag);
}

void ResourceSystem::UpdateResourceBar(ROLE_TYPE _role,RESOURCE_TYPE _type, RESOURCE_METHOD _method, int _data)
{
    if(_role == ROLE_TYPE::PLAYER)
    {
    switch (_type) {
        case HEALTH:
        {
            switch (_method) {
                case ADD:
                    _hpbar->Add(_data);
                    break;
                case REDUCE:
                {
                    int over = _svbar->Reduce(_data);
                    _hpbar->Reduce(over);
                }
                default:
                    break;
            }
        }
            break;
        case MAGIC:
        {
            switch (_method) {
                case ADD:
                    _mpbar->Add(_data);
                    break;
                case REDUCE:
                    _mpbar->Reduce(_data);
                default:
                    break;
            }
        }
            break;
        case SHEILD:
        {
            switch (_method) {
                case ADD:
                    _svbar->Add(_data);
                    break;
                case REDUCE:
                    _svbar->Reduce(_data);
                default:
                    break;
            }
        }
            break;
        case BUFFTIME:
        {
            switch (_method) {
                case ADD:
                    _btbar->Add(_data);
                    break;
                case REDUCE:
                    _btbar->Reduce(_data);
                default:
                    break;
            }
        }
            break;
        default:
            break;
    }
    }
    else if (_role == ROLE_TYPE::MONSTER)
    {
        switch (_type) {
            case HEALTH:
                switch (_method) {
                    case ADD:
                        _ehpbar->Add(_data);
                        break;
                    case REDUCE:
                        _ehpbar->Reduce(_data);
                    default:
                        break;
                }
                break;
            
            default:
                break;
        }
    }
}
