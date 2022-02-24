#include "LargeArrayCreation.h"


LargeArrayCreation::LargeArrayCreation(long _size, std::string _filename) {
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