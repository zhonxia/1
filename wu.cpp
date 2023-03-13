#include<iostream>
//员工类#include<iostream>
using namespace std;
class work
{
public:
	//姓名
	string name;
	//编号
	int id = 0;
	//级别
	//string level;
	/*使用getName（）更标准，更符合面向对象编程的原则。
	通过该函数，可以实现动态地根据不同的id来改变员工的岗位，
	而不需要每次都要重新定义string型的变量。*/
	//级别
	virtual string getName() = 0;
	//显示个人信息
	virtual void show() = 0;
};
//经理类
class Managers :public work
{
public:
	//经理固定月薪
	//double Fsalary;
	float Fsalary;
	//构造函数
	Managers(string na, int i, float Fs);
	virtual void show();
	virtual string getName();
};
Managers::Managers(string na, int i, float Fs)
{
	//中this->m_Id = id;语句中的this代表当前对象，它是指向该对象的指针。
	//因此，this->m_Id用于为当前对象设置id变量，而不是其他对象。所以，这条语句中的this是必需的，不能省略
	this->name = na;
	this->id = i;
	this->Fsalary = Fs;
}
void Managers::show()
{
	cout << "职工编号： " << this->id
		<< " \t职工姓名： " << this->name
		<< " \t固定薪水：" << this->Fsalary << endl;
}
string Managers::getName()
{
	return string("经理");
}
//销售经理
class  salesmanagers :public work
{
public:
	//销售经理固定月薪
	float Fsalary;
	//销售提成
	float Rsales;
	salesmanagers(string na, int i, float Fs, float Rs);
	virtual void show();
	virtual string getName();
};
salesmanagers::salesmanagers(string na, int i, float Fs, float Rs)
{
	this->name = na;
	this->id = i;
	this->Fsalary = Fs;
	this->Rsales = Rs;
}
void salesmanagers::show()
{
	cout << "职工编号： " << this->id
		<< " \t职工姓名： " << this->name
		<< " \t固定薪水：" << this->Fsalary
		<< " \t销售提成：" << this->Rsales << endl;
}
string salesmanagers::getName()
{
	return string("销售经理");
}
//兼职技术人员
class  parttimetechnicians :public work
{
public:
	//工作小时
	float hour;
	parttimetechnicians(string na, int i, float ho);
	virtual void show();
	virtual string getName();
};
parttimetechnicians::parttimetechnicians(string na, int i, float ho)
{
	this->name = na;
	this->id = i;
	this->hour = ho;
}
void parttimetechnicians::show()
{
	cout << "职工编号： " << this->id
		<< " \t职工姓名： " << this->name
		<< " \t工作小时数：" << this->hour << endl;
}
string parttimetechnicians::getName()
{
	return string("兼职技术人员");
}
//兼职推销员 
class parttimesalesmen :public work
{
	//销售提成
	float Rsales;
	parttimesalesmen(string na, int i, float Rs);
	virtual void show();
	virtual string getName();
};
parttimesalesmen::parttimesalesmen(string na, int i, float Rs)
{
	this->name = na;
	this->id = i;
	this->Rsales = Rs;
}
void parttimesalesmen::show()
{
	cout << "职工编号： " << this->id
		<< " \t职工姓名： " << this->name
		<< " \t销售提成：" << this->Rsales << endl;
}
string parttimesalesmen::getName()
{
	return string("兼职推销员");
}

class workmanager
{
public:
	//展示功能菜单
	void show_menu();
};
void workmanager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
int main()
{
	//测试
	/*Managers Ma("qinbai", 13, 5000);
	Managers* M = &Ma;
	M->show();*/
	/*work* worker = NULL;
	worker = new Managers("qinbai", 13, 5000);
	worker->show();*/
	//测试
	while (true)
	{
		int choice = 0;
		workmanager zs;
		zs.show_menu();
		cout << "请输入相应的数字选择对应的功能:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "欢迎下次使用,已退出系统" << endl;
			system("pause");
			return 0;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;

		}
	}


	system("pause");
	return 0;
}