#include "LargeArrayCreation.h"


LargeArray::LargeArray(long _size, std::string _filename) {
	if (_size < 0) {
		throw std::exception("Negative array size");
	}
	filename = _filename;
	size = _size;
	for (int i = 0; i < PagesInMemory; i++) {
		pages[i].lastAccessTime = time(NULL);
		pages[i].pageNum = i;
		pages[i].pageStatus = 0;
		for (int var : pages[i].valueArray)
			var = 0;
	}
	//че не так с битмапс??
	for (size_t i = 0; i < PagesInMemory; i++)
		bitMaps[i] = std::bitset<PageSize / 4>(0);
	filePtr = new std::fstream(filename, std::ios::binary | std::ios::in | std::ios::out | std::fstream::trunc);
	
	if (!filePtr) {
		throw std::exception("Couldn't open file");
	}
}
LargeArray::~LargeArray() {
	if (filePtr != NULL)
		delete filePtr;
}
long LargeArray::GetArraySize() const {
	return size;
}
void* LargeArray::GetAddress(long index) {
	int relativeAddress, absoluteAddress;
	int pageNum = 1 + index / (PageSize / 4);
	bool isPageExist = false;
	int selectedPage = -1;
	for (size_t i = 0; i < PagesInMemory; i++) {
		if (pages[i].pageNum == pageNum) {
			isPageExist = true;
			selectedPage = i;
			break;
		}
	}
	if (!isPageExist) {
		int oldestPage = 0;
		for (int i = 0; i < PagesInMemory; i++) {
			if (pages[oldestPage].lastAccessTime < pages[i].lastAccessTime)
				oldestPage = i;
		}
		selectedPage = oldestPage;
		if (pages[selectedPage].pageStatus == 0) {
			//Запись страницы в файл
		}
		//Запись в pages[selectedPage] страницы pageNum из файла
		pages[selectedPage].lastAccessTime = time(NULL);
	}
	relativeAddress = (1 + index * 4) % 256;
	absoluteAddress = 2 + pageNum * (128 /*размер битовой карты*/ + relativeAddress);
	return NULL;
}