#include<iostream>
using namespace std;
//ͷ�ļ��ṩ���ļ������������ͺ���
#include <fstream>
//������һ���ļ������� FILENAME Ϊ "empFile.txt"�����ں�����дԱ������ʱ��Ϊ�ļ���ʹ��
#define  FILENAME "empFile.txt"
#include "worker.h"
#include "parttechnicians.h"
#include "parttimesalesmen.h"
#include "Managers.h"
#include "salesmanagers.h"
class workmanager
{
public:

	//���캯��
	workmanager();

	//չʾ���ܲ˵�
	void show_menu();

	//�˳�ϵͳ�ĳ�Ա����
	void exitsystem();

	//��¼�ļ��е���������
	int m_EmpNum;

	//Ա�������ָ��
	worker** m_EmpArray;

	//����ְ��
	void add_worker();

	//�����ļ�
	void save();

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//��������
	~workmanager();
};
