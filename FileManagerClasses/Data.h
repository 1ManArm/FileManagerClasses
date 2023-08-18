#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

struct Inits {
	std::string surname,
		name,
		patrinymic;
};

struct Date {
	int day,
		month,
		year;
};

struct Address {
	std::string city;
	int home;
};

class Data {
private:
	Inits initials;
	Date date;
	Address address;
public:
	Data();
	Data(Inits initials_, Date date_, Address address_);
	~Data();

	void print();
	void dataEntry(Inits initials_, Date date_, Address address_);

	Inits getInits() { return initials; };
	Date getDate() { return date; };
	Address getAddress() { return address; };

	Data& operator = (Data d_o);
};