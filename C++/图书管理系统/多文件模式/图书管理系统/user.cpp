#include "user.h"

int User::User_Number=0;
string User::LogName;

void User::key_change(User *U)
{
    int find=0;string key,key1;
    for(int i=0;i<User::User_Number;i++)
    {
        if(U[i].Getname()==LogName)
        {
            find=i;break;
        }
    }
    cout<<"请输入原密码:";
    cin>>key;
    if(key==U[find].Getkey())
    {
        cout<<"请输入新密码:";
        cin>>key;
        cout<<"再输入一次新密码:";
        cin>>key1;
        if(key==key1)
        {
            U[find].Setkey(key);
            cout<<"修改成功！"<<endl;
        }
        else
        {
            cout<<"两次密码输入不一致,修改失败!"<<endl;
        }
    }
    else
    {
        cout<<"密码错误！"<<endl;
    }
}

int User::Judge()
{
    if(Is_Librarian==1)return 5;
    else if(Is_Admin==1)return 6;
    else return 7;
};

void User::Setname(string name1)
{
    name=name1;
};

void User::Setkey(string key1)
{
    key=key1;
};
