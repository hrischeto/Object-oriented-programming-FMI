#include "stringView.h"

StringView::StringView(const char* beg, const char* end) :_beg(beg), _end(end) {}
StringView::StringView(const char* str)
{
	_beg = str;
	_end = str + std::strlen(str);
}

StringView::StringView(const MyString& str)
{
	_beg = str.c_str();
	_end = str.c_str() + str.getSize();
}

size_t StringView::length()const
{
	return _end - _beg;
}

char StringView::operator[](int index) const
{
	return _beg[index];
}

StringView StringView::substr(size_t from, size_t length)
{
	if (_beg + from + length > _end)
		throw std::length_error("Error, substr out of range");

	return StringView(_beg + from, _beg + from + length);
}
std::ostream& operator<<(std::ostream& os, const StringView& str)
{
	const char* iter = str._beg;

	while (iter < str._end)
	{
		os << *iter;
		iter++;
	}
	return  os;
}
