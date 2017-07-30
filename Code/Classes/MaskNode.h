 //
//  MaskNode.h
//  NewGame
//
//  Created by 胡可 on 15/9/28.
//
//

#ifndef MaskNode_h
#define MaskNode_h


#include "cocos2d.h"
#include "BaseElement.h"

enum INIT_MASKNODE_TYPE
{
    NORMAL_INIT,
    TRAIL_INIT,
    GUIDE_INIT
};


class MaskNode
:public cocos2d::Node
{
private:
    MaskNode();
    ~MaskNode();
    virtual bool init();
    virtual bool GuideInit();
    virtual bool TrailInit();
    virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags);
    void onAfterVisitScissor();
    void onBeforeVisitScissor();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    void UpdateTime();
    void TouchWithTips(ELEMENT_TYPE);
public:
    static MaskNode* create(INIT_MASKNODE_TYPE = NORMAL_INIT);
    void UpdateGame();
    void Run();
    void GuideRun();
    void GuideAddElement();
    void Test(cocos2d::Layer* _t) {te = _t;}
    void SetOver(bool _over){isOver = _over;}
    
private:
    std::vector<BaseElement*> ElementsMatrix;
    int TouchNum;
    int _time;
private:
    cocos2d::CustomCommand _beforeVisitCmdScissor;
    cocos2d::CustomCommand _afterVisitCmdScissor;
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    cocos2d::Layer* te;
    cocos2d::Label* Time;
    ELEMENT_TYPE _LastType;
    bool isStart;
    bool isOver;
};


#endif /* MaskNode_h */
