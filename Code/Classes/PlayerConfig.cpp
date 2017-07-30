//
//  PlayerConfig.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/10.
//
//

#include "PlayerConfig.h"
#include "XMLParser.h"
#include "JsonParser.h"
#include "TalentConfig.h"
#include "FireConfig.h"
#include "WaterConfig.h"
#include "WindConfig.h"
#include "ThunderConfig.h"
#include "AttrSystem.h"
#include "UISystem.h"
#include "ReSetLayer.h"
#include "ItemInfoLayer.h"
#include "BackpackSystem.h"
#include "ItemSystem.h"
PlayerConfig::PlayerConfig()
{
    AttrSystem::getInstance()->Update();
    isMoved = false;
    AttrBarPool = new std::vector<AttrBar*>;
}

PlayerConfig::~PlayerConfig()
{
   
}

cocos2d::ui::Scale9Sprite* PlayerConfig::getSelectItemSprite(const std::string &_title)
{
    //点击状态
    cocos2d::ui::Scale9Sprite* pRet = cocos2d::ui::Scale9Sprite::create("UI/bottom_title.png");
    pRet->setInsetLeft(10);
    pRet->setInsetRight(10);
    pRet->setInsetTop(48);
    pRet->setInsetBottom(48);
    pRet->setContentSize(cocos2d::Size(200,100));
    cocos2d::Label* _titlelabel = cocos2d::Label::createWithTTF(_title, "fonts/black.ttf", 40);
    _titlelabel->setPosition(pRet->getContentSize().width/2,pRet->getContentSize().height*0.6);
    pRet->addChild(_titlelabel);
    return pRet;
}

cocos2d::ui::Scale9Sprite* PlayerConfig::getunSelectItemSprite(const std::string &_title)
{
    //点击状态
    cocos2d::ui::Scale9Sprite* pRet = cocos2d::ui::Scale9Sprite::create("UI/bottom_title_unselect.png");
    pRet->setInsetLeft(10);
    pRet->setInsetRight(10);
    pRet->setInsetTop(48);
    pRet->setInsetBottom(48);
    pRet->setContentSize(cocos2d::Size(200,100));
    cocos2d::Label* _titlelabel = cocos2d::Label::createWithTTF(_title, "fonts/black.ttf", 40);
    _titlelabel->setPosition(pRet->getContentSize().width/2,pRet->getContentSize().height*0.6);
    pRet->addChild(_titlelabel);
    return pRet;
}


cocos2d::MenuItemToggle* PlayerConfig::getTilteMenuItem(const std::string &_title,int _tag)
{
    cocos2d::MenuItemSprite* _SelectItem = cocos2d::MenuItemSprite::create(getSelectItemSprite(_title), getSelectItemSprite(_title));
    cocos2d::MenuItemSprite* _unSelectItem = cocos2d::MenuItemSprite::create(getunSelectItemSprite(_title), getunSelectItemSprite(_title));
    cocos2d::MenuItemToggle* pRet = cocos2d::MenuItemToggle::createWithCallback(std::bind(&PlayerConfig::TitleTouchCallBack,this,_tag), _SelectItem,_unSelectItem, NULL);
    return pRet;
}

void PlayerConfig::TitleTouchCallBack(int _tag)
{
    if(_tag == NowPage)
    {
        TitlePool.at(_tag)->setSelectedIndex(0);
        return;
    }
    for(int i = 0 ; i < 3;i++)
    {
        if(i != _tag)
        {
            TitlePool.at(i)->setSelectedIndex(1);
        }
        else if(i == _tag)
        {
            FloorSprite->removeChildByName("NodePage");
            FloorSprite->addChild(SelectPage(i),1,"NodePage");
            NowPage = i;
        }
    }
}

