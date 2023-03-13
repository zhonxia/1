#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
class  parttechnicians :public worker
{
public:
	//工作小时
	//float hour;
	parttechnicians(int i, string na, int mId, float sa);
	virtual void show();
	virtual string getName();
};
