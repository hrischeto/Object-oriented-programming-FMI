#pragma once
#include "MyString.h"
#include <fstream>
class FileReader
{
protected:
	MyString filePath;
public:
	FileReader(const MyString& filePath);
	virtual int* read(size_t& size) const = 0;

	virtual ~FileReader() = default;
};

