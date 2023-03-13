#include<iostream>
using namespace std;
//头文件提供了文件操作所需的类和函数
#include <fstream>
//定义了一个文件名常量 FILENAME 为 "empFile.txt"，用于后续读写员工数据时作为文件名使用
#define  FILENAME "empFile.txt"
#include "worker.h"
#include "parttechnicians.h"
#include "parttimesalesmen.h"
#include "Managers.h"
#include "salesmanagers.h"
class workmanager
{
public:

	//构造函数
	workmanager();

	//展示功能菜单
	void show_menu();

	//退出系统的成员函数
	void exitsystem();

	//记录文件中的人数个数
	int m_EmpNum;

	//员工数组的指针
	worker** m_EmpArray;

	//增加职工
	void add_worker();

	//保存文件
	void save();

	//标志文件是否为空
	bool m_FileIsEmpty;

	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//析构函数
	~workmanager();
};
