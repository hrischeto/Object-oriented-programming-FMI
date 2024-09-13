#include "BinaryWriter.h"

BinaryWriter::BinaryWriter(const MyString& filePath):FileWriter(filePath)
{

}
void BinaryWriter::write(const int* arr, size_t size) const
{
	std::ofstream ofs(filePath.c_str(), std::ios::out | std::ios::binary);

	if (!ofs.is_open())
		throw std::exception("Could not open file");

	ofs.write((const char*)arr, size);
	ofs.close();
}