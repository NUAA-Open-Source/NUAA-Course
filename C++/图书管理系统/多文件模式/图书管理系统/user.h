#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

//用户类
class User
{
protected:
    string name;//用户姓名
    string key;//用户密码
    bool Is_Admin,Is_Librarian,Is_Reader;//用户类型
public:
    void key_change(User *U);//修改用户密码
    int  Judge();//判断用户类型
    static int User_Number;
	static string LogName;//记录当前登陆用户的用户名
    User(){Is_Admin=0;Is_Librarian=0;Is_Reader=1;};//默认读者类型
    void Setname(string name1);
    void Setkey(string key1);
    void SetIdentity(bool ad,bool li,bool re )//设置用户类型
    {Is_Admin=ad;Is_Reader=re;Is_Librarian=li;}
    string Getname(){return name;}
    string Getkey(){return key;}
    bool GetisAd(){return Is_Admin;}
    bool Getisli(){return Is_Librarian;}
    bool Getisre(){return Is_Reader;}
};

#endif
