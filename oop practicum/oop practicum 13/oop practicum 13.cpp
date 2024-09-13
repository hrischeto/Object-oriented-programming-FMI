#include <iostream>
#include "restricted_ptr.hpp"

int main()
{
	RestrictedPtr<int, 2> ptr = new int(5);
	RestrictedPtr<int, 2> ptr2 = ptr;

    try
    {
        // This line should throw a logic_error because it exceeds the restriction
        RestrictedPtr<int, 2> ptr3 = ptr;
    }
    catch (const std::logic_error& exc)
    {
        std::cout << exc.what();  // Handle the specific logic_error exception
    }
    catch (...)
    {
        std::cout << "unknown";  // Handle any other exceptions
    }
}
