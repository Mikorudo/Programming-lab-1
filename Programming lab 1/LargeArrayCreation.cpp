#include "LargeArrayCreation.h"


LargeArray::LargeArray(long _size, std::string _filename) {
	if (size < 0) {
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
	for (size_t i = 0; i < PagesInMemory; i++)
		bits[i] = std::bitset<PageSize / 4>(0);
	filePtr = new std::fstream(filename, std::ios::binary | std::ios::in | std::ios::out);
	if (!filePtr) {
		throw std::exception("Couldn't open file");
	}
}
//123
LargeArray::~LargeArray() {
	if (filePtr != NULL)
		delete filePtr;
}
long LargeArray::GetArraySize() const {
	return size;
}
void* LargeArray::GetAddress(long index) {
	int pageNum = index / (PageSize / 4);
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
			//������ �������� � ����
		}
		//������ � pages[selectedPage] �������� pageNum �� �����
		pages[selectedPage].lastAccessTime = time(NULL);
		//��������� ������������� ����� �������� �� ��������;
		//���������� ���������� ����� �������� ��� NULL, ���� ���������� ������
		//���������� ������ = 2 + pageNum*( // sizeof(������� �����) // + 128 * 4)
			//������ ���������� � ������ ������
	}
}