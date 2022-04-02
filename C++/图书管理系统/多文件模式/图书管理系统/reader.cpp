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
    
    cout<<"---------借阅信息---------"<<endl;
    int ST=10,TE=20;
    int flag=0;
    cout<<"用户类别:";
    if(Is_teacher==true)
    {cout<<"教师"<<"     "<<"可以借书数量:"<<TE<<"本"<<endl;}
    else
    {   cout<<"学生"<<"     "<<"可以借书数量:"<<ST<<"本"<<endl;}
    
    cout<<"当前借书信息:"<<endl;
    for(int i=0;i<=s->Book_Number;i++)
    {
        if(s[i].GetIs_Lend()==true){flag=1;break;}
    }
    if(flag==0)cout<<"无借书记录\n";
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
            cout<<"还可以借"<<TE-LendBookNumber<<"本书."<<endl;}
        else
        {
            cout<<"还可以借"<<ST-LendBookNumber<<"本书."<<endl;}
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
    cout<<"---------借书---------"<<endl;
    cout<<"请输入需要借阅书籍的编号或书名:";
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
    if(!flag1)cout<<"图书不存在或已经被借出!"<<endl;
    else
    {
        if(Is_teacher==true&&LendBookNumber==20){
            throw LendBookNumber;
        }
        else if(Is_teacher==false&&LendBookNumber==10){
            throw LendBookNumber;
        }
        cout<<"借阅成功!"<<endl;
        b[Find].SetIs_Lend(true);
        s[Find].SetIs_Lend(true);
        s[Find].SetTime(getCurrentSystemTime());
        s[Find].SetDeadline(s[Find].GetDeadline());
        ofstream lendmessage("Lendmessage.txt",ios::app);
        if(lendmessage.is_open())
        {
            lendmessage << "姓名:"<<LogName<<endl;
            lendmessage << "    借书编号:"<<s[Find].GetIsbn();
            lendmessage << "    借书时间:"<<s[Find].Gettime()<<endl;
            lendmessage.close();
        }
    }
}

void Reader::Book_Return(Book *B)
{
    Book *b=B;int flag=0,Find=0;
    cout<<"---------还书---------"<<endl;
    string a;
    cout<<"请输入需要归还书籍的编号或书名:";
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
            
            cout<<"归还时间:"<<getCurrentSystemTime()<<endl;
            string lend_time=s[Find].Gettime();
            string return_time=getCurrentSystemTime();
            int mml,mmr,ddl,ddr;
            //判断是否超时
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
                    lendmessage << "姓名:"<<LogName<<endl;
                    lendmessage << "    还书编号:"<<s[Find].GetIsbn();
                    lendmessage << "    还书时间:"<<return_time<<endl;
                    lendmessage.close();
                }
                cout<<"归还成功！"<<endl;}
            else
                throw mmr*30+ddr-mml*30-ddl-day;
        }
        else
        {
            cout<<"此书未被借阅"<<endl;
        }
    }
    else
    {
        cout<<"未找到此书！"<<endl;
    }
}
