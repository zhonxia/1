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
	cout << "ְ����ţ� " << this->id
		<< " \tְ�������� " << this->name
		<< " \tнˮ��" << this->salary << endl;
}
string parttimesalesmen::getName()
{
	return string("��ְ����Ա");
}