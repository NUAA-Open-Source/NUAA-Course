#ifndef BOOKINFO_H
#define BOOKINFO_H
#include"BasicMessage.h"
class BookInfo:public BasicMessage
{
protected:	
	struct Book
	{
		int BookNum;//书籍数量
		char BookName[21];//书籍名称
		char BookAuthor[21];//书籍作者 
	}book;
public:
	friend void BasicMessage::showInfo(); 
	void setBInfo();//设置图书信息
	void borrowSBook(char*);//借书
	void borrowTBook(char*);
	void returnSBook(char*);//还书
	void returnTBook(char*);
	void showBInfo();//展示图书信息
	void clearBook();//清空书库  
};
#endif 
