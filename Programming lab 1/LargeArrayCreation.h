#pragma once
#define PageSize 512
#define PagesInMemory 8
#include "PageStruct.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <bitset>

class LargeArray {
public:
	LargeArray(long _size, std::string _filename);
	void* /*������� ��� ������*/ GetAddress(long index);
	int GetValue(long index, int& result) const;
	int SetValue(long index, int value);
	long GetArraySize() const;
	/*��������������� []*/
	~LargeArray();
private:
	std::string filename;
	long size;
	std::fstream* filePtr;
	Page pages[PagesInMemory];
	std::bitset<PageSize/4> bits[PagesInMemory];
	void savePage();
	Page LoadPage();
};

/* std::ios::app - ��������� ������*/
//����������� ��������
