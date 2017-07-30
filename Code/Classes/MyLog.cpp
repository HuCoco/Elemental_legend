//
//  MyLog.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/25.
//
//

#include "MyLog.h"

MyLog* MyLog::_instance = new MyLog;

MyLog::MyLog()
{
    _bLogSwitch = true;
}



MyLog::~MyLog()
{
    
}

MyLog* MyLog::getInstance()
{
    return _instance;
}


void MyLog::log(const char *format)
{
    if(!_bLogSwitch)
    {
        return;
    }
    cocos2d::log(format,NULL);
}

void MyLog::log(const char *format, float data)
{
    if(!_bLogSwitch)
    {
        return;
    }
    cocos2d::log(format,data);
}

void MyLog::log(const char *format, int data)
{
    if(!_bLogSwitch)
    {
        return;
    }
    cocos2d::log(format,data);
}


void MyLog::LogState(bool _bSwitch)
{
    _bLogSwitch = _bSwitch;
}