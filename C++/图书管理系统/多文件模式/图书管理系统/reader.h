#ifndef READER_H 
#define READER_H

#include "log.h"
#include "book.h"

//����
class Reader:public User,public Log,public Book
{
    Book s[100];
public:
    void zc(User *U,Log a,Reader *R)
    {
        a.SignIN(U);
        cout<<"�Ƿ�Ϊ��ʦ�û���(y or n)";
        string c;
        cin>>c;
        if(c=="y")R[a.number].Is_teacher=true;
        else R[a.number].Is_teacher=false;
        cout<<"ע��ɹ���"<<endl;
        U[a.number].SetIdentity(0, 0, 1);
        SetIdentity(0, 0, 1);
        User::Setname(a.tp.Getname());
        User::Setkey(a.tp.Getkey());
        R[Reader::Reader_Number].Setname(a.tp.Getname());
        Reader::Reader_Number++;
    }
    static int Reader_Number;
    void Book_Lend(Book *B);
    void Book_Return(Book *B);
    void Book_LR();
    void Book_show(Book *B);
    Reader():User(){User::Is_Admin=0;User::Is_Librarian=0;User::Is_Reader=1;}
};

#endif
