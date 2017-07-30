//
//  ChestLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/11/4.
//
//

#include "ChestLayer.h"
#include "XMLParser.h"
#include "UISystem.h"
#include "XMLParser.h"
ChestLayer::ChestLayer()
{
    srand((int)time(NULL));
}


ChestLayer::~ChestLayer()
{
    
}

ChestLayer* ChestLayer::create(CHEST_TYPE _type)
{
    ChestLayer* pRet = new ChestLayer;
    if(pRet && pRet->init(_type))
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

bool ChestLayer::init(CHEST_TYPE _type)
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    if(_type == CHEST_TYPE::GOLDEN)
    {
        GoldenInit();
    }
    else if(_type == CHEST_TYPE::SLIVER)
    {
        SliverInit();
    }
    
    return true;
}

void ChestLayer::GetSliverPrize()
{
    int Random = rand()%45;
    if(Random < 10)
    {
        _prizeData = PRIZE_LIST::ONE_TICKET;
    }
    else if(Random >= 10 && Random < 15)
    {
        _prizeData = PRIZE_LIST::THREE_TICKET;
    }
    else if(Random >= 15 && Random < 25)
    {
        _prizeData = PRIZE_LIST::FIFTH_COIN;
    }
    else if(Random >= 25 && Random < 28)
    {
        _prizeData = PRIZE_LIST::TWO_HURDENT_COIN;
    }
    else if(Random >= 28 && Random < 33)
    {
        _prizeData = PRIZE_LIST::THREE_DIAMONDS;
    }
    else if(Random >= 33 && Random < 35)
    {
        _prizeData = PRIZE_LIST::TEN_DIAMONDS;
    }
    else if(Random >= 35 && Random < 38)
    {
        _prizeData = PRIZE_LIST::FIFTH_COIN;
    }
    else if(Random >= 38 && Random < 40)
    {
        _prizeData = PRIZE_LIST::FIFTH_COIN;
    }
    else if(Random >= 40 && Random < 45)
    {
        _prizeData = PRIZE_LIST::FIFTH_COIN;
    }


}

void ChestLayer::GetGoldenPrize()
{
    int Random = rand()%15;
    if(Random < 2)
    {
        _prizeData = PRIZE_LIST::FIVE_HURDEND_COIN;
    }
    else if(Random >= 2 && Random < 8)
    {
        _prizeData = PRIZE_LIST::FIFTH_COIN;
    }
    else if(Random >= 7 && Random < 12)
    {
        _prizeData = PRIZE_LIST::FIFTH_COIN;
    }
    else if(Random >= 12 && Random < 15)
    {
        _prizeData = PRIZE_LIST::FIFTH_COIN;
    }

}




void ChestLayer::GoldenInit()
{
    
    if(Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::DIAMONDS)-10 < 0)
    {
        FailInit(CHEST_TYPE::GOLDEN);
    }
    else
    {
        Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::DIAMONDS,Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::DIAMONDS)-10 );
        _chestfile = "UI/goldenbox.png";
        _chestopenfile = "UI/goldenbox_open.png";
        GetGoldenPrize();
        BaseInit();
    }
}

void ChestLayer::SliverInit()
{
    if(Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COIN)-100 < 0)
    {
        FailInit(CHEST_TYPE::SLIVER);
    }
    else
    {
        Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COIN,Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COIN)-100 );
        _chestfile = "UI/sliverbox.png";
        _chestopenfile = "UI/sliverbox_open.png";
        GetSliverPrize();
        BaseInit();
    }
}

void ChestLayer::FailInit(CHEST_TYPE _type)
{
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    _okBtn = cocos2d::MenuItemImage::create("UI/ok_btn.png","UI/ok_btn.png",std::bind(&ChestLayer::Close,this));
    _okBtn->setPosition(visibleSize.width/2,visibleSize.height/5);
    switch (_type) {
        case GOLDEN:
            _info = cocos2d::Label::createWithTTF("钻石不够啦", "fonts/black.ttf", 100);
            break;
        case SLIVER:
            _info = cocos2d::Label::createWithTTF("金币不够啦", "fonts/black.ttf", 100);
            break;
        default:
            break;
    }
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite);
    
    _info->setPosition(visibleSize/2);
    this->addChild(_info);
    _menu = cocos2d::Menu::create(_okBtn,NULL);
    _menu->setPosition(0,0);
    this->addChild(_menu);
}

