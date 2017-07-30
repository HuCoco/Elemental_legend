//
//  ItemInfoLayer.c
//  NewGame
//
//  Created by 胡可 on 15/11/17.
//
//

#include "ItemInfoLayer.h"
#include "UISystem.h"
#include "SuitBar.h"
#include "SuitSystem.h"
#include "ItemSystem.h"
#include "EquipmentSystem.h"
#include "ItemBar.h"
#include "BackpackSystem.h"
ItemInfoLayer::ItemInfoLayer()
{
    
}

ItemInfoLayer::~ItemInfoLayer()
{
    
}

ItemInfoLayer* ItemInfoLayer::create(ITEM_DATA* _data,bool _bool,ITEM_SHOW_METHOD _method)
{
    ItemInfoLayer* pRet = new ItemInfoLayer;
    if(pRet && pRet->init(_data,_bool,_method))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

void ItemInfoLayer::NormalShow()
{
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite,-2);
    
    std::string floorpath = cocos2d::StringUtils::format("UI/backpack_level%d.png",data->_itemlevel);
    cocos2d::ui::Scale9Sprite* floor = cocos2d::ui::Scale9Sprite::create(floorpath);
    floor->setAnchorPoint(cocos2d::Vec2(0.5,1.0f));
    floor->setContentSize(cocos2d::Size(visibleSize/3*2));
    floor->setPosition(visibleSize.width/2,visibleSize.height/6*5);
    this->addChild(floor);
    
    float varlen = 15;
    float Left = visibleSize.width/6 + varlen;
    float Top = visibleSize.height/6*5 - varlen;
    
    //ICON
    std::string iconpath = cocos2d::StringUtils::format("Item/Item#%d.png",data->itemNo);
    cocos2d::Sprite* icon = cocos2d::Sprite::create(iconpath);
    icon->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    icon->setScale(1.5f);
    icon->setPosition(Left,Top - icon->getContentSize().height*1.5/2);
    this->addChild(icon);
    
    //NAME
    cocos2d::Label* ItemName = cocos2d::Label::createWithTTF(data->name, "fonts/black.ttf", 60);
    ItemName->setColor(getColorByLevel(data->_itemlevel));
    ItemName->setAlignment(cocos2d::TextHAlignment::LEFT);
    ItemName->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    ItemName->setPosition(Left + icon->getContentSize().width*1.5 + varlen ,Top - ItemName->getContentSize().height/2);
    this->addChild(ItemName);
    
    //ELE
    cocos2d::Label* ItemEle = getItemEle(data->_Ele,35);
    ItemEle->setAlignment(cocos2d::TextHAlignment::LEFT);
    ItemEle->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    ItemEle->setPosition(Left + icon->getContentSize().width*1.5 + varlen, ItemName->getPositionY() - ItemEle->getContentSize().height - varlen);
    this->addChild(ItemEle);

    cocos2d::Label* AttrTitle = cocos2d::Label::createWithTTF("基础属性", "fonts/black.ttf", 40 );
    AttrTitle->setAlignment(cocos2d::TextHAlignment::LEFT);
    AttrTitle->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    AttrTitle->setPosition(Left,icon->getPositionY() - icon->getContentSize().height*1.5/2 - AttrTitle->getContentSize().height/2 -varlen);
    this->addChild(AttrTitle);
    
    std::string attr1str = cocos2d::StringUtils::format("+ %d%% %s",data->attr1._value,getAttrStr(data->attr1._type).c_str());
    cocos2d::Label* attr1Label = cocos2d::Label::createWithTTF(attr1str, "fonts/black.ttf", 35);
    attr1Label->setAlignment(cocos2d::TextHAlignment::LEFT);
    attr1Label->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    attr1Label->setPosition(Left,AttrTitle->getPositionY() - AttrTitle->getContentSize().height/2 - attr1Label->getContentSize().height/2 - varlen);
    this->addChild(attr1Label);
    
    std::string attr2str = cocos2d::StringUtils::format("+ %d%% %s",data->attr2._value,getAttrStr(data->attr2._type).c_str());
    cocos2d::Label* attr2Label = cocos2d::Label::createWithTTF(attr2str, "fonts/black.ttf", 35);
    attr2Label->setAlignment(cocos2d::TextHAlignment::LEFT);
    attr2Label->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    attr2Label->setPosition(Left,attr1Label->getPositionY() - attr1Label->getContentSize().height/2 - attr2Label->getContentSize().height/2);
    this->addChild(attr2Label);
    
    std::string infostr = cocos2d::StringUtils::format("  “%s”",data->info.c_str());
    cocos2d::Label* info = cocos2d::Label::createWithTTF(infostr, "fonts/black.ttf", 35);
    info->setAlignment(cocos2d::TextHAlignment::LEFT);
    info->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    info->setColor(cocos2d::Color3B(227,215,98));
    info->setWidth(visibleSize.width/3*2-varlen*3);
    info->setPosition(Left,attr2Label->getPositionY() - attr2Label->getContentSize().height/2 - info->getContentSize().height/2 - varlen);
    this->addChild(info);
    
    std::string coinstr = cocos2d::StringUtils::format("售价:%d",ItemSystem::getInstance()->GetItemCoin(data));
    cocos2d::Label* CoinLabel = cocos2d::Label::createWithTTF(coinstr, "fonts/black.ttf", 30);
    CoinLabel->setAlignment(cocos2d::TextHAlignment::LEFT);
    CoinLabel->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    CoinLabel->setPosition(Left,info->getPositionY() - info->getContentSize().height/2 - CoinLabel->getContentSize().height/2 - varlen);
    this->addChild(CoinLabel);
    //cocos2d::Label
    
    cocos2d::Sprite* Coin1 = cocos2d::Sprite::create("UI/topstatebar_coin.png");
    Coin1->setPosition(CoinLabel->getPositionX() + CoinLabel->getContentSize().width + Coin1->getContentSize().width/3, CoinLabel->getPositionY());
    Coin1->setScale(0.6f);
    this->addChild(Coin1);
    
    floor->setContentSize(cocos2d::Size(visibleSize.width/3*2,(ItemName->getPositionY() + ItemName->getContentSize().height/2 + varlen) - (CoinLabel->getPositionY() - CoinLabel->getContentSize().height/2 - varlen)));
    
    
    if(data->_suit != SUIT_LIST::NO_SUIT)
    {
        std::vector<ITEM_EFFECTS_DATA>* _data = EquipmentSystem::getInstance()->GetItemEffectsData();
        int size = (int)_data->size();
        int number = 0;
        for(int i = 0 ; i < size ; i++)
        {
            if(_data->at(i)._suit == data->_suit)
            {
                number = _data->at(i).number;
                break;
            }
        }
        
        SUIT_STR_INFO suitstrinfo = SuitSystem::getInstance()->getSuitInfo(data->_suit);
        cocos2d::Label* suitlabel = cocos2d::Label::createWithTTF(suitstrinfo.suit, "fonts/black.ttf", 40);
        suitlabel->setAlignment(cocos2d::TextHAlignment::LEFT);
        suitlabel->setAnchorPoint(cocos2d::Vec2(0,0.5f));
        suitlabel->setColor(cocos2d::Color3B(81,230,43));
        suitlabel->setPosition(Left,info->getPositionY() - info->getContentSize().height/2 - suitlabel->getContentSize().height/2 - varlen);
        this->addChild(suitlabel);
        
        cocos2d::Label* suitinfo1 = cocos2d::Label::createWithTTF(suitstrinfo.info1, "fonts/black.ttf", 35);
        suitinfo1->setAlignment(cocos2d::TextHAlignment::LEFT);
        suitinfo1->setAnchorPoint(cocos2d::Vec2(0,0.5f));
        suitinfo1->setColor(cocos2d::Color3B(200,200,200));
        suitinfo1->setWidth(visibleSize.width/3*2-varlen*3);
        suitinfo1->setPosition(Left,suitlabel->getPositionY() - suitlabel->getContentSize().height/2 - suitinfo1->getContentSize().height/2);
        this->addChild(suitinfo1);
        
        cocos2d::Label* suitinfo2 = cocos2d::Label::createWithTTF(suitstrinfo.info2, "fonts/black.ttf", 35);
        suitinfo2->setAlignment(cocos2d::TextHAlignment::LEFT);
        suitinfo2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
        suitinfo2->setColor(cocos2d::Color3B(200,200,200));
        suitinfo2->setWidth(visibleSize.width/3*2-varlen*3);
        suitinfo2->setPosition(Left,suitinfo1->getPositionY() - suitinfo1->getContentSize().height/2- suitinfo2->getContentSize().height/2 - varlen/2);
        this->addChild(suitinfo2);
        
        if(number >= 2)
        {
            suitinfo1->setColor(cocos2d::Color3B(81,230,43));
        }
        if(number >= 4)
        {
            suitinfo2->setColor(cocos2d::Color3B(81,230,43));
        }
        CoinLabel->setPosition(Left,suitinfo2->getPositionY() - suitinfo2->getContentSize().height/2 - CoinLabel->getContentSize().height/2 - varlen);
        Coin1->setPosition(CoinLabel->getPositionX() + CoinLabel->getContentSize().width + Coin1->getContentSize().width/3, CoinLabel->getPositionY());
        
        floor->setContentSize(cocos2d::Size(visibleSize.width/3*2,(ItemName->getPositionY() + ItemName->getContentSize().height/2 + varlen) - (CoinLabel->getPositionY() - CoinLabel->getContentSize().height/2 - varlen)));
        
        
        
    }


}

