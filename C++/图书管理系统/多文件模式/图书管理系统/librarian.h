#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "log.h"
#include "book.h"
using namespace std;

//ͼ�����Ա
class Librarian:public User,public Log
{
public:
    static int Librarian_Number;
    void zc(User *U,Log a,Librarian *L)
    {
        a.SignIN(U);
        cout<<"ע��ɹ���"<<endl;
        Librarian_Number++;
        U[a.number].SetIdentity(0, 1, 0);
        SetIdentity(0, 1, 0);
        User::name=a.tp.Getname();
        User::key=a.tp.Getkey();
        L[Librarian::Librarian_Number].Setname(a.tp.Getname());
    }
    Librarian(){SetIdentity(0, 1, 0);}
    Librarian(string name1,string key1,User *U)
    {
        U[User_Number].Setname(name1);U[User_Number].Setkey(key1);
        U[User_Number].SetIdentity(0, 1, 0);
        SetIdentity(0, 1, 0);
        U->User_Number++;
        name=name1;
        key=key1;
    }
    void Book_Add(Book *B);//����ͼ��
    void Book_Dele(Book *B);//ɾ��ͼ��
    void Book_Alter(Book *B);//�޸�ͼ��
    void Book_Find(Book *B);//����ͼ��
    void Book_AddUp(Book *B);//ͳ��ͼ��
};

#endif
