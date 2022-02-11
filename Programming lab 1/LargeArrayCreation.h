#pragma once
class LargeArrayCreation {
public:
	LargeArrayCreation(long _size, std::string _filename);
	int /*сменить тип данных*/ GetAddress(long index);
	int GetValue(long index, int& result);
	int SetValue(long index, int value);
	/*Переопределение []*/
private:
	std::string filename;
	long size;
	FILE* filePtr;
	/*Буфер страниц*/
	/*Массив битовых карт страницы*/
	/**/
};