void ItemInfoLayer::CompareShow(ITEM_DATA* pdata)
{
    //
    // 物品信息
    //
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite,-2);
    
    
    cocos2d::Label* title1 = cocos2d::Label::createWithTTF("当前物品", "fonts/black.ttf", 50);
    title1->setPosition(visibleSize.width/4*3,visibleSize.height/6*5 + title1->getContentSize().height/2 + 15);
    this->addChild(title1);
    
    cocos2d::Label* title2 = cocos2d::Label::createWithTTF("当前装备", "fonts/black.ttf", 50);
    title2->setPosition(visibleSize.width/4,visibleSize.height/6*5 + title2->getContentSize().height/2 + 15);
    this->addChild(title2);
    
    std::string floorpath = cocos2d::StringUtils::format("UI/backpack_level%d.png",data->_itemlevel);
    cocos2d::ui::Scale9Sprite* floor = cocos2d::ui::Scale9Sprite::create(floorpath);
    floor->setAnchorPoint(cocos2d::Vec2(0.5,1.0f));
    floor->setContentSize(cocos2d::Size(visibleSize/3*2));
    floor->setPosition(visibleSize.width/4*3,visibleSize.height/6*5);
    this->addChild(floor);
    
    float varlen = 15;
    float Left = visibleSize.width/2 + varlen;
    float Top = visibleSize.height/6*5 - varlen;
    
    //ICON
    std::string iconpath = cocos2d::StringUtils::format("Item/Item#%d.png",data->itemNo);
    cocos2d::Sprite* icon = cocos2d::Sprite::create(iconpath);
    icon->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    //icon->setScale(1.5f);
    icon->setPosition(Left,Top - icon->getContentSize().height/2);
    this->addChild(icon);
    
    //NAME
    cocos2d::Label* ItemName = cocos2d::Label::createWithTTF(data->name, "fonts/black.ttf", 50);
    ItemName->setColor(getColorByLevel(data->_itemlevel));
    ItemName->setAlignment(cocos2d::TextHAlignment::LEFT);
    ItemName->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    ItemName->setPosition(Left + icon->getContentSize().width + varlen ,Top - ItemName->getContentSize().height/2);
    this->addChild(ItemName);
    
    //ELE
    cocos2d::Label* ItemEle = getItemEle(data->_Ele,30);
    ItemEle->setAlignment(cocos2d::TextHAlignment::LEFT);
    ItemEle->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    ItemEle->setPosition(Left + icon->getContentSize().width + varlen, ItemName->getPositionY() - ItemEle->getContentSize().height - varlen);
    this->addChild(ItemEle);
    
    cocos2d::Label* AttrTitle = cocos2d::Label::createWithTTF("基础属性", "fonts/black.ttf", 35 );
    AttrTitle->setAlignment(cocos2d::TextHAlignment::LEFT);
    AttrTitle->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    AttrTitle->setPosition(Left,icon->getPositionY() - icon->getContentSize().height*1.5/2 - AttrTitle->getContentSize().height/2 -varlen);
    this->addChild(AttrTitle);
    
    std::string attr1str = cocos2d::StringUtils::format("+ %d%% %s",data->attr1._value,getAttrStr(data->attr1._type).c_str());
    cocos2d::Label* attr1Label = cocos2d::Label::createWithTTF(attr1str, "fonts/black.ttf", 30);
    attr1Label->setAlignment(cocos2d::TextHAlignment::LEFT);
    attr1Label->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    attr1Label->setPosition(Left,AttrTitle->getPositionY() - AttrTitle->getContentSize().height/2 - attr1Label->getContentSize().height/2 - varlen);
    this->addChild(attr1Label);
    
    std::string attr2str = cocos2d::StringUtils::format("+ %d%% %s",data->attr2._value,getAttrStr(data->attr2._type).c_str());
    cocos2d::Label* attr2Label = cocos2d::Label::createWithTTF(attr2str, "fonts/black.ttf", 30);
    attr2Label->setAlignment(cocos2d::TextHAlignment::LEFT);
    attr2Label->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    attr2Label->setPosition(Left,attr1Label->getPositionY() - attr1Label->getContentSize().height/2 - attr2Label->getContentSize().height/2);
    this->addChild(attr2Label);
    
    std::string infostr = cocos2d::StringUtils::format("  “%s”",data->info.c_str());
    cocos2d::Label* info = cocos2d::Label::createWithTTF(infostr, "fonts/black.ttf", 30);
    info->setAlignment(cocos2d::TextHAlignment::LEFT);
    info->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    info->setColor(cocos2d::Color3B(227,215,98));
    info->setWidth(visibleSize.width/2-varlen*3);
    info->setPosition(Left,attr2Label->getPositionY() - attr2Label->getContentSize().height/2 - info->getContentSize().height/2 - varlen);
    this->addChild(info);
    

    std::string coinstr = cocos2d::StringUtils::format("售价:%d",ItemSystem::getInstance()->GetItemCoin(data));
    cocos2d::Label* CoinLabel = cocos2d::Label::createWithTTF(coinstr, "fonts/black.ttf", 30);
    CoinLabel->setAlignment(cocos2d::TextHAlignment::LEFT);
    CoinLabel->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    CoinLabel->setPosition(Left,info->getPositionY() - info->getContentSize().height/2 - CoinLabel->getContentSize().height/2 - varlen);
    this->addChild(CoinLabel);
    //cocos2d::Label
    
    cocos2d::Sprite* Coin1 = cocos2d::Sprite::create("UI/topstatebar_coin.png");
    Coin1->setPosition(CoinLabel->getPositionX() + CoinLabel->getContentSize().width + Coin1->getContentSize().width/3, CoinLabel->getPositionY());
    Coin1->setScale(0.5f);
    this->addChild(Coin1);
    
    floor->setContentSize(cocos2d::Size(visibleSize.width/2,(ItemName->getPositionY() + ItemName->getContentSize().height/2 + varlen) - (CoinLabel->getPositionY() - CoinLabel->getContentSize().height/2 - varlen)));
    
    
    if(data->_suit != SUIT_LIST::NO_SUIT)
    {
        std::vector<ITEM_EFFECTS_DATA>* _data = EquipmentSystem::getInstance()->GetItemEffectsData();
        int size = (int)_data->size();
        int number = 0;
        for(int i = 0 ; i < size ; i++)
        {
            if(_data->at(i)._suit == data->_suit)
            {
                number = _data->at(i).number;
                break;
            }
        }
        
        SUIT_STR_INFO suitstrinfo = SuitSystem::getInstance()->getSuitInfo(data->_suit);
        cocos2d::Label* suitlabel = cocos2d::Label::createWithTTF(suitstrinfo.suit, "fonts/black.ttf", 35);
        suitlabel->setAlignment(cocos2d::TextHAlignment::LEFT);
        suitlabel->setAnchorPoint(cocos2d::Vec2(0,0.5f));
        suitlabel->setColor(cocos2d::Color3B(81,230,43));
        suitlabel->setPosition(Left,info->getPositionY() - info->getContentSize().height/2 - suitlabel->getContentSize().height/2 - varlen);
        this->addChild(suitlabel);
        
        cocos2d::Label* suitinfo1 = cocos2d::Label::createWithTTF(suitstrinfo.info1, "fonts/black.ttf", 30);
        suitinfo1->setAlignment(cocos2d::TextHAlignment::LEFT);
        suitinfo1->setAnchorPoint(cocos2d::Vec2(0,0.5f));
        suitinfo1->setColor(cocos2d::Color3B(200,200,200));
        suitinfo1->setWidth(visibleSize.width/2-varlen*3);
        suitinfo1->setPosition(Left,suitlabel->getPositionY() - suitlabel->getContentSize().height/2 - suitinfo1->getContentSize().height/2);
        this->addChild(suitinfo1);
        
        cocos2d::Label* suitinfo2 = cocos2d::Label::createWithTTF(suitstrinfo.info2, "fonts/black.ttf", 30);
        suitinfo2->setAlignment(cocos2d::TextHAlignment::LEFT);
        suitinfo2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
        suitinfo2->setColor(cocos2d::Color3B(200,200,200));
        suitinfo2->setWidth(visibleSize.width/2-varlen*3);
        suitinfo2->setPosition(Left,suitinfo1->getPositionY() - suitinfo1->getContentSize().height/2- suitinfo2->getContentSize().height/2 - varlen/2);
        this->addChild(suitinfo2);
        
        if(number >= 2)
        {
            suitinfo1->setColor(cocos2d::Color3B(81,230,43));
        }
        if(number >= 4)
        {
            suitinfo2->setColor(cocos2d::Color3B(81,230,43));
        }
        
        CoinLabel->setPosition(Left,suitinfo2->getPositionY() - suitinfo2->getContentSize().height/2 - CoinLabel->getContentSize().height/2 - varlen);
        Coin1->setPosition(CoinLabel->getPositionX() + CoinLabel->getContentSize().width + Coin1->getContentSize().width/3, CoinLabel->getPositionY());

        
        floor->setContentSize(cocos2d::Size(visibleSize.width/2,(ItemName->getPositionY() + ItemName->getContentSize().height/2 + varlen) - (CoinLabel->getPositionY() - CoinLabel->getContentSize().height/2 - varlen)));
        
        
        
    }
    
    
    // 同部位装备信息
    std::string floorpath2 = cocos2d::StringUtils::format("UI/backpack_level%d.png",pdata->_itemlevel);
    cocos2d::ui::Scale9Sprite* floor2 = cocos2d::ui::Scale9Sprite::create(floorpath2);
    floor2->setAnchorPoint(cocos2d::Vec2(0.5,1.0f));
    floor2->setContentSize(cocos2d::Size(visibleSize/3*2));
    floor2->setPosition(visibleSize.width/4,visibleSize.height/6*5);
    this->addChild(floor2);
    

    float Left2 = varlen;
    float Top2 = visibleSize.height/6*5 - varlen;
    
    //ICON
    std::string iconpath2 = cocos2d::StringUtils::format("Item/Item#%d.png",pdata->itemNo);
    cocos2d::Sprite* icon2 = cocos2d::Sprite::create(iconpath2);
    icon2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    icon2->setPosition(Left2,Top2 - icon2->getContentSize().height/2);
    this->addChild(icon2);
    
    //NAME
    cocos2d::Label* ItemName2 = cocos2d::Label::createWithTTF(pdata->name, "fonts/black.ttf", 50);
    ItemName2->setColor(getColorByLevel(pdata->_itemlevel));
    ItemName2->setAlignment(cocos2d::TextHAlignment::LEFT);
    ItemName2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    ItemName2->setPosition(Left2 + icon2->getContentSize().width + varlen ,Top2 - ItemName2->getContentSize().height/2);
    this->addChild(ItemName2);
    
    //ELE
    cocos2d::Label* ItemEle2 = getItemEle(pdata->_Ele,30);
    ItemEle2->setAlignment(cocos2d::TextHAlignment::LEFT);
    ItemEle2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    ItemEle2->setPosition(Left2 + icon2->getContentSize().width + varlen, ItemName2->getPositionY() - ItemEle2->getContentSize().height - varlen);
    this->addChild(ItemEle2);
    
    cocos2d::Label* AttrTitle2 = cocos2d::Label::createWithTTF("基础属性", "fonts/black.ttf", 35 );
    AttrTitle2->setAlignment(cocos2d::TextHAlignment::LEFT);
    AttrTitle2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    AttrTitle2->setPosition(Left2,icon2->getPositionY() - icon2->getContentSize().height*1.5/2 - AttrTitle2->getContentSize().height/2 -varlen);
    this->addChild(AttrTitle2);
    
    std::string attr1str2 = cocos2d::StringUtils::format("+ %d%% %s",pdata->attr1._value,getAttrStr(pdata->attr1._type).c_str());
    cocos2d::Label* attr1Label2 = cocos2d::Label::createWithTTF(attr1str2, "fonts/black.ttf", 30);
    attr1Label2->setAlignment(cocos2d::TextHAlignment::LEFT);
    attr1Label2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    attr1Label2->setPosition(Left2,AttrTitle->getPositionY() - AttrTitle2->getContentSize().height/2 - attr1Label2->getContentSize().height/2 - varlen);
    this->addChild(attr1Label2);
    
    std::string attr2str2 = cocos2d::StringUtils::format("+ %d%% %s",pdata->attr2._value,getAttrStr(pdata->attr2._type).c_str());
    cocos2d::Label* attr2Label2 = cocos2d::Label::createWithTTF(attr2str2, "fonts/black.ttf", 30);
    attr2Label2->setAlignment(cocos2d::TextHAlignment::LEFT);
    attr2Label2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    attr2Label2->setPosition(Left2,attr1Label2->getPositionY() - attr1Label2->getContentSize().height/2 - attr2Label2->getContentSize().height/2);
    this->addChild(attr2Label2);
    
    std::string infostr2 = cocos2d::StringUtils::format("  “%s”",pdata->info.c_str());
    cocos2d::Label* info2 = cocos2d::Label::createWithTTF(infostr2, "fonts/black.ttf", 30);
    info2->setAlignment(cocos2d::TextHAlignment::LEFT);
    info2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    info2->setColor(cocos2d::Color3B(227,215,98));
    info2->setWidth(visibleSize.width/2-varlen*3);
    info2->setPosition(Left2,attr2Label->getPositionY() - attr2Label2->getContentSize().height/2 - info2->getContentSize().height/2 - varlen);
    this->addChild(info2);
    
    
    std::string coinstr2 = cocos2d::StringUtils::format("售价:%d",ItemSystem::getInstance()->GetItemCoin(pdata));
    cocos2d::Label* CoinLabel2 = cocos2d::Label::createWithTTF(coinstr2, "fonts/black.ttf", 30);
    CoinLabel2->setAlignment(cocos2d::TextHAlignment::LEFT);
    CoinLabel2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
    CoinLabel2->setPosition(Left2,info2->getPositionY() - info2->getContentSize().height/2 - CoinLabel2->getContentSize().height/2 - varlen);
    this->addChild(CoinLabel2);
    //cocos2d::Label
    
    cocos2d::Sprite* Coin2 = cocos2d::Sprite::create("UI/topstatebar_coin.png");
    Coin2->setPosition(CoinLabel2->getPositionX() + CoinLabel2->getContentSize().width + Coin2->getContentSize().width/3, CoinLabel2->getPositionY());
    Coin2->setScale(0.5f);
    this->addChild(Coin2);
    
    floor2->setContentSize(cocos2d::Size(visibleSize.width/2,(ItemName2->getPositionY() + ItemName2->getContentSize().height/2 + varlen) - (CoinLabel2->getPositionY() - CoinLabel2->getContentSize().height/2 - varlen)));
    
    
    if(pdata->_suit != SUIT_LIST::NO_SUIT)
    {
        std::vector<ITEM_EFFECTS_DATA>* _data = EquipmentSystem::getInstance()->GetItemEffectsData();
        int size = (int)_data->size();
        int number = 0;
        for(int i = 0 ; i < size ; i++)
        {
            if(_data->at(i)._suit == pdata->_suit)
            {
                number = _data->at(i).number;
                break;
            }
        }
        
        SUIT_STR_INFO suitstrinfo2 = SuitSystem::getInstance()->getSuitInfo(pdata->_suit);
        cocos2d::Label* suitlabel2 = cocos2d::Label::createWithTTF(suitstrinfo2.suit, "fonts/black.ttf", 35);
        suitlabel2->setAlignment(cocos2d::TextHAlignment::LEFT);
        suitlabel2->setAnchorPoint(cocos2d::Vec2(0,0.5f));
        suitlabel2->setColor(cocos2d::Color3B(81,230,43));
        suitlabel2->setPosition(Left2,info2->getPositionY() - info2->getContentSize().height/2 - suitlabel2->getContentSize().height/2 - varlen);
        this->addChild(suitlabel2);
        
        cocos2d::Label* suitinfo12 = cocos2d::Label::createWithTTF(suitstrinfo2.info1, "fonts/black.ttf", 30);
        suitinfo12->setAlignment(cocos2d::TextHAlignment::LEFT);
        suitinfo12->setAnchorPoint(cocos2d::Vec2(0,0.5f));
        suitinfo12->setColor(cocos2d::Color3B(200,200,200));
        suitinfo12->setWidth(visibleSize.width/2-varlen*3);
        suitinfo12->setPosition(Left2,suitlabel2->getPositionY() - suitlabel2->getContentSize().height/2 - suitinfo12->getContentSize().height/2);
        this->addChild(suitinfo12);
        
        cocos2d::Label* suitinfo22 = cocos2d::Label::createWithTTF(suitstrinfo2.info2, "fonts/black.ttf", 30);
        suitinfo22->setAlignment(cocos2d::TextHAlignment::LEFT);
        suitinfo22->setAnchorPoint(cocos2d::Vec2(0,0.5f));
        suitinfo22->setColor(cocos2d::Color3B(200,200,200));
        suitinfo22->setWidth(visibleSize.width/2-varlen*3);
        suitinfo22->setPosition(Left2,suitinfo12->getPositionY() - suitinfo12->getContentSize().height/2- suitinfo22->getContentSize().height/2 - varlen/2);
        this->addChild(suitinfo22);
        
        if(number >= 2)
        {
            suitinfo12->setColor(cocos2d::Color3B(81,230,43));
        }
        if(number >= 4)
        {
            suitinfo22->setColor(cocos2d::Color3B(81,230,43));
        }
        
        CoinLabel2->setPosition(Left2,suitinfo22->getPositionY() - suitinfo22->getContentSize().height/2 - CoinLabel->getContentSize().height/2 - varlen);
        Coin2->setPosition(CoinLabel2->getPositionX() + CoinLabel2->getContentSize().width + Coin2->getContentSize().width/3, CoinLabel2->getPositionY());
        
        floor2->setContentSize(cocos2d::Size(visibleSize.width/2,(ItemName2->getPositionY() + ItemName2->getContentSize().height/2 + varlen) - (CoinLabel2->getPositionY() - CoinLabel2->getContentSize().height/2 - varlen)));
        
        
        
    }
    
    
    
    

}


