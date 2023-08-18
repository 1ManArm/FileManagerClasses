#pragma once
#include "Data.h"

void dataEntry(Data* (&d), int& n);
void dataReading(Data* (&d), int& n, std::string fileName);
void print(Data* d, int n);
void dataChange(Data* d, int n);
void copy(Data* d_n, Data* d_o, int n);
void addData(Data* (&d), int& n);
void deleteData(Data* (&d), int& n);
void sortData(Data* d, int n);
void saveData(Data* d, int n, std::string fileName);