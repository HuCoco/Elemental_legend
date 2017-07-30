//
//  MaskNode.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#include "MaskNode.h"
#include "BattleSystem.h"
#include "ElementSystem.h"
#include "SkillFactory.h"
#include "GameSystem.h"
#include "RecordSystem.h"
#include "GameConfigSystem.h"
#include "SuitSystem.h"
#include "EquipmentSystem.h"
#include "GuideSystem.h"
MaskNode::MaskNode()
{
    TouchNum = 0;
}


MaskNode::~MaskNode()
{
    
}

MaskNode* MaskNode::create(INIT_MASKNODE_TYPE _type)
{
    MaskNode* pRet = new MaskNode;
    if(_type == GUIDE_INIT)
    {
        if(pRet && pRet->GuideInit())
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
    else if(_type == NORMAL_INIT)
    {
        if(pRet && pRet->init())
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
    else if(_type == TRAIL_INIT)
    {
        if(pRet && pRet->TrailInit())
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
}

bool MaskNode::init()
{
    if(!Node::init())
    {
        return false;
    }
    isStart = false;
    isOver = false;
    BattleSystem::getInstance()->init(GameSystem::getInsatance()->getGate());
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(MaskNode::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(MaskNode::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(MaskNode::onTouchEnded,this);
    _touchListener->retain();
    for(int i = 0 ; i < 20 ; i++)
    {
        BaseElement* pRet = new BaseElement();
        ElementsMatrix.push_back(pRet);
        ElementsMatrix.back()->initPosition(i);
        ElementsMatrix.back()->AddToParent(this);
        ElementsMatrix.back()->SetTag(i);
        ElementsMatrix.back()->AddToTouchListen(_eventDispatcher, _touchListener);
    }
    this->scheduleUpdate();
    

    return true;
}

bool MaskNode::GuideInit()
{
    if(!Node::init())
    {
        return false;
    }
    isStart = false;
    isOver = false;
    BattleSystem::getInstance()->GuideInit();
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(MaskNode::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(MaskNode::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(MaskNode::onTouchEnded,this);
    
    for(int i = 0 ; i < 20 ; i++)
    {
        BaseElement* pRet = new BaseElement();
        ElementsMatrix.push_back(pRet);
        ElementsMatrix.back()->initPosition(i);
        ElementsMatrix.back()->AddToParent(this);
        ElementsMatrix.back()->SetTag(i);
        ElementsMatrix.back()->AddToTouchListen(_eventDispatcher, _touchListener);
        ElementsMatrix.back()->SetOpacity(0);
    }
    this->scheduleUpdate();
    return true;
}

bool MaskNode::TrailInit()
{
    if(!Node::init())
    {
        return false;
    }
    isStart = false;
    isOver = false;
    BattleSystem::getInstance()->TrailInit();
    _touchListener = cocos2d::EventListenerTouchOneByOne::create();
    _touchListener->setSwallowTouches(true);
    _touchListener->onTouchBegan = CC_CALLBACK_2(MaskNode::onTouchBegan,this);
    _touchListener->onTouchMoved = CC_CALLBACK_2(MaskNode::onTouchMoved,this);
    _touchListener->onTouchEnded = CC_CALLBACK_2(MaskNode::onTouchEnded,this);
    
    for(int i = 0 ; i < 20 ; i++)
    {
        BaseElement* pRet = new BaseElement();
        ElementsMatrix.push_back(pRet);
        ElementsMatrix.back()->initPosition(i);
        ElementsMatrix.back()->AddToParent(this);
        ElementsMatrix.back()->SetTag(i);
        ElementsMatrix.back()->AddToTouchListen(_eventDispatcher, _touchListener);
        //ElementsMatrix.back()->SetOpacity(0);
    }
    this->scheduleUpdate();
    return true;
}

void MaskNode::GuideAddElement()
{
    for(int i = 0 ; i < 20 ; i++)
    {
        ElementsMatrix.at(i)->SetOpacity(255);
    }
}

void MaskNode::Run()
{
    _time = 3;
    std::string timechar = cocos2d::StringUtils::format("%d",_time);
    Time = cocos2d::Label::createWithTTF(timechar, "fonts/arial.ttf", 200);
    Time->setPosition(Director::getInstance()->getVisibleSize()/2);
    te->addChild(Time,99);
    this->schedule(std::bind(&MaskNode::UpdateTime,this),1,"updatetime");
}

void MaskNode::GuideRun()
{
    GameConfigSystem::getInstance()->SetGameSpeed(4);
    _time = 3;
    std::string timechar = cocos2d::StringUtils::format("%d",_time);
    Time = cocos2d::Label::createWithTTF(timechar, "fonts/arial.ttf", 200);
    Time->setPosition(Director::getInstance()->getVisibleSize()/2);
    te->addChild(Time,99);
    this->schedule(std::bind(&MaskNode::UpdateTime,this),1,"updatetime");

}

void MaskNode::UpdateTime()
{
    _time--;
    if(_time > 0)
    {
        std::string timechar = cocos2d::StringUtils::format("%d",_time);
        Time->setString(timechar);
        
    }
    else if(_time == 0)
    {
        Time->setString("Go");
    }
    else if(_time < 0)
    {
        te->removeChild(Time);
        this->unschedule("updatetime");
        this->schedule(std::bind(&MaskNode::UpdateGame,this), "updategame");
        BattleSystem::getInstance()->getMonster()->Cast(this);
        BattleSystem::getInstance()->getMonster()->RunAciton(BattleSystem::getInstance()->getMonster()->GetStayRepeat());
        SuitSystem::getInstance()->ItemEffectInit(EquipmentSystem::getInstance()->GetItemEffectsData());
        
        isStart = true;
    }
}



void MaskNode::UpdateGame()
{
    for (int i = 0; i < 20; i++)
    {
        ElementsMatrix.at(i)->setPosition(cocos2d::Vec2(ElementsMatrix.at(i)->getPosition().x,ElementsMatrix.at(i)->getPosition().y-GameConfigSystem::getInstance()->GetGameSpeed()));
        if(ElementsMatrix.at(i)->OverButton())
        {
            int tag = i + 16 >= 20? i - 4:i+16;
            ElementsMatrix.at(i)->Reback(ElementsMatrix.at(tag)->getPosition());
            ElementsMatrix[i]->ReSetType();
        }
    }
    
}



void MaskNode::visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags)
{
    _beforeVisitCmdScissor.init(_globalZOrder);
    _beforeVisitCmdScissor.func = CC_CALLBACK_0(MaskNode::onBeforeVisitScissor, this);
    renderer->addCommand(&_beforeVisitCmdScissor);
    
    Node::visit(renderer, parentTransform, parentFlags);
    
    _afterVisitCmdScissor.init(_globalZOrder);
    _afterVisitCmdScissor.func = CC_CALLBACK_0(MaskNode::onAfterVisitScissor, this);
    renderer->addCommand(&_afterVisitCmdScissor);
}

void MaskNode::onBeforeVisitScissor()
{
    cocos2d::Point pos = cocos2d::Point(0,0);
    pos = this->convertToNodeSpace(pos);
    
    cocos2d::Rect clippingRect = cocos2d::Rect(pos.x,pos.y,cocos2d::Director::getInstance()->getVisibleSize().width/18*17,cocos2d::Director::getInstance()->getVisibleSize().width/9*8);
    glEnable(GL_SCISSOR_TEST);
    auto glview = cocos2d::Director::getInstance()->getOpenGLView();
    glview->setScissorInPoints(clippingRect.origin.x, clippingRect.origin.y, clippingRect.size.width, clippingRect.size.height);
}

void MaskNode::onAfterVisitScissor()
{
    glDisable(GL_SCISSOR_TEST);
}

void MaskNode::TouchWithTips(ELEMENT_TYPE _t)
{
    if(_LastType != _t)
    {
        if(GameSystem::getInsatance()->isRunning())
        {
            GameSystem::getInsatance()->GetTipsInstance()->ChangeIcon(_t);
        }
        else if(GuideSystem::getInstance()->isRunning())
        {
            GuideSystem::getInstance()->GetTipsInstance()->ChangeIcon(_t);
        }
    }
    else
    {
        if(GameSystem::getInsatance()->isRunning())
        {
            GameSystem::getInsatance()->GetTipsInstance()->SetTouchTimes(TouchNum);
        }
        else if(GuideSystem::getInstance()->isRunning())
        {
            GuideSystem::getInstance()->GetTipsInstance()->SetTouchTimes(TouchNum);
        }
        
    }
}

bool MaskNode::onTouchBegan(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    if(!isStart || isOver)
    {
        return false;
    }
    
    cocos2d::Sprite* TagSprite = static_cast<cocos2d::Sprite*>(_event->getCurrentTarget());
    cocos2d::Rect rect = cocos2d::Rect(0,0,TagSprite->getContentSize().width,TagSprite->getContentSize().height);
    cocos2d::Point _touchPoint = TagSprite->convertToNodeSpace(_touch->getLocation());
    if(_touchPoint.y >= 800)
    {
        return true;
    }
    if(rect.containsPoint(_touchPoint))
    {
        
        cocos2d::log("%d",TagSprite->getTag());
        if(TagSprite->getOpacity() != 0)
        { 
            ELEMENT_TYPE _type = ElementsMatrix.at(TagSprite->getTag())->getElementType();
            if(_type == _LastType)
            {
                TouchNum++;
            }
            else
            {
                TouchNum = 1;
            }
            switch (_type) {
                case ET_FIRE:
                    if(BattleSystem::getInstance()->PlayerCastSkill(SN_FIRE, te, TagSprite->getPosition(), TouchNum))
                    {
                        TagSprite->setOpacity(0);
                        TouchWithTips(_type);
                        RecordSystem::getInstance()->AddData(_type);
                        ElementSystem::getInstance()->UpdateOdds(_type);
                        SuitSystem::getInstance()->CastEffects(TouchNum, _type, this);
                        _LastType = _type;
                    }
                    break;
                case ET_THUNDER:
                    if(BattleSystem::getInstance()->PlayerCastSkill(SN_THUNDER, te, TagSprite->getPosition(), TouchNum))
                    {
                        TagSprite->setOpacity(0);
                        TouchWithTips(_type);
                        RecordSystem::getInstance()->AddData(_type);
                        ElementSystem::getInstance()->UpdateOdds(_type);
                        SuitSystem::getInstance()->CastEffects(TouchNum, _type, this);
                        _LastType = _type;
                    }
                    break;
                case ET_WATER:
                    if(BattleSystem::getInstance()->PlayerCastSkill(SN_WATER, te, TagSprite->getPosition(), TouchNum))
                    {
                        TagSprite->setOpacity(0);
                        TouchWithTips(_type);
                        RecordSystem::getInstance()->AddData(_type);
                        ElementSystem::getInstance()->UpdateOdds(_type);
                        SuitSystem::getInstance()->CastEffects(TouchNum, _type, this);
                        _LastType = _type;
                    }
                    break;
                case ET_WIND:
                    if(BattleSystem::getInstance()->PlayerCastSkill(SN_WIND, te, TagSprite->getPosition(), TouchNum))
                    {
                        TagSprite->setOpacity(0);
                        TouchWithTips(_type);
                        RecordSystem::getInstance()->AddData(_type);
                        ElementSystem::getInstance()->UpdateOdds(_type);
                        SuitSystem::getInstance()->CastEffects(TouchNum, _type, this);
                        _LastType = _type;
                    }
                    break;
                case ET_MAGIC:
                    if(BattleSystem::getInstance()->PlayerCastSkill(SN_MAGIC, te, TagSprite->getPosition(), TouchNum))
                    {
                        TagSprite->setOpacity(0);
                        TouchWithTips(_type);
                        RecordSystem::getInstance()->AddData(_type);
                        ElementSystem::getInstance()->UpdateOdds(_type);
                        SuitSystem::getInstance()->CastEffects(TouchNum, _type, this);
                        _LastType = _type;
                    }
                default:
                    break;
            }
            

            
        }
        
        return true;
    }
    return false;
}


void MaskNode::onTouchMoved(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
                                                                                                                                                                        
}

void MaskNode::onTouchEnded(cocos2d::Touch *_touch, cocos2d::Event *_event)
{
    
}














