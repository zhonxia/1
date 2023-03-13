#pragma once
#include<iostream>
using namespace std;
class worker
{
public:
	//姓名
	string name;
	//编号
	int id;
	//薪水
	float salary;
	//级别
	//string level;
	/*使用getName（）更标准，更符合面向对象编程的原则。
	通过该函数，可以实现动态地根据不同的id来改变员工的岗位，
	而不需要每次都要重新定义string型的变量。*/
	//级别
	int m_DeptId; //职工所在部门名称编号
	virtual string getName() = 0;
	//显示个人信息
	virtual void show() = 0;
};
