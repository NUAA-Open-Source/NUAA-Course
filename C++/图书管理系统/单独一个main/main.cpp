#include <iostream>
#include <fstream>
#include<iomanip>
#include<string>
#include<time.h>
using namespace std;


//书本类
class Book
{
protected:
    string isbn;//标准代号 
	string name;//书名 
	string author;//作者 
	string publisher;//出版社 
	string time;//日期 
    int deadline;//借书期限
    double price;//价格
    bool Is_Lend;//书是否被借出
public:
    bool Is_teacher;
    static int Book_Number;
    Book(string c,string n,string a,string p,double pr)
    {
        isbn=c;
		name=n;
		author=a;
		publisher=p;
        price =pr;
		Is_Lend=0;
		Book_Number++;
    };
    Book(){Is_Lend=false;}
    string Gettime(){return time;}
    string GetIsbn(){return isbn;}
    string GetName(){return name;}
    string GetAuthor(){return author;}
    string GetPub(){return publisher;}
    int GetDeadline(){return deadline;}
    double GetPrice(){return price;}
    bool GetIs_Lend(){return Is_Lend;}
    void SetDeadline(int);
    void SetTime(string);
    void SetIs_Lend(bool);
    void SetIsbn(string);
    void SetName(string);
    void SetAuthor(string);
    void SetPub(string);
    void SetPrice(float);
    void Display();
    friend const std::string getCurrentSystemTime();//获取现在的时间
    friend istream& operator >> (istream &stream,Book &b);//重载操作符>>
    friend ostream& operator << (ostream &stream,Book &b);//重载操作符<<
};

ostream &operator << (ostream &stream,Book &b)
{
    stream<<"编号"<<setw(9)<<b.isbn<<" 书名:"<<setw(9)
    <<b.name<<" 作者:"<<setw(9)<<b.author<<" 出版社:"
    <<setw(9)<<b.publisher<<" 单价:"<<setw(5)<<b.price<<endl;
    return stream;
}

istream &operator >> (istream &stream,Book &b)
{
    cout<<"请输入编号:";
    stream>>b.isbn;
    cout<<"请输入书名:";
    stream>>b.name;
    cout<<"请输入作者名:";
    stream>>b.author;
    cout<<"请输入出版社:";
    stream>>b.publisher;
    cout<<"请输入单价:";
    stream>>b.price;
    return stream;
}

//获取系统当前时间的函数.
const string getCurrentSystemTime()
{
    time_t t;
    struct tm * lt;
    time (&t);
    lt = localtime (&t);//转为时间结构。
    char date[60] = {0};
    sprintf(date, "%d-%02d-%02d %02d:%02d:%02d",
            (int)lt->tm_year + 1900,(int)lt->tm_mon + 1,(int)lt->tm_mday,
            (int)lt->tm_hour,(int)lt->tm_min,(int)lt->tm_sec);
    return string(date);
}

void Book::SetDeadline(int a){deadline =a;}
void Book::SetTime(string a){time =a;}
void Book::SetIs_Lend(bool a){Is_Lend =a;}
void Book::Display()//用来展示借书情况
{
    cout<<"编号"<<setw(9)<<GetIsbn()<<" 书名:"<<setw(9)
    <<GetName()<<" 作者:"<<setw(9)<<GetAuthor()<<" 出版社:"
    <<setw(9)<<GetPub()<<" 单价:"<<setw(5)<<GetPrice()<<" 借书时间:"
    <<setw(10)<<Gettime()<<" 借书期限:"<<GetDeadline()<<"天"<<endl;
}
void Book::SetIsbn(string code1)
{isbn=code1;}
void Book::SetName(string name1)
{name=name1;}
void Book::SetAuthor(string author1)
{author=author1;}
void Book::SetPub(string press1)
{publisher=press1;}
void Book::SetPrice(float price1)
{price=price1;}
int Book::Book_Number=0;



