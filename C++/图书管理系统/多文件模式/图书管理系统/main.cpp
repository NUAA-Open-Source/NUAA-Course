#include <iostream>
#include <fstream>
#include<iomanip>
#include<string>
#include<time.h>
using namespace std;

#include "book.h"
#include "user.h"
#include "log.h"
#include "librarian.h"
#include "reader.h"
#include "admin.h"

void jiemian()//������
{   
    cout <<endl<< "\t������������������������������������������������������������������" ;
	cout <<endl<< "\t��                                                              ��" ;
    cout <<endl<< "\t��                       NUAAͼ�����ϵͳ                       ��" ;
	cout <<endl<< "\t��                                                              ��" ;
    cout <<endl<< "\t������������������������������������������������������������������" ;
	cout <<endl<< "\t��                                                              ��" ;
    cout <<endl<< "\t��                         1.  ע��                             ��" ;
	cout <<endl<< "\t��                                                              ��" ;
	cout <<endl<< "\t��                         2.  ��¼                             ��" ;
	cout <<endl<< "\t��                                                              ��" ;
	cout <<endl<< "\t��                         3.�˳�ϵͳ                           ��" ;
	cout <<endl<< "\t��                                                              ��" ;
	cout <<endl<< "\t��                                                              ��" ;
	cout <<endl<< "\t��                                                              ��" ;
	cout <<endl<< "\t��                                                              ��" ;
	cout <<endl<< "\t��                                                              ��" ;
	cout <<endl<< "\t������������������������������������������������������������������" ;
	cout <<endl<<"\t��������1~3������:";
}
void reajm()//���߽���
{
    cout<<"��-------�鿴ͼ��"<<endl;
    cout<<"��-------����"<<endl;
    cout<<"��-------����"<<endl;
    cout<<"��-------��ѯ�軹��Ϣ"<<endl;
    cout<<"��-------�޸�����"<<endl;
    cout<<"��-------�˳�"<<endl;
}
void libjm()//ͼ�����Ա����
{
    cout<<"��-------����ͼ��"<<endl;//�٢ڢۢܢݢޢߢ��
    cout<<"��-------�޸�ͼ��"<<endl;
    cout<<"��-------ɾ��ͼ��"<<endl;
    cout<<"��-------��ѯͼ��"<<endl;
    cout<<"��-------ͳ��ͼ��"<<endl;
    cout<<"��-------�޸�����"<<endl;
    cout<<"��-------�˳�"<<endl;
}
void admjm()//ϵͳ����Ա����
{
    cout<<"��-------���Ӷ���"<<endl;//�٢ڢۢܢݢޢߢ��
    cout<<"��-------ɾ������"<<endl;
    cout<<"��-------����ͼ�����Ա"<<endl;
    cout<<"��-------ɾ��ͼ�����Ա"<<endl;
    cout<<"��-------����Ȩ���޸�"<<endl;
    cout<<"��-------ͼ�����ԱȨ���޸�"<<endl;
    cout<<"��-------�޸��û�����"<<endl;
    cout<<"��-------�޸�����"<<endl;
    cout<<"��-------�˳�"<<endl;
}
Book B[100]{Book("1000","�������C++","����","666",51.3),Book("1001","C����","����","777",48.8),Book("1002","python","����","888",59.9)};
User U[100];
Reader R[100];
Librarian L[100]{Librarian("L","8",U) };
Admin A[100]{Admin("A","8",U)};
Log c;

int main(int argc, const char * argv[]) 
{
    while (1) {
        jiemian();
        int a;string aa;cin>>aa;//��ֹһ��ʼ�������������bug.
        if(aa=="1")a=1;
        else if(aa=="2")a=2;
        else if(aa=="3")a=3;
        else {
            cout<<"����,������1��3�ڵ�����"<<endl;continue;
        }
        switch (a) {
                
            case 1:
            {cout<<"             ����ע��"<<endl;
                R[Reader::Reader_Number].zc(U, c,R);
                break;}
                
                
            case 2:
            {
                cout<<"             ��  ½"<<endl;
                c.Login(U);
                if(c.Is_Log==false)break;
                
                
                if(c.tp.Judge()==5)//ͼ�����Ա
                {
                    int n=1;
                    while (n) {
                        libjm();
                        int b;cin>>b;
                        switch (b) {
                            case 1:
                            {
                                L[c.number].Book_Add(B);
                                break;}
                            case 2:
                            {
                                L[c.number].Book_Alter(B);
                                break;}
                            case 3:
                            {
                                L[c.number].Book_Dele(B);
                                break;}
                            case 4:
                            {
                                L[c.number].Book_Find(B);
                                break;}
                            case 5:
                            {
                                L[c.number].Book_AddUp(B);
                                break;}
                            case 6:
                            {
                                L[c.number].key_change(U);
                                break;}
                            default:
                                n=0;
                        }
                    }
                }
                
                else if(c.tp.Judge()==6)//ϵͳ����Ա
                {
                    
                    int n=1;
                    while (n) {
                        admjm();
                        int b;cin>>b;
                        switch (b) {
                            case 1://���Ӷ���
                            {
                                A[c.number].Reader_Add(U, R);
                                break;}
                            case 2://ɾ������
                            {
                                A[c.number].Reader_Dele(U, R);
                                break;}
                            case 3://����ͼ�����Ա
                            {
                                A[c.number].Librarian_Add(U,L);
                                break;
                            }
                            case 4://����ͼ�����Ա
                            {
                                A[c.number].Librarian_Dele(U,L);
                                break;
                            }
                            case 5://����Ȩ���޸�
                            {
                                A[c.number].Reader_Alter(R,U, A, L);
                                break;
                            }
                            case 6://ͼ�����ԱȨ���޸�
                            {
                                A[c.number].Librarian_Alter(L,U, A, R);
                                break;
                            }
                            case 7://�޸��û�����
                            {
                                A[c.number].User_keychange(U);
                                break;
                            }
                            case 8://�޸�����
                            {
                                A[c.number].key_change(U);
                                break;
                            }
                            default:
                                n=0;break;
                        }
                    }
                }
                
                else if(c.tp.Judge()==7)//����
                {
                    int n=1;
                    while (n) {
                        reajm();
                        int b;cin>>b;
                        switch (b) {
                            case 1://�鱾չʾ
                            {
                                R[c.number].Book_show(B);
                                break;
                            }
                            case 2://����
                            {
                                try{
                                    R[c.number].Book_Lend(B);
                                }
                                catch(int Num)
                                {
                                    cout<<"��������������������ʧ�ܡ�"<<endl;
                                }
                                
                                break;}
                            case 3://����
                            {
                                try{
                                    R[c.number].Book_Return(B);}
                                
                                catch(int day)
                                {
                                    cout<<"�黹ͼ�鳬ʱ"<<day<<"��"<<"����50��"<<endl;
                                }
                                break;}
                                
                            case 4://��ʾ�軹��Ϣ
                            {
                                R[c.number].Book_LR();
                                break;
                            }
                            case 5://�޸�����
                            {
                                R[c.number].key_change(U);
                                break;
                            }
                            default:
                                n=0;
                        }
                    }
                }
                else break;
                break;}
                
            case 3:
            {cout<<"             ϵͳ���˳�"<<endl;
                return 0;
                break;}
            default:
                break;
        }
        cin.get();//���ջس���
        cout<<"���س�������������\n";
        cin.get();
    }
    return 0;
}

