#include "salesmanagers.h"

salesmanagers::salesmanagers(int i, string na, int mId,float sa)
{
	this->name = na;
	this->id = i;
	this->m_DeptId = mId;
	this->salary = sa;
}
void salesmanagers::show()
{
	cout << "ְ����ţ� " << this->id
		<< " \tְ�������� " << this->name
		<< " \tнˮ��" << this->salary<< endl;
}
string salesmanagers::getName()
{
	return string("���۾���");
}