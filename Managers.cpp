#include "Managers.h"

Managers::Managers(int i, string na, int mId, float sa)
{
	//��this->m_Id = id;����е�this����ǰ��������ָ��ö����ָ�롣
	//��ˣ�this->m_Id����Ϊ��ǰ��������id�����������������������ԣ���������е�this�Ǳ���ģ�����ʡ��
	this->name = na;
	this->id = i;
	this->m_DeptId = mId;
	this->salary = sa;
}
void Managers::show()
{
	cout << " \tְ�������� " << this->name
		<< "ְ����ţ� " << this->id
		<< " \tнˮ��" << this->salary << endl;
}
string Managers::getName()
{
	return string("����");
}