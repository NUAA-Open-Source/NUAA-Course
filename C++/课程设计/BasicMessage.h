#ifndef BASICMESSAGE_H
#define BASICMESSAGE_H
#include"Date.h"
class BasicMessage:public Date                      //�̳�Date�� 
{
protected:
	struct message//�ṹ�崢����Ϣ 
	{
		char Name[21];//���� 
		char BookName1[5][21];//����
		//char BookName2[21];
		//char BookName3[21];
		//char BookName4[21]; 
		//char BookNum[21];//ͼ����
		char Depart[21];//Ժϵ
		char Identity;//��� 
		int ReserveDay[5];//Ԥ��ʱ��
		long long ID;//ѧ��
		int counter;//������ 
		int Password;//����	
		Date date[5];//���� 
		//BookInfo book_;//������� 
	};
public:
	BasicMessage(){ 
		message New;
		New.counter=0;
	}
	//friend void menu_select();//��Ԫ���������ɲ˵� 
	//friend void menu_select1();
	//friend void menu_select2();
	//friend void menu_select3();
	void setInfo();//������Ϣ 
	void delInfo();//ɾ����Ϣ 
	void modInfo();//�޸���Ϣ 
	void searchInfo();//��ѯ��Ϣ 
	void showInfo();//չʾ��Ϣ 
	void formatInfo();//��ʽ����Ϣ	
};
#endif 
