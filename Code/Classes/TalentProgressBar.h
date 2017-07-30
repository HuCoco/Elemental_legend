//
//  TalentProgressBar.h
//  NewGame
//
//  Created by 胡可 on 15/10/21.
//
//

#ifndef TalentProgressBar_h
#define TalentProgressBar_h


#include "cocos2d.h"
#include "BaseElement.h"
#include <cocos-ext.h>
class TalentProgressBar
:public cocos2d::ui::Scale9Sprite
{
private:
    TalentProgressBar();
    ~TalentProgressBar();
    virtual bool init(ELEMENT_TYPE _type,int _progress);
public:
    static TalentProgressBar* create(ELEMENT_TYPE _type,int _progress);
    void InitData();
private:
    float _odd;
};

#endif /* TalentProgressBar_h */
