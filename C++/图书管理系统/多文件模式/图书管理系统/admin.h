#ifndef ADMIN_H
#define ADMIN_H

#include "log.h"
#include "reader.h"
#include "librarian.h"

//系统管理员
class Admin:public User,public Log
{
public:
    void Reader_Add(User *U,Reader *R);//添加读者
    void Reader_Dele(User *U,Reader *R);//删除读者
    void Librarian_Add(User *U,Librarian *L);//添加图书管理员
    void Librarian_Dele(User *U,Librarian *L);//删除图书管理员
    void Reader_Alter(Reader *R,User *U,Admin *A,Librarian *L);//读者权限更改
    void Librarian_Alter(Librarian *L,User *U,Admin *A,Reader *R);//图书管理员权限更改
    void User_keychange(User *U);//修改用户密码
    static int Admin_Number;
    Admin(){Is_Admin=1;Is_Librarian=0;Is_Reader=0;};
    Admin(string name1,string key1,User *U)
    {   U[U->User_Number].Setname(name1);
        U[U->User_Number].Setkey(key1);
        Is_Admin=1;Is_Librarian=0;Is_Reader=0;
        U[U->User_Number].SetIdentity(1, 0, 0);
        U->User_Number++;
        name=name1;
        key=key1;
    }
};

#endif
