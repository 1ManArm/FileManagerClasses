#include "Funcs.h"

int _stateMenu;
void menu() {
	std::cout << "Выберите действие: " << std::endl
		<< "(0) Выход из программы" << std::endl
		<< "(1) Ввод данных" << std::endl
		<< "(2) Вывод данных" << std::endl
		<< "(3) Изменение данных" << std::endl
		<< "(4) Добавление данных" << std::endl
		<< "(5) Удаление данных" << std::endl
		<< "(6) Сортировка данных" << std::endl
		<< "(7) Сохранение данных" << std::endl
		<< "Ваш выбор -> ";
	std::cin >> _stateMenu;
}

int main() {
	setlocale(LC_ALL, "Russian"); //Для перестраховки
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

			std::cout << "Ввод данных производится вручную или считать из файла?\n1 - вручную, 2 - из файла\nВыбор -> ";
			std::cin >> actions;

			system("cls");
			if (actions == 1) {
				dataEntry(d, _size);
			}
			else {
				std::cout << "Введите название файла -> ";
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
				std::cout << "Данные отсутствуют" << std::endl;
			
			system("pause");
			system("cls");
			menu();
			break;

		case 3:
			system("cls");

			if (_size != 0)
				dataChange(d, _size);
			else
				std::cout << "Данные отсутствуют" << std::endl;
			system("pause");
			system("cls");
			menu();
			break;

		case 4:
			system("cls");

			if (_size != 0)
				addData(d, _size);
			else
				std::cout << "Данные пусты" << std::endl;

			system("pause");
			system("cls");
			menu();
			break;

		case 5:
			system("cls");

			if (_size != 0)
				deleteData(d, _size);
			else
				std::cout << "Данные отсутствуют" << std::endl;

			system("pause");
			system("cls");
			menu();
			break;

		case 6:
			system("cls");

			if (_size != 0)
				sortData(d, _size);
			else
				std::cout << "Данные отсутствуют" << std::endl;

			system("pause");
			system("cls");
			menu();
			break;

		case 7:
			system("cls");

			if (_size != 0) {
				std::cout << "Введите название файла: ";
				std::cin >> fileName;

				saveData(d, _size, fileName);
			}
			else
				std::cout << "Данные отсутствуют" << std::endl;

			system("pause");
			system("cls");
			menu();
			break;

		default:
			std::cout << "Пункт меню введен неверно. Сверьтесь с функциями и повторите попытку" << std::endl;
			system("cls");
			menu();
			break;
		}

	}

	system("cls");
	std::cout << "Работа завершена" << std::endl;
	system("pause");
}