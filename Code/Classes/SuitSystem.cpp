//
//  SuitSystem.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#include "SuitSystem.h"

#include "Sand1.h"
#include "Sand2.h"






SuitSystem* SuitSystem::_instance = nullptr;
SuitSystem::SuitSystem()
{
    
}

SuitSystem::~SuitSystem()
{
    
}

SuitSystem* SuitSystem::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new SuitSystem;
    }
    return _instance;
}

SUIT_STR_INFO SuitSystem::getSuitInfo(SUIT_LIST _list)
{
    SUIT_STR_INFO pRet;
    switch (_list) {
        case SAND:
            pRet.info1 = "· 2件套装效果：当生命值低于50%，消耗的每一个元素都会为你恢复10%生命回复量的生命值";
            pRet.info2 = "· 4件套装效果：每消耗3个水元素，会强化下一个元素的效果";
            break;
            
        default:
            break;
    }
    
    return pRet;
}

void SuitSystem::createEffect(ITEM_EFFECTS_DATA _data)
{

    switch (_data._suit) {
        case SAND:
        {
            if(_data.number >= 2)
            {
                EffectsPool.push_back(new Sand1);
            }
            if(_data.number >= 4)
            {
                EffectsPool.push_back(new Sand2);
            }
            break;
        }
        default:
            break;
    }

}

void SuitSystem::ItemEffectInit(std::vector<ITEM_EFFECTS_DATA> * _list)
{
    int size = (int)_list->size();
    for(int i = 0 ; i < size ; i++)
    {
        createEffect(_list->at(i));
    }
}

void SuitSystem::CastEffects(int touchtime,ELEMENT_TYPE _type ,cocos2d::Node* _tag)
{
    int size = (int)EffectsPool.size();
    for(int i = 0 ; i < size ; i++)
    {
        EffectsPool.at(i)->Cast(touchtime, _type, _tag);
    }
}