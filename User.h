#ifndef USER_H
#define USER_H
#include<string>
using namespace std;

typedef struct user
{
	string m_name;              //用户名
	string m_password;          //密码
	user *next_user;            //链表
}user;

class User
{
public:
	User()
	{
		head = new user;
		head->m_name = "admin";
		head->m_password = "123";
		head->next_user = NULL;
	}            
	~User()
	{
		user *p = head, *q;
		while (p)
		{
			q = p;
			p = q->next_user;
			delete q;
		}
	}
	user *findByName(const string &name) const;      //查找文件中的用户名
	void readFile();             //读取文件
	void saveFile();             //保存文件
	void login();                //注册函数
	bool logon();                //登陆函数
	unsigned headCount();          //结构计数函数
	bool insert(const user &astu);        //插入函数
	void deleteByName();      //删除函数
	void show();              //显示函数
private:
	user *head;
};



#endif // !USER_H
