//
//  MyLog.h
//  NewGame
//
//  Created by 胡可 on 15/9/25.
//
//

#ifndef MyLog_h
#define MyLog_h

#include <stdio.h>
#include "cocos2d.h"

class MyLog
{
private:
    MyLog();
    ~MyLog();
public:
    static MyLog* getInstance();
public:
    void log(const char* format);
    void log(const char* format,float data);
    void log(const char* format,int data);
    void LogState(bool);
private:
    static MyLog* _instance;
    bool _bLogSwitch;
};



#endif /* MyLog_h */
