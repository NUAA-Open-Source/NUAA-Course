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
//���˵� 
void menu_select()
{

	int choice;
	cout<<"***��ӭ����ͼ�����ϵͳ***\n";
	cout<<"1:��Ϣ����\n2:ͼ�����\n3:ͼ�鴦��(���޹���Ա)\n"; 
	cin>>choice;
	if(choice==1)
		menu_select1();
	if(choice==2)
		menu_select2();
	if(choice==3)
	{
		int PW;
		system("cls");
		cout<<"\n***����������***\n";
		cin>>PW;
		if(PW==1618)
			menu_select3();
		else
		{
			cout<<"\n***�������***\n"; 
			menu_select();
		}
	}
}
//��Ϣ���� 
void menu_select1()
{
	system("cls");
	BasicMessage user;
	int a;//ѡ�� 
	cout<<"***��Ϣ����***\n";
	cout<<"1:������Ϣ\n2:�༭��Ϣ\n3:ɾ����Ϣ\n4:��ѯ��Ϣ\n5:չʾ��Ϣ\n6:��ʽ����Ϣ\n7:����\n";
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
//ͼ����� 
void menu_select2()
{
	system("cls");
	BookInfo user;

	char Bookn[21];
	cout<<"***ͼ�����***\n";
	int a;
	cout<<"1:�鿴�鼮��Ϣ\n2:����\n3:����\n4:����\n";
	cin>>a;
	cin.ignore();
	switch(a)
	{
		case 1:
			user.showBInfo();
			break;
		case 2:
			cout<<"\n***��������ǣ�S/T)***\n";
			char choice;
			cin>>choice;
			cin.ignore();
			if(choice=='S') 
			{
				while(1)
				{
					cout<<"\n***������Ҫ�������***\n";
					cin>>Bookn;
					user.borrowSBook(Bookn); 
					char ch;
					cout<<"\n***�Ƿ��������(y/n)***";
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
					cout<<"\n***������Ҫ�������***\n";
					cin>>Bookn;
					user.borrowTBook(Bookn);
					char ch;
					cout<<"\n***�Ƿ��������(y/n)***";
					cin>>ch;
					cin.ignore();
					if(ch=='n')
						break;
				}
			}
			break;
		case 3:
			cout<<"\n***��������ǣ�S/T)***\n";
			char a;
			cin>>a;
			cin.ignore();
			if(a=='S') 
			{
				while(1)
				{
					cout<<"\n***������Ҫ��������***\n";
					cin>>Bookn;
					user.returnSBook(Bookn);
					char ch;
					cout<<"\n***�Ƿ��������(y/n)***";
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
					cout<<"\n***������Ҫ�軹������***\n";
					cin>>Bookn;
					user.returnTBook(Bookn); 
					char ch;
					cout<<"\n***�Ƿ��������(y/n)***";
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
	cout<<"\n***ͼ������***\n";
	cout<<"1:�鼮���\n2:����鼮\n3:����\n";
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
