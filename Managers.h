#pragma once// 防止头文件重复包含
#include<iostream>
using namespace std;
#include "worker.h"
class Managers :public worker
{
public:
	//经理固定月薪
	//double Fsalary;
	//float Fsalary;
	//编号
	//构造函数
	Managers(int i, string na,int mId,float sa);
	virtual void show();
	virtual string getName();
};