cocos2d::Node* PlayerConfig::Page1Init()
{

    
    cocos2d::Node* NodePage = cocos2d::Node::create();
    NodePage->setPosition(0,0);
    
    cocos2d::Label* title1= cocos2d::Label::createWithTTF("元素天赋","fonts/black.ttf",60);
    title1->setPosition(FloorSprite->getContentSize().width/2,FloorSprite->getContentSize().height/5 + title1->getContentSize().height*1.5);
    NodePage->addChild(title1);
    
    FireIcon = cocos2d::Sprite::create("gs_fire.png");
    FireIcon->setScale(0.6f);
    FireIcon->setPosition(FloorSprite->getContentSize().width/5,FloorSprite->getContentSize().height/5);
    NodePage->addChild(FireIcon);
    
    ThunderIcon = cocos2d::Sprite::create("gs_thunder.png");
    ThunderIcon->setScale(0.6f);
    ThunderIcon->setPosition(FloorSprite->getContentSize().width/5*2,FloorSprite->getContentSize().height/5);
    NodePage->addChild(ThunderIcon);
    
    WaterIcon = cocos2d::Sprite::create("gs_water.png");
    WaterIcon->setScale(0.6f);
    WaterIcon->setPosition(FloorSprite->getContentSize().width/5*3,FloorSprite->getContentSize().height/5);
    NodePage->addChild(WaterIcon);
    
    WindIcon = cocos2d::Sprite::create("gs_wind.png");
    WindIcon->setScale(0.6f);
    WindIcon->setPosition(FloorSprite->getContentSize().width/5*4,FloorSprite->getContentSize().height/5);
    NodePage->addChild(WindIcon);
    
    int _fire_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_FIRE);
    std::string _firepath;
    _firepath = cocos2d::StringUtils::format("skillicon/fireskillicon_%d.png",_fire_no-1);
    FireSkillIcon = cocos2d::Sprite::create(_firepath);
    FireSkillIcon->setPosition(FireIcon->getPositionX(),FireIcon->getPositionY() - FireSkillIcon->getContentSize().height*1.2f);
    NodePage->addChild(FireSkillIcon);
    
    
    int _thunder_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_THUNDER);
    std::string _thunderpath;
    _thunderpath = cocos2d::StringUtils::format("skillicon/thunderskillicon_%d.png",_thunder_no-1);
    ThunderSkillIcon = cocos2d::Sprite::create(_thunderpath);
    ThunderSkillIcon->setPosition(ThunderIcon->getPositionX(),ThunderIcon->getPositionY() - ThunderSkillIcon->getContentSize().height*1.2f);
    NodePage->addChild(ThunderSkillIcon);
    
    int _water_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_WATER);
    std::string _waterpath;
    _waterpath = cocos2d::StringUtils::format("skillicon/waterskillicon_%d.png",_water_no-1);
    WaterSkillIcon = cocos2d::Sprite::create(_waterpath);
    WaterSkillIcon->setPosition(WaterIcon->getPositionX(),WaterIcon->getPositionY() - WaterSkillIcon->getContentSize().height*1.2f);
    NodePage->addChild(WaterSkillIcon);
    
    int _wind_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_WIND);
    std::string _windpath;
    _windpath = cocos2d::StringUtils::format("skillicon/windskillicon_%d.png",_wind_no-1);
    WindSkillIcon = cocos2d::Sprite::create(_windpath);
    WindSkillIcon->setPosition(WindIcon->getPositionX(),WindIcon->getPositionY() - WindSkillIcon->getContentSize().height*1.2f);
    NodePage->addChild(WindSkillIcon);
    
    ///
    
    cocos2d::Label* title2= cocos2d::Label::createWithTTF("魔力原石","fonts/black.ttf",60);
    title2->setPosition(FloorSprite->getContentSize().width/2,FloorSprite->getContentSize().height - title2->getContentSize().height*1.5);
    NodePage->addChild(title2);
    _suitbar = SuitBar::create();
    _suitbar->setPosition(FloorSprite->getContentSize().width/2,FloorSprite->getContentSize().height/5*3);
    NodePage->addChild(_suitbar);
    
    return NodePage;
}

cocos2d::Node* PlayerConfig::Page2Init()
{
    cocos2d::Node* NodePage = cocos2d::Node::create();
    std::string attrchar;
    attrchar = cocos2d::StringUtils::format("剩余属性点:%d",AttrSystem::getInstance()->GetARRTNUM());
    AttrNumLabel= cocos2d::Label::createWithTTF(attrchar,"fonts/black.ttf",60);
    AttrNumLabel->setPosition(FloorSprite->getContentSize().width/2,FloorSprite->getContentSize().height - AttrNumLabel->getContentSize().height*1.5);
    NodePage->addChild(AttrNumLabel);
    NodePage->setPosition(0,0);
    delete AttrBarPool;
    AttrBarPool = new std::vector<AttrBar*>;
    for(int i = 0 ; i < 9 ; i++)
    {
        AttrBar* pRet = AttrBar::create((ATTR_TYPE)i);
        pRet->setPosition(FloorSprite->getContentSize().width/2,AttrNumLabel->getPositionY()  - pRet->GetHeight()*(i+1));
        AttrBarPool->push_back(pRet);
        NodePage->addChild(pRet);
    }
    NodePage->schedule(std::bind(&PlayerConfig::UpdateAttrNum,this),"updateAttr");
    
    cocos2d::MenuItemImage* resetBtn = cocos2d::MenuItemImage::create("UI/reset.png","UI/reset.png",std::bind(&PlayerConfig::ResetAttr,this));
    resetBtn->setPosition(FloorSprite->getContentSize().width/2,resetBtn->getContentSize().height*1.1f);
    
    cocos2d::Menu* menu = cocos2d::Menu::create(resetBtn,NULL);
    menu->setPosition(0,0);
    NodePage->addChild(menu);
    return NodePage;
    
}

