#include<iostream>
//Ա����#include<iostream>
using namespace std;
class work
{
public:
	//����
	string name;
	//���
	int id = 0;
	//����
	//string level;
	/*ʹ��getName��������׼����������������̵�ԭ��
	ͨ���ú���������ʵ�ֶ�̬�ظ��ݲ�ͬ��id���ı�Ա���ĸ�λ��
	������Ҫÿ�ζ�Ҫ���¶���string�͵ı�����*/
	//����
	virtual string getName() = 0;
	//��ʾ������Ϣ
	virtual void show() = 0;
};
//������
class Managers :public work
{
public:
	//����̶���н
	//double Fsalary;
	float Fsalary;
	//���캯��
	Managers(string na, int i, float Fs);
	virtual void show();
	virtual string getName();
};
Managers::Managers(string na, int i, float Fs)
{
	//��this->m_Id = id;����е�this����ǰ��������ָ��ö����ָ�롣
	//��ˣ�this->m_Id����Ϊ��ǰ��������id�����������������������ԣ���������е�this�Ǳ���ģ�����ʡ��
	this->name = na;
	this->id = i;
	this->Fsalary = Fs;
}
void Managers::show()
{
	cout << "ְ����ţ� " << this->id
		<< " \tְ�������� " << this->name
		<< " \t�̶�нˮ��" << this->Fsalary << endl;
}
string Managers::getName()
{
	return string("����");
}
//���۾���
class  salesmanagers :public work
{
public:
	//���۾���̶���н
	float Fsalary;
	//�������
	float Rsales;
	salesmanagers(string na, int i, float Fs, float Rs);
	virtual void show();
	virtual string getName();
};
salesmanagers::salesmanagers(string na, int i, float Fs, float Rs)
{
	this->name = na;
	this->id = i;
	this->Fsalary = Fs;
	this->Rsales = Rs;
}
void salesmanagers::show()
{
	cout << "ְ����ţ� " << this->id
		<< " \tְ�������� " << this->name
		<< " \t�̶�нˮ��" << this->Fsalary
		<< " \t������ɣ�" << this->Rsales << endl;
}
string salesmanagers::getName()
{
	return string("���۾���");
}
//��ְ������Ա
class  parttimetechnicians :public work
{
public:
	//����Сʱ
	float hour;
	parttimetechnicians(string na, int i, float ho);
	virtual void show();
	virtual string getName();
};
parttimetechnicians::parttimetechnicians(string na, int i, float ho)
{
	this->name = na;
	this->id = i;
	this->hour = ho;
}
void parttimetechnicians::show()
{
	cout << "ְ����ţ� " << this->id
		<< " \tְ�������� " << this->name
		<< " \t����Сʱ����" << this->hour << endl;
}
string parttimetechnicians::getName()
{
	return string("��ְ������Ա");
}
//��ְ����Ա 
class parttimesalesmen :public work
{
	//�������
	float Rsales;
	parttimesalesmen(string na, int i, float Rs);
	virtual void show();
	virtual string getName();
};
parttimesalesmen::parttimesalesmen(string na, int i, float Rs)
{
	this->name = na;
	this->id = i;
	this->Rsales = Rs;
}
void parttimesalesmen::show()
{
	cout << "ְ����ţ� " << this->id
		<< " \tְ�������� " << this->name
		<< " \t������ɣ�" << this->Rsales << endl;
}
string parttimesalesmen::getName()
{
	return string("��ְ����Ա");
}

class workmanager
{
public:
	//չʾ���ܲ˵�
	void show_menu();
};
void workmanager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
int main()
{
	//����
	/*Managers Ma("qinbai", 13, 5000);
	Managers* M = &Ma;
	M->show();*/
	/*work* worker = NULL;
	worker = new Managers("qinbai", 13, 5000);
	worker->show();*/
	//����
	while (true)
	{
		int choice = 0;
		workmanager zs;
		zs.show_menu();
		cout << "��������Ӧ������ѡ���Ӧ�Ĺ���:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "��ӭ�´�ʹ��,���˳�ϵͳ" << endl;
			system("pause");
			return 0;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;

		}
	}


	system("pause");
	return 0;
}