#include "Funcs.h"

int _stateMenu;
void menu() {
	std::cout << "�������� ��������: " << std::endl
		<< "(0) ����� �� ���������" << std::endl
		<< "(1) ���� ������" << std::endl
		<< "(2) ����� ������" << std::endl
		<< "(3) ��������� ������" << std::endl
		<< "(4) ���������� ������" << std::endl
		<< "(5) �������� ������" << std::endl
		<< "(6) ���������� ������" << std::endl
		<< "(7) ���������� ������" << std::endl
		<< "��� ����� -> ";
	std::cin >> _stateMenu;
}

int main() {
	setlocale(LC_ALL, "Russian"); //��� �������������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu();
	int actions;
	std::string fileName;

	int _size = 0;
	Data* d = new Data[_size];

	while (_stateMenu != 0) {
		switch (_stateMenu) {
		case 1:
			system("cls");

			std::cout << "���� ������ ������������ ������� ��� ������� �� �����?\n1 - �������, 2 - �� �����\n����� -> ";
			std::cin >> actions;

			system("cls");
			if (actions == 1) {
				dataEntry(d, _size);
			}
			else {
				std::cout << "������� �������� ����� -> ";
				std::cin >> fileName;
				dataReading(d, _size, fileName);
			}
			system("pause");
			system("cls");
			menu();
			break;

		case 2:
			system("cls");

			if (_size != 0) 
				print(d, _size);
			else
				std::cout << "������ �����������" << std::endl;
			
			system("pause");
			system("cls");
			menu();
			break;

		case 3:
			system("cls");

			if (_size != 0)
				dataChange(d, _size);
			else
				std::cout << "������ �����������" << std::endl;
			system("pause");
			system("cls");
			menu();
			break;

		case 4:
			system("cls");

			if (_size != 0)
				addData(d, _size);
			else
				std::cout << "������ �����" << std::endl;

			system("pause");
			system("cls");
			menu();
			break;

		case 5:
			system("cls");

			if (_size != 0)
				deleteData(d, _size);
			else
				std::cout << "������ �����������" << std::endl;

			system("pause");
			system("cls");
			menu();
			break;

		case 6:
			system("cls");

			if (_size != 0)
				sortData(d, _size);
			else
				std::cout << "������ �����������" << std::endl;

			system("pause");
			system("cls");
			menu();
			break;

		case 7:
			system("cls");

			if (_size != 0) {
				std::cout << "������� �������� �����: ";
				std::cin >> fileName;

				saveData(d, _size, fileName);
			}
			else
				std::cout << "������ �����������" << std::endl;

			system("pause");
			system("cls");
			menu();
			break;

		default:
			std::cout << "����� ���� ������ �������. ��������� � ��������� � ��������� �������" << std::endl;
			system("cls");
			menu();
			break;
		}

	}

	system("cls");
	std::cout << "������ ���������" << std::endl;
	system("pause");
}