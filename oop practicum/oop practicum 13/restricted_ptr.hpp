template<typename T, const unsigned S>
class RestrictedPtr
{
	T* data=nullptr;
	unsigned* counter=nullptr;
	const unsigned maxPointers = S;

	void free();
	void copyFrom(const RestrictedPtr& other);
	void moveFrom(RestrictedPtr&& other);

public:
	RestrictedPtr();
	RestrictedPtr(T* data);

	~RestrictedPtr();
	RestrictedPtr(const RestrictedPtr& other);
	RestrictedPtr(RestrictedPtr&& other) noexcept;

	RestrictedPtr& operator=(const RestrictedPtr& other);
	RestrictedPtr& operator=(RestrictedPtr&& other) noexcept;
};

template<typename T, const unsigned S>
RestrictedPtr<T, S>::RestrictedPtr(T* data)
{
	this->data = data;
	if (this->data)
	{
		counter = new unsigned int;
		(*counter )= 1;
	}
}

template<typename T, const unsigned S>
RestrictedPtr<T, S>::RestrictedPtr()
{
	data = nullptr;
	counter = nullptr;
}

template<typename T, const unsigned S>
void RestrictedPtr<T, S>::free()
{
	delete data;
	delete counter;
}

template<typename T, const unsigned S>
void RestrictedPtr<T, S>::copyFrom(const RestrictedPtr<T, S>& other)
{
	if (*(other.counter) == other.maxPointers)
		throw std::logic_error("Limit reached");

	counter = other.counter;
	data = other.data;
	(*counter)++;
}

template<typename T, const unsigned S>
void RestrictedPtr<T, S>::moveFrom(RestrictedPtr<T, S>&& other)
{
	counter = other.counter;
	data = other.data;
	other.data = nullptr;
	other.counter = nullptr;
}

template<typename T, const unsigned S>
RestrictedPtr<T, S>::~RestrictedPtr()
{
	*(counter)--;
	if (*counter == 0)
	{
		delete data;
		delete counter;
	}

	data = nullptr;
	counter = nullptr;
}

template<typename T, const unsigned S>
RestrictedPtr<T, S>::RestrictedPtr(const RestrictedPtr<T, S>& other)
{
		copyFrom(other);
}

template<typename T, const unsigned S>
RestrictedPtr<T, S>::RestrictedPtr(RestrictedPtr<T, S>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T, const unsigned S>
RestrictedPtr<T, S>& RestrictedPtr<T, S>::operator=(const RestrictedPtr<T,S>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T, const unsigned S>
RestrictedPtr<T, S>& RestrictedPtr<T, S>::operator=(RestrictedPtr<T, S>&& other) noexcept
{

	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}