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
	cout << "职工编号： " << this->id
		<< " \t职工姓名： " << this->name
		<< " \t薪水：" << this->salary << endl;
}
string parttechnicians::getName()
{
	return string("兼职技术人员");
}