void ChestLayer::BaseInit()
{
    switch (_prizeData) {
        case ONE_TICKET:
            _prize = cocos2d::Sprite::create("UI/ticket.png");
            _light = cocos2d::Sprite::create("UI/prize_light.png");
            _info = cocos2d::Label::createWithTTF("恭喜你获得1个试炼券", "fonts/black.ttf", 50);
            break;
        case THREE_TICKET:
            _prize = cocos2d::Sprite::create("UI/ticket.png");
            _light = cocos2d::Sprite::create("UI/prize_light.png");
            _info = cocos2d::Label::createWithTTF("恭喜你获得3个试炼券", "fonts/black.ttf", 50);
            break;
        case FIVE_TICKET:
            _prize = cocos2d::Sprite::create("UI/ticket.png");
            _light = cocos2d::Sprite::create("UI/prize_light.png");
            _info = cocos2d::Label::createWithTTF("恭喜你获得5个试炼券", "fonts/black.ttf", 50);
            break;
        case FIFTH_COIN:
            _prize = cocos2d::Sprite::create("UI/topstatebar_coin.png");
            _light = cocos2d::Sprite::create("UI/prize_light.png");
            _info = cocos2d::Label::createWithTTF("恭喜你获得50金币", "fonts/black.ttf", 50);
            Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COIN, Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COIN)+50);
            break;
        case TWO_HURDENT_COIN:
            _prize = cocos2d::Sprite::create("UI/topstatebar_coin.png");
            _light = cocos2d::Sprite::create("UI/prize_light.png");
            _info = cocos2d::Label::createWithTTF("恭喜你获得200金币", "fonts/black.ttf", 50);
            Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COIN, Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COIN)+200);
            break;
        case FIVE_HURDEND_COIN:
            _prize = cocos2d::Sprite::create("UI/topstatebar_coin.png");
            _light = cocos2d::Sprite::create("UI/prize_light.png");
            _info = cocos2d::Label::createWithTTF("恭喜你获得500金币", "fonts/black.ttf", 50);
            Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::COIN, Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::COIN)+500);
            break;
        case THREE_DIAMONDS:
            _prize = cocos2d::Sprite::create("UI/3diamond.png");
            _light = cocos2d::Sprite::create("UI/prize_light.png");
            _info = cocos2d::Label::createWithTTF("恭喜你获得3颗钻石", "fonts/black.ttf", 50);
            Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::DIAMONDS, Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::DIAMONDS)+3);
            break;
        case TEN_DIAMONDS:
            _prize = cocos2d::Sprite::create("UI/10diamond.png");
            _light = cocos2d::Sprite::create("UI/prize_light.png");
            _info = cocos2d::Label::createWithTTF("恭喜你获得10颗钻石", "fonts/black.ttf", 50);
            Parser::XML::getInstance()->UpdateData(Parser::USER_DATA_TYPE::DIAMONDS, Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::DIAMONDS)+10);
            break;

    }
    
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite);
    
    
    _chest = cocos2d::Sprite::create(_chestfile);
    _chest->setPosition(visibleSize/2);
    _chest->setScale(3);
    _chestlight = cocos2d::Sprite::create("UI/chest_light.png");
    _chestlight->setPosition(visibleSize/2);
    _chestlight->setScale(5);
    //_chestlight->setOpacity(0);
    _prize->setPosition(visibleSize.width/2,visibleSize.height/5*3);
    _prize->setScale(0.01);
    _prize->retain();
    _info->setPosition(visibleSize.width/2,visibleSize.height/10*3);
    _info->retain();
    _light->setPosition(visibleSize.width/2,visibleSize.height/5*3);
    _light->setScale(0.01);
    _light->setOpacity(0);
    _light->retain();

    cocos2d::RotateBy* ChestRotate = cocos2d::RotateBy::create(0.05f, 10);
    cocos2d::Sequence* ChestSeq = cocos2d::Sequence::create(ChestRotate,ChestRotate->reverse(),ChestRotate->reverse(),ChestRotate,NULL);
    cocos2d::Repeat* ChestRotateRepeat = cocos2d::Repeat::create(ChestSeq, 4);
    
    cocos2d::CallFunc* CallBack1 = cocos2d::CallFunc::create(std::bind([=]
                                                                       {
                                                                           cocos2d::MoveTo* ChestMoveTo = cocos2d::MoveTo::create(0.3f, cocos2d::Vec2(visibleSize.width/2,visibleSize.height/5*3));
                                                                           _chest->setTexture(_chestopenfile);
                                                                           _chest->setScale(3);
                                                                           _chest->runAction(ChestMoveTo->clone());
                                                                           _chestlight->runAction(ChestMoveTo->clone());
                                                                           
                                                                           cocos2d::ScaleTo* PrizeBeNormal = cocos2d::ScaleTo::create(0.2f, 1.5);
                                                                           cocos2d::ScaleTo* LightBeNormal = cocos2d::ScaleTo::create(0.2f, 2.5);
                                                                           cocos2d::FadeIn* lightFadeIn = cocos2d::FadeIn::create(0.2f);
                                                                           cocos2d::MoveTo* PrizeMove = cocos2d::MoveTo::create(0.2f, cocos2d::Vec2(visibleSize.width/2,visibleSize.height/5*2));
                                                                           cocos2d::RotateBy* PrizeRotate = cocos2d::RotateBy::create(1.0f, 20);
                                                                           cocos2d::RepeatForever* PrizeRotateRepeat = cocos2d::RepeatForever::create(PrizeRotate);
                                                                           this->addChild(_light);
                                                                           this->addChild(_prize);
                                                                           _prize->runAction(PrizeBeNormal);
                                                                           _prize->runAction(PrizeMove->clone());
                                                                           _light->runAction(LightBeNormal);
                                                                           _light->runAction(PrizeMove);
                                                                           _light->runAction(lightFadeIn);
                                                                           _light->runAction(PrizeRotateRepeat);
                                                                           
                                                                           this->addChild(_info);
                                                                           
                                                                       }));
    cocos2d::Sequence* ChestMainSeq = cocos2d::Sequence::create(ChestRotateRepeat,CallBack1, NULL);
    cocos2d::RotateBy* ChestLightRotate = cocos2d::RotateBy::create(1.0f, 20);
    cocos2d::RepeatForever* ChestLightRep = cocos2d::RepeatForever::create(ChestLightRotate);
    cocos2d::FadeIn* ChestLightFadeIn = cocos2d::FadeIn::create(0.8f);
    
    this->addChild(_chestlight);
    _chestlight->runAction(ChestLightRep);
    _chestlight->runAction(ChestLightFadeIn);
    this->addChild(_chest);
    _chest->runAction(ChestMainSeq);

    

    
    
    
    
    
    
    _okBtn = cocos2d::MenuItemImage::create("UI/ok_btn.png","UI/ok_btn.png",std::bind(&ChestLayer::Close,this));
    _okBtn->setPosition(visibleSize.width/2,visibleSize.height/4);
    
    _menu = cocos2d::Menu::create(_okBtn,NULL);
    _menu->setPosition(0,0);
    this->addChild(_menu);
    
}


void ChestLayer::Close()
{
    this->getParent()->removeChild(this);
    UISystem::getInstance()->setBottomStateBarControl(true);
    UISystem::getInstance()->setMapCanControl(true);
    UISystem::getInstance()->setTopStateBarControl(true);
}

