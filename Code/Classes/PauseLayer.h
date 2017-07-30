//
//  PauseLayer.h
//  NewGame
//
//  Created by 胡可 on 15/10/15.
//
//

#ifndef PauseLayer_h
#define PauseLayer_h


#include "cocos2d.h"

class PauseLayer
:public cocos2d::Layer
{
private:
    PauseLayer();
    ~PauseLayer();
    virtual bool init();
    void GoToHomeScene();
    void ResumeGame();
public:
    CREATE_FUNC(PauseLayer);
private:
    cocos2d::MenuItemImage* _homebtn;
    cocos2d::MenuItemImage* _resumebtn;
    cocos2d::Menu* _menu;
};

#endif /* PauseLayer_h */
