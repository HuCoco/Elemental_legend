//
//  LoadingLayer.h
//  NewGame
//
//  Created by 胡可 on 15/11/8.
//
//

#ifndef LoadingLayer_h
#define LoadingLayer_h

#include <stdio.h>
#include "cocos2d.h"

class LoadingLayer
:public cocos2d::Layer
{
private:
    LoadingLayer();
    ~LoadingLayer();
    virtual bool init();
    void StartGameBtnCallBack();
public:
    CREATE_FUNC(LoadingLayer);
};
#endif /* LoadingLayer_h */
