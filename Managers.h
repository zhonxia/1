#pragma once// ��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include "worker.h"
class Managers :public worker
{
public:
	//����̶���н
	//double Fsalary;
	//float Fsalary;
	//���
	//���캯��
	Managers(int i, string na,int mId,float sa);
	virtual void show();
	virtual string getName();
};
