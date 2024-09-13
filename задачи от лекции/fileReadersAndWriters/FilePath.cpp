#include "FilePath.h"

FilePath::FilePath(const MyString& file)
{
	const char* beg = file.c_str();
	const char* end = file.c_str() + file.getSize();
	const char* iter = end;

	while (iter != beg && *iter != '.') {
		iter--;
	}

	this->name = file.substr(0, iter - beg);
	this->extension = file.substr(iter - beg, end - iter);
}
const MyString& FilePath::getName() const
{
	return name;
}
const MyString& FilePath::getExtension() const
{
	return extension;
}