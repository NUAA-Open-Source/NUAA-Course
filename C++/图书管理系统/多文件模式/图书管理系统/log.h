#ifndef LOG_H
#define LOG_H

#include "user.h"
using namespace std;

class Log
{
public:
    User tp;//�洢��½�ɹ����û�����Ϣ
    int number;//�洢��ǰ�û���Ϣ��Ӧ��User�����±�ֵ
    void Login(User *p);//��½
    void SignIN(User *p);//ע��
    Log(){number=0;};
    bool Is_Log;//�ж��Ƿ��½�ɹ���
};

#endif
