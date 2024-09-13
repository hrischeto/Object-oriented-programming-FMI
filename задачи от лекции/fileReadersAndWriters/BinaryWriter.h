#pragma once
#include "FileWriter.h"

class BinaryWriter :
    public FileWriter
{
	public:
		BinaryWriter(const MyString& filePath);
		void write(const int* arr, size_t size) const override;
	
};