bool ItemInfoLayer::init(ITEM_DATA * _data,bool _bool,ITEM_SHOW_METHOD _method)
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    data = _data;
    if(_method == NORMAL_SHOW)
    {
        NormalShow();
    }
    else if(_method == COMPARE_SHOW)
    {
        ITEM_DATA* pdata = EquipmentSystem::getInstance()->GetEquipmentDataByPos(data->_Ele);
        if(pdata->itemNo < 0 || pdata->ItemCode == data->ItemCode)
        {
            NormalShow();
        }
        else if(pdata->itemNo >= 0)
        {
            CompareShow(pdata);
        }
    }
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    cocos2d::Menu* _menu = cocos2d::Menu::create();
    _menu->setPosition(0,0);
    this->addChild(_menu);
    
    backBtn = cocos2d::MenuItemImage::create("UI/item_back.png", "UI/item_back.png", std::bind(&ItemInfoLayer::BackCallBack,this));
    backBtn->setPosition(visibleSize.width/4*3,visibleSize.height/10);
    _menu->addChild(backBtn);
    if(_bool)
    {
        ITEM_DATA* pdata = EquipmentSystem::getInstance()->GetEquipmentDataByPos(data->_Ele);
        if(pdata->ItemCode != data->ItemCode)
        {
            cocos2d::MenuItemImage* paybtn = cocos2d::MenuItemImage::create("UI/pay_btn.png", "UI/pay_btn.png", std::bind(&ItemInfoLayer::PayCallBack,this));
            paybtn->setPosition(visibleSize.width/2,visibleSize.height/10);
            _menu->addChild(paybtn);
            cocos2d::MenuItemImage* getbtn = cocos2d::MenuItemImage::create("UI/get_btn.png", "UI/get_btn.png", std::bind(&ItemInfoLayer::GetCallBack,this));
            getbtn->setPosition(visibleSize.width/4,visibleSize.height/10);
            _menu->addChild(getbtn);
        }
        else
        {
            cocos2d::MenuItemImage* putbtn = cocos2d::MenuItemImage::create("UI/put_btn.png", "UI/put_btn.png", std::bind(&ItemInfoLayer::PutCallBack,this,false));
            putbtn->setPosition(visibleSize.width/4,visibleSize.height/10);
            _menu->addChild(putbtn);
        }

    }
    else
    {
        cocos2d::MenuItemImage* putbtn = cocos2d::MenuItemImage::create("UI/put_btn.png", "UI/put_btn.png", std::bind(&ItemInfoLayer::PutCallBack,this,true));
        putbtn->setPosition(visibleSize.width/4,visibleSize.height/10);
        _menu->addChild(putbtn);
    }
    


    return true;
}