void PlayerConfig::ResetAttr()
{
    for(int i = 0 ; i < 9 ; i++)
    {
        AttrBarPool->at(i)->Reset();
    }
}

cocos2d::Node* PlayerConfig::Page3Init()
{
    cocos2d::Node* NodePage = cocos2d::Node::create();
    NodePage->setPosition(0,0);
    std::string backpackchar;
    backpackchar = cocos2d::StringUtils::format("背包%d",1);
    cocos2d::Label* backpacktitle = cocos2d::Label::createWithTTF(backpackchar,"fonts/black.ttf",60);
    backpacktitle->setPosition(FloorSprite->getContentSize().width/2,FloorSprite->getContentSize().height - backpacktitle->getContentSize().height*1.5f);
    NodePage->addChild(backpacktitle);
    float RightLength = (FloorSprite->getContentSize().width - 600 - 60)/2;
    BackpackPool = BackpackSystem::getInstance()->BackpackInit();
    cocos2d::Menu* menu = cocos2d::Menu::create();
    menu->setPosition(0,0);
    NodePage->addChild(menu);
    for(int i = 0 ; i < 42 ; i ++)
    {
        cocos2d::MenuItemImage* touchFloor = cocos2d::MenuItemImage::create("UI/backpack_level0.png","UI/backpack_level0.png",std::bind(&PlayerConfig::AddItemLayer,this,i));
        touchFloor->setPosition(RightLength + touchFloor->getContentSize().width/2 + (touchFloor->getContentSize().width + 12)*(i%6),FloorSprite->getContentSize().height - touchFloor->getContentSize().height*2 - (touchFloor->getContentSize().height + 12) * (i / 6));
        BackpackPool->at(i)->setPosition(touchFloor->getPosition());
        menu->addChild(touchFloor);
        NodePage->addChild(BackpackPool->at(i));
    }
     
    
    return NodePage;
}

void PlayerConfig::AddItemLayer(int tag)
{
    if(UISystem::getInstance()->getItemLayerOpen() || BackpackPool->at(tag)->isEmpty())
    {
        return;
    }
    ItemInfoLayer* layer = ItemInfoLayer::create(BackpackPool->at(tag)->getData(),true,COMPARE_SHOW);
    layer->SetThisItemBar(BackpackPool->at(tag));
    this->addChild(layer);
    UISystem::getInstance()->SetItemLayerOpen(true);
}

cocos2d::Node* PlayerConfig::SelectPage(int _page)
{
    switch (_page) {
        case 0:
            return Page1Init();
            break;
        case 1:
            return Page2Init();
            break;
        case 2:
            return Page3Init();
            break;
        default:
            break;
    }
    return nullptr;
}

