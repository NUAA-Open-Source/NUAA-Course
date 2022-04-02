#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
	int year;//年
	int month;//月
	int day;//日
public:
	void setDate()//设置信息 
	{
		//cout<<"请输入日期："<<endl;
		cout<<"月：";
		cin>>month;
		cout<<"日：";
		cin>>day;
		cout<<"年：";
		cin>>year; 
	}
	void showDate()
	{
		cout<<month<<"/"<<day<<"/"<<year; 
	}
};//累加日期;
#endif 
