#include "log.h"

void Log::SignIN(User *p)
{
    int f1;string a,b,bb;
    while(1)
    {
        f1=1;
        cout<<"�������û�����";
        cin>>a;
        for(int i=0;i<=User::User_Number;i++)
        {
            if(p[i].Getname()==a)
            {
                cout<<"�û����Ѵ��ڣ�����������."<<endl;f1=0;
            }
        }
        if(f1==0){};
        if(f1==1) {break;}
    }
    while(1)
    {
        cout<<"����������:";
        cin>>b;
        cout<<"�ٴ���������:";
        cin>>bb;
        if(bb!=b)
        {
            cout<<"�������벻һ�£�����������."<<endl;
        }
        if(bb==b)
        {
            break;
        }
    }
    //��ע��ɹ����û���Ϣ�洢��user���
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
    cout<<"�������˺�:"<<endl;
    cin>>a;
    cout<<"����������:"<<endl;
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
        cout<<"��½�ɹ���"<<endl;Is_Log=true;
        cout<<"�𾴵Ķ���"<<tp.Getname()<<",���ã�"<<endl;
    }
    else if(tp.Judge()==5)
    {   User::LogName=tp.Getname();
        cout<<"��½�ɹ���"<<endl;Is_Log=true;
        cout<<"�𾴵�ͼ�����Ա"<<tp.Getname()<<",���ã�"<<endl;
    }
    else if(tp.Judge()==6)
    {   User::LogName=tp.Getname();
        cout<<"��½�ɹ���"<<endl;Is_Log=true;
        cout<<"�𾴵�ϵͳ����Ա"<<tp.Getname()<<",���ã�"<<endl;
    }
    }
    else {cout<<"�˺Ż��������"<<endl;Is_Log=false;}
}