bool PlayerConfig::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(PlayerConfig::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(PlayerConfig::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(PlayerConfig::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    
    
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Sprite* ShadowSprite = cocos2d::Sprite::create("UI/shadow.png");
    ShadowSprite->setPosition(visibleSize/2);
    this->addChild(ShadowSprite);
    
    FloorSprite = cocos2d::ui::Scale9Sprite::create("UI/playerconfig_floor.png");
    FloorSprite->setInsetLeft(20);
    FloorSprite->setInsetRight(20);
    FloorSprite->setInsetTop(20);
    FloorSprite->setInsetBottom(20);
    FloorSprite->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width/20*19,cocos2d::Director::getInstance()->getVisibleSize().height/16*13));
    //FloorSprite->setColor(cocos2d::Color3B(47,47,47));
    FloorSprite->setPosition(visibleSize.width/2,visibleSize.height/2 - 100);
    this->addChild(FloorSprite);
    
    
    _menu = cocos2d::Menu::create();
    _menu->setPosition(0,0);
    FloorSprite->addChild(_menu);
    
    cocos2d::MenuItemToggle* pRet = getTilteMenuItem("核心",0);
    pRet->setPosition(FloorSprite->getContentSize().width/6,FloorSprite->getContentSize().height + pRet->getContentSize().height/5);
    TitlePool.push_back(pRet);
    _menu->addChild(pRet);
    
    cocos2d::MenuItemToggle* pRet2 = getTilteMenuItem("属性",1);
    pRet2->setPosition(FloorSprite->getContentSize().width/2,FloorSprite->getContentSize().height + pRet2->getContentSize().height/5);
    pRet2->setSelectedIndex(1);
    TitlePool.push_back(pRet2);
    _menu->addChild(pRet2);
    
    cocos2d::MenuItemToggle* pRet3 = getTilteMenuItem("背包",2);
    pRet3->setPosition(FloorSprite->getContentSize().width/6*5,FloorSprite->getContentSize().height + pRet3->getContentSize().height/5);
    pRet3->setSelectedIndex(1);
    TitlePool.push_back(pRet3);
    _menu->addChild(pRet3);
    
    ////
    
    
    CloseBtn = cocos2d::MenuItemImage::create("UI/touchback.png", "UI/touchback.png", std::bind([=]{this->getParent()->removeChild(this);UISystem::getInstance()->ClosePlayerConfig();}));
    CloseBtn->setPosition(FloorSprite->getContentSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height - CloseBtn->getContentSize().height*1.35f);
    _menu->addChild(CloseBtn);
    FloorSprite->addChild(Page1Init(),1,"NodePage");
    NowPage = 0;
    
    ////

    
    //BackpackSystem::getInstance()->ParseItemDataByItemString(BackpackSystem::getInstance()->GetItemStringByItemData(ItemSystem::getInstance()->CreateItem()));
    

//    cocos2d::Label* TalentSettingLabel = cocos2d::Label::createWithTTF("天赋配置", "fonts/black.ttf", 60);
//    TalentSettingLabel->setPosition(FloorSprite->getContentSize().width/2,FloorSprite->getContentSize().height/40 * 36);
//    FloorSprite->addChild(TalentSettingLabel);
//    
//    

//    
//    

//    
//    
//    cocos2d::Label* AttrSettingLabel = cocos2d::Label::createWithTTF("属性配置", "fonts/black.ttf", 60);
//    AttrSettingLabel->setPosition(FloorSprite->getContentSize().width/2,FloorSprite->getContentSize().height/40 * 24);
//    FloorSprite->addChild(AttrSettingLabel);
//    
//    
//    std::vector<ATTR_DATA>* AttrVector = JsonParser::getInstance()->GetAttrData();
//    for(int i = 0 ; i < 9 ; i++)
//    {
//        cocos2d::Label* pRet = cocos2d::Label::createWithTTF(AttrVector->at(i).attr, "fonts/black.ttf", 40);
//        pRet->setPosition(FloorSprite->getContentSize().width/6*(2*(i%3+1)-1),FloorSprite->getContentSize().height/6*(4-(i/3+1))+40+20*(i/3));
//        AttrNamePool.push_back(pRet);
//        FloorSprite->addChild(AttrNamePool.back());
//        AttrBar* pRet2 = AttrBar::create();
//        pRet2->setPosition(AttrNamePool.back()->getPositionX(),AttrNamePool.back()->getPositionY() - pRet2->getContentSize().height*0.8f);
//        AttrBarPool.push_back(pRet2);
//        FloorSprite->addChild(AttrBarPool.back());
//    }
//    
//    AttrBarPool.at(0)->SetLevel(Parser::XML::getInstance()->GetData(Parser::ATK));
//    AttrBarPool.at(1)->SetLevel(Parser::XML::getInstance()->GetData(Parser::DEF));
//    AttrBarPool.at(2)->SetLevel(Parser::XML::getInstance()->GetData(Parser::HEALTH));
//    AttrBarPool.at(3)->SetLevel(Parser::XML::getInstance()->GetData(Parser::MAGIC));
//    AttrBarPool.at(4)->SetLevel(Parser::XML::getInstance()->GetData(Parser::SHEILD));
//    AttrBarPool.at(5)->SetLevel(Parser::XML::getInstance()->GetData(Parser::SPEED));
//    AttrBarPool.at(6)->SetLevel(Parser::XML::getInstance()->GetData(Parser::REHP));
//    AttrBarPool.at(7)->SetLevel(Parser::XML::getInstance()->GetData(Parser::REMP));
//    AttrBarPool.at(8)->SetLevel(Parser::XML::getInstance()->GetData(Parser::BUFFTIME));
//    AttrBarPool.at(0)->InitType(ATTR_TYPE::ATTR_ATK);
//    AttrBarPool.at(1)->InitType(ATTR_TYPE::ATTR_DEF);
//    AttrBarPool.at(2)->InitType(ATTR_TYPE::ATTR_HEALTH);
//    AttrBarPool.at(3)->InitType(ATTR_TYPE::ATTR_MAGIC);
//    AttrBarPool.at(4)->InitType(ATTR_TYPE::ATTR_SHIELD);
//    AttrBarPool.at(5)->InitType(ATTR_TYPE::ATTR_SPEED);
//    AttrBarPool.at(6)->InitType(ATTR_TYPE::ATTR_REHP);
//    AttrBarPool.at(7)->InitType(ATTR_TYPE::ATTR_REMP);
//    AttrBarPool.at(8)->InitType(ATTR_TYPE::ATTR_BUFFTIME);
//    AttrSystem::getInstance()->Update();
//    char attrchar[20];
//    sprintf(attrchar, "剩余属性点:%d",AttrSystem::getInstance()->GetARRTNUM());
//    AttrNumLabel = cocos2d::Label::createWithTTF(attrchar, "fonts/black.ttf", 40);
//    AttrNumLabel->setName("AttrLabel");
//    AttrNumLabel->setPosition(FloorSprite->getContentSize().width/2,FloorSprite->getContentSize().height/10);
//    FloorSprite->addChild(AttrNumLabel);
//    _menu = cocos2d::Menu::create(CloseBtn,NULL);
//    _menu->setPosition(0,0);
//    FloorSprite->addChild(_menu);
    
    return true;
}

