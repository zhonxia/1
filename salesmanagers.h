#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
//���۾���
class  salesmanagers :public worker
{
public:
	//���۾���̶���н
	//float Fsalary;
	//�������
	float Rsales;
	salesmanagers(int i, string na, int mId,float sa);
	virtual void show();
	virtual string getName();
};