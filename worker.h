#pragma once
#include<iostream>
using namespace std;
class worker
{
public:
	//����
	string name;
	//���
	int id;
	//нˮ
	float salary;
	//����
	//string level;
	/*ʹ��getName��������׼����������������̵�ԭ��
	ͨ���ú���������ʵ�ֶ�̬�ظ��ݲ�ͬ��id���ı�Ա���ĸ�λ��
	������Ҫÿ�ζ�Ҫ���¶���string�͵ı�����*/
	//����
	int m_DeptId; //ְ�����ڲ������Ʊ��
	virtual string getName() = 0;
	//��ʾ������Ϣ
	virtual void show() = 0;
};
