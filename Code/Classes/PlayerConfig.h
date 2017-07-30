//
//  PlayerConfig.h
//  NewGame
//
//  Created by 胡可 on 15/10/10.
//
//

#ifndef PlayerConfig_h
#define PlayerConfig_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "TalentConfig.h"
#include "SuitBar.h"
#include "AttrBar.h"
#include <cocos-ext.h>
#include "ItemBar.h"
enum CONFIG_TOUCH_EVENT
{
    
    TOUCH_ATK,
    TOUCH_DEF,
    TOUCH_HEALTH,
    TOUCH_MAGIC,
    TOUCH_SHIELD,
    TOUCH_SPEED,
    TOUCH_REHEALTH,
    TOUCH_REMAGIC,
    TOUCH_BUFFTIME,
    TOUCH_FIRE,
    TOUCH_WATER,
    TOUCH_WIND,
    TOUCH_THUNDER,
    TOUCH_NONE
};




class PlayerConfig
:public cocos2d::Layer
{
private:
    PlayerConfig();
    ~PlayerConfig();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    cocos2d::ui::Scale9Sprite* getSelectItemSprite(const std::string& _title);
    cocos2d::ui::Scale9Sprite* getunSelectItemSprite(const std::string& _title);
    cocos2d::MenuItemToggle* getTilteMenuItem(const std::string& _title,int _tag);
    cocos2d::Node* Page1Init();
    cocos2d::Node* Page2Init();
    cocos2d::Node* Page3Init();
    cocos2d::Node* SelectPage(int _page);
    void ResetAttr();
    void AddItemLayer(int tag);
public:
    CREATE_FUNC(PlayerConfig);
    void AddToTag(cocos2d::Node* _tag);
    void ReSetTalentList();
    void UpdateAttrNum();
    void TitleTouchCallBack(int);
private:
    cocos2d::ui::Scale9Sprite* FloorSprite;
    std::vector<cocos2d::MenuItemToggle*> TitlePool;
    std::vector<cocos2d::Node*> NodePool;
    std::vector<ItemBar*>* BackpackPool;
    SuitBar* _suitbar;
    cocos2d::Menu* _menu;
    cocos2d::MenuItemImage* CloseBtn;
    cocos2d::Sprite* FireIcon;
    cocos2d::Sprite* FireSkillIcon;
    cocos2d::Sprite* WaterIcon;
    cocos2d::Sprite* WaterSkillIcon;
    cocos2d::Sprite* ThunderIcon;
    cocos2d::Sprite* ThunderSkillIcon;
    cocos2d::Sprite* WindIcon;
    cocos2d::Sprite* WindSkillIcon;
    std::vector<cocos2d::Label*> AttrNamePool;
    std::vector<AttrBar*>* AttrBarPool;
    cocos2d::Label* AttrNumLabel;
    CONFIG_TOUCH_EVENT _MyEvent;
    TALENT_TYPE _touchtype;
    int isMoved;
    int isOpenResetLayer;
    int NowPage;
private:
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    cocos2d::Point NowTouchPoint;
    cocos2d::Point LastTouchPoint;
};

#endif /* PlayerConfig_h */
