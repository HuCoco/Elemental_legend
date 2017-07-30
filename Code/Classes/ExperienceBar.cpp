//
//  ExperienceBar.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/21.
//
//

#include "ExperienceBar.h"
#include "ExperienceSystem.h"
ExperienceBar::ExperienceBar()
{

}


ExperienceBar::~ExperienceBar()
{
    
}

ExperienceBar* ExperienceBar::create()
{
    ExperienceBar* pRet = new ExperienceBar;
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

bool ExperienceBar::init()
{
    if(!cocos2d::Node::init())
    {
        return false;
    }
    //ExperienceSystem::getInstance()->UpdateData();
    MaxExp = ExperienceSystem::getInstance()->getMaxExp();
    NowExp = ExperienceSystem::getInstance()->getNowExp();
    
    
    ExpBarInit();
    
    return true;
}

void ExperienceBar::ExpBarInit()
{
    
    if(MaxExp<=5)
    {
        for(int i = 0;i < MaxExp;i++)
        {
            cocos2d::Sprite* SkillSign = cocos2d::Sprite::create("UI/kill_sign.png");
            float LengthMax = MaxExp * SkillSign->getContentSize().width + (MaxExp - 1) * 10;
            SkillSign->setPosition(-LengthMax/2 + SkillSign->getContentSize().width/2 + (SkillSign->getContentSize().width + 10) * i,0);
            if(i+1 <= NowExp)
            {
                cocos2d::Sprite* SkillSignPass = cocos2d::Sprite::create("UI/kill_sign_pass.png");
                SkillSignPass->setPosition(SkillSign->getContentSize()/2);
                SkillSign->addChild(SkillSignPass);
                PassPool.push_back(SkillSignPass);
            }
            SkillSignPool.push_back(SkillSign);
            this->addChild(SkillSignPool.back());
        }
    }
    else
    {
        for(int i = 0;i < 5;i++)
        {
            cocos2d::Sprite* SkillSign = cocos2d::Sprite::create("UI/kill_sign.png");
            float LengthMax = 5 * SkillSign->getContentSize().width + 4 * 10;
            SkillSign->setPosition(-LengthMax/2 + SkillSign->getContentSize().width/2 + (SkillSign->getContentSize().width + 10) * i,SkillSign->getContentSize().height/2);
            if(i+1 <= NowExp)
            {
                cocos2d::Sprite* SkillSignPass = cocos2d::Sprite::create("UI/kill_sign_pass.png");
                SkillSignPass->setPosition(SkillSign->getContentSize()/2);
                SkillSign->addChild(SkillSignPass,1,"pass");
                PassPool.push_back(SkillSignPass);
            }
            SkillSignPool.push_back(SkillSign);
            this->addChild(SkillSignPool.back());
        }
        for(int i=0;i<MaxExp-5;i++)
        {
            cocos2d::Sprite* SkillSign = cocos2d::Sprite::create("UI/kill_sign.png");
            float LengthMax = (MaxExp-5) * SkillSign->getContentSize().width + (MaxExp-6) * 10;
            SkillSign->setPosition(-LengthMax/2 + SkillSign->getContentSize().width/2 + (SkillSign->getContentSize().width + 10) * i,-SkillSign->getContentSize().height/2);
            if(i+1 <= NowExp-5)
            {
                cocos2d::Sprite* SkillSignPass = cocos2d::Sprite::create("UI/kill_sign_pass.png");
                SkillSignPass->setPosition(SkillSign->getContentSize()/2);
                SkillSign->addChild(SkillSignPass,1,"pass");
                PassPool.push_back(SkillSignPass);
            }
            SkillSignPool.push_back(SkillSign);
            this->addChild(SkillSignPool.back());
        }
    }
    
}

void ExperienceBar::AddExp()
{
    cocos2d::Sprite* SkillSignPass = cocos2d::Sprite::create("UI/kill_sign_pass.png");
    SkillSignPass->setScale(10);
    SkillSignPass->setPosition(0,-500);
    SkillSignPass->setOpacity(0);
    cocos2d::FadeIn* _fadein = cocos2d::FadeIn::create(0.5f);
    cocos2d::MoveTo* _moveto = cocos2d::MoveTo::create(0.5f,cocos2d::Vec2(SkillSignPool.at(NowExp)->getContentSize()/2));
    cocos2d::ScaleTo* _scaleto = cocos2d::ScaleTo::create(0.5f, 1);
    cocos2d::Spawn* _spwan = cocos2d::Spawn::create(_fadein,_moveto,_scaleto,NULL);
    SkillSignPool.at(NowExp)->addChild(SkillSignPass,1,"pass");
    PassPool.push_back(SkillSignPass);
    SkillSignPass->runAction(_spwan);
    if(ExperienceSystem::getInstance()->AddExp())
    {
        cocos2d::Sprite* LevelUp = cocos2d::Sprite::create("UI/level_up.png");
        LevelUp->setScale(0.01f);
        this->addChild(LevelUp);
        cocos2d::CallFunc* callback = cocos2d::CallFunc::create(std::bind([=]
                                                                          {
                                                                              cocos2d::FadeOut* _fadeout = cocos2d::FadeOut::create(0.2f);
                                                                              //SkillSignPool.at(NowExp)->getChildByName("pass")->runAction(_fadeout->clone());
                                                                              for(int i = 0;i<SkillSignPool.size();i++)
                                                                              {
                                                                                  SkillSignPool.at(i)->runAction(_fadeout->clone());
                                                                              }
                                                                              for(int i = 0;i<PassPool.size();i++)
                                                                              {
                                                                                  PassPool.at(i)->runAction(_fadeout->clone());
                                                                              }
                                                                          }));
        cocos2d::DelayTime* timewait1 = cocos2d::DelayTime::create(1.0f);
        cocos2d::DelayTime* timewait2 = cocos2d::DelayTime::create(0.3f);
        cocos2d::ScaleTo* levelScaleTo1 = cocos2d::ScaleTo::create(0.3f, 1);
        cocos2d::EaseElasticInOut* action1 = cocos2d::EaseElasticInOut::create(levelScaleTo1);
        cocos2d::Sequence* AcitonSeq = cocos2d::Sequence::create(timewait1,callback,timewait2,action1, NULL);
        
        LevelUp->runAction(AcitonSeq);
    }
}
