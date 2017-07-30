//
//  GameInterfaceGuideLayer.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#include "GameInterfaceGuideLayer.h"
#include "GuideSystem.h"
#include "ResourceSystem.h"
GameInterfaceGuideLayer::GameInterfaceGuideLayer()
{
    
}


GameInterfaceGuideLayer::~GameInterfaceGuideLayer()
{
    
}

bool GameInterfaceGuideLayer::init()
{
    if(!BaseGuideLayer::init())
    {
        return false;
    }
    
    Step = 0;
    
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(GameInterfaceGuideLayer::onTouchBegan, this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(GameInterfaceGuideLayer::onTouchMoved, this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(GameInterfaceGuideLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    
    Tips1 = cocos2d::Label::createWithTTF("首先看下界面", "fonts/black.ttf", 40);
    Tips1->setDimensions(cocos2d::Director::getInstance()->getVisibleSize().width/8*7,cocos2d::Director::getInstance()->getVisibleSize().height/5);
    Tips1->setAlignment(cocos2d::TextHAlignment::CENTER);
    Tips1->setPosition(cocos2d::Director::getInstance()->getVisibleSize()/2);
    this->addChild(Tips1);
    
    AddTouchTips();
    
    return true;
}

bool GameInterfaceGuideLayer::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(!CanTouch)
    {
        return false;
    }
    
    switch (Step) {
            
        case 0:
            Tips1->setString("这些是状态条");
            Tips1->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/3*2);
            System->AddResourceBar();
            ResetTouchTips();
            AddTouchTips();
            Step++;
            break;
        case 1:
            Tips1->setString("首先，这绿色的状态条你的生命值，当它为0是战斗就失败了");
            Tips1->setPositionY(cocos2d::Director::getInstance()->getVisibleSize().height/40*21);
            Step++;
            ResetTouchTips();
            AddTouchTips();
            break;
        case 2:
            Tips1->setString("这蓝色的状态条你的魔法条，当魔法足够是才能使用法术");
            Tips1->setPositionY(cocos2d::Director::getInstance()->getVisibleSize().height/5*2);
            Step++;
            ResetTouchTips();
            AddTouchTips();
            break;
        case 3:
            Tips1->setString("左边的是护盾条，护盾能保护你不受到伤害");
            ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, SHEILD, ADD, 50);
            Tips1->setPositionY(cocos2d::Director::getInstance()->getVisibleSize().height/3);
            Step++;
            ResetTouchTips();
            AddTouchTips();
            break;
        case 4:
            Tips1->setString("右边的是增益条，它表示你拥有某种增益效果的剩余时间");
            ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, BUFFTIME, ADD, 10);
            Tips1->setPositionY(cocos2d::Director::getInstance()->getVisibleSize().height/4);
            Step++;
            ResetTouchTips();
            AddTouchTips();
            break;
        case 5:
            Tips1->setString("这是我们的作战面板");
            Tips1->setPositionY(cocos2d::Director::getInstance()->getVisibleSize().height/5*3);
            System->AddFloorFrame();
            Step++;
            ResetTouchTips();
            AddTouchTips(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/5*4));
            break;
        case 6:
            Tips1->setString("这是顶部的菜单栏，这里不仅可以看到自己的攻击力和防御力，同时也是暂停游戏");
            Tips1->setPositionY(cocos2d::Director::getInstance()->getVisibleSize().height/5*3);
            System->AddTopStatrBar();
            Step++;
            ResetTouchTips();
            AddTouchTips(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/5*4));
            break;
        case 7:
            Tips1->setString("现在出现的是我们的武器，火、水、风、雷、魔法，五种元素");
            Tips1->setPositionY(cocos2d::Director::getInstance()->getVisibleSize().height/5*3);
            System->AddElement();
            Step++;
            ResetTouchTips();
            AddTouchTips(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/5*4));
            break;
        case 8:
            Tips1->setString("火元素为攻击型元素，点击它能释放火球术攻击敌人");
            Step++;
            ResetTouchTips();
            AddTouchTips(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/5*4));
            break;
        case 9:
            Tips1->setString("水元素为治疗型元素，点击它能治疗自己恢复生命值");
            Step++;
            ResetTouchTips();
            AddTouchTips(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/5*4));
            break;
        case 10:
            Tips1->setString("风元素为防护型元素，点击能生成护盾保护自己不受伤害");
            Step++;
            ResetTouchTips();
            AddTouchTips(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/5*4));
            break;
        case 11:
            Tips1->setString("雷元素为功能型元素，点击能增加增益时间并且获得某些特殊增益");
            Step++;
            ResetTouchTips();
            AddTouchTips(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/5*4));
            break;
        case 12:
            Tips1->setString("最后一个为魔法元素，点击它能回复魔法值");
            Step++;
            ResetTouchTips();
            AddTouchTips(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/5*4));
            break;
        case 13:
            Tips1->setString("！！怪物出现！！现在试试用这些元素击败他！");
            Tips1->setPositionY(cocos2d::Director::getInstance()->getVisibleSize().height/40*23);
            System->AddMonster();
            Step++;
            ResetTouchTips();
            AddTouchTips(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,cocos2d::Director::getInstance()->getVisibleSize().height/40*21));
            break;
        case 14:

            System->run();
            this->getParent()->removeChild(this);
            break;
        default:
            break;
    }
//    this->getParent()->addChild(Parent->at(thisNum+1));
//
    return true;
}


void GameInterfaceGuideLayer::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}

void GameInterfaceGuideLayer::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}