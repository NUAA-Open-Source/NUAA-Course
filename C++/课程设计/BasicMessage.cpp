#include<iostream>
using namespace std;
#include"BasicMessage.h"
#include"Date.h"
#include<fstream>
#include<string.h>
#include<stdlib.h>
//������Ϣ
void BasicMessage::setInfo() 
{
	
	cout<<"\n\n***������Ϣ***\n";
	message New;
	cout<<"������������";
	cin>>New.Name;
	cout<<"������������ǣ�T/S)��";
	cin>>New.Identity;
	if(New.Identity=='S')
	{
		cout<<"����������ѧ�ţ�";
		cin>>New.ID;
		if(New.ID<10000000||New.ID>170000000)//�ж�ѧ�ź���Դ��д���� 
		{
			cout<<"ѧ�Ŵ�������������\n";
			cin>>New.ID;
		}
		if(New.ID/10000000==1)
		{
			char dep[21]={"�����ѧԺ"}; 
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==2)
		{
			char dep[21]={"��Դ�붯��ѧԺ"};
			strcpy(New.Depart,dep); 
		}
		if(New.ID/10000000==3)
		{
			char dep[21]={"�Զ���ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==4)
		{
			char dep[21]={"������Ϣ����ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==5)
		{
			char dep[21]={"����ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==6)
		{
			char dep[21]={"����ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==7)
		{
			char dep[21]={"�񺽷���ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==8)
		{
			char dep[21]={"��ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==9)
		{
			char dep[21]={"����ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==10)
		{
			char dep[21]={"����ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==11)
		{
			char dep[21]={"����ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==12)
		{
			char dep[21]={"�����ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==15)
		{
			char dep[21]={"����ѧԺ"};
			strcpy(New.Depart,dep);
		}
		if(New.ID/10000000==16)
		{
			char dep[21]={"�������ѧ�����ѧԺ"};
			strcpy(New.Depart,dep);
		}
	}
	if(New.Identity=='T')
	{
		cout<<"�����빤�ţ�";
		cin>>New.ID;	
	}

	cout<<"�������������룺";
	cin>>New.Password;
	
	cout<<"����counter\n";
	cin>>New.counter;
	//New.date.claDate(New.ReserveDay);                                                       	
	fstream infile,infile2,infile3,infile4;
	infile.open("Sreader.dat",ios::app|ios::binary);//���м�¼ 
	infile2.open("Sreader1.dat",ios::app|ios::binary);//ֻ����¼ 
	infile3.open("Treader.dat",ios::app|ios::binary);
	infile4.open("Treader2.dat",ios::app|ios::binary);
	if(infile.fail())
	{
		cout<<"��ʧ��!"<<endl;
		exit(0); 
	}
	if(infile2.fail())
	{
		cout<<"��ʧ��!"<<endl;
		exit(0); 
	}
	if(infile3.fail())
	{
		cout<<"��ʧ��!"<<endl;
		exit(0); 
	}
	if(infile4.fail())
	{
		cout<<"��ʧ��!"<<endl;
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

//ɾ����Ϣ 
void BasicMessage::delInfo()  
{
	fstream infile,outfile;
	int choice;
	long long Number;
	message New; 
	cout<<"\n\n***������Ҫɾ���˵����***\n";
	cout<<"1:��ʦ\t2:ѧ��\t3:ȡ��ɾ��\n";
	cin>>choice;
	if(choice==1)   //��������ʦ 
	{
		infile.open("Treader.dat",ios::in|ios::binary);
		outfile.open("Treader3.dat",ios::out|ios::binary);//Treader3�ļ�ֻ��һ��������������ʱ���Treader��������ݣ����������ɾ������ 
		cout<<"�����뽫Ҫɾ����ʦ�Ĺ��ţ�";
		cin>>Number;
		cin.ignore();
		if(infile.fail())
		{
			cout<<"��ʧ�ܣ�\n";
			exit(0); 
		}
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
				break;
			if(New.ID==Number)
			{
				cout<<"\n\n****��Ҫɾ������ʦ��ϢΪ****��\n";
				cout<<"����\t";
				cout<<"����\n";
				cout<<New.Name<<"\t"<<New.ID<<endl; 
				if(New.counter==0)                                //�ж��鼮�Ƿ��� 
				{
					int PW;//���� 
					cout<<"���������룺";
					cin>>PW;
					cin.ignore();
					if(New.Password==PW)//�ж������Ƿ���ȷ 
					{
						char ch;//ѡ�� 
						cout<<"ȷ��ɾ����(y/n)";
						cin>>ch;
						if(ch=='y')
						{ 
							New.ID=0;//�ɹ�ɾ�������Ź��� 
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
						cout<<"�������\n";
						break; 
					} 
				}
				if(New.counter!=0)
				{
					outfile.write((char*)&New,sizeof(New));
					cout<<"\n\n***ɾ��ʧ�ܣ�������Ϊ�����鼮***\n";
					break; 
				}
				Number=0;//�жϱ�־��0 
			
			}
			else
			{
				outfile.write((char*)&New,sizeof(New));
			}	 
		}
		infile.close();
		outfile.close();
		infile.open("Treader3.dat",ios::in|ios::binary);//���µ���Ϣ�Ӹ��������� 
		outfile.open("Treader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"���ļ�ʧ�ܣ�\n";
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
	if(choice==2)//������ѧ��
	{
		infile.open("Sreader.dat",ios::in|ios::binary);
		outfile.open("Sreader3.dat",ios::out|ios::binary);//Treader3�ļ�ֻ��һ��������������ʱ���Treader��������ݣ����������ɾ������ 
		cout<<"�����뽫Ҫɾ��ѧ����ѧ�ţ�";
		cin>>Number;
		cin.ignore();
		if(infile.fail())
		{
			cout<<"��ʧ�ܣ�\n";
			exit(0); 
		}
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
				break;
			if(New.ID==Number)
			{
				cout<<"\n\n****��Ҫɾ����ѧ����ϢΪ****��\n";
				cout<<"����\t";
				cout<<"ѧ��\t\t";
				cout<<"Ժϵ\t\n"; 
				cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.Depart<<endl; 
				if(New.counter==0)                                //�ж��鼮�Ƿ��� 
				{
					int PW;//���� 
					cout<<"���������룺";
					cin>>PW;
					cin.ignore();
					if(New.Password==PW)//�ж������Ƿ���ȷ 
					{
						char ch;//ѡ�� 
						cout<<"ȷ��ɾ����(y/n)";
						cin>>ch;
						if(ch=='y')
						{ 
							New.ID=0;//�ɹ�ɾ����ѧ�Ź��� 
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
						cout<<"�������\n";
						break; 
					} 
				}
				if(New.counter!=0) 
				{
					outfile.write((char*)&New,sizeof(New));
					cout<<"\n\n***ɾ��ʧ�ܣ�������δ�����鼮***\n";
					break; 
				}
				Number=0;//�жϱ�־��0 
			
			}
			else
			{
				outfile.write((char*)&New,sizeof(New));
			}	 
		}
		infile.close();
		outfile.close();
		infile.open("Sreader3.dat",ios::in|ios::binary);//���µ���Ϣ�Ӹ��������� 
		outfile.open("Sreader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"���ļ�ʧ�ܣ�\n";
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
		cout<<"\n\n***ȡ��ɾ��***\n"; 
	 } 
}

//�޸���Ϣ
void BasicMessage::modInfo() 
{
	system("cls");
	fstream infile,outfile;
	int choice;
	long long Id;
	message New;
	cout<<"\n\n***������Ҫ�޸���Ϣ�˵����***\n";
	cout<<"1:��ʦ\t"<<"2:ѧ��\t3:ȡ��\n";
	cin>>choice;
	cin.ignore();
	if(choice==1)//�޸���ʦ 
	{
		cout<<"\n\n***�������޸���Ϣ��ʦ�Ĺ���***\n";
		cin>>Id;
		int flag=0;//��־ 
		infile.open("Treader.dat",ios::in|ios::binary);
		outfile.open("Treader3.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"��ʧ��!\n";
			exit(0); 
		}
		while(!infile.eof())
		{
			int PW;//���� 
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
			{
				if(flag==0)
					cout<<"\n\n***��ѯʧ��***\n"; 
				break;
			}
			if(New.ID==Id)
			{
				cout<<"\n\n***��Ҫ�޸ĵ���ʦ��ϢΪ***\n";
				cout<<"����\t����\n";
				cout<<New.Name<<"\t"<<New.Name<<"\t"<<endl;
				cout<<"\n\n***����������***\n";
				cin>>PW;
				int count=0;//�����������������������Ĵ���
				while(1)
				{ 
					if(New.Password==PW)                                        //���� 
					{
						int a;//ѡ�� 
						cout<<"\n\n***��ѡ����Ҫ�޸ĵ���Ϣ***\n";
						cout<<"1:����\t2:����\t3:����\t4:���±༭\t5:�˳��༭\n";
						cin>>a;
						if(a==1)
						{
							cout<<"������";
							cin>>New.Name;
							outfile.write((char*)&New,sizeof(New));	 
						}
						if(a==2)
						{
							cout<<"���ţ�";
							cin>>New.ID;
							outfile.write((char*)&New,sizeof(New)); 
						}
						if(a==3)
						{
							cout<<"���룺";
							cin>>New.Password;
							outfile.write((char*)&New,sizeof(New));
						}
						if(a==4)
						{
							cout<<"������";
							cin>>New.Name;
							cout<<"���ţ�";
							cin>>New.ID;
							cout<<"���룺";
							cin>>New.Password;
							outfile.write((char*)&New,sizeof(New));
						}
						if(a==5)
						{
							cout<<"\n\n***ȡ���޸�***\n";
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
							cout<<"\n\n***�������������࣡�޸�ʧ��***\n";
							Id=0;
							break; 
						} 
						cout<<"�����������������\n";
						cin>>PW;
						count++; //������������ʧ�ܴ��� 
					}
				}
				flag++;
			}
			else
				outfile.write((char*)&New,sizeof(New));
		}
		infile.close();
		outfile.close();
		infile.open("Treader3.dat",ios::in|ios::binary);//���µ���Ϣ�Ӹ��������� 
		outfile.open("Treader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"���ļ�ʧ�ܣ�\n";
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
		cout<<"\n\n***�����Ƿ�����޸�(y/n)***\n";
		cin>>ch;
		if(ch=='y')
			modInfo();
		else
			system("cls"); 
	}
	if(choice==2)//�޸�ѧ����Ϣ 
	{
		cout<<"�������޸���Ϣѧ����ѧ�ţ�";
		cin>>Id;
		int flag=0;
		infile.open("Sreader.dat",ios::in|ios::binary);
		outfile.open("Sreader3.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"��ʧ��!\n";
			exit(0); 
		}
		while(!infile.eof())
		{
			int PW;//���� 
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
			{
				if(flag==0)
					cout<<"\n\n***����ʧ��***\n";
				break;
			}
			if(New.ID==Id)
			{
				cout<<"\n\n***��Ҫ�޸ĵ�ѧ����ϢΪ***\n";
				cout<<"����\tѧ��\t\tԺϵ\n";
				cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.Depart<<endl;
				cout<<"\n\n***����������***\n";
				cin>>PW;
				cin.ignore();
				int count=0;//�����������������������Ĵ���
				while(1)
				{ 
					if(New.Password==PW)                                        //���� 
					{
						int a;//ѡ�� 
						cout<<"\n\n***��ѡ����Ҫ�޸ĵ���Ϣ***\n";
						cout<<"1:����\t2:ѧ��\t3:����\t4:���±༭\t5:�˳��༭\n";
						cin>>a;
						if(a==1)
						{
							cout<<"������";
							cin>>New.Name;
							outfile.write((char*)&New,sizeof(New));	 
						}
						if(a==2)
						{
							cout<<"ѧ�ţ�";
							cin>>New.ID;
							if(New.ID<10000000||New.ID>170000000)//�ж�ѧ�ź���Դ��д���� 
							{
								cout<<"ѧ�Ŵ�������������\n";
								cin>>New.ID;
							}
							if(New.ID/10000000==1)
							{
								char dep[21]={"�����ѧԺ"}; 
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==2)
							{
								char dep[21]={"��Դ�붯��ѧԺ"};
								strcpy(New.Depart,dep); 
							}
							if(New.ID/10000000==3)
							{
								char dep[21]={"�Զ���ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==4)
							{
								char dep[21]={"������Ϣ����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==5)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==6)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}	
							if(New.ID/10000000==7)
							{
								char dep[21]={"�񺽷���ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==8)
							{
								char dep[21]={"��ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==9)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==10)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==11)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==12)
							{
								char dep[21]={"�����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==15)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==16)
							{
								char dep[21]={"�������ѧ�����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							outfile.write((char*)&New,sizeof(New)); 
						}
						if(a==3)
						{
							cout<<"���룺";
							cin>>New.Password;
							cin.ignore();
							outfile.write((char*)&New,sizeof(New));
						}
						if(a==4)
						{
							cout<<"������";
							cin>>New.Name;
							cout<<"ѧ�ţ�";
							cin>>New.ID;
							if(New.ID<10000000||New.ID>170000000)//�ж�ѧ�ź���Դ��д���� 
							{
								cout<<"ѧ�Ŵ�������������\n";
								cin>>New.ID;
							}
							if(New.ID/10000000==1)
							{
								char dep[21]={"�����ѧԺ"}; 
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==2)
							{
								char dep[21]={"��Դ�붯��ѧԺ"};
								strcpy(New.Depart,dep); 
							}
							if(New.ID/10000000==3)
							{
								char dep[21]={"�Զ���ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==4)
							{
								char dep[21]={"������Ϣ����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==5)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==6)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}	
							if(New.ID/10000000==7)
							{
								char dep[21]={"�񺽷���ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==8)
							{
								char dep[21]={"��ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==9)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==10)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==11)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==12)
							{
								char dep[21]={"�����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==15)
							{
								char dep[21]={"����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							if(New.ID/10000000==16)
							{
								char dep[21]={"�������ѧ�����ѧԺ"};
								strcpy(New.Depart,dep);
							}
							cout<<"���룺";
							cin>>New.Password;
							outfile.write((char*)&New,sizeof(New));
						}
						if(a==5)
						{
							cout<<"\n\n***ȡ���޸�***\n";
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
							cout<<"\n\n***�������������࣡�޸�ʧ��***\n";
							Id=0;
							break; 
						} 
						cout<<"\n\n***�����������������***\n";
						cin>>PW;
						count++; //������������ʧ�ܴ��� 
					}
				}
				flag++;
			}
			else
				outfile.write((char*)&New,sizeof(New));
		}
		infile.close();
		outfile.close();
		infile.open("Sreader3.dat",ios::in|ios::binary);//���µ���Ϣ�Ӹ��������� 
		outfile.open("Sreader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"���ļ�ʧ�ܣ�\n";
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
		cout<<"\n\n***�����Ƿ�����޸�(y/n)***\n";
		cin>>ch;
		if(ch=='y')
			modInfo();
		else
			system("cls"); 
	}
	if(choice==3)
	{
		cout<<"\n\n***ȡ���޸�***\n";
	} 
}

//��ѯ��Ϣ
void BasicMessage::searchInfo() 
{
	system("cls");
	fstream infile;
	int choice;
	message New;
	cout<<"\n\n***��������Ҫ���ҵĶ���***\n";
	cout<<"1:��ʦ\t2:ѧ��\t3:Ժϵ\t4:ȡ��\n"; 
	cin>>choice;
	if(choice==1)//���Ҷ�������ʦ 
	{
		char Name3[21];
		int flag=0;//�ж��Ƿ���ҵ��ı�־ 
		cout<<"\n\n***��������Ҫ������ʦ������***\n";
		cin>>Name3;
		infile.open("Treader.dat",ios::in|ios::binary);
		if(infile.fail())
		{
			cout<<"��ʧ��!\n";
			exit(0);
		}
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
			{
				if(flag==0)
					cout<<"\n\n***����ʧ��***\n"; 
				break;
			}
			if(strcmp(New.Name,Name3)==0)
			{
				cout<<"\n\n***�����ǲ��ҵ���ʦ��Ϣ***\n";
				cout<<"����\t����\t\t�����鼮\t����ʱ��\t�����������죩\n";
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t\t"<<"��"<<"\t";
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
	if(choice==2)//���Ҷ�����ѧ�� 
	{
		char Name3[21];
		int flag=0;//�ж��Ƿ���ҵ��ı�־ 
		cout<<"\n\n***��������Ҫ����ѧ��������***\n";
		cin>>Name3;
		infile.open("Sreader.dat",ios::in|ios::binary);
		if(infile.fail())
		{
			cout<<"��ʧ�ܣ�\n";
			exit(0);
		}
		while(!infile.eof())
		{
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
			{
				if(flag==0)
					cout<<"\n\n***����ʧ��***\n"; 
				break;
			}
			if(strcmp(New.Name,Name3)==0)
			{
				cout<<"\n\n***�����ǲ��ҵ�ѧ����Ϣ***\n";
				cout<<"����\tѧ��\t\tԺϵ\t\t�����鼮\t����ʱ��\t������������\n";
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t"<<New.Depart<<"\t"<<"��"<<"\t\t";
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
	if(choice==3)//���Ҷ�����Ժϵ
	{
		int a; 
		cout<<"\n\n***��������Ҫ���ҵ�Ժϵ����***\n";
		cin>>a;                                               //�������� 
		cout<<endl; 
		infile.open("Sreader.dat",ios::in|ios::binary);
		if(infile.fail())
		{
			cout<<"��ʧ�ܣ�\n";
			exit(0);
		}
		int flag=0;
		while(!infile.eof())
		{
			
			infile.read((char*)&New,sizeof(New));
			if(infile.fail())
			{
				if(flag==0)
					cout<<"\n\n***����ѯѧԺ������Ϣ***\n"; 
				break;
			}
			if(New.ID/10000000==a)
			{
				cout<<"Ժϵ\t\t����\t\tѧ��\t\t�����鼮��\n";
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
		cout<<"\n\n***ȡ����ѯ***\n"; 
	}
	char ch;
	cout<<"\n\n***�����Ƿ��������(y/n)***\n";
	cin>>ch;
	if(ch=='y')
		searchInfo();
	else	
		cout<<"\n\n***�˳�����***\n";
		system("cls");  
}

//չʾ��Ϣ
void BasicMessage::showInfo() 
{
	fstream outfile;
	message New;
	int choice;
	cout<<"\n\n***��ѡ����ʾ��Ϣ����***\n";
	cout<<"1:��ʦ\t2:ѧ��\t3:ȫ��\t4:����\n";
	cin>>choice;
	if(choice==2)
	{ 
		int flag=0;//�жϱ�־ 
		outfile.open("Sreader.dat",ios::in|ios::binary);
		if(outfile.fail())
		{
			cout<<"��ʧ�ܣ�\n";
			exit(0); 
		}
		while(!outfile.eof())
		{
			outfile.read((char*)&New,sizeof(New));
			if(outfile.fail())
			{
				if(flag==0)
				{
					cout<<"\n\n***ѧ����Ϣ��Ϊ��***\n"; 
				}
				break;
			}
			if(New.ID!=0)
			{
				cout<<"\n\n***ѧ����ϢΪ***\n";
				cout<<"����\tѧ��\t";
				cout<<"�����鼮\t";
				cout<<"����ʱ�䣨�죩\t\t";
				cout<<"����ʱ��\t\t";
				cout<<"Ժϵ\t"<<endl; 
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t"<<"��"<<"\t\t"<<"0"<<"\t\t";
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
		int flag=0;//�жϱ�־ 
		if(outfile.fail())
		{
			cout<<"��ʧ�ܣ�\n";
			exit(0); 
		}
		while(!outfile.eof())
		{
			outfile.read((char*)&New,sizeof(New));
			if(outfile.fail())
			{
				
				if(flag==0)
				{
					cout<<"\n\n***��ʦ��Ϣ��Ϊ��***\n"; 
				}
				break;
			} 
			if(New.ID!=0)
			{
				cout<<"\n\n��ʦ��ϢΪ***\n";
				cout<<"����\t����\t";
				cout<<"�����鼮\t";
				cout<<"����ʱ�䣨�죩\t\t";
				cout<<"����ʱ��\t\t";
				cout<<endl;
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t"<<"��"<<"\t\t"<<"0"<<"\t\t";
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
			cout<<"��ʧ�ܣ�\n";
			exit(0); 
		}
		while(!outfile.eof())
		{
			outfile.read((char*)&New,sizeof(New));
			if(outfile.fail())
			{
				if(flag==0)
					cout<<"\n\n***ѧ����Ϣ��Ϊ��***\n"; 
				break;
			}
			if(New.ID!=0)
			{
				cout<<"\n\n***ѧ����ϢΪ***\n";
				cout<<"����\tѧ��\t";
				cout<<"�����鼮\t";
				cout<<"����ʱ�䣨�죩\t\t";
				cout<<"����ʱ��\t\t";
				cout<<"Ժϵ\t"<<endl;
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t"<<"��"<<"\t\t"<<"0"<<"\t\t";
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
			cout<<"��ʧ�ܣ�\n";
			exit(0); 
		}
		while(!outfile.eof())
		{
			outfile.read((char*)&New,sizeof(New));
			if(outfile.fail())
			{
				if(flag==0)
					cout<<"\n\n***��ʦ��Ϣ��Ϊ��***\n"; 
				break;
			}
			if(New.ID!=0)
			{ 
				cout<<"\n\n��ʦ��ϢΪ***\n";
				cout<<"����\t����\t";
				cout<<"�����鼮\t";
				cout<<"����ʱ�䣨�죩\t\t";
				cout<<"����ʱ��\t\t";
				cout<<endl;
				if(New.counter==0)
				{
					cout<<New.Name<<"\t"<<New.ID<<"\t"<<"��"<<"\t\t"<<"0"<<"\t\t";
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
		cout<<"\n\n***ȡ����Ϣչʾ***\n";
	} 
}

//��ʽ����Ϣ
void BasicMessage::formatInfo() 
{
	fstream infile,infile1,infile3,infile4;
	int choice;
	cout<<"\n\n***��ѡ���ʽ����Ϣ����***\n";
	cout<<"1:��ʦ\t2:ѧ��\t3:ȫ��\t4:ȡ��\n";
	cin>>choice;
	if(choice==1)
	{ 
		infile.open("Treader.dat",ios::out|ios::binary);
		infile1.open("Treader.dat",ios::out|ios::binary);
		if(infile.fail())
		{
			cout<<"��ʧ�ܣ�\n";
			exit(0);
		}
		if(infile1.fail())
		{
			cout<<"��ʧ�ܣ�\n";
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
			cout<<"��ʧ�ܣ�\n";
			exit(0);
		}
		if(infile1.fail())
		{
			cout<<"��ʧ�ܣ�\n";
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
			cout<<"��ʧ�ܣ�\n";
			exit(0);
		}
			if(infile1.fail())
		{
			cout<<"��ʧ�ܣ�\n";
			exit(0);
		}
			if(infile3.fail())
		{
			cout<<"��ʧ�ܣ�\n";
			exit(0);
		}
			if(infile4.fail())
		{
			cout<<"��ʧ�ܣ�\n";
			exit(0);
		}
		infile.close();
		infile1.close();
		infile3.close();
		infile4.close();
	}
	if(choice==4)
	{
		cout<<"\n\n***ȡ����ʽ��***\n";
	}
}  
