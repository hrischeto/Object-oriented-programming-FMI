#include <iostream>
union ipAddress {
	uint32_t num;
	char octets[4];
};

//int main()
//{
//	ipAddress myAddress;
//	myAddress.num = 16777343;
//
//	std::cout << (unsigned)myAddress.octets[0] << "."
//		<< (unsigned)myAddress.octets[1] << "."
//		<< (unsigned)myAddress.octets[2] << "."
//		<< (unsigned)myAddress.octets[3];
//}