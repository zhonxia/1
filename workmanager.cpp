#include "workmanager.h"

workmanager::workmanager()
{
	ifstream ifs;
	//读取文件
	ifs.open(FILENAME, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl; //测试输出
		this->m_EmpNum = 0;  //初始化人数
		this->m_FileIsEmpty = true; //初始化文件为空标志
		this->m_EmpArray = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}
	//文件存在，并且没有记录
	char ch;
	//ifs是一个ifstream对象，通过调用open()函数打开了一个文件。>>操作符会从文件中读取下一个字符，并将其存储到变量ch中。
	//这里只会读取一个字符。如果需要读取一行或多个字符，需要使用其他的函数，如getline()。
	ifs >> ch;
	if (ifs.eof())
		//ifs.eof()是用于判断文件是否已经到达文件末尾的函数。它返回一个bool值，如果文件指针已经到达文件末尾，
		//则返回true，否则返回false。
		//在代码中，如果读取文件时已经到达文件末尾，则说明文件为空，需要进行相应的处理。
	{
		cout << "文件为空!" << endl;
		this->m_EmpNum = 0;//初始化人数
		this->m_FileIsEmpty = true;//初始化文件为空标志
		this->m_EmpArray = NULL; //初始化数组
		ifs.close();//关闭文件
		return;
	}
	//根据职工数创建数组
	this->m_EmpArray = new worker * [this->m_EmpNum];
	//初始化职工
	init_Emp();
	//测试代码
		//for (int i = 0; i < m_EmpNum; i++)
		//{
			//cout << "职工号： " << this->m_EmpArray[i]->id
				//<< " 职工姓名： " << this->m_EmpArray[i]->name
				//<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId
				//<< "薪水：" << this->m_EmpArray[i]->salary << endl;
//		}
}

workmanager::~workmanager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}
//展示功能菜单
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
//退出系统的成员函数
void workmanager::exitsystem()
{
	cout << "欢迎下次使用,已退出系统" << endl;
	system("pause");
	//return 0;void不能返回
	exit(0);
}
//增加职工
void workmanager::add_worker()
{
	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		worker** newSpace = new worker * [newSize];

		//将原空间下内容存放到新空间下
		if (this->m_EmpArray != NULL)
		{
			// 将原空间下内容存放到新空间下
			memcpy_s(newSpace, newSize * sizeof(worker*), this->m_EmpArray, this->m_EmpNum * sizeof(worker*));
		}


		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			//销售经理固定月薪
			float Fsalary = 0;
			//销售提成
			float Rsales = 0;
			//工作小时
			float hour = 0;
			//每小时/元
			float money = 0;
			//月薪
			float salary = 0;
			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、经理" << endl;
			cout << "2、销售经理" << endl;
			cout << "3、兼职技术人员" << endl;
			cout << "4、兼职推销员" << endl;
			cin >> dSelect;

			if (dSelect == 1)
			{
				cout << "经理的固定月薪：";
				cin >> Fsalary;
				salary = Fsalary;

			}
			if (dSelect == 2)
			{
				cout << "销售经理的固定月薪：";
				cin >> Fsalary;
				cout << "销售经理的销售提成：";
				cin >> Rsales;
				salary = Fsalary + Rsales;
			}
			if (dSelect == 3)
			{
				cout << "工作小时数：";
				cin >> hour;
				cout << "每小时/元：";
				cin >> money;
				salary = money * hour;
			}
			if (dSelect == 4)
			{
				cout << "兼职推销员的销售提成：";
				cin >> Rsales;
				salary = Rsales;
			}
			worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //经理
				worker = new Managers(id, name, 1, salary);
				break;
			case 2: //销售经理
				worker = new salesmanagers(id, name, 2, salary);
				break;
			case 3:  //兼职技术人员
				worker = new parttechnicians(id, name, 3, salary);
				break;
			case 4://兼职推销员
				worker = new parttimesalesmen(id, name, 4, salary);
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的个数
		this->m_EmpNum = newSize;

		//更新职工不为空标志
		//意味着该对象所代表的文件不为空。
		this->m_FileIsEmpty = false;

		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;
		//保存数据
		/*this->save() 是类 workmanager 中的一个成员函数，用于将当前对象中的员工信息保存到文件中。
		在类的成员函数中，可以直接访问该类的成员变量和其他成员函数
		因此在 save() 函数中可以访问 m_EmpArray、m_EmpNum 等成员变量，并将它们保存到文件中。*/
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}
void workmanager::save()
{
	//ofstream 是 C++ 中用于写入文件的输出流类，用于将数据写入到文件中
	ofstream ofs;
	// ios::out这里使用ios::out模式打开文件，表示输出模式，也就是说，如果打开的文件不存在，
	// 就会新建一个同名的文件；如果文件已存在，则会清空文件原有内容。
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->id << " "
			<< this->m_EmpArray[i]->name << " "
			<< this->m_EmpArray[i]->m_DeptId << " "
			<< this->m_EmpArray[i]->salary << endl;
	}

}
int workmanager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	float salary;

	int num = 0;
	//ifs >> id 表示从输入文件流 ifs 中读取一个整数，并将其存储在变量 id 中。
	//都用了 && 连接，所以只有在所有操作都成功（读取到了正确的数据类型）的情况下，条件表达式的结果才为真。
	while (ifs >> id && ifs >> name && ifs >> dId && ifs >> salary)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}


//初始化员工
void workmanager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	float salary;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId && ifs >> salary)
	{
		worker* worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1经理
		{
			worker = new Managers(id, name, dId, salary);
		}
		else if (dId == 2) //2
		{
			worker = new salesmanagers(id, name, dId, salary);
		}
		else if (dId == 3)//3
		{
			worker = new parttechnicians(id, name, dId, salary);
		}
		else//4兼职推销员
		{
			worker = new parttimesalesmen(id, name, dId, salary);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}
//显示职工
void workmanager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->show();
		}
	}

	system("pause");
	system("cls");
}