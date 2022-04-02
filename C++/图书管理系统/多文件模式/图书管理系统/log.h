#ifndef LOG_H
#define LOG_H

#include "user.h"
using namespace std;

class Log
{
public:
    User tp;//存储登陆成功的用户的信息
    int number;//存储当前用户信息对应的User类中下标值
    void Login(User *p);//登陆
    void SignIN(User *p);//注册
    Log(){number=0;};
    bool Is_Log;//判断是否登陆成功。
};

#endif
