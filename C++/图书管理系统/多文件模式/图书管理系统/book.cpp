#include "book.h"

int Book::Book_Number=0;

ostream &operator << (ostream &stream,Book &b)
{
    stream<<"编号"<<setw(9)<<b.isbn<<" 书名:"<<setw(9)
    <<b.name<<" 作者:"<<setw(9)<<b.author<<" 出版社:"
    <<setw(9)<<b.publisher<<" 单价:"<<setw(5)<<b.price<<endl;
    return stream;
}

istream &operator >> (istream &stream,Book &b)
{
    cout<<"请输入编号:";
    stream>>b.isbn;
    cout<<"请输入书名:";
    stream>>b.name;
    cout<<"请输入作者名:";
    stream>>b.author;
    cout<<"请输入出版社:";
    stream>>b.publisher;
    cout<<"请输入单价:";
    stream>>b.price;
    return stream;
}

//获取系统当前时间的函数.
const string getCurrentSystemTime()
{
    time_t t;
    struct tm * lt;
    time (&t);
    lt = localtime (&t);//转为时间结构。
    char date[60] = {0};
    sprintf(date, "%d-%02d-%02d %02d:%02d:%02d",
            (int)lt->tm_year + 1900,(int)lt->tm_mon + 1,(int)lt->tm_mday,
            (int)lt->tm_hour,(int)lt->tm_min,(int)lt->tm_sec);
    return string(date);
}

void Book::SetDeadline(int a){deadline =a;}

void Book::SetTime(string a){time =a;}

void Book::SetIs_Lend(bool a){Is_Lend =a;}

void Book::Display()//用来展示借书情况
{
    cout<<"编号"<<setw(9)<<GetIsbn()<<" 书名:"<<setw(9)
    <<GetName()<<" 作者:"<<setw(9)<<GetAuthor()<<" 出版社:"
    <<setw(9)<<GetPub()<<" 单价:"<<setw(5)<<GetPrice()<<" 借书时间:"
    <<setw(10)<<Gettime()<<" 借书期限:"<<GetDeadline()<<"天"<<endl;
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
