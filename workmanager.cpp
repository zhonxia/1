#include "workmanager.h"

workmanager::workmanager()
{
	ifstream ifs;
	//��ȡ�ļ�
	ifs.open(FILENAME, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl; //�������
		this->m_EmpNum = 0;  //��ʼ������
		this->m_FileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpArray = NULL; //��ʼ������
		ifs.close(); //�ر��ļ�
		return;
	}
	//�ļ����ڣ�����û�м�¼
	char ch;
	//ifs��һ��ifstream����ͨ������open()��������һ���ļ���>>����������ļ��ж�ȡ��һ���ַ���������洢������ch�С�
	//����ֻ���ȡһ���ַ��������Ҫ��ȡһ�л����ַ�����Ҫʹ�������ĺ�������getline()��
	ifs >> ch;
	if (ifs.eof())
		//ifs.eof()�������ж��ļ��Ƿ��Ѿ������ļ�ĩβ�ĺ�����������һ��boolֵ������ļ�ָ���Ѿ������ļ�ĩβ��
		//�򷵻�true�����򷵻�false��
		//�ڴ����У������ȡ�ļ�ʱ�Ѿ������ļ�ĩβ����˵���ļ�Ϊ�գ���Ҫ������Ӧ�Ĵ���
	{
		cout << "�ļ�Ϊ��!" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpArray = NULL; //��ʼ������
		ifs.close();//�ر��ļ�
		return;
	}
	//����ְ������������
	this->m_EmpArray = new worker * [this->m_EmpNum];
	//��ʼ��ְ��
	init_Emp();
	//���Դ���
		//for (int i = 0; i < m_EmpNum; i++)
		//{
			//cout << "ְ���ţ� " << this->m_EmpArray[i]->id
				//<< " ְ�������� " << this->m_EmpArray[i]->name
				//<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId
				//<< "нˮ��" << this->m_EmpArray[i]->salary << endl;
//		}
}

workmanager::~workmanager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}
//չʾ���ܲ˵�
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
//�˳�ϵͳ�ĳ�Ա����
void workmanager::exitsystem()
{
	cout << "��ӭ�´�ʹ��,���˳�ϵͳ" << endl;
	system("pause");
	//return 0;void���ܷ���
	exit(0);
}
//����ְ��
void workmanager::add_worker()
{
	cout << "����������ְ�������� " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		worker** newSpace = new worker * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			// ��ԭ�ռ������ݴ�ŵ��¿ռ���
			memcpy_s(newSpace, newSize * sizeof(worker*), this->m_EmpArray, this->m_EmpNum * sizeof(worker*));
		}


		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			//���۾���̶���н
			float Fsalary = 0;
			//�������
			float Rsales = 0;
			//����Сʱ
			float hour = 0;
			//ÿСʱ/Ԫ
			float money = 0;
			//��н
			float salary = 0;
			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;


			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1������" << endl;
			cout << "2�����۾���" << endl;
			cout << "3����ְ������Ա" << endl;
			cout << "4����ְ����Ա" << endl;
			cin >> dSelect;

			if (dSelect == 1)
			{
				cout << "����Ĺ̶���н��";
				cin >> Fsalary;
				salary = Fsalary;

			}
			if (dSelect == 2)
			{
				cout << "���۾���Ĺ̶���н��";
				cin >> Fsalary;
				cout << "���۾����������ɣ�";
				cin >> Rsales;
				salary = Fsalary + Rsales;
			}
			if (dSelect == 3)
			{
				cout << "����Сʱ����";
				cin >> hour;
				cout << "ÿСʱ/Ԫ��";
				cin >> money;
				salary = money * hour;
			}
			if (dSelect == 4)
			{
				cout << "��ְ����Ա��������ɣ�";
				cin >> Rsales;
				salary = Rsales;
			}
			worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //����
				worker = new Managers(id, name, 1, salary);
				break;
			case 2: //���۾���
				worker = new salesmanagers(id, name, 2, salary);
				break;
			case 3:  //��ְ������Ա
				worker = new parttechnicians(id, name, 3, salary);
				break;
			case 4://��ְ����Ա
				worker = new parttimesalesmen(id, name, 4, salary);
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µĸ���
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�ձ�־
		//��ζ�Ÿö�����������ļ���Ϊ�ա�
		this->m_FileIsEmpty = false;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		//��������
		/*this->save() ���� workmanager �е�һ����Ա���������ڽ���ǰ�����е�Ա����Ϣ���浽�ļ��С�
		����ĳ�Ա�����У�����ֱ�ӷ��ʸ���ĳ�Ա������������Ա����
		����� save() �����п��Է��� m_EmpArray��m_EmpNum �ȳ�Ա�������������Ǳ��浽�ļ��С�*/
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}
void workmanager::save()
{
	//ofstream �� C++ ������д���ļ���������࣬���ڽ�����д�뵽�ļ���
	ofstream ofs;
	// ios::out����ʹ��ios::outģʽ���ļ�����ʾ���ģʽ��Ҳ����˵������򿪵��ļ������ڣ�
	// �ͻ��½�һ��ͬ�����ļ�������ļ��Ѵ��ڣ��������ļ�ԭ�����ݡ�
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->id << " "
			<< this->m_EmpArray[i]->name << " "
			<< this->m_EmpArray[i]->m_DeptId << " "
			<< this->m_EmpArray[i]->salary << endl;
	}

}
int workmanager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	float salary;

	int num = 0;
	//ifs >> id ��ʾ�������ļ��� ifs �ж�ȡһ��������������洢�ڱ��� id �С�
	//������ && ���ӣ�����ֻ�������в������ɹ�����ȡ������ȷ���������ͣ�������£��������ʽ�Ľ����Ϊ�档
	while (ifs >> id && ifs >> name && ifs >> dId && ifs >> salary)
	{
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}


//��ʼ��Ա��
void workmanager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	float salary;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId && ifs >> salary)
	{
		worker* worker = NULL;
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)  // 1����
		{
			worker = new Managers(id, name, dId, salary);
		}
		else if (dId == 2) //2
		{
			worker = new salesmanagers(id, name, dId, salary);
		}
		else if (dId == 3)//3
		{
			worker = new parttechnicians(id, name, dId, salary);
		}
		else//4��ְ����Ա
		{
			worker = new parttimesalesmen(id, name, dId, salary);
		}
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}
}
//��ʾְ��
void workmanager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
			this->m_EmpArray[i]->show();
		}
	}

	system("pause");
	system("cls");
}