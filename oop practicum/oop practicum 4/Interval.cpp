#include <iostream>

bool isPrime(int n)
{
	if (n == 1)
		return false;

	double square = sqrt(n);

	for (int i = 2;i <= square;i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}
struct ClosedInterval
{
public:
	ClosedInterval(int beg, int end)
	{
		setBeg(beg);
		setEnd(end);
	}

	ClosedInterval() :ClosedInterval(0, 0) {}

	void setBeg(int a)
	{
		beg = a;
	}

	void setEnd(int b)
	{
		if (b >= beg)
			end = b;
		else
			end = beg=0;
	}

	int getLenght() const
	{
		return end - beg;
	}

	bool contains(int n) const
	{
		return n >= beg && n <= end;
	}

	int PrimeNumbersCount() const
	{
		int count = 0;
		for (int i = beg;i <= end;i++)
		{
			if (isPrime(i))
			{
				count++;
				std::cout << i << " ";
			}
				
		}

		return count;
	}

	ClosedInterval intersection(const ClosedInterval& other) const
	{
		int _beg = beg > other.beg ? beg:other.beg;
		int _end = end <other.end ? end:other.end;

		return ClosedInterval(_beg, _end);
	}

	bool isSubinterval(const ClosedInterval& other) const
	{
		return other.beg >= beg && other.end <= end;
	}

	void print() const
	{
		std::cout << "[" << beg << "," << end << "]" << std::endl;
	}

private:
	int beg = 0;
	int end = 0;


};