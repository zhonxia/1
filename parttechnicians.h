#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
class  parttechnicians :public worker
{
public:
	//����Сʱ
	//float hour;
	parttechnicians(int i, string na, int mId, float sa);
	virtual void show();
	virtual string getName();
};
