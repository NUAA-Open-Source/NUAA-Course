#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
	int year;//��
	int month;//��
	int day;//��
public:
	void setDate()//������Ϣ 
	{
		//cout<<"���������ڣ�"<<endl;
		cout<<"�£�";
		cin>>month;
		cout<<"�գ�";
		cin>>day;
		cout<<"�꣺";
		cin>>year; 
	}
	void showDate()
	{
		cout<<month<<"/"<<day<<"/"<<year; 
	}
};//�ۼ�����;
#endif 
