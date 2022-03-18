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

void jiemian()//主界面
{   
    cout <<endl<< "\t◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆" ;
	cout <<endl<< "\t◆                                                              ◆" ;
    cout <<endl<< "\t◆                       NUAA图书管理系统                       ◆" ;
	cout <<endl<< "\t◆                                                              ◆" ;
    cout <<endl<< "\t◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆" ;
	cout <<endl<< "\t◆                                                              ◆" ;
    cout <<endl<< "\t◆                         1.  注册                             ◆" ;
	cout <<endl<< "\t◆                                                              ◆" ;
	cout <<endl<< "\t◆                         2.  登录                             ◆" ;
	cout <<endl<< "\t◆                                                              ◆" ;
	cout <<endl<< "\t◆                         3.退出系统                           ◆" ;
	cout <<endl<< "\t◆                                                              ◆" ;
	cout <<endl<< "\t◆                                                              ◆" ;
	cout <<endl<< "\t◆                                                              ◆" ;
	cout <<endl<< "\t◆                                                              ◆" ;
	cout <<endl<< "\t◆                                                              ◆" ;
	cout <<endl<< "\t◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆" ;
	cout <<endl<<"\t★请输入1~3的数字:";
}
void reajm()//读者界面
{
    cout<<"①-------查看图书"<<endl;
    cout<<"②-------借书"<<endl;
    cout<<"③-------还书"<<endl;
    cout<<"④-------查询借还信息"<<endl;
    cout<<"⑤-------修改密码"<<endl;
    cout<<"⑥-------退出"<<endl;
}
void libjm()//图书管理员界面
{
    cout<<"①-------增加图书"<<endl;//①②③④⑤⑥⑦⑧⑨
    cout<<"②-------修改图书"<<endl;
    cout<<"③-------删除图书"<<endl;
    cout<<"④-------查询图书"<<endl;
    cout<<"⑤-------统计图书"<<endl;
    cout<<"⑥-------修改密码"<<endl;
    cout<<"⑦-------退出"<<endl;
}
void admjm()//系统管理员界面
{
    cout<<"①-------增加读者"<<endl;//①②③④⑤⑥⑦⑧⑨
    cout<<"②-------删除读者"<<endl;
    cout<<"③-------增加图书管理员"<<endl;
    cout<<"④-------删除图书管理员"<<endl;
    cout<<"⑤-------读者权限修改"<<endl;
    cout<<"⑥-------图书管理员权限修改"<<endl;
    cout<<"⑦-------修改用户密码"<<endl;
    cout<<"⑧-------修改密码"<<endl;
    cout<<"⑨-------退出"<<endl;
}
Book B[100]{Book("1000","面向对象C++","张三","666",51.3),Book("1001","C基础","李四","777",48.8),Book("1002","python","王五","888",59.9)};
User U[100];
Reader R[100];
Librarian L[100]{Librarian("L","8",U) };
Admin A[100]{Admin("A","8",U)};
Log c;

int main(int argc, const char * argv[]) 
{
    while (1) {
        jiemian();
        int a;string aa;cin>>aa;//防止一开始输入序号输错出现bug.
        if(aa=="1")a=1;
        else if(aa=="2")a=2;
        else if(aa=="3")a=3;
        else {
            cout<<"出错,请输入1～3内的数字"<<endl;continue;
        }
        switch (a) {
                
            case 1:
            {cout<<"             读者注册"<<endl;
                R[Reader::Reader_Number].zc(U, c,R);
                break;}
                
                
            case 2:
            {
                cout<<"             登  陆"<<endl;
                c.Login(U);
                if(c.Is_Log==false)break;
                
                
                if(c.tp.Judge()==5)//图书管理员
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
                
                else if(c.tp.Judge()==6)//系统管理员
                {
                    
                    int n=1;
                    while (n) {
                        admjm();
                        int b;cin>>b;
                        switch (b) {
                            case 1://增加读者
                            {
                                A[c.number].Reader_Add(U, R);
                                break;}
                            case 2://删除读者
                            {
                                A[c.number].Reader_Dele(U, R);
                                break;}
                            case 3://增加图书管理员
                            {
                                A[c.number].Librarian_Add(U,L);
                                break;
                            }
                            case 4://增加图书管理员
                            {
                                A[c.number].Librarian_Dele(U,L);
                                break;
                            }
                            case 5://读者权限修改
                            {
                                A[c.number].Reader_Alter(R,U, A, L);
                                break;
                            }
                            case 6://图书管理员权限修改
                            {
                                A[c.number].Librarian_Alter(L,U, A, R);
                                break;
                            }
                            case 7://修改用户密码
                            {
                                A[c.number].User_keychange(U);
                                break;
                            }
                            case 8://修改密码
                            {
                                A[c.number].key_change(U);
                                break;
                            }
                            default:
                                n=0;break;
                        }
                    }
                }
                
                else if(c.tp.Judge()==7)//读者
                {
                    int n=1;
                    while (n) {
                        reajm();
                        int b;cin>>b;
                        switch (b) {
                            case 1://书本展示
                            {
                                R[c.number].Book_show(B);
                                break;
                            }
                            case 2://借书
                            {
                                try{
                                    R[c.number].Book_Lend(B);
                                }
                                catch(int Num)
                                {
                                    cout<<"超出最大借书数量，借书失败。"<<endl;
                                }
                                
                                break;}
                            case 3://还书
                            {
                                try{
                                    R[c.number].Book_Return(B);}
                                
                                catch(int day)
                                {
                                    cout<<"归还图书超时"<<day<<"天"<<"罚款50！"<<endl;
                                }
                                break;}
                                
                            case 4://显示借还信息
                            {
                                R[c.number].Book_LR();
                                break;
                            }
                            case 5://修改密码
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
            {cout<<"             系统已退出"<<endl;
                return 0;
                break;}
            default:
                break;
        }
        cin.get();//吸收回车符
        cout<<"按回车键返回主界面\n";
        cin.get();
    }
    return 0;
}

