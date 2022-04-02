#include "reader.h"

int Reader::Reader_Number=0;

void Reader::Book_show(Book *B)
{
    for(int i=0;i<Book::Book_Number;i++)
    {
        cout<<B[i];
    }
}

void Reader::Book_LR()
{
    
    cout<<"---------������Ϣ---------"<<endl;
    int ST=10,TE=20;
    int flag=0;
    cout<<"�û����:";
    if(Is_teacher==true)
    {cout<<"��ʦ"<<"     "<<"���Խ�������:"<<TE<<"��"<<endl;}
    else
    {   cout<<"ѧ��"<<"     "<<"���Խ�������:"<<ST<<"��"<<endl;}
    
    cout<<"��ǰ������Ϣ:"<<endl;
    for(int i=0;i<=s->Book_Number;i++)
    {
        if(s[i].GetIs_Lend()==true){flag=1;break;}
    }
    if(flag==0)cout<<"�޽����¼\n";
    else
    {
        int LendBookNumber=0;
        for(int i=0;i<=Book::Book_Number;i++)
        {
            if(s[i].GetIs_Lend()==true)
            { s[i].Display();
                LendBookNumber++;
            }
        }
        
        if(Is_teacher==true)
        {
            cout<<"�����Խ�"<<TE-LendBookNumber<<"����."<<endl;}
        else
        {
            cout<<"�����Խ�"<<ST-LendBookNumber<<"����."<<endl;}
    }
}

void Reader::Book_Lend(Book *B)
{
    for(int i=0;i<Book_Number;i++)
    {
        (s+i)->SetIsbn((B+i)->GetIsbn());
        (s+i)->SetName((B+i)->GetName());
        (s+i)->SetAuthor((B+i)->GetAuthor());
        (s+i)->SetPub((B+i)->GetPub());
        (s+i)->SetPrice((B+i)->GetPrice());
        (s+i)->Book_Number=(B+i)->Book_Number;
        if(Is_teacher==true)
            (s+i)->SetDeadline(60);
        else
            (s+i)->SetDeadline(30);
    }
    Book *b=B;string a;
    cout<<"---------����---------"<<endl;
    cout<<"��������Ҫ�����鼮�ı�Ż�����:";
    cin>>a;int Find=0,flag1=0;int LendBookNumber=0;
    for(int j=0;j<=Book::Book_Number;j++)
    {
        if((a==b[j].GetIsbn()||a==b[j].GetName())&&b[j].GetIs_Lend()==false)
        {
            flag1=1;Find =j;break;
        }
    }
    
    for(int i=0;i<=Book::Book_Number;i++)
    {
        if(s[i].GetIs_Lend()==true)
        {
            LendBookNumber++;
        }
    }
    if(!flag1)cout<<"ͼ�鲻���ڻ��Ѿ������!"<<endl;
    else
    {
        if(Is_teacher==true&&LendBookNumber==20){
            throw LendBookNumber;
        }
        else if(Is_teacher==false&&LendBookNumber==10){
            throw LendBookNumber;
        }
        cout<<"���ĳɹ�!"<<endl;
        b[Find].SetIs_Lend(true);
        s[Find].SetIs_Lend(true);
        s[Find].SetTime(getCurrentSystemTime());
        s[Find].SetDeadline(s[Find].GetDeadline());
        ofstream lendmessage("Lendmessage.txt",ios::app);
        if(lendmessage.is_open())
        {
            lendmessage << "����:"<<LogName<<endl;
            lendmessage << "    ������:"<<s[Find].GetIsbn();
            lendmessage << "    ����ʱ��:"<<s[Find].Gettime()<<endl;
            lendmessage.close();
        }
    }
}

void Reader::Book_Return(Book *B)
{
    Book *b=B;int flag=0,Find=0;
    cout<<"---------����---------"<<endl;
    string a;
    cout<<"��������Ҫ�黹�鼮�ı�Ż�����:";
    cin>>a;
    for(int j=0;j<Book::Book_Number;j++)
    {
        if(a==b[j].GetIsbn()||a==b[j].GetName())
        {
            flag=1;Find =j;break;
        }
    }
    if(flag==1){
        if(s[Find].GetIs_Lend()==true)
        {
            
            cout<<"�黹ʱ��:"<<getCurrentSystemTime()<<endl;
            string lend_time=s[Find].Gettime();
            string return_time=getCurrentSystemTime();
            int mml,mmr,ddl,ddr;
            //�ж��Ƿ�ʱ
            mmr=return_time[6]-'0'+(return_time[5]-'0')*10;
            mml=lend_time[6]-'0'+(lend_time[5]-'0')*10;
            ddr=return_time[9]-'0'+(return_time[8]-'0')*10;
            ddl=lend_time[9]-'0'+(lend_time[8]-'0')*10;
            int day=0;
            if(Is_teacher==true) day=60;
            else day=30;
            if(mmr*30+ddr-mml*30-ddl<=day)
            {   s[Find].SetIs_Lend(false);
                b[Find].SetIs_Lend(false);
                ofstream lendmessage("Lendmessage.txt",ios::app);
                if(lendmessage.is_open())
                {
                    lendmessage << "����:"<<LogName<<endl;
                    lendmessage << "    ������:"<<s[Find].GetIsbn();
                    lendmessage << "    ����ʱ��:"<<return_time<<endl;
                    lendmessage.close();
                }
                cout<<"�黹�ɹ���"<<endl;}
            else
                throw mmr*30+ddr-mml*30-ddl-day;
        }
        else
        {
            cout<<"����δ������"<<endl;
        }
    }
    else
    {
        cout<<"δ�ҵ����飡"<<endl;
    }
}
