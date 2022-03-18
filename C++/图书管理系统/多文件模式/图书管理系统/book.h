#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h> 
using namespace std;

//�鱾��
class Book
{
protected:
    string isbn;//��׼���� 
	string name;//���� 
	string author;//���� 
	string publisher;//������ 
	string time;//���� 
    int deadline;//��������
    double price;//�۸�
    bool Is_Lend;//���Ƿ񱻽��
    
public:
    bool Is_teacher;
    static int Book_Number;
    Book(string c,string n,string a,string p,double pr)
    {
        isbn=c;
		name=n;
		author=a;
		publisher=p;
        price =pr;
		Is_Lend=0;
		Book_Number++;
    };
    Book(){Is_Lend=false;}
    string Gettime(){return time;}
    string GetIsbn(){return isbn;}
    string GetName(){return name;}
    string GetAuthor(){return author;}
    string GetPub(){return publisher;}
    int GetDeadline(){return deadline;}
    double GetPrice(){return price;}
    bool GetIs_Lend(){return Is_Lend;}
    void SetDeadline(int);
    void SetTime(string);
    void SetIs_Lend(bool);
    void SetIsbn(string);
    void SetName(string);
    void SetAuthor(string);
    void SetPub(string);
    void SetPrice(float);
    void Display();
    friend const std::string getCurrentSystemTime();//��ȡ���ڵ�ʱ��
    friend istream& operator >> (istream &stream,Book &b);//���ز�����>>
    friend ostream& operator << (ostream &stream,Book &b);//���ز�����<<
};

const string getCurrentSystemTime();

#endif