void ItemInfoLayer::BackCallBack()
{
    UISystem::getInstance()->SetItemLayerOpen(false);
    this->getParent()->removeChild(this);
}

void ItemInfoLayer::GetCallBack()
{
    EquipmentSystem::getInstance()->GetUpEquipment(data);
    UISystem::getInstance()->SetItemLayerOpen(false);
    this->getParent()->removeChild(this);
}

void ItemInfoLayer::PayCallBack()
{
    BackpackSystem::getInstance()->CleanItem(itembar);
    UISystem::getInstance()->SetItemLayerOpen(false);
    this->getParent()->removeChild(this);
}

void ItemInfoLayer::PutCallBack(bool _bool)
{
    if(_bool)
    {
        itembar->getData()->itemNo = -1;
        static_cast<SuitBar*>(itembar->getParent())->HaloRunAction();
        itembar->getParent()->removeChild(itembar);
    }
    EquipmentSystem::getInstance()->PutDownEquipment(itembar->getData());
        
    UISystem::getInstance()->SetItemLayerOpen(false);
    this->getParent()->removeChild(this);
}

void ItemInfoLayer::SetThisItemBar(ItemBar * _itembar)
{
    itembar = _itembar;
}

std::string ItemInfoLayer::getAttrStr(ATTR_TYPE _type)
{
    std::string titlestr;
    switch (_type) {
        case ATTR_ATK:
            titlestr = "基础攻击力";
            break;
        case ATTR_DEF:
            titlestr = "基础防御力";
            break;
        case ATTR_HEALTH:
            titlestr = "基础生命值";
            break;
        case ATTR_MAGIC:
            titlestr = "基础魔力值";
            break;
        case ATTR_REHP:
            titlestr = "基础生命恢复";
            break;
        case ATTR_REMP:
            titlestr = "基础魔力恢复";
            break;
        case ATTR_BUFFTIME:
            titlestr = "基础增益时间";
            break;
        case ATTR_SHIELD:
            titlestr = "基础护盾值";
            break;
        case ATTR_SPEED:
            titlestr = "基础速度";
            break;
        default:
            break;
    }
    return titlestr;;
}

