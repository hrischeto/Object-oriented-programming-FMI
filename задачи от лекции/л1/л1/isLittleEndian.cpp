#include <iostream>
bool isLittleEndian() {

	union endianessTest {
		uint32_t num = 1;
		char ch[4];
	} myTest;

	return myTest.ch[0];
};

//int main()
//{
//	std::cout << isLittleEndian();
//}