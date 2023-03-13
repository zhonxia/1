#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
//销售经理
class  salesmanagers :public worker
{
public:
	//销售经理固定月薪
	//float Fsalary;
	//销售提成
	float Rsales;
	salesmanagers(int i, string na, int mId,float sa);
	virtual void show();
	virtual string getName();
};