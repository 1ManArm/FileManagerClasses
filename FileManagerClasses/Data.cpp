#include "Data.h"

Data::Data() {
	initials.surname = "";
	initials.name = "";
	initials.patrinymic = "";

	date.day = 0;
	date.month = 0;
	date.year = 0;

	address.city = "";
	address.home = 0;
}

Data::Data(Inits initials_, Date date_, Address address_) {
	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patrinymic = initials_.patrinymic;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	address.city = address_.city;
	address.home = address_.home;
}

Data::~Data(){}

void Data::print() {
	std::cout << "ÔÈÎ: " << initials.surname << " " << initials.name << "" << initials.patrinymic << std::endl;
	std::cout << "Äàòà: " << date.day << " " << date.month << " " << date.year << std::endl;
	std::cout << "Àäğåñ: " << address.city << " " << address.home << std::endl;
}

void Data::dataEntry(Inits initials_, Date date_, Address address_) {
	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patrinymic = initials_.patrinymic;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	address.city = address_.city;
	address.home = address_.home;
}

Data& Data::operator=(Data d_o) {
	this->initials.surname = d_o.initials.surname;
	this->initials.name = d_o.initials.name;
	this->initials.patrinymic = d_o.initials.patrinymic;

	this->date.day = d_o.date.day;
	this->date.month = d_o.date.month;
	this->date.year = d_o.date.year;

	this->address.city = d_o.address.city;
	this->address.home = d_o.address.home;

	return *this;
}