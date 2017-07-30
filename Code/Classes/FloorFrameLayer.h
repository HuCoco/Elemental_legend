//
//  FloorFrameLayer.h
//  NewGame
//
//  Created by 胡可 on 15/10/24.
//
//

#ifndef FloorFrameLayer_h
#define FloorFrameLayer_h


#include "cocos2d.h"
#include <cocos-ext.h>

class FloorFrameLayer
:public cocos2d::Layer
{
private:
    FloorFrameLayer();
    ~FloorFrameLayer();
    virtual bool init();
public:
    CREATE_FUNC(FloorFrameLayer);
private:
    cocos2d::ui::Scale9Sprite* _floor;
    cocos2d::ui::Scale9Sprite* _frame;
};
#endif /* FloorFrameLayer_h */
