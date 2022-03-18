#include "admin.h"

int Admin::Admin_Number=1;

void Admin::User_keychange(User *U)
{
    
    int find=0;string Name,key,key1;
    bool is_find=false;
    cout<<"请输入用户名:";
    cin>>Name;
    for(int i=0;i<User::User_Number;i++)
    {
        if(U[i].Getname()==Name)
        {
            find=i;is_find=true;break;
        }
    }
    
    if(is_find==true)
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
        cout<<"未找到该用户."<<endl;
    }
}

//读者权限修改
void Admin::Reader_Alter(Reader *R,User *U,Admin *A,Librarian *L)
{   string name,key;
    string a;cout<<"请输入需要进行操作的读者用户名:";cin>>a;
    int flag=0,find=0;
    for(int i=0;i<Reader::Reader_Number;i++)
    {
        if(R[i].Getname()==a){
            flag=1;find=i;name=R[i].Getname();key=R[i].Getkey();break;
        }
    }
    
    if(flag)
    {
        int t=0;
        cout<<"请选择需要变更的权限类型:"<<endl;
        cout<<"①图书管理员"<<endl;
        cout<<"②系统管理员"<<endl;
        cout<<"③返回"<<endl;
        cin>>a;
        if(a=="1")
        {
            t=1;
        }
        else if(a=="2")
        {
            t=2;
        }
        else
        {
            cout<<"返回成功!"; t=0;
        }
        if(t==1||t==2)
        {
            for(int j=find;j<Reader::Reader_Number;j++)
            {
                if(j==Reader::Reader_Number-1){Reader::Reader_Number--;break;}
                R[j]=R[j+1];
            }
            if(t==1)
            {
                for(int j=0;j<U->User_Number;j++)
                {
                    if(U[j].Getname()==name){
                        U[j].SetIdentity(0, 1, 0);
                        break;}
                }
                L[Librarian::Librarian_Number].Setname(name);
                L[Librarian::Librarian_Number].Setkey(key);
                L[Librarian::Librarian_Number].SetIdentity(0, 1, 0);
                L->Librarian_Number++;
            }
            
            if(t==2)
            {
                for(int j=0;j<U->User_Number;j++)
                {
                    if(U[j].Getname()==name){
                        U[j].SetIdentity(1, 0, 0);
                        break;}
                }
                A[Admin::Admin_Number].Setname(name);
                A[Admin::Admin_Number].Setkey(key);
                A[Admin::Admin_Number].SetIdentity(1, 0, 0);
                A->Admin_Number++;
            }
            cout<<"变更成功!"<<endl;
        }
    }
    else    cout<<"读者用户不存在！"<<endl;
}

//图书管理员权限修改
void Admin::Librarian_Alter(Librarian *L,User *U,Admin *A,Reader *R)
{
    string name,key;
    string a;cout<<"请输入需要进行操作的图书管理员用户名:";cin>>a;
    int flag=0,find=0;
    for(int i=0;i<Librarian::Librarian_Number;i++)
    {
        if(L[i].Getname()==a){
            flag=1;find=i;name=L[i].Getname();key=L[i].Getkey();break;
        }
    }
    
    if(flag)
    {
        int t=0;
        cout<<"请选择需要变更的权限类型:"<<endl;
        cout<<"①读者"<<endl;
        cout<<"②系统管理员"<<endl;
        cout<<"③返回"<<endl;
        cin>>a;
        if(a=="1")
        {
            t=1;
        }
        else if(a=="2")
        {
            t=2;
        }
        else
        {
            cout<<"返回成功!"; t=0;
        }
        if(t==1||t==2)
        {
            for(int j=find;j<Librarian::Librarian_Number;j++)
            {
                if(j==Librarian::Librarian_Number-1){Librarian::Librarian_Number--;break;}
                L[j]=L[j+1];
            }
            if(t==1)
            {
                for(int j=0;j<U->User_Number;j++)
                {
                    if(U[j].Getname()==name){
                        U[j].SetIdentity(0, 0, 1);
                        break;}
                }
                R[Reader::Reader_Number].Setname(name);
                R[Reader::Reader_Number].Setkey(key);
                R[Reader::Reader_Number].SetIdentity(0, 0, 1);
                R->Reader_Number++;
            }
            
            if(t==2)
            {
                for(int j=0;j<U->User_Number;j++)
                {
                    if(U[j].Getname()==name){
                        U[j].SetIdentity(1, 0, 0);
                        break;}
                }
                A[Admin::Admin_Number].Setname(name);
                A[Admin::Admin_Number].Setkey(key);
                A[Admin::Admin_Number].SetIdentity(1, 0, 0);
                A->Admin_Number++;
            }
            cout<<"变更成功!"<<endl;
        }
    }
    else    cout<<"读者用户不存在！"<<endl;
}

//增加读者
void Admin::Reader_Add(User *U,Reader *R)
{   Log a;
    R[Reader::Reader_Number].zc(U, a,R);
}

//增加图书管理员
void Admin::Librarian_Add(User *U,Librarian *L)
{   Log a;
    L[Librarian::Librarian_Number].zc(U, a,L);
}

//删除读者
void Admin::Reader_Dele(User *U,Reader *R)
{
    string a;
    cout<<"请输入需要进行操作的用户名:";cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0;i<Reader::Reader_Number;i++)
    {
        if(R[i].Getname()==a){
            flag=1;find=i;break;
        }
    }
    if(flag)
    {
        for(int j=find;j<Reader::Reader_Number;j++)
        {
            if(j==Reader::Reader_Number-1){Reader::Reader_Number--;break;}
            R[j]=R[j+1];
        }
        for(int j=0;j<U->User_Number;j++)
        {
            if(U[j].Getname()==a){find1=j;break;}
        }
        for(int j=find1;j<U->User_Number;j++)
        {
            if(j==U->User_Number-1){U->User_Number--;break;}
            U[j]=U[j+1];
        }
        cout<<"删除成功！"<<endl;
    }
    else    cout<<"用户不存在！"<<endl;
}

//删除图书管理员
void Admin::Librarian_Dele(User *U,Librarian *L)
{
    string a;
    cout<<"请输入需要进行操作的用户名:";cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0;i<Librarian::Librarian_Number;i++)
    {
        if(L[i].Getname()==a){
            flag=1;find=i;break;
        }
        
    }
    if(flag)
    {
        for(int j=find;j<Librarian::Librarian_Number;j++)
        {
            if(j==Librarian::Librarian_Number-1){Librarian::Librarian_Number--;break;}
            L[j]=L[j+1];
        }
        for(int k=0;k<U->User_Number;k++)
        {
            if(U[k].Getname()==a)
            {
                find1=k;break;
            }
        }
        for(int j=find1;j<U->User_Number;j++)
        {
            if(j==U->User_Number-1){U->User_Number--;break;}
            U[j]=U[j+1];
        }
        cout<<"删除成功！"<<endl;
    }
    else    cout<<"用户不存在！"<<endl;
}
