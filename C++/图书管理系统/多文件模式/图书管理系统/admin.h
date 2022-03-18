#ifndef ADMIN_H
#define ADMIN_H

#include "log.h"
#include "reader.h"
#include "librarian.h"

//ϵͳ����Ա
class Admin:public User,public Log
{
public:
    void Reader_Add(User *U,Reader *R);//��Ӷ���
    void Reader_Dele(User *U,Reader *R);//ɾ������
    void Librarian_Add(User *U,Librarian *L);//���ͼ�����Ա
    void Librarian_Dele(User *U,Librarian *L);//ɾ��ͼ�����Ա
    void Reader_Alter(Reader *R,User *U,Admin *A,Librarian *L);//����Ȩ�޸���
    void Librarian_Alter(Librarian *L,User *U,Admin *A,Reader *R);//ͼ�����ԱȨ�޸���
    void User_keychange(User *U);//�޸��û�����
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
