//
//  ChapterBar.h
//  NewGame
//
//  Created by 胡可 on 15/11/6.
//
//

#ifndef ChapterBar_h
#define ChapterBar_h

#include "cocos2d.h"
#include <cocos-ext.h>

enum CHAPTER_BAR_TOUCH_EVENT
{
    TOUCH_NOTING_IN_CHAPTER_BAR,
    TOUCH_MOVE_IN_CHAPTER_BAR,
    TOUCH_CHAPTER
};

struct CHAPTER_DATA
{
    cocos2d::ui::Scale9Sprite* _chapterSpirte;
    bool _isOpen;
};

class ChapterBar
:public cocos2d::Layer
{
private:
    ChapterBar();
    ~ChapterBar();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    void Open();
    void Close();
public:
    CREATE_FUNC(ChapterBar);
private:
    cocos2d::EventListenerTouchOneByOne* _touchListener;
    cocos2d::ui::Scale9Sprite* _floor;
    std::vector<CHAPTER_DATA> ChapterPool;
    CHAPTER_BAR_TOUCH_EVENT _touchEvent;
    cocos2d::Point NowPoint;
    cocos2d::Point LastPoint;
    bool _isOpen;
};

#endif /* ChapterBar_h */
