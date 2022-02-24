#include "LargeArrayCreation.h"
#include "PageStruct.h"
#include <string>
#include <fstream>
#include <exception>
#include <bitset>

LargeArrayCreation::LargeArrayCreation(long _size, std::string _filename = "default.dat") {
	if (size < 0) {
		throw std::exception("Negative array size");
	}
	filename = _filename;
	size = _size;
	filePtr = new std::fstream(filename, std::ios::binary | std::ios::in | std::ios::out);
	if (!filePtr) {
		throw std::exception("Couldn't open file");
	}
}
LargeArrayCreation::~LargeArrayCreation() {
	if (filePtr != NULL)
		delete filePtr;
}
long LargeArrayCreation::GetArraySize() const {
	return size;
}