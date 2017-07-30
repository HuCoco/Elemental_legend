//
//  SuitBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/15.
//
//

#include "SuitBar.h"
#include "XMLParser.h"
#include "BackpackSystem.h"
#include "UISystem.h"
#include "ItemInfoLayer.h"
#define PI 3.1415

SuitBar::SuitBar()
{
    
}


SuitBar::~SuitBar()
{
    OuterHalo->release();
    InnerHalo->release();
}

void SuitBar::FloorInit()
{
    float Length = (OuterHalo->getContentSize().width/2*2.5f)*0.9f;
    
    cocos2d::Menu* menu = cocos2d::Menu::create();
    menu->setPosition(0,0);
    this->addChild(menu);
    
    cocos2d::MenuItemImage* FloorT = cocos2d::MenuItemImage::create("UI/halo_floor.png","UI/halo_floor.png",std::bind(&SuitBar::TouchCallBack,this,0));
    FloorT->setPosition(0,Length);
    floorPool.push_back(FloorT);
    menu->addChild(floorPool.back());
    
    cocos2d::MenuItemImage* FloorTR = cocos2d::MenuItemImage::create("UI/halo_floor.png","UI/halo_floor.png",std::bind(&SuitBar::TouchCallBack,this,1));
    FloorTR->setContentSize(cocos2d::Size(100,100));
    FloorTR->setPosition(-Length*cos(18.0f*PI/180),Length*sin(18.0f*PI/180));
    floorPool.push_back(FloorTR);
    menu->addChild(floorPool.back());
    
    cocos2d::MenuItemImage* FloorTL = cocos2d::MenuItemImage::create("UI/halo_floor.png","UI/halo_floor.png",std::bind(&SuitBar::TouchCallBack,this,2));
    FloorTL->setContentSize(cocos2d::Size(100,100));
    FloorTL->setPosition(Length*cos(18.0f*PI/180),Length*sin(18*PI/180));
    floorPool.push_back(FloorTL);
    menu->addChild(floorPool.back());
    
    cocos2d::MenuItemImage* FloorBR = cocos2d::MenuItemImage::create("UI/halo_floor.png","UI/halo_floor.png",std::bind(&SuitBar::TouchCallBack,this,3));
    FloorBR->setContentSize(cocos2d::Size(100,100));
    FloorBR->setPosition(Length*sin(36.0*PI/180),-Length*cos(36.0f*PI/180));
    floorPool.push_back(FloorBR);
    menu->addChild(floorPool.back());
    
    cocos2d::MenuItemImage* FloorBL = cocos2d::MenuItemImage::create("UI/halo_floor.png","UI/halo_floor.png",std::bind(&SuitBar::TouchCallBack,this,4));
    FloorBL->setContentSize(cocos2d::Size(100,100));
    FloorBL->setPosition(-Length*sin(36.0f*PI/180),-Length*cos(36.0f*PI/180));
    floorPool.push_back(FloorBL);
    menu->addChild(floorPool.back());
    
    SuitInit();
    
    for(int i = 0 ; i < 5 ; i++)
    {
        SuitPool->at(i)->setPosition(floorPool.at(i)->getPosition());
        this->addChild(SuitPool->at(i));
    }
    
}

void SuitBar::TouchCallBack(int _tag)
{
    if(UISystem::getInstance()->getItemLayerOpen() || SuitPool->at(_tag)->isEmpty())
    {
        return;
    }
    ItemInfoLayer* layer = ItemInfoLayer::create(SuitPool->at(_tag)->getData(),false);
    layer->SetThisItemBar(SuitPool->at(_tag));
    this->getParent()->getParent()->getParent()->addChild(layer,2);
    UISystem::getInstance()->SetItemLayerOpen(true);
}

bool SuitBar::init()
{
    if(!cocos2d::Node::init())
    {
        return false;
    }
    OuterHalo = cocos2d::Sprite::create("UI/outerhalo.png");
    OuterHalo->setOpacity(100);
    OuterHalo->setScale(2.5f);
    OuterHalo->setPosition(0,0);
    OuterHalo->retain();
    InnerHalo = cocos2d::Sprite::create("UI/innerhalo.png");
    InnerHalo->setOpacity(0);
    InnerHalo->setScale(2.5f);
    InnerHalo->setPosition(0,0);
    InnerHalo->retain();
    

   
    this->addChild(OuterHalo);
    this->addChild(InnerHalo);
    FloorInit();


    HaloRunAction();
    
    return true;
}

void SuitBar::HaloRunAction()
{
    InnerHalo->stopAllActions();
    InnerHalo->setOpacity(0);
    OuterHalo->stopAllActions();
    int EquipmentNum = 0;
    for(int i = 0;i< 5 ;i++)
    {
        if(SuitPool->at(i)->getData()->itemNo >= 0)
        {
            EquipmentNum++;
        }
    }
    
    switch (EquipmentNum) {
        default:
        case 5:
            L5Aciton();
        case 4:
            L4Aciion();
        case 3:
            L3Action();
        case 2:
            L2Aciton();
        case 1:
            L1Aciton();
        case 0:
            break;
    }

}

void SuitBar::L1Aciton()
{
    cocos2d::FadeTo* fade1 = cocos2d::FadeTo::create(2.0f, 255);
    cocos2d::FadeTo* fade2 = cocos2d::FadeTo::create(2.0f, 100);
    cocos2d::Sequence* Seq = cocos2d::Sequence::create(fade1,fade2, NULL);
    cocos2d::RepeatForever* Rep = cocos2d::RepeatForever::create(Seq);
    OuterHalo->runAction(Rep);
}

void SuitBar::L2Aciton()
{
    cocos2d::RotateBy* Rotate = cocos2d::RotateBy::create(5.0f, -360);
    cocos2d::RepeatForever* Rep = cocos2d::RepeatForever::create(Rotate);
    OuterHalo->runAction(Rep);
}

void SuitBar::L3Action()
{
    InnerHalo->setOpacity(100);
}

void SuitBar::L4Aciion()
{
    cocos2d::FadeTo* fade1 = cocos2d::FadeTo::create(1.5f, 255);
    cocos2d::FadeTo* fade2 = cocos2d::FadeTo::create(1.5f, 100);
    cocos2d::Sequence* Seq = cocos2d::Sequence::create(fade1,fade2, NULL);
    cocos2d::RepeatForever* Rep = cocos2d::RepeatForever::create(Seq);
    InnerHalo->runAction(Rep);
}

void SuitBar::L5Aciton()
{
    cocos2d::RotateBy* Rotate = cocos2d::RotateBy::create(5.0f, 360);
    cocos2d::RepeatForever* Rep = cocos2d::RepeatForever::create(Rotate);
    InnerHalo->runAction(Rep);
}

void SuitBar::SuitInit()
{
    SuitPool = new std::vector<ItemBar*>;
    for(int i = 0 ; i < 5 ; i++)
    {
        std::string itemstr = Parser::XML::getInstance()->GetEquipmentData(i);
        if(itemstr == "")
        {
            ItemBar* item = ItemBar::create(new ITEM_DATA());
            item->retain();
            SuitPool->push_back(item);
        }
        else
        {
            ItemBar* item = ItemBar::create(ItemSystem::getInstance()->ParseItemDataByItemString(itemstr));
            item->retain();
            SuitPool->push_back(item);
        }
    }

}


