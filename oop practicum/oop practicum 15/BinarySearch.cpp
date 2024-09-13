
#include <iostream>

template<typename Iter, typename  T>
Iter binarySearch(Iter begin, Iter end, T searched)
{
	while (begin <= end)
	{
		Iter mid = begin + (end - begin) / 2;

		if (searched > *mid)
			begin = mid + 1;
		else if (searched < *mid)
			end = mid - 1;
		else if (searched == *mid)
			return mid;
	}
}

int main()
{
	int* arr = new int[5] {1, 2, 3, 4, 5};
	int* four = binarySearch<int*, int>(arr, arr + 5, 4);
	std::cout << *four;
}