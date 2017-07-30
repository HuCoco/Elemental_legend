//
//  GameInterfaceGuideLayer.h
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#ifndef GameInterfaceGuideLayer_h
#define GameInterfaceGuideLayer_h

#include <stdio.h>
#include "BaseGuideLayer.h"

class GameInterfaceGuideLayer
:public BaseGuideLayer
{
private:
    GameInterfaceGuideLayer();
    ~GameInterfaceGuideLayer();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
public:
    CREATE_FUNC_RETAIN(GameInterfaceGuideLayer);
private:
    cocos2d::Label* Tips1;
    int Step;
};


#endif /* GameInterfaceGuideLayer_h */
