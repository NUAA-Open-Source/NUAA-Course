#include "book.h"

int Book::Book_Number=0;

ostream &operator << (ostream &stream,Book &b)
{
    stream<<"���"<<setw(9)<<b.isbn<<" ����:"<<setw(9)
    <<b.name<<" ����:"<<setw(9)<<b.author<<" ������:"
    <<setw(9)<<b.publisher<<" ����:"<<setw(5)<<b.price<<endl;
    return stream;
}

istream &operator >> (istream &stream,Book &b)
{
    cout<<"��������:";
    stream>>b.isbn;
    cout<<"����������:";
    stream>>b.name;
    cout<<"������������:";
    stream>>b.author;
    cout<<"�����������:";
    stream>>b.publisher;
    cout<<"�����뵥��:";
    stream>>b.price;
    return stream;
}

//��ȡϵͳ��ǰʱ��ĺ���.
const string getCurrentSystemTime()
{
    time_t t;
    struct tm * lt;
    time (&t);
    lt = localtime (&t);//תΪʱ��ṹ��
    char date[60] = {0};
    sprintf(date, "%d-%02d-%02d %02d:%02d:%02d",
            (int)lt->tm_year + 1900,(int)lt->tm_mon + 1,(int)lt->tm_mday,
            (int)lt->tm_hour,(int)lt->tm_min,(int)lt->tm_sec);
    return string(date);
}

void Book::SetDeadline(int a){deadline =a;}

void Book::SetTime(string a){time =a;}

void Book::SetIs_Lend(bool a){Is_Lend =a;}

void Book::Display()//����չʾ�������
{
    cout<<"���"<<setw(9)<<GetIsbn()<<" ����:"<<setw(9)
    <<GetName()<<" ����:"<<setw(9)<<GetAuthor()<<" ������:"
    <<setw(9)<<GetPub()<<" ����:"<<setw(5)<<GetPrice()<<" ����ʱ��:"
    <<setw(10)<<Gettime()<<" ��������:"<<GetDeadline()<<"��"<<endl;
}

void Book::SetIsbn(string code1)
{isbn=code1;}

void Book::SetName(string name1)
{name=name1;}

void Book::SetAuthor(string author1)
{author=author1;}

void Book::SetPub(string press1)
{publisher=press1;}

void Book::SetPrice(float price1)
{price=price1;}