cocos2d::Color3B ItemInfoLayer::getColorByLevel(ITEM_LEVEL_LIST _list)
{
    switch (_list)
    {
        case NORMAL_ITEM:
            return cocos2d::Color3B(228,220,208);
            break;
        case EXCELLENT_ITEM:
            return cocos2d::Color3B(28,165,252);
            break;
        case EPIC_ITEM:
            return cocos2d::Color3B(222,34,220);
            break;
        case SUIT_ITEM:
            return cocos2d::Color3B(81,230,43);
            break;
        case LEGEND_ITEM:
            return cocos2d::Color3B(253,160,40);
            break;
        default:
            break;
    }
}

cocos2d::Label* ItemInfoLayer::getItemEle(ITEM_ELEMENT _ele,int size)
{
    std::string elestr;
    cocos2d::Color3B color;
    switch (_ele)
    {
        case ITEM_FIRE:
            elestr = "契合属性:火";
            color = cocos2d::Color3B(255,0,0);
            break;
        case ITEM_WATER:
            elestr = "契合属性:水";
            color = cocos2d::Color3B(0,150,255);
            break;
        case ITEM_MAGIC:
            elestr = "契合属性:魔法";
            color = cocos2d::Color3B(200,0,200);
            break;
        case ITEM_THUNDER:
            elestr = "契合属性:雷";
            color = cocos2d::Color3B(255,255,0);
            break;
        case ITEM_WIND:
            elestr = "契合属性:风";
            color = cocos2d::Color3B(200,200,200);
            break;
        default:
            break;
    }
    cocos2d::Label* pRet = cocos2d::Label::createWithTTF(elestr, "fonts/black.ttf", size);
    pRet->setColor(color);
    return pRet;
}











