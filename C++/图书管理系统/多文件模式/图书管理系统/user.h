#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

//�û���
class User
{
protected:
    string name;//�û�����
    string key;//�û�����
    bool Is_Admin,Is_Librarian,Is_Reader;//�û�����
public:
    void key_change(User *U);//�޸��û�����
    int  Judge();//�ж��û�����
    static int User_Number;
	static string LogName;//��¼��ǰ��½�û����û���
    User(){Is_Admin=0;Is_Librarian=0;Is_Reader=1;};//Ĭ�϶�������
    void Setname(string name1);
    void Setkey(string key1);
    void SetIdentity(bool ad,bool li,bool re )//�����û�����
    {Is_Admin=ad;Is_Reader=re;Is_Librarian=li;}
    string Getname(){return name;}
    string Getkey(){return key;}
    bool GetisAd(){return Is_Admin;}
    bool Getisli(){return Is_Librarian;}
    bool Getisre(){return Is_Reader;}
};

#endif
