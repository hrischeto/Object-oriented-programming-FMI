#include <iostream>
#include <assert.h>
struct Rational
{
    int nom;
    int denom;
};

bool isValid(const Rational& r)
{
    return r.denom != 0;
}

void printRational(const Rational& r)
{
    std::cout << r.nom << "/" << r.denom << std::endl;
}

int getGCD(unsigned a, unsigned b)
{
    if (a < b)
        std::swap(a, b);

    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

void rationalize(Rational& r)
{
    assert(isValid(r));

    unsigned gcd = getGCD(r.nom, r.denom);

    r.nom /= gcd;
    r.denom /= gcd;

    if (r.nom < 0 && r.denom < 0 || r.nom > 0 && r.denom < 0)
    {
        r.nom*=-1;
        r.denom *= -1;
    }
}

Rational& plusEq(Rational& lhs, const Rational& rhs)
{
    assert(isValid(lhs) && isValid(rhs));

    lhs.nom *= rhs.denom;
    lhs.nom += rhs.nom * lhs.denom;
    lhs.denom *= rhs.denom;
    rationalize(lhs);

    return lhs;
}

Rational plusRationals(const Rational& lhs, const Rational& rhs)
{
    Rational lhsCopy = lhs;

    plusEq(lhsCopy, rhs);
    return lhsCopy;
}
//int main()
//{
//    Rational r1{ 1,4 };
//    Rational r2{ 1,3 };
//
//    Rational r3 = plusRationals(r1, r2);
//
//    printRational(r3);
//
//    plusEq(r3, r1);
//
//    printRational(r3);
//}

