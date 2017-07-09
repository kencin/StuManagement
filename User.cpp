#include"user.h"
#include<fstream>
#include<iostream>
using namespace std;


void User::readFile()
{
	string new_file = "user";
	fstream file;
	file.open(new_file.c_str(), ios::in);
	if (file.bad())
	{
		cout << "文件打开失败. " << endl;
		return;
	}
	int len = 0;
	file >> len;
	if (!len)
	{
		cout << "已新建管理员数据文件，请注册管理员账号。 " << endl;
		login();
		return;
	}
	user pHead;
	file.get();
	while (len--)
	{
		file >> pHead.m_name;
		file >> pHead.m_password;
		insert(pHead);
	}
	file.close();
	cout << "请输入管理员账号以登陆. " << endl;
	return;
} 

void User::saveFile()
{
	string new_file = "user";

	fstream file;
	file.open(new_file.c_str(), ios::out);
	if (file.bad())
	{
		cout << "文件打开失败. " << endl;
		return;
	}
	int len = headCount() - 1;
	file << len << endl;
	user *pHead = head->next_user;
	while (pHead != NULL)
	{
		file << pHead->m_name << endl;
		file << pHead->m_password << endl;
		pHead = pHead->next_user;
	}
	file.close();
	return;
}



bool User::insert(const user &astu)
{
	user *p = head;
	if (p->next_user == NULL)    //当没有下一个堆，则新建一个堆来储存修改数据
	{
		p->next_user = new user(astu);   //用传入的已修改结构初始化
		p->next_user->next_user = NULL;      //NULL处理再下一个堆
		return true;
	}
	while (p->next_user)           //当存在下一个堆
	{
		if (p->next_user->m_name == astu.m_name)    //判重
		{
			cout << "重复的用户名, 插入失败! \n";
			return false;
		}
		p = p->next_user;    //既不大于也不重复就后移添加
	}
	p->next_user = new user(astu);
	p->next_user->next_user = NULL;
	return true;
}
unsigned User::headCount()
{
	unsigned cnt = 0;
	user *p;
	for (p = head; p; p = p->next_user, ++cnt);
	return cnt;

}
user *User::findByName(const string &name) const
{
	user *p;
	for (p = head; p->next_user; p = p->next_user)
		if (p->next_user->m_name == name) return p;
	return NULL;
}
void User::deleteByName()
{
	user *q, *p;
	cout << "请输入用户名" << endl;
	string name;
	cin >> name;
	p = findByName(name);
	if (p == NULL)
	{
		cout << "没有找到账号 \"" << name << "\" ，删除失败! \n";
		
	}
	q = p->next_user;
	p->next_user = NULL;
	delete q;
	cout << "成功删除 " << name << " 的账号. \n";
	saveFile();
}
void User::show()
{
	user *p;
	cout << "----------------------------------------------------------\n";
	for (p = head->next_user; p; p = p->next_user)
	{
		cout << "  用户名：" << p->m_name << "  密码： " << p->m_password << endl;
	}
	cout << "----------------------------------------------------------\n";

}

void User::login()
{
	user tmp;
	cout << "新用户名: ";
	cin >> tmp.m_name;

	if (findByName(tmp.m_name) == NULL)
	{
		cout << "新密码: ";
		cin >> tmp.m_password;
		insert(tmp);
	}
	else
	{
		cout << "重复的用户名: " << tmp.m_name << endl;
		login();
	}
	saveFile();

}
bool User::logon()
{
	cout << "  登录" << endl;
	cout << "用户名：";
	string name;
	cin >> name;
	user *p;
	if (findByName(name))
	{
		p = findByName(name);
		cout << "密码：";
		string password;
		cin >> password;
		if (p->next_user->m_password == password)
		{
			cout << "登陆成功" << endl;
			return true;
		}
		else
		{
			cout << "密码输入错误" << endl;
			logon();
		}
	}
	else
	{
		cout << "没有找到相关用户名！" << endl;
		logon();
	}
}