void PlayerConfig::UpdateAttrNum()
{
    std::string attrchar;
    attrchar = cocos2d::StringUtils::format("剩余属性点:%d",AttrSystem::getInstance()->GetARRTNUM());
    AttrNumLabel->setString(attrchar);
}

void PlayerConfig::ReSetTalentList()
{
    int _fire_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_FIRE);
    char _firepath[30];
    sprintf(_firepath, "skillicon/fireskillicon_%d.png",_fire_no-1);
    FireSkillIcon->setTexture(_firepath);
    
    int _thunder_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_THUNDER);
    char _thunderpath[30];
    sprintf(_thunderpath, "skillicon/thunderskillicon_%d.png",_thunder_no-1);
    ThunderSkillIcon->setTexture(_thunderpath);
    
    
    int _water_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_WATER);
    char _waterpath[30];
    sprintf(_waterpath, "skillicon/waterskillicon_%d.png",_water_no-1);
    WaterSkillIcon->setTexture(_waterpath);
    
    int _wind_no = Parser::XML::getInstance()->GetData(Parser::USER_DATA_TYPE::TALENT_WIND);
    char _windpath[30];
    sprintf(_windpath, "skillicon/windskillicon_%d.png",_wind_no-1);
    WindSkillIcon->setTexture(_windpath);
    
}



void PlayerConfig::AddToTag(cocos2d::Node *_tag)
{
    
    _tag->addChild(this,10,"PlayerConfig");
}


bool PlayerConfig::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    isMoved = false;
    NowTouchPoint = FloorSprite->convertToNodeSpace(_touch->getLocation());
    LastTouchPoint = NowTouchPoint;
    if(NowPage == 0)
    {
        if(FireIcon->getBoundingBox().containsPoint(FloorSprite->convertToNodeSpace(_touch->getLocation())))
        {
            _MyEvent = CONFIG_TOUCH_EVENT::TOUCH_FIRE;
            return true;
        }
        else if(WaterIcon->getBoundingBox().containsPoint(FloorSprite->convertToNodeSpace(_touch->getLocation())))
        {
            _MyEvent = CONFIG_TOUCH_EVENT::TOUCH_WATER;
            return true;
        }
        else if(ThunderIcon->getBoundingBox().containsPoint(FloorSprite->convertToNodeSpace(_touch->getLocation())))
        {
            _MyEvent = CONFIG_TOUCH_EVENT::TOUCH_THUNDER;
            return true;
        }
        else if(WindIcon->getBoundingBox().containsPoint(FloorSprite->convertToNodeSpace(_touch->getLocation())))
        {
            _MyEvent = CONFIG_TOUCH_EVENT::TOUCH_WIND;
            return true;
        }
    }
