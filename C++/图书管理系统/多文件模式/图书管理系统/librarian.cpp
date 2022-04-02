#include "librarian.h"

int Librarian::Librarian_Number=1;

//����ͼ��
void Librarian::Book_Add(Book *B)
{
    string aa;
    cout<<"---------------���ͼ��---------------"<<endl;
    while(1)
    {
        cin>>B[Book::Book_Number];
        ofstream bookmessage("Bookmessage.txt",ios::app);
        if(bookmessage.is_open())
        {
            bookmessage << getCurrentSystemTime();
            bookmessage << "����:����ͼ�� "<<endl;
            bookmessage <<B[Book::Book_Number]<<endl;
            bookmessage.close();
        }
        Book::Book_Number++;
        cout<<"¼��ɹ���"<<endl;
        aa=cin.get();
        cout<<"�����������¼��(����'0'�ɷ������˵�)��";
        aa=cin.get();
        if(aa=="0")break;
    }
}

//ɾ��ͼ��
void Librarian::Book_Dele(Book *B)
{
    cout<<"---------------ɾ��ͼ��---------------"<<endl;
    string a;
    if(Book::Book_Number==0)cout<<"Ŀǰ��ͼ��,�������ͼ��!"<<endl;
    else
    {
        cout<<"������ͼ���Ż�����";
        cin>>a;int flag=0,find=0;
        for(int j=0;j<Book::Book_Number;j++)
        {
            if(a==B[j].GetIsbn()||a==B[j].GetName())
            {flag=1;find=j;break;}
        }
        if(flag==1)
        {
            char a;
            cout<<"�Ѿ��ҵ�ͼ�飬��Ӧ���Ϊ:"<<B[find].GetIsbn()<<"����Ϊ:"<<B[find].GetName()<<"���Ƿ�ѡ��ɾ����(y or n)"<<endl;
            cin>>a;if(a=='y')
            {
                for(int k=find;k<Book::Book_Number;k++)
                {
                    if(k==Book::Book_Number-1){Book::Book_Number--;break;}
                    B[k]=B[k+1];
                }
                ofstream bookmessage("Bookmessage.txt",ios::app);
                if(bookmessage.is_open())
                {
                    bookmessage << getCurrentSystemTime();
                    bookmessage << "����:ɾ��ͼ�� "<<endl;
                    bookmessage <<B[find]<<endl;
                    bookmessage.close();
                }
                cout<<"ɾ���ɹ���"<<endl;
            }
            else
            {
                cout<<"��ȡ��ɾ����";
            }
        }
        else
            cout<<"ͼ�鲻���ڣ���ȷ���Ƿ��Ѿ�¼�롣"<<endl;
    }
}

//�޸�ͼ��
void DisplayAlter()
{
    cout<<"��ѡ���޸���:"<<endl;
    cout<<"1-�޸ı��"<<endl;
    cout<<"2-�޸�����"<<endl;
    cout<<"3-�޸�����"<<endl;
    cout<<"4-�޸ĳ�����"<<endl;
    cout<<"5-�޸ĵ���"<<endl;
    cout<<"0-�˳��޸�"<<endl;
}

void Librarian::Book_Alter(Book *B)
{   string a;
    cout<<"---------------�޸�ͼ��---------------"<<endl;
    if(Book::Book_Number==0)cout<<"Ŀǰ��ͼ��,�������ͼ��"<<endl;
    else{
        cout<<"������ͼ���Ż�����";
        cin>>a;int flag=0,find=0;
        for(int j=0;j<Book::Book_Number;j++)
        {
            if(a==B[j].GetIsbn()||a==B[j].GetName())
            {flag=1;find=j;break;}
        }
        if(flag==1)
        {
            char b;
            cout<<"�Ѿ��ҵ�ͼ�飬�Ƿ�ѡ���޸ģ�(y or n)"<<endl;
            cin>>b;
            if(b=='y')
            {
                DisplayAlter();
                int c;cin>>c;
                switch (c)
                {
                    case 1:
                    {while(1)
                    {
                        cout<<"�������޸ĺ�ı��:"<<endl;
                        int flag=1;
                        cin>>a;
                        for(int l=0;l<Book::Book_Number;l++)
                        {
                            if(B[l].GetIsbn()==a)
                            { flag=0;break;}
                        }
                        if(flag){B[find].SetIsbn(a);cout<<"���޸�!"<<endl;break;}
                        else cout<<"�Ѵ��ڸñ�ţ����޸�!"<<endl;
                    }
                        break;
                    }
                    case 2:{
                        cout<<"�������޸ĺ������:"<<endl;
                        cin>>a;B[find].SetName(a);cout<<"���޸�!"<<endl;break;}
                    case 3:{
                        cout<<"�������޸ĺ��������:"<<endl;
                        cin>>a;B[find].SetAuthor(a);cout<<"���޸�!"<<endl;break;}
                    case 4:{
                        cout<<"�������޸ĺ�ĳ�������:"<<endl;
                        cin>>a;B[find].SetPub(a);cout<<"���޸�!"<<endl;;break;}
                    case 5:{
                        cout<<"�������޸ĺ�ļ۸�:"<<endl;
                        double p;
                        cin>>p;B[find].SetPrice(p);cout<<"���޸�!"<<endl;break;}
                    case 0:
                    {
                        break;
                    }
                    default: cout<<"��������ȷ����:"<<endl;
                }
                ofstream bookmessage("Bookmessage.txt",ios::app);
                if(bookmessage.is_open())
                {
                    bookmessage << getCurrentSystemTime();
                    bookmessage << "����:�޸�ͼ�� "<<endl;
                    bookmessage <<B[find]<<endl;
                    bookmessage.close();
                }
            }
        }
    }
}

//��ѯͼ��
void Librarian::Book_Find(Book *B)
{
    cout<<"-------��ѯͼ��-------"<<endl;
    cout<<"������ͼ���Ż�����:";
    string a1;
    cin>>a1;int flag=0,count=0;
    for(int j=0;j<Book::Book_Number;j++)
    {
        if(a1==B[j].GetIsbn()||a1==B[j].GetName())
        {flag=1;cout<<B[j];count++;}
    }
    if(count==0)cout<<"δ�ҵ�����..."<<endl;
    else
        cout<<"���ҵ�"<<count<<"���顣"<<endl;
}

//ͳ��ͼ��
void Librarian::Book_AddUp(Book *B)
{
    cout<<"Ŀǰ����"<<Book::Book_Number<<"���顣"<<endl;
    for(int i=0;i<Book::Book_Number;i++)
    {
        cout<<B[i];
    }
}