static string LogName;//记录当前登陆用户的用户名
//用户类
class User
{
protected:
    string name;//用户姓名
    string key;//用户密码
    bool Is_Admin,Is_Librarian,Is_Reader;//用户类型
public:
    void key_change(User *U);//修改用户密码
    int  Judge();//判断用户类型
    static int User_Number;
    User(){Is_Admin=0;Is_Librarian=0;Is_Reader=1;};//默认读者类型
    void Setname(string name1);
    void Setkey(string key1);
    void SetIdentity(bool ad,bool li,bool re )//设置用户类型
    {Is_Admin=ad;Is_Reader=re;Is_Librarian=li;}
    string Getname(){return name;}
    string Getkey(){return key;}
    bool GetisAd(){return Is_Admin;}
    bool Getisli(){return Is_Librarian;}
    bool Getisre(){return Is_Reader;}
};
void User::key_change(User *U)
{
    int find=0;string key,key1;
    for(int i=0;i<User::User_Number;i++)
    {
        if(U[i].Getname()==LogName)
        {
            find=i;break;
        }
    }
    cout<<"请输入原密码:";
    cin>>key;
    if(key==U[find].Getkey())
    {
        cout<<"请输入新密码:";
        cin>>key;
        cout<<"再输入一次新密码:";
        cin>>key1;
        if(key==key1)
        {
            U[find].Setkey(key);
            cout<<"修改成功！"<<endl;
        }
        else
        {
            cout<<"两次密码输入不一致,修改失败!"<<endl;
        }
    }
    else
    {
        cout<<"密码错误！"<<endl;
    }
}
int User::Judge()
{
    if(Is_Librarian==1)return 5;
    else if(Is_Admin==1)return 6;
    else return 7;
};
void User::Setname(string name1)
{
    name=name1;
};
void User::Setkey(string key1)
{
    key=key1;
};

int User::User_Number=0;
class Log
{
public:
    User tp;//存储登陆成功的用户的信息
    int number;//存储当前用户信息对应的User类中下标值
    void Login(User *p);//登陆
    void SignIN(User *p);//注册
    Log(){number=0;};
    bool Is_Log;//判断是否登陆成功。
};

void Log::SignIN(User *p)
{
    int f1;string a,b,bb;
    while(1)
    {
        f1=1;
        cout<<"请输入用户名：";
        cin>>a;
        for(int i=0;i<=User::User_Number;i++)
        {
            if(p[i].Getname()==a)
            {
                cout<<"用户名已存在，请重新输入."<<endl;f1=0;
            }
        }
        if(f1==0){};
        if(f1==1) {break;}
    }
    while(1)
    {
        cout<<"请设置密码:";
        cin>>b;
        cout<<"再次输入密码:";
        cin>>bb;
        if(bb!=b)
        {
            cout<<"两次密码不一致，请重新输入."<<endl;
        }
        if(bb==b)
        {
            break;
        }
    }
    //将注册成功的用户信息存储到user类里。
    (p+User::User_Number)->Setname(a);
    (p+User::User_Number)->Setkey(b);
    (p+User::User_Number)->SetIdentity(0, 0, 1);
    tp.Setname(a);
    number=User::User_Number;
    User::User_Number++;
};
void Log::Login(User *p)
{
    string a,b;int flag=0;
    cout<<"请输入账号:"<<endl;
    cin>>a;
    cout<<"请输入密码:"<<endl;
    cin>>b;
    for(int i=0;i<User::User_Number;i++)
    {
        if(a==p[i].Getname()&&b==p[i].Getkey())
        {
            tp.SetIdentity(p[i].GetisAd(), p[i].Getisli(), p[i].Getisre());
            flag=1;tp.Setname(a);tp.Setkey(b);number=i;break;
        }
    }
    if(flag)
    {   if(tp.Judge()==7)
    {   LogName=tp.Getname();
        cout<<"登陆成功！"<<endl;Is_Log=true;
        cout<<"尊敬的读者"<<tp.Getname()<<",您好！"<<endl;
    }
    else if(tp.Judge()==5)
    {   LogName=tp.Getname();
        cout<<"登陆成功！"<<endl;Is_Log=true;
        cout<<"尊敬的图书管理员"<<tp.Getname()<<",您好！"<<endl;
    }
    else if(tp.Judge()==6)
    {   LogName=tp.Getname();
        cout<<"登陆成功！"<<endl;Is_Log=true;
        cout<<"尊敬的系统管理员"<<tp.Getname()<<",您好！"<<endl;
    }
    }
    else {cout<<"账号或密码错误！"<<endl;Is_Log=false;}
}

//图书管理员
class Librarian:public User,public Log
{
public:
    static int Librarian_Number;
    void zc(User *U,Log a,Librarian *L)
    {
        a.SignIN(U);
        cout<<"注册成功！"<<endl;
        Librarian_Number++;
        U[a.number].SetIdentity(0, 1, 0);
        SetIdentity(0, 1, 0);
        User::name=a.tp.Getname();
        User::key=a.tp.Getkey();
        L[Librarian::Librarian_Number].Setname(a.tp.Getname());
    }
    Librarian(){SetIdentity(0, 1, 0);}
    Librarian(string name1,string key1,User *U)
    {
        U[User_Number].Setname(name1);U[User_Number].Setkey(key1);
        U[User_Number].SetIdentity(0, 1, 0);
        SetIdentity(0, 1, 0);
        U->User_Number++;
        name=name1;
        key=key1;
    }
    void Book_Add(Book *B);//增加图书
    void Book_Dele(Book *B);//删除图书
    void Book_Alter(Book *B);//修改图书
    void Book_Find(Book *B);//查找图书
    void Book_AddUp(Book *B);//统计图书
};
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
int Librarian::Librarian_Number=1;


