#include<iostream>
#include "Student.h"
#include "User.h"
using namespace std;



void menu() {
	cout << "+---------------------------------------------+\n";
	cout << "|               学生学籍信息管理系统            |\n";
	cout << "+---------------------------------------------+\n";
	cout << "|   1、注册新管理员账号  |  6、添加新学生信息   |\n";
	cout << "|   2、查看管理员账号    |  7、修改学生信息     |\n";
	cout << "|   3、删除管理员账号    |  8、显示学生信息     |\n";
	cout << "|   4、读取学生信息      |  9、查询学生信息     |\n";
	cout << "|   5、保存学生信息      | 10、删除学生信息     |\n";
	cout << "+---------------------------------------------+\n";
	cout << "|                     0、退出                  |\n";
	cout << "+---------------------------------------------+\n";
}
int main() 
{
	User u1;
	u1.readFile();
	if (u1.logon())
	{
		Student m_stu;
			int choice;
			menu();
			do {
				cout << "请输入指令:" ;
				cin >> choice;
				switch (choice) {
				case 1: u1.login(); break;
				case 2: u1.show(); break;
				case 3: u1.deleteByName(); break;
				case 4: m_stu.readFile(); break;
				case 5: m_stu.saveToFile(); break;
				case 6: m_stu.logon(); break;
				case 7: m_stu.modify(); break;
				case 8: m_stu.Show(); break;
				case 9: m_stu.Query(); break;
				case 10: m_stu.deleteBy(); break;
		
				case 0: ; break;
				default: cout << "请输入正确的选项" << endl; menu(); break;
				}
			} while (choice);
			return 0;
	}
	
}
