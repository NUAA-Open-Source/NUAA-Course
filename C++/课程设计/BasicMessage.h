#ifndef BASICMESSAGE_H
#define BASICMESSAGE_H
#include"Date.h"
class BasicMessage:public Date                      //继承Date类 
{
protected:
	struct message//结构体储存信息 
	{
		char Name[21];//姓名 
		char BookName1[5][21];//书名
		//char BookName2[21];
		//char BookName3[21];
		//char BookName4[21]; 
		//char BookNum[21];//图书编号
		char Depart[21];//院系
		char Identity;//身份 
		int ReserveDay[5];//预算时间
		long long ID;//学号
		int counter;//记书器 
		int Password;//密码	
		Date date[5];//日期 
		//BookInfo book_;//借书情况 
	};
public:
	BasicMessage(){ 
		message New;
		New.counter=0;
	}
	//friend void menu_select();//友元函数，生成菜单 
	//friend void menu_select1();
	//friend void menu_select2();
	//friend void menu_select3();
	void setInfo();//设置信息 
	void delInfo();//删除信息 
	void modInfo();//修改信息 
	void searchInfo();//查询信息 
	void showInfo();//展示信息 
	void formatInfo();//格式化信息	
};
#endif 