//读者
class Reader:public User,public Log,public Book
{
    Book s[100];
public:
    void zc(User *U,Log a,Reader *R)
    {
        a.SignIN(U);
        cout<<"是否为教师用户？(y or n)";
        string c;
        cin>>c;
        if(c=="y")R[a.number].Is_teacher=true;
        else R[a.number].Is_teacher=false;
        cout<<"注册成功！"<<endl;
        U[a.number].SetIdentity(0, 0, 1);
        SetIdentity(0, 0, 1);
        User::Setname(a.tp.Getname());
        User::Setkey(a.tp.Getkey());
        R[Reader::Reader_Number].Setname(a.tp.Getname());
        Reader::Reader_Number++;
    }
    static int Reader_Number;
    void Book_Lend(Book *B);
    void Book_Return(Book *B);
    void Book_LR();
    void Book_show(Book *B);
    Reader():User(){User::Is_Admin=0;User::Is_Librarian=0;User::Is_Reader=1;}
};
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
int Reader::Reader_Number=0;


//系统管理员
class Admin:public User,public Log
{
public:
    void Reader_Add(User *U,Reader *R);//添加读者
    void Reader_Dele(User *U,Reader *R);//删除读者
    void Librarian_Add(User *U,Librarian *L);//添加图书管理员
    void Librarian_Dele(User *U,Librarian *L);//删除图书管理员
    void Reader_Alter(Reader *R,User *U,Admin *A,Librarian *L);//读者权限更改
    void Librarian_Alter(Librarian *L,User *U,Admin *A,Reader *R);//图书管理员权限更改
    void User_keychange(User *U);//修改用户密码
    static int Admin_Number;
    Admin(){Is_Admin=1;Is_Librarian=0;Is_Reader=0;};
    Admin(string name1,string key1,User *U)
    {   U[U->User_Number].Setname(name1);
        U[U->User_Number].Setkey(key1);
        Is_Admin=1;Is_Librarian=0;Is_Reader=0;
        U[U->User_Number].SetIdentity(1, 0, 0);
        U->User_Number++;
        name=name1;
        key=key1;
    }
};
void Admin::User_keychange(User *U)
{
    
    int find=0;string Name,key,key1;
    bool is_find=false;
    cout<<"请输入用户名:";
    cin>>Name;
    for(int i=0;i<User::User_Number;i++)
    {
        if(U[i].Getname()==Name)
        {
            find=i;is_find=true;break;
        }
    }
    
    if(is_find==true)
    {
        cout<<"请输入新密码:";
        cin>>key;
        cout<<"再输入一次新密码:";
        cin>>key1;
        if(key==key1)
        {
            U[find].Setkey(key);
            cout<<"修改成功！"<<endl;
        }
        else
        {
            cout<<"两次密码输入不一致,修改失败!"<<endl;
        }
    }
    else
    {
        cout<<"未找到该用户."<<endl;
    }
}
//读者权限修改
void Admin::Reader_Alter(Reader *R,User *U,Admin *A,Librarian *L)
{   string name,key;
    string a;cout<<"请输入需要进行操作的读者用户名:";cin>>a;
    int flag=0,find=0;
    for(int i=0;i<Reader::Reader_Number;i++)
    {
        if(R[i].Getname()==a){
            flag=1;find=i;name=R[i].Getname();key=R[i].Getkey();break;
        }
    }
    
    if(flag)
    {
        int t=0;
        cout<<"请选择需要变更的权限类型:"<<endl;
        cout<<"①图书管理员"<<endl;
        cout<<"②系统管理员"<<endl;
        cout<<"③返回"<<endl;
        cin>>a;
        if(a=="1")
        {
            t=1;
        }
        else if(a=="2")
        {
            t=2;
        }
        else
        {
            cout<<"返回成功!"; t=0;
        }
        if(t==1||t==2)
        {
            for(int j=find;j<Reader::Reader_Number;j++)
            {
                if(j==Reader::Reader_Number-1){Reader::Reader_Number--;break;}
                R[j]=R[j+1];
            }
            if(t==1)
            {
                for(int j=0;j<U->User_Number;j++)
                {
                    if(U[j].Getname()==name){
                        U[j].SetIdentity(0, 1, 0);
                        break;}
                }
                L[Librarian::Librarian_Number].Setname(name);
                L[Librarian::Librarian_Number].Setkey(key);
                L[Librarian::Librarian_Number].SetIdentity(0, 1, 0);
                L->Librarian_Number++;
            }
            
            if(t==2)
            {
                for(int j=0;j<U->User_Number;j++)
                {
                    if(U[j].Getname()==name){
                        U[j].SetIdentity(1, 0, 0);
                        break;}
                }
                A[Admin::Admin_Number].Setname(name);
                A[Admin::Admin_Number].Setkey(key);
                A[Admin::Admin_Number].SetIdentity(1, 0, 0);
                A->Admin_Number++;
            }
            cout<<"变更成功!"<<endl;
        }
    }
    else    cout<<"读者用户不存在！"<<endl;
}
//图书管理员权限修改
void Admin::Librarian_Alter(Librarian *L,User *U,Admin *A,Reader *R)
{
    string name,key;
    string a;cout<<"请输入需要进行操作的图书管理员用户名:";cin>>a;
    int flag=0,find=0;
    for(int i=0;i<Librarian::Librarian_Number;i++)
    {
        if(L[i].Getname()==a){
            flag=1;find=i;name=L[i].Getname();key=L[i].Getkey();break;
        }
    }
    
    if(flag)
    {
        int t=0;
        cout<<"请选择需要变更的权限类型:"<<endl;
        cout<<"①读者"<<endl;
        cout<<"②系统管理员"<<endl;
        cout<<"③返回"<<endl;
        cin>>a;
        if(a=="1")
        {
            t=1;
        }
        else if(a=="2")
        {
            t=2;
        }
        else
        {
            cout<<"返回成功!"; t=0;
        }
        if(t==1||t==2)
        {
            for(int j=find;j<Librarian::Librarian_Number;j++)
            {
                if(j==Librarian::Librarian_Number-1){Librarian::Librarian_Number--;break;}
                L[j]=L[j+1];
            }
            if(t==1)
            {
                for(int j=0;j<U->User_Number;j++)
                {
                    if(U[j].Getname()==name){
                        U[j].SetIdentity(0, 0, 1);
                        break;}
                }
                R[Reader::Reader_Number].Setname(name);
                R[Reader::Reader_Number].Setkey(key);
                R[Reader::Reader_Number].SetIdentity(0, 0, 1);
                R->Reader_Number++;
            }
            
            if(t==2)
            {
                for(int j=0;j<U->User_Number;j++)
                {
                    if(U[j].Getname()==name){
                        U[j].SetIdentity(1, 0, 0);
                        break;}
                }
                A[Admin::Admin_Number].Setname(name);
                A[Admin::Admin_Number].Setkey(key);
                A[Admin::Admin_Number].SetIdentity(1, 0, 0);
                A->Admin_Number++;
            }
            cout<<"变更成功!"<<endl;
        }
    }
    else    cout<<"读者用户不存在！"<<endl;
}
//增加读者
void Admin::Reader_Add(User *U,Reader *R)
{   Log a;
    R[Reader::Reader_Number].zc(U, a,R);
}
//增加图书管理员
void Admin::Librarian_Add(User *U,Librarian *L)
{   Log a;
    L[Librarian::Librarian_Number].zc(U, a,L);
}
//删除读者
void Admin::Reader_Dele(User *U,Reader *R)
{
    string a;
    cout<<"请输入需要进行操作的用户名:";cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0;i<Reader::Reader_Number;i++)
    {
        if(R[i].Getname()==a){
            flag=1;find=i;break;
        }
    }
    if(flag)
    {
        for(int j=find;j<Reader::Reader_Number;j++)
        {
            if(j==Reader::Reader_Number-1){Reader::Reader_Number--;break;}
            R[j]=R[j+1];
        }
        for(int j=0;j<U->User_Number;j++)
        {
            if(U[j].Getname()==a){find1=j;break;}
        }
        for(int j=find1;j<U->User_Number;j++)
        {
            if(j==U->User_Number-1){U->User_Number--;break;}
            U[j]=U[j+1];
        }
        cout<<"删除成功！"<<endl;
    }
    else    cout<<"用户不存在！"<<endl;
}
//删除图书管理员
void Admin::Librarian_Dele(User *U,Librarian *L)
{
    string a;
    cout<<"请输入需要进行操作的用户名:";cin>>a;
    int flag=0,find=0,find1=0;
    for(int i=0;i<Librarian::Librarian_Number;i++)
    {
        if(L[i].Getname()==a){
            flag=1;find=i;break;
        }
        
    }
    if(flag)
    {
        for(int j=find;j<Librarian::Librarian_Number;j++)
        {
            if(j==Librarian::Librarian_Number-1){Librarian::Librarian_Number--;break;}
            L[j]=L[j+1];
        }
        for(int k=0;k<U->User_Number;k++)
        {
            if(U[k].Getname()==a)
            {
                find1=k;break;
            }
        }
        for(int j=find1;j<U->User_Number;j++)
        {
            if(j==U->User_Number-1){U->User_Number--;break;}
            U[j]=U[j+1];
        }
        cout<<"删除成功！"<<endl;
    }
    else    cout<<"用户不存在！"<<endl;
}
int Admin::Admin_Number=1;


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

