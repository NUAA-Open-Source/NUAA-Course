#ifndef BOOKINFO_H
#define BOOKINFO_H
#include"BasicMessage.h"
class BookInfo:public BasicMessage
{
protected:	
	struct Book
	{
		int BookNum;//�鼮����
		char BookName[21];//�鼮����
		char BookAuthor[21];//�鼮���� 
	}book;
public:
	friend void BasicMessage::showInfo(); 
	void setBInfo();//����ͼ����Ϣ
	void borrowSBook(char*);//����
	void borrowTBook(char*);
	void returnSBook(char*);//����
	void returnTBook(char*);
	void showBInfo();//չʾͼ����Ϣ
	void clearBook();//������  
};
#endif 
