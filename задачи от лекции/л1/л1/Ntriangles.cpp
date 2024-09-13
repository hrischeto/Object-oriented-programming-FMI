#include <iostream>

namespace Points
{
	struct Point
	{
		int x = 0;
		int y = 0;
	};

	void readPoint(Point& p)
	{
		std::cin >> p.x;
		std::cin >> p.y;
	}

	void printPoint(const Point& p)
	{
		std::cout << "(" << p.x << ", " << p.y << ") ";
	}

	double getDistance(const Point& p1, const Point& p2)
	{
		double dx = p2.x - p1.x;
		double dy = p2.y - p1.y;

		return sqrt(dx * dx + dy * dy);
	}
}

namespace Figures
{
	using namespace Points;

	struct Triangle
	{
		Point p1;
		Point p2;
		Point p3;
	};
	
	void readTriangle(Triangle& tr)
	{
		readPoint(tr.p1);
		readPoint(tr.p2);
		readPoint(tr.p3);
	}


	double getArea(const Triangle& tr)
	{
		double sideA = getDistance(tr.p1, tr.p2);
		double sideB = getDistance(tr.p2, tr.p3);
		double sideC = getDistance(tr.p1, tr.p3);

		double halfPer = (sideA + sideB + sideC) / 2;

		return sqrt(halfPer * (halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC));
	}

	void printTriangle(const Triangle& tr)
	{
		printPoint(tr.p1);
		printPoint(tr.p2);
		printPoint(tr.p3);

		std::cout << getArea(tr);
		std::cout << std::endl;
	}

	void sortTrianglesByArea(Triangle* triangles, size_t trCount)
	{
		if (!triangles)
			return;

		double* areas = new double[trCount];

		for (int i = 00;i < trCount;i++)
		{
			areas[i] = getArea(triangles[i]);
		}

		for (int i = 0; i < trCount - 1;i++)
		{
			int minElementIndex = i;

			for (int j = i + 1; j < trCount;j++)
			{
				if (areas[j] < areas[minElementIndex])
					minElementIndex = j;
			}

			if (minElementIndex != i) {
				std::swap(areas[i], areas[minElementIndex]);
				std::swap(triangles[i], triangles[minElementIndex]);
			}

		}

		delete[] areas;
	}
}

int main()
{
	size_t N = 0;
	std::cin >> N;

	Figures::Triangle* triangles = new Figures::Triangle[N];

	for (int i = 0;i < N;i++)
	{
		Figures::readTriangle(triangles[i]);
	}

	Figures::sortTrianglesByArea(triangles, N);

	for (int i = 0;i < N;i++)
	{
		Figures::printTriangle(triangles[i]);
	}

	delete[] triangles;
}