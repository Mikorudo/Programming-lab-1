#include "LargeArrayCreation.h"
#include <string>
#include <fstream>
#include <exception>

LargeArrayCreation::LargeArrayCreation(long _size, std::string _filename = "default.dat") {
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