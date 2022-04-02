#include<iostream>
using namespace std;
#include"BasicMessage.h"
#include"Date.h"
#include"BookInfo.h"
#include<stdlib.h>
#include<fstream>
void menu_select();
void menu_select1();
void menu_select2();
void menu_select3();
int main()
{
	menu_select();
	while(1)
	{ 
		system("pause"); 
		system("cls");
		menu_select();    
	}
	return 0;
} 
//主菜单 
void menu_select()
{

	int choice;
	cout<<"***欢迎进入图书管理系统***\n";
	cout<<"1:信息处理\n2:图书管理\n3:图书处理(仅限管理员)\n"; 
	cin>>choice;
	if(choice==1)
		menu_select1();
	if(choice==2)
		menu_select2();
	if(choice==3)
	{
		int PW;
		system("cls");
		cout<<"\n***请输入密码***\n";
		cin>>PW;
		if(PW==1618)
			menu_select3();
		else
		{
			cout<<"\n***密码错误***\n"; 
			menu_select();
		}
	}
}
//信息处理 
void menu_select1()
{
	system("cls");
	BasicMessage user;
	int a;//选择 
	cout<<"***信息处理***\n";
	cout<<"1:设置信息\n2:编辑信息\n3:删除信息\n4:查询信息\n5:展示信息\n6:格式化信息\n7:返回\n";
	cin>>a;
	cin.ignore();
	switch(a)
	{
		case 1:
			user.setInfo();
			break;
		case 2:
			user.modInfo();
			break;
		case 3:
			user.delInfo();
			break;
		case 4:
			user.searchInfo();
			break;
		case 5:
			user.showInfo();
			break; 
		case 6:
			user.formatInfo();
			break;
		case 7:
			system("cls");
			menu_select();
			break;
	}
}
//图书管理 
void menu_select2()
{
	system("cls");
	BookInfo user;

	char Bookn[21];
	cout<<"***图书管理***\n";
	int a;
	cout<<"1:查看书籍信息\n2:借书\n3:还书\n4:返回\n";
	cin>>a;
	cin.ignore();
	switch(a)
	{
		case 1:
			user.showBInfo();
			break;
		case 2:
			cout<<"\n***您的身份是（S/T)***\n";
			char choice;
			cin>>choice;
			cin.ignore();
			if(choice=='S') 
			{
				while(1)
				{
					cout<<"\n***输入您要借的书名***\n";
					cin>>Bookn;
					user.borrowSBook(Bookn); 
					char ch;
					cout<<"\n***是否继续借书(y/n)***";
					cin>>ch;
					cin.ignore();
					if(ch=='n')
						break;
				}
			}
			if(choice=='T')
			{
				while(1)
				{
					cout<<"\n***输入您要借的书名***\n";
					cin>>Bookn;
					user.borrowTBook(Bookn);
					char ch;
					cout<<"\n***是否继续借书(y/n)***";
					cin>>ch;
					cin.ignore();
					if(ch=='n')
						break;
				}
			}
			break;
		case 3:
			cout<<"\n***您的身份是（S/T)***\n";
			char a;
			cin>>a;
			cin.ignore();
			if(a=='S') 
			{
				while(1)
				{
					cout<<"\n***输入您要还的书名***\n";
					cin>>Bookn;
					user.returnSBook(Bookn);
					char ch;
					cout<<"\n***是否继续还书(y/n)***";
					cin>>ch;
					cin.ignore();
					if(ch=='n')
						break;
				}
			}
			if(a=='T')
			{
				while(1)
				{
					cout<<"\n***输入您要借还的书名***\n";
					cin>>Bookn;
					user.returnTBook(Bookn); 
					char ch;
					cout<<"\n***是否继续还书(y/n)***";
					cin>>ch;
					cin.ignore();
					if(ch=='n')
						break;
				}
			}
			break;
		case 4: 
			system("cls");
			menu_select();
			break;  
	} 
} 
void menu_select3()
{
	system("cls");
	BookInfo user;
	int a;
	cout<<"\n***图书整理***\n";
	cout<<"1:书籍入库\n2:清空书籍\n3:返回\n";
	cin>>a;
	switch(a)
	{
		case 1:
			user.setBInfo();
			break;
		case 2:
			user.clearBook();
			break;
		case 3:
			system("cls");
			menu_select();
			break;	
	} 
}
