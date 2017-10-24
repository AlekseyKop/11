/*№11
Реализовать класс Account,представляющий собой банковский счёт.
В классе должны быть 4 поля:фамилия владельца,номер счёта,процент начисления и сумма в рублях.
Открытие счёта выполняется операцией инициализации.Необходимо выполнять следующие операции:
cменить владельца счёта,снять некоторую сумму денег со счёта,положить деньги на счёт,начислить проценты,перевести сумму в доллары,евро.
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
	void Read(); // ввод владельца
	void Init(); // инициализация владельца
	void Display(); // печать владельца
	void chown(); // смена владельца 
	void pull_of(); // снять сумму 
	void put(); // положить сумму
	void per(); // начислениe процента
	void change(); // перевод в другую валюту
	void ToString(); //преобразование данных о владельце в строку
};

void Account::Read()// ввод владельца
{
	cout << "Введите фамилию " << endl;
	cin >> name;
	cout << "Введите номер банковского счёта " << endl;
	cin >> number;
	cout << "Введите сумму " << endl;
	cin >> summa;
	cout << "Введите проценты " << endl;
	cin >> percent;
	Init();
}

void Account::Init()// проверка данных о владельце
{
	while (number < 0)
	{
		cout << "Номер банковского счета введен неверно" << endl;
		cout << "Введите номер банковского счёта " << endl;
		cin >> number;
	}
	while (summa < 0)
	{
		cout << "Сумма не может быть отрицательным числом" << endl;
		cout << "Введите cумму" << endl;
		cin >> summa;
	}
	while ((percent < 0) || (percent > 100))
	{
		cout << "Процент введён неверно" << endl;
		cout << "Введите проценты " << endl;
		cin >> percent;
	}
}

void Account::Display()// печать владельца
{
	cout << "Фамилия " << name << endl;
	cout << "Номер банковского счёта " << number << endl;
	cout << "Сумма равна " << summa << endl;
	cout << "Ваши проценты равны " << percent << endl;
}

void Account::chown()// смена владельца 
{
	cout << "Смена владельца счёта " << endl;
	cout << "Введите фамилию нового владельца " << endl;
	cin >> name;
}

void Account::pull_of()// снять сумму 
{
	int s;
	cout << "Вы производите снятие денег " << endl;
	cout << "Введите сумму которую вы хотите снять " << endl;
	cin >> s;

	if (s > summa)
		cout << "Вы не можете снять такую сумму, у вас на счету не такой суммы " << endl;
	else
	{
		summa -= s;
		cout << "Остаток равен " << summa << endl;
	}
}

void Account::put()// положить cумму
{
	int s;
	cout << "Введите сумму, которую вы хотите внести " << endl;
	cin >> s;

	summa += s;
	cout << "Сумма на вашем счету равна " << summa << endl;
}

void Account::per()
{
	cout << "Произошло начисление суммы по процентам " << endl;
	cout << "Процент по вашему вклдау равен " << percent << endl;
	summa = summa + ((summa*percent) / 100);
	cout << "Сумма после начисления процента равна " << endl;
	cout << summa << endl;
}

void Account::change()
{
	int number;
	cout << "В какую валюту хотите перевести " << endl;
	cout << "1) доллар " << endl;
	cout << "2) евро " << endl;
	cout << "Введите ваш вариант " << endl;
	cin >> number;
	if (number == 1)
		cout << "Ваша сумма в долларах равна " << summa / 57 << endl;
	else if (number == 2)
		cout << "Ваша сумма в евро равна " << summa / 67 << endl;
	else
		cout << "Не корретный ввод " << endl;

}

void Account::ToString()
{
	if (name[0] == '\0')
	{
		Read();
	}
	ostringstream strs;
	strs << name << ": " << number << " Сумма: " << summa << " Процент: " << percent << endl;
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
		cout << " Меню  " << endl;
		cout << "1 Ввод персональных данных" << endl;
		cout << "2 Вывод данных " << endl;
		cout << "3 Смена владельца банковского счёта " << endl;
		cout << "4 Снять сумму" << endl;
		cout << "5 Положить сумму " << endl;
		cout << "6 Начислить проценты" << endl;
		cout << "7 Перевод суммы в другую валюту" << endl;
		cout << "8 Перевод в строку" << endl;
		cout << "9 Выход " << endl << endl;
		cout << "Введите ваш вариант " << endl;
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
		case 9: cout << "До свидания " << endl; exit(1); break;
		default: cout << "Некорретный ввод " << endl; break;
		}
		getchar();

	}
}