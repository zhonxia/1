#include "parttechnicians.h"

parttechnicians::parttechnicians(int i, string na, int mId, float sa)
{
	this->name = na;
	this->id = i;
	this->m_DeptId = mId;
	this->salary = sa;
}
void parttechnicians::show()
{
	cout << "ְ����ţ� " << this->id
		<< " \tְ�������� " << this->name
		<< " \tнˮ��" << this->salary << endl;
}
string parttechnicians::getName()
{
	return string("��ְ������Ա");
}