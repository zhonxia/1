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
	cout << "职工编号： " << this->id
		<< " \t职工姓名： " << this->name
		<< " \t薪水：" << this->salary<< endl;
}
string salesmanagers::getName()
{
	return string("销售经理");
}