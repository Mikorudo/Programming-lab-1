#include <iostream>
typedef unsigned char byte;
#include "LargeArrayCreation.h"

void changeValue(size_t index, int value, int* valueArray, std::bitset<128>& bitmap)
{
	valueArray[index] = value;
	bitmap.set(index);
}
std::string packBytes(std::bitset<128>& bitmap)
{
	std::string str(128, char(00));
	for (size_t i = 0; i < 128; i++)
	{
		if (bitmap[i] == 1)
		{
			str[i] = char(01);
		}
		else
		{
			str[i] = char(00);
		}
	}
	std::cout << str;
	return str;
}

void main() {

	std::bitset<128> bits(0);

	int valueArray[128];
	for (size_t i = 0; i < 128; i++)
	{
		valueArray[i] = 0;
	}
	try
	{
		for (size_t i = 4; i < 125; i++)
		{
			changeValue(i, 25, valueArray, bits);
		}
		changeValue(127, 25, valueArray, bits);
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}

	std::cout << "Value: " << valueArray[127] << '\n';
	std::cout << "All the bits: " << bits << '\n';
	std::cout << "0 bit: " << bits[0] << '\n';
	std::cout << "125 bit: " << bits[125] << '\n';
	std::cout << "126 bit: " << bits[126] << '\n';
	std::cout << "127 bit: " << bits[127] << '\n';
	std::fstream file("tesst.txt",std::ios::binary | std::ios::in | std::ios::out | std::fstream::trunc);
	
	file << packBytes(bits);

	//int index = 0;
	//int pageNum = 1 + index / (PageSize / 4);
	//int relativeAddress, absoluteAddress = 0;
	//relativeAddress = (1 + index*4) % 256;
	//absoluteAddress = 2 + pageNum * (16+ relativeAddress);
	//std::cout << "pageNum: " << pageNum - 1 << '\n';
	//std::cout << "relativeAddress: " << relativeAddress << '\n';
	//std::cout << "absoluteAddress: " << absoluteAddress << '\n';
}