//
//    for(int i = 0 ;i<9;i++)
//    {
//        if(AttrBarPool.at(i)->getBoundingBox().containsPoint(FloorSprite->convertToNodeSpace(_touch->getLocation())))
//        {
//            _MyEvent = (CONFIG_TOUCH_EVENT)i;
//            if(this->getChildByName("ResetLayer") != nullptr)
//            {
//                return false;
//            }
//            if( AttrBarPool.at((int)_MyEvent)->getlevel()==0)
//            {
//                return true;
//            }
//            this->scheduleOnce(std::bind([=]
//                                         {
//                                             ReSetLayer* pRetm = ReSetLayer::create(AttrBarPool.at((int)_MyEvent), AttrBarPool.at((int)_MyEvent)->getlevel()*5);
//                                             this->addChild(pRetm,4,"ResetLayer");
//                                             _MyEvent = TOUCH_NONE;
//                                         }), 0.5f ,"Reset");
//            return true;
//        }
//    }
    return true;
}

void PlayerConfig::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
//    this->unschedule("Reset");
//    NowTouchPoint = FloorSprite->convertToNodeSpace(_touch->getLocation());
//    if(NowTouchPoint.y - LastTouchPoint.y > 50)
//    {
//        switch (_MyEvent) {
//            case TOUCH_ATK:
//                if(AttrSystem::getInstance()->GetARRTNUM() - 1 < 0)
//                {
//                    break;
//                }
//                AttrBarPool.at(0)->AddLevel();
//                break;
//            case TOUCH_DEF:
//                if(AttrSystem::getInstance()->GetARRTNUM() - 1 < 0)
//                {
//                    break;
//                }
//                AttrBarPool.at(1)->AddLevel();
//                break;
//            case TOUCH_HEALTH:
//                if(AttrSystem::getInstance()->GetARRTNUM() - 1 < 0)
//                {
//                    break;
//                }
//                AttrBarPool.at(2)->AddLevel();
//                break;
//            case TOUCH_MAGIC:
//                if(AttrSystem::getInstance()->GetARRTNUM() - 1 < 0)
//                {
//                    break;
//                }
//                AttrBarPool.at(3)->AddLevel();
//                break;
//            case TOUCH_SHIELD:
//                if(AttrSystem::getInstance()->GetARRTNUM() - 1 < 0)
//                {
//                    break;
//                }
//                AttrBarPool.at(4)->AddLevel();
//                break;
//            case TOUCH_SPEED:
//                if(AttrSystem::getInstance()->GetARRTNUM() - 1 < 0)
//                {
//                    break;
//                }
//                AttrBarPool.at(5)->AddLevel();
//                break;
//            case TOUCH_REHEALTH:
//                if(AttrSystem::getInstance()->GetARRTNUM() - 1 < 0)
//                {
//                    break;
//                }
//                AttrBarPool.at(6)->AddLevel();
//                break;
//            case TOUCH_REMAGIC:
//                if(AttrSystem::getInstance()->GetARRTNUM() - 1 < 0)
//                {
//                    break;
//                }
//                AttrBarPool.at(7)->AddLevel();
//                break;
//            case TOUCH_BUFFTIME:
//                if(AttrSystem::getInstance()->GetARRTNUM() - 1 < 0)
//                {
//                    break;
//                }
//                AttrBarPool.at(8)->AddLevel();
//                
//                break;
//            default:
//                break;
//        }
//        LastTouchPoint = NowTouchPoint;
//        
//    }
//    
//    isMoved = true;
}

void PlayerConfig::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(isMoved)
    {
        return;
    }
    this->unschedule("Reset");
    switch (_MyEvent) {
        case TOUCH_FIRE:
            TalentConfig* _tc;
            _tc = FireConfig::create();
            _tc->AddToTag(this);
            break;
        case TOUCH_WATER:
            TalentConfig* _tc2;
            _tc2 = WaterConfig::create();
            _tc2->AddToTag(this);
            break;
        case TOUCH_THUNDER:
            TalentConfig* _tc3;
            _tc3 = ThunderConfig::create();
            _tc3->AddToTag(this);
            break;
        case TOUCH_WIND:
            TalentConfig* _tc4;
            _tc4 = WindConfig::create();
            _tc4->AddToTag(this);
            break;
            default:
            break;
    }
    
    _MyEvent = TOUCH_NONE;
//
//    
    
}