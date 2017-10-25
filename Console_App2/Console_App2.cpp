/*�11 
����������� ����� Account,�������������� ����� ���������� ����.
� ������ ������ ���� 4 ����:������� ���������,����� �����,������� ���������� � ����� � ������.
�������� ����� ����������� ��������� �������������.���������� ��������� ��������� ��������:
c������ ��������� �����,����� ��������� ����� ����� �� �����,�������� ������ �� ����,��������� ��������,��������� ����� � �������,����.
*/
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
class Account
{
private:
	string name;
	int number;
	int summa;
	int percent;
public:
	Account() { number = 0; summa = 0; percent = 0; };
	void enter(); // ���� ���������
	void show(); // ������ ���������
	void chown(); // ����� ��������� 
	void pull_of(); // ����� ����� 
	void put(); // �������� �����
	void per(); // ���������e ��������
	void change(); // ������� � ������ ������
};

void Account::enter()// ���� ���������
{
	cout << "������� ������� " << endl;
	cin >> name;
	cout << "������� ����� ����������� ����� " << endl;
	cin >> number;
	cout << "������� ����� " << endl;
	cin >> summa;
	cout << "������� �������� " << endl;
	cin >> percent;
}

void Account::show()// ������ ���������
{
	cout << "������� " << name << endl;
	cout << "����� ����������� ����� " << number << endl;
	cout << "����� ����� " << summa << endl;
	cout << "���� �������� ����� " << percent << endl;
}

void Account::chown()// ����� ��������� 
{
	cout << "����� ��������� ����� " << endl;
	cout << "������� ������� ������ ��������� " << endl;
	cin >> name;
}

void Account::pull_of()// ����� ����� 
{
	int s;
	cout << "�� ����������� ������ ����� " << endl;
	cout << "������� ����� ������� �� ������ ����� " << endl;
	cin >> s;

	if (s > summa)
		cout << "�� �� ������ ����� ����� �����, � ��� �� ����� �� ����� ����� " << endl;
	else
	{
		summa -= s;
		cout << "������� ����� " << summa << endl;
	}
}

void Account::put()// �������� c����
{
	int s;
	cout << "������� �����, ������� �� ������ ������ " << endl;
	cin >> s;

	summa += s;
	cout << "����� �� ����� ����� ����� " << summa << endl;
}

void Account::per()
{
	cout << "��������� ���������� ����� �� ��������� " << endl;
	cout << "������� �� ������ ������ ����� " << percent << endl;
	summa = summa + ((summa*percent) / 100);
	cout << "����� ����� ���������� �������� ����� " << endl;
	cout << summa << endl;
}

void Account::change()
{
	int number;
	cout << "� ����� ������ ������ ��������� " << endl;
	cout << "1) ������ " << endl;
	cout << "2) ���� " << endl;
	cout << "������� ��� ������� " << endl;
	cin >> number;
	if (number == 1)
		cout << "���� ����� � �������� ����� " << summa / 57<< endl;
	else if (number == 2)
		cout << "���� ����� � ���� ����� " << summa / 67<< endl;
	else
		cout << "�� ��������� ���� " << endl;

}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Account ac;
	int number;

	for (; ;)
	{
		cout << " ����  " << endl;
		cout << "1 ���� ������������ ������" << endl;
		cout << "2 ����� ������ " << endl;
		cout << "3 ����� ��������� ����������� ����� " << endl;
		cout << "4 ����� �����" << endl;
		cout << "5 �������� ����� " << endl;
		cout << "6 ��������� ��������" << endl;
		cout << "7 ������� ����� � ������ ������" << endl;
		cout << "8 ����� " << endl << endl;
		cout << "������� ��� ������� " << endl;
		cin >> number;

		switch (number)
		{
		case 1: ac.enter(); break;
		case 2: ac.show(); break;
		case 3: ac.chown(); break;
		case 4: ac.pull_of(); break;
		case 5: ac.put(); break;
		case 6: ac.per(); break;
		case 7: ac.change(); break;
		case 8: cout << "�� �������� " << endl; exit(1); break;
		default: cout << "����������� ���� " << endl; break;
		}
		getchar();

	}
}