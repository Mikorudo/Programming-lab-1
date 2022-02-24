#pragma once
#include "PageStruct.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <bitset>

class LargeArrayCreation {
public:
	const int intSize = sizeof(int);
	const int pageSize = 512;
	const int intCount = pageSize / intSize;
	LargeArrayCreation(long _size, std::string _filename);
	void* /*сменить тип данных*/ GetAddress(long index) const;
	int GetValue(long index, int& result) const;
	int SetValue(long index, int value);
	long GetArraySize() const;
	/*Переопределение []*/
	~LargeArrayCreation();
private:
	std::string filename;
	long size;
	std::fstream* filePtr;
	Page pages[5];
	std::bitset<128> bits; 
};

/* std::ios::app - возможная ошибка*/
//Модификация страницы
