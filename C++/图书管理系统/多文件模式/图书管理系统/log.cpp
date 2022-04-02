#include "log.h"

void Log::SignIN(User *p)
{
    int f1;string a,b,bb;
    while(1)
    {
        f1=1;
        cout<<"请输入用户名：";
        cin>>a;
        for(int i=0;i<=User::User_Number;i++)
        {
            if(p[i].Getname()==a)
            {
                cout<<"用户名已存在，请重新输入."<<endl;f1=0;
            }
        }
        if(f1==0){};
        if(f1==1) {break;}
    }
    while(1)
    {
        cout<<"请设置密码:";
        cin>>b;
        cout<<"再次输入密码:";
        cin>>bb;
        if(bb!=b)
        {
            cout<<"两次密码不一致，请重新输入."<<endl;
        }
        if(bb==b)
        {
            break;
        }
    }
    //将注册成功的用户信息存储到user类里。
    (p+User::User_Number)->Setname(a);
    (p+User::User_Number)->Setkey(b);
    (p+User::User_Number)->SetIdentity(0, 0, 1);
    tp.Setname(a);
    number=User::User_Number;
    User::User_Number++;
};

void Log::Login(User *p)
{
    string a,b;int flag=0;
    cout<<"请输入账号:"<<endl;
    cin>>a;
    cout<<"请输入密码:"<<endl;
    cin>>b;
    for(int i=0;i<User::User_Number;i++)
    {
        if(a==p[i].Getname()&&b==p[i].Getkey())
        {
            tp.SetIdentity(p[i].GetisAd(), p[i].Getisli(), p[i].Getisre());
            flag=1;tp.Setname(a);tp.Setkey(b);number=i;break;
        }
    }
    if(flag)
    {   if(tp.Judge()==7)
    {   User::LogName=tp.Getname();
        cout<<"登陆成功！"<<endl;Is_Log=true;
        cout<<"尊敬的读者"<<tp.Getname()<<",您好！"<<endl;
    }
    else if(tp.Judge()==5)
    {   User::LogName=tp.Getname();
        cout<<"登陆成功！"<<endl;Is_Log=true;
        cout<<"尊敬的图书管理员"<<tp.Getname()<<",您好！"<<endl;
    }
    else if(tp.Judge()==6)
    {   User::LogName=tp.Getname();
        cout<<"登陆成功！"<<endl;Is_Log=true;
        cout<<"尊敬的系统管理员"<<tp.Getname()<<",您好！"<<endl;
    }
    }
    else {cout<<"账号或密码错误！"<<endl;Is_Log=false;}
}
