#pragma once
class NumberSeries
{
private:
	int _a0 = 0;
	int (*transFunc)(int);
	int* cache = nullptr;
	size_t cacheSize;

	void copyFrom(const NumberSeries& other);
	void free();

	void resize(size_t newSize);

public:
	NumberSeries(int a0, int(*func)(int));
	NumberSeries(const NumberSeries& other);
	NumberSeries& operator=(const NumberSeries& other);
	~NumberSeries();

	void setStartingPoint(int a0);
	void setTransitionFunction(int (*func)(int));

	bool isPartOfSeries(int n) const;
	int getNumInPosition(size_t pos);

	
};

