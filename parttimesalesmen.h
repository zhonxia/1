#pragma once
#include<iostream>
#include "worker.h"
using namespace std;
class parttimesalesmen :public worker
{
public:
	//�������
	//float Rsales;
	parttimesalesmen(int i, string na, int mId, float sa);
	virtual void show();
	virtual string getName();
};
