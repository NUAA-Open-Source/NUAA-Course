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
    cout<<"������ԭ����:";
    cin>>key;
    if(key==U[find].Getkey())
    {
        cout<<"������������:";
        cin>>key;
        cout<<"������һ��������:";
        cin>>key1;
        if(key==key1)
        {
            U[find].Setkey(key);
            cout<<"�޸ĳɹ���"<<endl;
        }
        else
        {
            cout<<"�����������벻һ��,�޸�ʧ��!"<<endl;
        }
    }
    else
    {
        cout<<"�������"<<endl;
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
