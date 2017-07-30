//
//  FireConfig.h
//  NewGame
//
//  Created by 胡可 on 15/10/11.
//
//

#ifndef FireConfig_h
#define FireConfig_h


#include "TalentConfig.h"
#include "CsvParser.h"
class FireConfig
:public TalentConfig
{
protected:
    FireConfig();
    ~FireConfig();
    virtual bool init();
    virtual bool onTouchBegan(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchMoved(cocos2d::Touch* _touch,cocos2d::Event* _event);
    virtual void onTouchEnded(cocos2d::Touch* _touch,cocos2d::Event* _event);
    void Change(int _num);
public:
    CREATE_FUNC(FireConfig);


};

#endif /* FireConfig_h */
