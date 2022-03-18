#include "librarian.h"

int Librarian::Librarian_Number=1;

//增加图书
void Librarian::Book_Add(Book *B)
{
    string aa;
    cout<<"---------------添加图书---------------"<<endl;
    while(1)
    {
        cin>>B[Book::Book_Number];
        ofstream bookmessage("Bookmessage.txt",ios::app);
        if(bookmessage.is_open())
        {
            bookmessage << getCurrentSystemTime();
            bookmessage << "操作:增加图书 "<<endl;
            bookmessage <<B[Book::Book_Number]<<endl;
            bookmessage.close();
        }
        Book::Book_Number++;
        cout<<"录入成功！"<<endl;
        aa=cin.get();
        cout<<"按任意键继续录入(输入'0'可返回主菜单)，";
        aa=cin.get();
        if(aa=="0")break;
    }
}

//删除图书
void Librarian::Book_Dele(Book *B)
{
    cout<<"---------------删除图书---------------"<<endl;
    string a;
    if(Book::Book_Number==0)cout<<"目前无图书,请先添加图书!"<<endl;
    else
    {
        cout<<"请输入图书编号或书名";
        cin>>a;int flag=0,find=0;
        for(int j=0;j<Book::Book_Number;j++)
        {
            if(a==B[j].GetIsbn()||a==B[j].GetName())
            {flag=1;find=j;break;}
        }
        if(flag==1)
        {
            char a;
            cout<<"已经找到图书，对应编号为:"<<B[find].GetIsbn()<<"书名为:"<<B[find].GetName()<<"，是否选择删除？(y or n)"<<endl;
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
                    bookmessage << "操作:删除图书 "<<endl;
                    bookmessage <<B[find]<<endl;
                    bookmessage.close();
                }
                cout<<"删除成功！"<<endl;
            }
            else
            {
                cout<<"已取消删除。";
            }
        }
        else
            cout<<"图书不存在，请确认是否已经录入。"<<endl;
    }
}

//修改图书
void DisplayAlter()
{
    cout<<"请选择修改项:"<<endl;
    cout<<"1-修改编号"<<endl;
    cout<<"2-修改书名"<<endl;
    cout<<"3-修改作者"<<endl;
    cout<<"4-修改出版社"<<endl;
    cout<<"5-修改单价"<<endl;
    cout<<"0-退出修改"<<endl;
}

void Librarian::Book_Alter(Book *B)
{   string a;
    cout<<"---------------修改图书---------------"<<endl;
    if(Book::Book_Number==0)cout<<"目前无图书,请先添加图书"<<endl;
    else{
        cout<<"请输入图书编号或书名";
        cin>>a;int flag=0,find=0;
        for(int j=0;j<Book::Book_Number;j++)
        {
            if(a==B[j].GetIsbn()||a==B[j].GetName())
            {flag=1;find=j;break;}
        }
        if(flag==1)
        {
            char b;
            cout<<"已经找到图书，是否选择修改？(y or n)"<<endl;
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
                        cout<<"请输入修改后的编号:"<<endl;
                        int flag=1;
                        cin>>a;
                        for(int l=0;l<Book::Book_Number;l++)
                        {
                            if(B[l].GetIsbn()==a)
                            { flag=0;break;}
                        }
                        if(flag){B[find].SetIsbn(a);cout<<"已修改!"<<endl;break;}
                        else cout<<"已存在该编号，请修改!"<<endl;
                    }
                        break;
                    }
                    case 2:{
                        cout<<"请输入修改后的书名:"<<endl;
                        cin>>a;B[find].SetName(a);cout<<"已修改!"<<endl;break;}
                    case 3:{
                        cout<<"请输入修改后的作者名:"<<endl;
                        cin>>a;B[find].SetAuthor(a);cout<<"已修改!"<<endl;break;}
                    case 4:{
                        cout<<"请输入修改后的出版社名:"<<endl;
                        cin>>a;B[find].SetPub(a);cout<<"已修改!"<<endl;;break;}
                    case 5:{
                        cout<<"请输入修改后的价格:"<<endl;
                        double p;
                        cin>>p;B[find].SetPrice(p);cout<<"已修改!"<<endl;break;}
                    case 0:
                    {
                        break;
                    }
                    default: cout<<"请输入正确数字:"<<endl;
                }
                ofstream bookmessage("Bookmessage.txt",ios::app);
                if(bookmessage.is_open())
                {
                    bookmessage << getCurrentSystemTime();
                    bookmessage << "操作:修改图书 "<<endl;
                    bookmessage <<B[find]<<endl;
                    bookmessage.close();
                }
            }
        }
    }
}

//查询图书
void Librarian::Book_Find(Book *B)
{
    cout<<"-------查询图书-------"<<endl;
    cout<<"请输入图书编号或书名:";
    string a1;
    cin>>a1;int flag=0,count=0;
    for(int j=0;j<Book::Book_Number;j++)
    {
        if(a1==B[j].GetIsbn()||a1==B[j].GetName())
        {flag=1;cout<<B[j];count++;}
    }
    if(count==0)cout<<"未找到此书..."<<endl;
    else
        cout<<"共找到"<<count<<"本书。"<<endl;
}

//统计图书
void Librarian::Book_AddUp(Book *B)
{
    cout<<"目前共有"<<Book::Book_Number<<"本书。"<<endl;
    for(int i=0;i<Book::Book_Number;i++)
    {
        cout<<B[i];
    }
}
