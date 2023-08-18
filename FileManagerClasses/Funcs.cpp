#include "Funcs.h"


void dataEntry(Data* (&d), int& n)
{
	Inits initials;
	Date date;
	Address address;

	std::cout << "������� ������ �������: ";
	std::cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		std::cout << "������� ��� ���������: ";
		std::cin >> initials.surname >> initials.name >> initials.patrinymic;

		std::cout << "������� ����: ";
		std::cin >> date.day >> date.month >> date.year;

		std::cout << "������� �����: ";
		std::cin >> address.city >> address.home;

		d[i].dataEntry(initials, date, address);

		std::cout << "______________________________________\n";
	}
}

void dataReading(Data* (&d), int& n, std::string fileName)
{
	std::ifstream reading(fileName);

	if (reading) {
		Inits initials;
		Date date;
		Address address;

		reading >> n;
		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> initials.surname >> initials.name >> initials.patrinymic;
			reading >> date.day >> date.month >> date.year;
			reading >> address.city >> address.home;

			d[i].dataEntry(initials, date, address);
		}
		std::cout << "������ ������� �������" << std::endl;
	}
	else
		std::cout << "������ �������� �����" << std::endl;

	reading.close();
}

void print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		std::cout << "������ �" << i + 1 << std::endl;

		d[i].print();
		std::cout << "______________________________________\n";
	}
}

void dataChange(Data* d, int n)
{
	Inits initials;
	Date date;
	Address address;
	int _n;

	std::cout << "������� ����� ������� �������� (�� 1 �� " << n << "): ";
	std::cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		std::cout << "������� ����� ��� ���������: ";
		std::cin >> initials.surname >> initials.name >> initials.patrinymic;

		std::cout << "������� ����� ����: ";
		std::cin >> date.day >> date.month >> date.year;

		std::cout << "������� ����� �����: ";
		std::cin >> address.city >> address.home;

		d[_n].dataEntry(initials, date, address);
	}
	else
		std::cout << "����� ������ �������" << std::endl;
}

void copy(Data* d_n, Data* d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];
}

void addData(Data* (&d), int& n)
{
	Inits initials;
	Date date;
	Address address;
	Data* buf = new Data[n];
	int size = n, new_size = ++n;

	copy(buf, d, size);

	d = new Data[new_size];

	copy(d, buf, size);

	std::cout << "������� ����� ��� ���������: ";
	std::cin >> initials.surname >> initials.name >> initials.patrinymic;

	std::cout << "������� ����� ����: ";
	std::cin >> date.day >> date.month >> date.year;

	std::cout << "������� ����� �����: ";
	std::cin >> address.city >> address.home;

	d[size].dataEntry(initials, date, address);

	std::cout << "������ ������� ���������" << std::endl;

	delete[] buf;
}

void deleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	std::cout << "������� ����� ������� �������� (�� 1 �� " << n << "): ";
	std::cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		copy(buf, d, n);
		int q = 0;
		n--;

		d = new Data[n];

		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				q++;
			}
		}

		std::cout << "������ �������" << std::endl;
	}
	else
		std::cout << "������ �������� �����" << std::endl;

	delete[]buf;
}

void sortData(Data* d, int n)
{
	Data buf;
	int numOfSorted = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i].getInits().surname > d[j].getInits().surname) {
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				numOfSorted++;
			}
		}
	}
	std::cout << "������ ������� �������������\n���������� ����������: " << numOfSorted << std::endl;
}

void saveData(Data* d, int n, std::string fileName)
{
	std::ofstream record(fileName);

	if (record) {
		record << n << std::endl;

		for (int i = 0; i < n; i++) {
			record << d[i].getInits().surname << d[i].getInits().name << d[i].getInits().patrinymic << std::endl;
			record << d[i].getDate().day << d[i].getDate().month << d[i].getDate().year << std::endl;
			record << d[i].getAddress().city << d[i].getAddress().home << std::endl;

			if (i < n - 1)
				record << std::endl;
		}
	}
	else
		std::cout << "������ �������� �����" << std::endl;

	std::cout << "������ ������� ��������� � ���� " << fileName << std::endl;

	record.close();
}
