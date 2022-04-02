#include<iostream>
using namespace std;
#include"BasicMessage.h"
#include"Date.h"
#include<fstream>
#include<string.h>
#include<stdlib.h>
//设置信息
void BasicMessage::setInfo() 
{
	
	cout<<"\n\n***设置信息***\n";
	message New;
	cout<<"请输入姓名：";
	cin>>New.Name;
	cout<<"请问您的身份是（T/S)：";
	cin>>New.Identity;
	if(New.Identity=='S')
	{
		cout<<"请输入您的学号：";
		cin>>New.ID;
		if(New.ID<10000000||New.ID>170000000)//判断学号后面对错有待提高 
		{
			cout<<"学号错误！请重新输入\n";
			cin>>New.ID;
		}
		if(New.ID/10000000==1)
		{
			char dep[21]={"航空宇航学院"}; 
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==2)
		{
			char dep[21]={"能源与动力学院"};
			strcpy(New.Depart,dep); 
		}
		if(New.ID/10000000==3)
		{
			char dep[21]={"自动化学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==4)
		{
			char dep[21]={"电子信息工程学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==5)
		{
			char dep[21]={"机电学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==6)
		{
			char dep[21]={"材料学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==7)
		{
			char dep[21]={"民航飞行学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==8)
		{
			char dep[21]={"理学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==9)
		{
			char dep[21]={"经管学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==10)
		{
			char dep[21]={"人文学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==11)
		{
			char dep[21]={"艺术学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==12)
		{
			char dep[21]={"外国语学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==15)
		{
			char dep[21]={"航天学院"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==16)
		{
			char dep[21]={"计算机科学与计术学院"};
			strcpy(New.Depart,dep);
		}
	}
	if(New.Identity=='T')
	{
		cout<<"请输入工号：";
		cin>>New.ID;	
	}

	cout<<"请设置您的密码：";
	cin>>New.Password;
	
	cout<<"输入counter\n";
	cin>>New.counter;
	//New.date.claDate(New.ReserveDay);                                                       	
	fstream infile,infile2,infile3,infile4;
	infile.open("Sreader.dat",ios::app|ios::binary);//所有记录 
	infile2.open("Sreader1.dat",ios::app|ios::binary);//只读记录 
	infile3.open("Treader.dat",ios::app|ios::binary);
	infile4.open("Treader2.dat",ios::app|ios::binary);
	if(infile.fail())
	{
		cout<<"打开失败!"<<endl;
		exit(0); 
	}
	if(infile2.fail())
	{
		cout<<"打开失败!"<<endl;
		exit(0); 
	}
	if(infile3.fail())
	{
		cout<<"打开失败!"<<endl;
		exit(0); 
	}
	if(infile4.fail())
	{
		cout<<"打开失败!"<<endl;
		exit(0); 
	}
	if(New.Identity=='S')
	{ 
		infile.write((char*)&New,sizeof(New));
		infile2.write((char*)&New,sizeof(New));
	}
	if(New.Identity=='T')
	{
		infile3.write((char*)&New,sizeof(New));
		infile4.write((char*)&New,sizeof(New));
	}
	infile.close();
	infile2.close();
	infile3.close();
	infile4.close();
	cout<<"*****************\n"; 
}

//删除信息 
void BasicMessage::delInfo()  
{
	fstream infile,outfile;
	int choice;
	long long Number;
	message New; 
	cout<<"\n\n***请问您要删除人的身份***\n";
	cout<<"1:老师\t2:学生\t3:取消删除\n";
	cin>>choice;
	if(choice==1)   //对象是老师 
	{
		infile.open("Treader.dat",ios::in|ios::binary);
		outfile.open("Treader3.dat",ios::out|ios::binary);//Treader3文件只是一个副本，用来暂时存放Treader里面的数据，便于下面的删除操作 
		cout<<"请输入将要删除老师的工号：";
		cin>>Number;
		cin.ignore();
		if(infile.fail())
		{
			cout<<"打开失败！\n";
			exit(0); 
		}
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
				break;
			if(New.ID==Number)
			{
				cout<<"\n\n****将要删除的老师信息为****：\n";
				cout<<"姓名\t";
				cout<<"工号\n";
				cout<<New.Name<<"\t"<<New.ID<<endl; 
				if(New.counter==0)                                //判断书籍是否还清 
				{
					int PW;//密码 
					cout<<"请输入密码：";
					cin>>PW;
					cin.ignore();
					if(New.Password==PW)//判断密码是否正确 
					{
						char ch;//选择 
						cout<<"确认删除？(y/n)";
						cin>>ch;
						if(ch=='y')
						{ 
							New.ID=0;//成功删除，工号归零 
							outfile.write((char*)&New,sizeof(New));
						}
						else
						{
							outfile.write((char*)&New,sizeof(New));
							//break;
						}
					}
					else
					{
						outfile.write((char*)&New,sizeof(New));
						cout<<"密码错误！\n";
						break; 
					} 
				}
				if(New.counter!=0)
				{
					outfile.write((char*)&New,sizeof(New));
					cout<<"\n\n***删除失败！您还有为还的书籍***\n";
					break; 
				}
				Number=0;//判断标志归0 
			
			}
			else
			{
				outfile.write((char*)&New,sizeof(New));
			}	 
		}
		infile.close();
		outfile.close();
		infile.open("Treader3.dat",ios::in|ios::binary);//将新的信息从副本中输入 
		outfile.open("Treader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"打开文件失败！\n";
			exit(0);
		} 
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
				break;
			if(New.ID!=0)
			{
				outfile.write((char*)&New,sizeof(New));
			}
		} 
		infile.close();
		outfile.close();
		cout<<endl; 
	}
	if(choice==2)//对象是学生
	{
		infile.open("Sreader.dat",ios::in|ios::binary);
		outfile.open("Sreader3.dat",ios::out|ios::binary);//Treader3文件只是一个副本，用来暂时存放Treader里面的数据，便于下面的删除操作 
		cout<<"请输入将要删除学生的学号：";
		cin>>Number;
		cin.ignore();
		if(infile.fail())
		{
			cout<<"打开失败！\n";
			exit(0); 
		}
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
				break;
			if(New.ID==Number)
			{
				cout<<"\n\n****将要删除的学生信息为****：\n";
				cout<<"姓名\t";
				cout<<"学号\t\t";
				cout<<"院系\t\n"; 
				cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.Depart<<endl; 
				if(New.counter==0)                                //判断书籍是否还清 
				{
					int PW;//密码 
					cout<<"请输入密码：";
					cin>>PW;
					cin.ignore();
					if(New.Password==PW)//判断密码是否正确 
					{
						char ch;//选择 
						cout<<"确认删除？(y/n)";
						cin>>ch;
						if(ch=='y')
						{ 
							New.ID=0;//成功删除，学号归零 
							outfile.write((char*)&New,sizeof(New));
						}
						else
						{
							outfile.write((char*)&New,sizeof(New));
							//break;
						}
					}
					else
					{
						outfile.write((char*)&New,sizeof(New));
						cout<<"密码错误！\n";
						break; 
					} 
				}
				if(New.counter!=0) 
				{
					outfile.write((char*)&New,sizeof(New));
					cout<<"\n\n***删除失败！您还有未还的书籍***\n";
					break; 
				}
				Number=0;//判断标志归0 
			
			}
			else
			{
				outfile.write((char*)&New,sizeof(New));
			}	 
		}
		infile.close();
		outfile.close();
		infile.open("Sreader3.dat",ios::in|ios::binary);//将新的信息从副本中输入 
		outfile.open("Sreader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"打开文件失败！\n";
			exit(0);
		} 
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
				break;
			if(New.ID!=0)
			{
				outfile.write((char*)&New,sizeof(New));
			}
		} 
		infile.close();
		outfile.close();
		cout<<endl; 
	}
	if(choice==3)
	{
		cout<<"\n\n***取消删除***\n"; 
	 } 
}

//修改信息
void BasicMessage::modInfo() 
{
	system("cls");
	fstream infile,outfile;
	int choice;
	long long Id;
	message New;
	cout<<"\n\n***请问你要修改信息人的身份***\n";
	cout<<"1:老师\t"<<"2:学生\t3:取消\n";
	cin>>choice;
	cin.ignore();
	if(choice==1)//修改老师 
	{
		cout<<"\n\n***请输入修改信息老师的工号***\n";
		cin>>Id;
		int flag=0;//标志 
		infile.open("Treader.dat",ios::in|ios::binary);
		outfile.open("Treader3.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"打开失败!\n";
			exit(0); 
		}
		while(!infile.eof())
		{
			int PW;//密码 
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
			{
				if(flag==0)
					cout<<"\n\n***查询失败***\n"; 
				break;
			}
			if(New.ID==Id)
			{
				cout<<"\n\n***您要修改的老师信息为***\n";
				cout<<"姓名\t工号\n";
				cout<<New.Name<<"\t"<<New.Name<<"\t"<<endl;
				cout<<"\n\n***请输入密码***\n";
				cin>>PW;
				int count=0;//用来计算输入输入密码错误的此数
				while(1)
				{ 
					if(New.Password==PW)                                        //待做 
					{
						int a;//选择 
						cout<<"\n\n***请选择您要修改的信息***\n";
						cout<<"1:姓名\t2:工号\t3:密码\t4:重新编辑\t5:退出编辑\n";
						cin>>a;
						if(a==1)
						{
							cout<<"姓名：";
							cin>>New.Name;
							outfile.write((char*)&New,sizeof(New));	 
						}
						if(a==2)
						{
							cout<<"工号：";
							cin>>New.ID;
							outfile.write((char*)&New,sizeof(New)); 
						}
						if(a==3)
						{
							cout<<"密码：";
							cin>>New.Password;
							outfile.write((char*)&New,sizeof(New));
						}
						if(a==4)
						{
							cout<<"姓名：";
							cin>>New.Name;
							cout<<"工号：";
							cin>>New.ID;
							cout<<"密码：";
							cin>>New.Password;
							outfile.write((char*)&New,sizeof(New));
						}
						if(a==5)
						{
							cout<<"\n\n***取消修改***\n";
							outfile.write((char*)&New,sizeof(New));
							break;
						}
						Id=0;
						break; 
					}
					else
					{
						if(count==2)
						{
							cout<<"\n\n***输入错误此数过多！修改失败***\n";
							Id=0;
							break; 
						} 
						cout<<"密码错误！请重新输入\n";
						cin>>PW;
						count++; //计算密码输入失败次数 
					}
				}
				flag++;
			}
			else
				outfile.write((char*)&New,sizeof(New));
		}
		infile.close();
		outfile.close();
		infile.open("Treader3.dat",ios::in|ios::binary);//将新的信息从副本中输入 
		outfile.open("Treader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"打开文件失败！\n";
			exit(0);
		} 
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
				break;
			outfile.write((char*)&New,sizeof(New));
		} 
		infile.close();
		outfile.close();
		cout<<endl;
		char ch;
		cout<<"\n\n***请问是否继续修改(y/n)***\n";
		cin>>ch;
		if(ch=='y')
			modInfo();
		else
			system("cls"); 
	}
	if(choice==2)//修改学生信息 
	{
		cout<<"请输入修改信息学生的学号：";
		cin>>Id;
		int flag=0;
		infile.open("Sreader.dat",ios::in|ios::binary);
		outfile.open("Sreader3.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"打开失败!\n";
			exit(0); 
		}
		while(!infile.eof())
		{
			int PW;//密码 
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
			{
				if(flag==0)
					cout<<"\n\n***查找失败***\n";
				break;
			}
			if(New.ID==Id)
			{
				cout<<"\n\n***您要修改的学生信息为***\n";
				cout<<"姓名\t学号\t\t院系\n";
				cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.Depart<<endl;
				cout<<"\n\n***请输入密码***\n";
				cin>>PW;
				cin.ignore();
				int count=0;//用来计算输入输入密码错误的此数
				while(1)
				{ 
					if(New.Password==PW)                                        //待做 
					{
						int a;//选择 
						cout<<"\n\n***请选择您要修改的信息***\n";
						cout<<"1:姓名\t2:学号\t3:密码\t4:重新编辑\t5:退出编辑\n";
						cin>>a;
						if(a==1)
						{
							cout<<"姓名：";
							cin>>New.Name;
							outfile.write((char*)&New,sizeof(New));	 
						}
						if(a==2)
						{
							cout<<"学号：";
							cin>>New.ID;
							if(New.ID<10000000||New.ID>170000000)//判断学号后面对错有待提高 
							{
								cout<<"学号错误！请重新输入\n";
								cin>>New.ID;
							}
							if(New.ID/10000000==1)
							{
								char dep[21]={"航空宇航学院"}; 
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==2)
							{
								char dep[21]={"能源与动力学院"};
								strcpy(New.Depart,dep); 
							}
							if(New.ID/10000000==3)
							{
								char dep[21]={"自动化学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==4)
							{
								char dep[21]={"电子信息工程学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==5)
							{
								char dep[21]={"机电学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==6)
							{
								char dep[21]={"材料学院"};
								strcpy(New.Depart,dep);
							}	
							if(New.ID/10000000==7)
							{
								char dep[21]={"民航飞行学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==8)
							{
								char dep[21]={"理学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==9)
							{
								char dep[21]={"经管学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==10)
							{
								char dep[21]={"人文学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==11)
							{
								char dep[21]={"艺术学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==12)
							{
								char dep[21]={"外国语学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==15)
							{
								char dep[21]={"航天学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==16)
							{
								char dep[21]={"计算机科学与计术学院"};
								strcpy(New.Depart,dep);
							}
							outfile.write((char*)&New,sizeof(New)); 
						}
						if(a==3)
						{
							cout<<"密码：";
							cin>>New.Password;
							cin.ignore();
							outfile.write((char*)&New,sizeof(New));
						}
						if(a==4)
						{
							cout<<"姓名：";
							cin>>New.Name;
							cout<<"学号：";
							cin>>New.ID;
							if(New.ID<10000000||New.ID>170000000)//判断学号后面对错有待提高 
							{
								cout<<"学号错误！请重新输入\n";
								cin>>New.ID;
							}
							if(New.ID/10000000==1)
							{
								char dep[21]={"航空宇航学院"}; 
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==2)
							{
								char dep[21]={"能源与动力学院"};
								strcpy(New.Depart,dep); 
							}
							if(New.ID/10000000==3)
							{
								char dep[21]={"自动化学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==4)
							{
								char dep[21]={"电子信息工程学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==5)
							{
								char dep[21]={"机电学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==6)
							{
								char dep[21]={"材料学院"};
								strcpy(New.Depart,dep);
							}	
							if(New.ID/10000000==7)
							{
								char dep[21]={"民航飞行学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==8)
							{
								char dep[21]={"理学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==9)
							{
								char dep[21]={"经管学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==10)
							{
								char dep[21]={"人文学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==11)
							{
								char dep[21]={"艺术学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==12)
							{
								char dep[21]={"外国语学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==15)
							{
								char dep[21]={"航天学院"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==16)
							{
								char dep[21]={"计算机科学与计术学院"};
								strcpy(New.Depart,dep);
							}
							cout<<"密码：";
							cin>>New.Password;
							outfile.write((char*)&New,sizeof(New));
						}
						if(a==5)
						{
							cout<<"\n\n***取消修改***\n";
							outfile.write((char*)&New,sizeof(New));
							break;
						}
						Id=0;
						break; 
					}
					else
					{
						if(count==2)
						{
							cout<<"\n\n***输入错误此数过多！修改失败***\n";
							Id=0;
							break; 
						} 
						cout<<"\n\n***密码错误！请重新输入***\n";
						cin>>PW;
						count++; //计算密码输入失败次数 
					}
				}
				flag++;
			}
			else
				outfile.write((char*)&New,sizeof(New));
		}
		infile.close();
		outfile.close();
		infile.open("Sreader3.dat",ios::in|ios::binary);//将新的信息从副本中输入 
		outfile.open("Sreader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"打开文件失败！\n";
			exit(0);
		} 
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
				break;
			outfile.write((char*)&New,sizeof(New));
		} 
		infile.close();
		outfile.close();
		cout<<endl;
		char ch;
		cout<<"\n\n***请问是否继续修改(y/n)***\n";
		cin>>ch;
		if(ch=='y')
			modInfo();
		else
			system("cls"); 
	}
	if(choice==3)
	{
		cout<<"\n\n***取消修改***\n";
	} 
}

//查询信息
void BasicMessage::searchInfo() 
{
	system("cls");
	fstream infile;
	int choice;
	message New;
	cout<<"\n\n***请输入您要查找的对象***\n";
	cout<<"1:老师\t2:学生\t3:院系\t4:取消\n"; 
	cin>>choice;
	if(choice==1)//查找对象是老师 
	{
		char Name3[21];
		int flag=0;//判断是否查找到的标志 
		cout<<"\n\n***请输入您要查找老师的姓名***\n";
		cin>>Name3;
		infile.open("Treader.dat",ios::in|ios::binary);
		if(infile.fail())
		{
			cout<<"打开失败!\n";
			exit(0);
		}
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
			{
				if(flag==0)
					cout<<"\n\n***查找失败***\n"; 
				break;
			}
			if(strcmp(New.Name,Name3)==0)
			{
				cout<<"\n\n***以下是查找的老师信息***\n";
				cout<<"姓名\t工号\t\t所借书籍\t借书时间\t借书天数（天）\n";
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t\t"<<"无"<<"\t";
					cout<<"0/0/0";
					cout<<"\t"<<"0"<<endl;
				}
				else
				{ 
					for(int i=0;i<New.counter;i++)
					{ 
						cout<<New.Name<<"\t"<<New.ID<<"\t\t"<<New.BookName1[i]<<"\t";
						New.date[i].showDate();
						cout<<"\t"<<New.ReserveDay[i]<<endl;
					}
					
				} 
				flag++;
			}
		}
		infile.close();
		cout<<endl; 
	} 
	if(choice==2)//查找对象是学生 
	{
		char Name3[21];
		int flag=0;//判断是否查找到的标志 
		cout<<"\n\n***请输入您要查找学生的姓名***\n";
		cin>>Name3;
		infile.open("Sreader.dat",ios::in|ios::binary);
		if(infile.fail())
		{
			cout<<"打开失败！\n";
			exit(0);
		}
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
			{
				if(flag==0)
					cout<<"\n\n***查找失败***\n"; 
				break;
			}
			if(strcmp(New.Name,Name3)==0)
			{
				cout<<"\n\n***以下是查找的学生信息***\n";
				cout<<"姓名\t学号\t\t院系\t\t所借书籍\t借书时间\t借书天数（天\n";
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.Depart<<"\t"<<"无"<<"\t\t";
					cout<<"0/0/0";
					cout<<"\t"<<"0"<<endl;
				}
				else
				{
				 
					for(int i=0;i<New.counter;i++)
					{
						cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.Depart<<"\t"<<New.BookName1[i]<<"\t\t";
						New.date[i].showDate();
						cout<<"\t"<<New.ReserveDay[i]<<endl;
					}
					
				}
				flag++;
			}
		}
		infile.close();
		cout<<endl; 
	}
	if(choice==3)//查找对象是院系
	{
		int a; 
		cout<<"\n\n***请输入你要查找的院系代号***\n";
		cin>>a;                                               //可以增多 
		cout<<endl; 
		infile.open("Sreader.dat",ios::in|ios::binary);
		if(infile.fail())
		{
			cout<<"打开失败！\n";
			exit(0);
		}
		int flag=0;
		while(!infile.eof())
		{
			
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
			{
				if(flag==0)
					cout<<"\n\n***所查询学院暂无信息***\n"; 
				break;
			}
			if(New.ID/10000000==a)
			{
				cout<<"院系\t\t姓名\t\t学号\t\t所借书籍数\n";
				cout<<New.Depart<<"\t"<<New.Name<<"\t\t"<<New.ID<<"\t"<<New.counter<<endl;
				flag++; 
			} 
		}
		flag=0;
		infile.close();
		cout<<endl; 
	}
	if(choice==4)
	{
		cout<<"\n\n***取消查询***\n"; 
	}
	char ch;
	cout<<"\n\n***请问是否继续查找(y/n)***\n";
	cin>>ch;
	if(ch=='y')
		searchInfo();
	else	
		cout<<"\n\n***退出查找***\n";
		system("cls");  
}

//展示信息
void BasicMessage::showInfo() 
{
	fstream outfile;
	message New;
	int choice;
	cout<<"\n\n***请选择显示信息类型***\n";
	cout<<"1:教师\t2:学生\t3:全部\t4:返回\n";
	cin>>choice;
	if(choice==2)
	{ 
		int flag=0;//判断标志 
		outfile.open("Sreader.dat",ios::in|ios::binary);
		if(outfile.fail())
		{
			cout<<"打开失败！\n";
			exit(0); 
		}
		while(!outfile.eof())
		{
			outfile.read((char*)&New,sizeof(New));
			if(outfile.fail())
			{
				if(flag==0)
				{
					cout<<"\n\n***学生信息库为空***\n"; 
				}
				break;
			}
			if(New.ID!=0)
			{
				cout<<"\n\n***学生信息为***\n";
				cout<<"姓名\t学号\t";
				cout<<"所借书籍\t";
				cout<<"所借时间（天）\t\t";
				cout<<"借书时间\t\t";
				cout<<"院系\t"<<endl; 
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t"<<"无"<<"\t\t"<<"0"<<"\t\t";
					cout<<"0/0/0";
					cout<<"\t"<<New.Depart<<endl; 
					cout<<"********************\n";
				 }
				else
				{
				 
					for(int i=0;i<New.counter;i++)
					{
				
						cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.BookName1[i]<<"\t\t"<<New.ReserveDay[i]<<"\t\t";
						New.date[i].showDate();
						cout<<"\t"<<New.Depart<<endl; 
						cout<<"********************\n";
					}
					flag++;
				}
			}
		}
		outfile.close();
	}
	if(choice==1)
	{ 
		outfile.open("Treader.dat",ios::in|ios::binary);
		int flag=0;//判断标志 
		if(outfile.fail())
		{
			cout<<"打开失败！\n";
			exit(0); 
		}
		while(!outfile.eof())
		{
			outfile.read((char*)&New,sizeof(New));
			if(outfile.fail())
			{
				
				if(flag==0)
				{
					cout<<"\n\n***教师信息库为空***\n"; 
				}
				break;
			} 
			if(New.ID!=0)
			{
				cout<<"\n\n老师信息为***\n";
				cout<<"姓名\t工号\t";
				cout<<"所借书籍\t";
				cout<<"所借时间（天）\t\t";
				cout<<"借书时间\t\t";
				cout<<endl;
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t"<<"无"<<"\t\t"<<"0"<<"\t\t";
					cout<<"0/0/0";
					cout<<"\t"<<endl; 
					cout<<"********************\n";
				}
				else
				{
			
					for(int i=0;i<New.counter;i++)
					{
					 
						cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.BookName1[i]<<"\t\t"<<New.ReserveDay[i]<<"\t\t";
						New.date[i].showDate();
						cout<<"\t"<<endl; 
						cout<<"********************\n";
					}
					flag++;
				}
				
			}
		}
		flag=0;
		outfile.close();
	}
	if(choice==3)
	{
		int flag=0; 
		outfile.open("Sreader.dat",ios::in|ios::binary);
		if(outfile.fail())
		{
			cout<<"打开失败！\n";
			exit(0); 
		}
		while(!outfile.eof())
		{
			outfile.read((char*)&New,sizeof(New));
			if(outfile.fail())
			{
				if(flag==0)
					cout<<"\n\n***学生信息库为空***\n"; 
				break;
			}
			if(New.ID!=0)
			{
				cout<<"\n\n***学生信息为***\n";
				cout<<"姓名\t学号\t";
				cout<<"所借书籍\t";
				cout<<"所借时间（天）\t\t";
				cout<<"借书时间\t\t";
				cout<<"院系\t"<<endl;
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t"<<"无"<<"\t\t"<<"0"<<"\t\t";
					cout<<"0/0/0";
					cout<<"\t"<<New.Depart<<endl;
					cout<<"********************\n";
				}
				else
				{ 
					for(int i=0;i<New.counter;i++)
					{
					  
						cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.BookName1[i]<<"\t\t"<<New.ReserveDay[i]<<"\t\t";
						New.date[i].showDate();
						cout<<"\t"<<New.Depart<<endl;
						cout<<"********************\n";
					}
					flag++;
				}
				
			}
		}
		outfile.close();
		flag=0;
		outfile.open("Treader.dat",ios::in|ios::binary);
		if(outfile.fail())
		{
			cout<<"打开失败！\n";
			exit(0); 
		}
		while(!outfile.eof())
		{
			outfile.read((char*)&New,sizeof(New));
			if(outfile.fail())
			{
				if(flag==0)
					cout<<"\n\n***教师信息库为空***\n"; 
				break;
			}
			if(New.ID!=0)
			{ 
				cout<<"\n\n老师信息为***\n";
				cout<<"姓名\t工号\t";
				cout<<"所借书籍\t";
				cout<<"所借时间（天）\t\t";
				cout<<"借书时间\t\t";
				cout<<endl;
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t"<<"无"<<"\t\t"<<"0"<<"\t\t";
					cout<<"0/0/0";
					cout<<"\t"<<endl;
					cout<<"********************\n";
				}
				else
				{
				
					for(int i=0;i<New.counter;i++)
					{
				 
						cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.BookName1[i]<<"\t\t"<<New.ReserveDay[i]<<"\t\t";
						New.date[i].showDate();
						cout<<"\t"<<endl;
						cout<<"********************\n";
					}
					flag++;
				}
				
			}
		}
		flag=0;
		outfile.close();
	}
	if(choice==4)
	{
		cout<<"\n\n***取消信息展示***\n";
	} 
}

//格式化信息
void BasicMessage::formatInfo() 
{
	fstream infile,infile1,infile3,infile4;
	int choice;
	cout<<"\n\n***请选择格式化信息类型***\n";
	cout<<"1:老师\t2:学生\t3:全部\t4:取消\n";
	cin>>choice;
	if(choice==1)
	{ 
		infile.open("Treader.dat",ios::out|ios::binary);
		infile1.open("Treader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"打开失败！\n";
			exit(0);
		}
		if(infile1.fail())
		{
			cout<<"打开失败！\n";
			exit(0);
		}
		infile.close();
		infile1.close();
	}
	if(choice==2)
	{ 
		infile.open("Sreader.dat",ios::out|ios::binary);
		infile1.open("Sreader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"打开失败！\n";
			exit(0);
		}
		if(infile1.fail())
		{
			cout<<"打开失败！\n";
			exit(0);
		}
		infile.close();
		infile1.close();
	}
	if(choice==3)
	{ 
		infile.open("Treader.dat",ios::out|ios::binary);
		infile1.open("Treader.dat",ios::out|ios::binary);
		infile3.open("Sreader.dat",ios::out|ios::binary);
		infile4.open("Sreader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"打开失败！\n";
			exit(0);
		}
			if(infile1.fail())
		{
			cout<<"打开失败！\n";
			exit(0);
		}
			if(infile3.fail())
		{
			cout<<"打开失败！\n";
			exit(0);
		}
			if(infile4.fail())
		{
			cout<<"打开失败！\n";
			exit(0);
		}
		infile.close();
		infile1.close();
		infile3.close();
		infile4.close();
	}
	if(choice==4)
	{
		cout<<"\n\n***取消格式化***\n";
	}
}  
