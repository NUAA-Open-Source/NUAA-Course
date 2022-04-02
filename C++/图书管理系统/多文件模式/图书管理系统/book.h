#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h> 
using namespace std;

//书本类
class Book
{
protected:
    string isbn;//标准代号 
	string name;//书名 
	string author;//作者 
	string publisher;//出版社 
	string time;//日期 
    int deadline;//借书期限
    double price;//价格
    bool Is_Lend;//书是否被借出
    
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
    friend const std::string getCurrentSystemTime();//获取现在的时间
    friend istream& operator >> (istream &stream,Book &b);//重载操作符>>
    friend ostream& operator << (ostream &stream,Book &b);//重载操作符<<
};

const string getCurrentSystemTime();

#endif
