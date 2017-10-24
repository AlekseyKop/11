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
#include <locale.h>
#include <sstream>

using namespace std;
class Account
{
private:
	unsigned char name[80];
	int number;
	int summa;
	int percent;

public:
	Account() { number = 0; summa = 0; percent = 0; };
	void Read(); // ���� ���������
	void Init(); // ������������� ���������
	void Display(); // ������ ���������
	void chown(); // ����� ��������� 
	void pull_of(); // ����� ����� 
	void put(); // �������� �����
	void per(); // ���������e ��������
	void change(); // ������� � ������ ������
	void ToString(); //�������������� ������ � ��������� � ������
};

void Account::Read()// ���� ���������
{
	cout << "������� ������� " << endl;
	cin >> name;
	cout << "������� ����� ����������� ����� " << endl;
	cin >> number;
	cout << "������� ����� " << endl;
	cin >> summa;
	cout << "������� �������� " << endl;
	cin >> percent;
	Init();
}

void Account::Init()// �������� ������ � ���������
{
	while (number < 0)
	{
		cout << "����� ����������� ����� ������ �������" << endl;
		cout << "������� ����� ����������� ����� " << endl;
		cin >> number;
	}
	while (summa < 0)
	{
		cout << "����� �� ����� ���� ������������� ������" << endl;
		cout << "������� c����" << endl;
		cin >> summa;
	}
	while ((percent < 0) || (percent > 100))
	{
		cout << "������� ����� �������" << endl;
		cout << "������� �������� " << endl;
		cin >> percent;
	}
}

void Account::Display()// ������ ���������
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
		cout << "���� ����� � �������� ����� " << summa / 57 << endl;
	else if (number == 2)
		cout << "���� ����� � ���� ����� " << summa / 67 << endl;
	else
		cout << "�� ��������� ���� " << endl;

}

void Account::ToString()
{
	if (name[0] == '\0')
	{
		Read();
	}
	ostringstream strs;
	strs << name << ": " << number << " �����: " << summa << " �������: " << percent << endl;
	string result = strs.str();
	cout << result << endl;
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
		cout << "8 ������� � ������" << endl;
		cout << "9 ����� " << endl << endl;
		cout << "������� ��� ������� " << endl;
		cin >> number;

		switch (number)
		{
		case 1: ac.Read(); break;
		case 2: ac.Display(); break;
		case 3: ac.chown(); break;
		case 4: ac.pull_of(); break;
		case 5: ac.put(); break;
		case 6: ac.per(); break;
		case 7: ac.change(); break;
		case 8: ac.ToString(); break;
		case 9: cout << "�� �������� " << endl; exit(1); break;
		default: cout << "����������� ���� " << endl; break;
		}
		getchar();

	}
}