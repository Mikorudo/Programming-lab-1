#pragma once
class LargeArrayCreation {
public:
	LargeArrayCreation(long _size, std::string _filename);
	int /*������� ��� ������*/ GetAddress(long index);
	int GetValue(long index, int& result);
	int SetValue(long index, int value);
	/*��������������� []*/
private:
	std::string filename;
	long size;
	FILE* filePtr;
	/*����� �������*/
	/*������ ������� ���� ��������*/
	/**/
};

