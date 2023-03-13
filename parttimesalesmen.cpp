#include "parttimesalesmen.h"
parttimesalesmen::parttimesalesmen(int i, string na, int mId, float sa)
{
	this->name = na;
	this->id = i;
	this->m_DeptId = mId;
	this->salary = sa;
}
void parttimesalesmen::show()
{
	cout << "职工编号： " << this->id
		<< " \t职工姓名： " << this->name
		<< " \t薪水：" << this->salary << endl;
}
string parttimesalesmen::getName()
{
	return string("兼职推销员");
}