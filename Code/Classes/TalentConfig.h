//
//  TalentConfig.h
//  NewGame
//
//  Created by 胡可 on 15/10/11.
//
//

#ifndef TalentConfig_h
#define TalentConfig_h


#include "cocos2d.h"
#include "JsonParser.h"
#include <cocos-ext.h>
enum TALENT_TYPE
{
    TT_FIRE,
    TT_WATER,
    TT_THUNDER,
    TT_WIND
};

struct TALENT_INFO
{
    cocos2d::Sprite* _talent;
    int Num;
};

class TalentConfig
:public cocos2d::Layer
{
protected:
    TalentConfig();
    ~TalentConfig();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    void close();
    void ReSetScale();
    int GetTalentDataByUsedData(int _used);
public:
    CREATE_FUNC(TalentConfig);
    void AddToTag(cocos2d::Layer* _tag);
protected:
    std::vector<PLAYER_SKILL_DATA>* SkillVector;
    cocos2d::ui::Scale9Sprite* _floor;
    cocos2d::Label* _name;
    cocos2d::Label* _introduction;
    cocos2d::Label* _cost;
    std::vector<cocos2d::Sprite*> _talentfloorpool;
    std::vector<TALENT_INFO> _talentpool;
    cocos2d::Menu* _menu;
    cocos2d::MenuItemImage* _okbtn;
    
protected:
    cocos2d::EventListenerTouchOneByOne* _touchListener;
};

#endif /* TalentConfig_h */
