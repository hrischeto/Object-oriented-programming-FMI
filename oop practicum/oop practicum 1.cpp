#include <iostream>


constexpr size_t SIZE = 51;

/*zad1*/
struct Complex {
	int Real;
	int Imaginary;
};

Complex addRightToLeft(const Complex& lhs, const Complex& rhs)
{
	Complex lhsCopy = lhs;
	lhsCopy.Real += rhs.Real;
	lhsCopy.Imaginary += rhs.Imaginary;

	return lhsCopy;
}

Complex multiplication(const Complex& lhs, const Complex& rhs)
{
	{
		Complex lhsCopy = lhs;

		lhsCopy.Real = lhs.Real * rhs.Real - lhs.Imaginary * rhs.Imaginary;


		lhsCopy.Imaginary = lhs.Real * rhs.Imaginary + lhs.Imaginary * rhs.Real;

		return lhsCopy;
	}
}

void printComplexNum(const Complex& num)
{
	std::cout << num.Real << " + " << num.Imaginary << 'i' << std::endl;
}
/*zad2*/
enum Genre { Novel, Historic, Poetry, Other };

struct Book {
	char title[SIZE];
	char autor[SIZE];
	Genre genre = Other;
	bool availability = 0;
};

struct Library {
	int numberOfBooks = 0;
	Book library[SIZE];
};

Library& addNewBook(Library& l1, const Book& book)
{
	l1.library[l1.numberOfBooks] = book;
	l1.numberOfBooks++;
}
int main()
{

}