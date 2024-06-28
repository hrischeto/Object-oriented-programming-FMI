#include "SmartPtr.hpp"

class Session
{
public:
	int examCount = 5;
	int PassedExams = 4;
	bool inSession = 1;
};

int main()
{
	LimitedPtr<Session, 2> firstYear(new Session());
	LimitedPtr<Session, 2> secondYear = firstYear;

	try {
		LimitedPtr<Session, 2> thirdYear = firstYear;
	}
	catch (LimitReachedException e)
	{
		e.what();
		std::cout << (*secondYear).inSession;
	}

}
