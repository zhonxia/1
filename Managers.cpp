#include "Managers.h"

Managers::Managers(int i, string na, int mId, float sa)
{
	//中this->m_Id = id;语句中的this代表当前对象，它是指向该对象的指针。
	//因此，this->m_Id用于为当前对象设置id变量，而不是其他对象。所以，这条语句中的this是必需的，不能省略
	this->name = na;
	this->id = i;
	this->m_DeptId = mId;
	this->salary = sa;
}
void Managers::show()
{
	cout << " \t职工姓名： " << this->name
		<< "职工编号： " << this->id
		<< " \t薪水：" << this->salary << endl;
}
string Managers::getName()
{
	return string("经理");
}