#include<iostream>
using namespace std;
#include "workmanager.h"

int main()
{
	while (true)
	{
		workmanager zs;
		zs.show_menu();
		int choice = 0;
		cout << "��������Ӧ������ѡ���Ӧ�Ĺ���:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			zs.exitsystem();
		case 1:
			zs.add_worker();
			break;
		case 2:
			zs.Show_Emp();
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