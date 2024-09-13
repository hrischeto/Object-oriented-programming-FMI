#include "ControlContainer.h"
#include "ControlFactory.h"
void ControlContainer::addControl()
{
	if (size == capacity)
		resize();

	controls[size++] = controlFactory();
}
void ControlContainer::changeControlSizeAtIndex(size_t newSize, size_t index)
{
	if (index >= size)
		throw std::out_of_range("Invalid index");

	controls[index]->setSize(newSize);
}
//void ControlContainer::setControlLocationAtIndex(Location newLocation, size_t index);
void ControlContainer::change(size_t index)
{
	if (index >= size)
		throw std::out_of_range("Invalid index");

	controls[index]->setDataDialog();
}

ControlContainer::ControlContainer()
{
	size = 0;
	capacity = 8;
	controls = new Control * [capacity] {nullptr};
}

ControlContainer::ControlContainer(const ControlContainer& other)
{
	copyFrom(other);
}
ControlContainer::ControlContainer(ControlContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

ControlContainer& ControlContainer::operator=(const ControlContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ControlContainer& ControlContainer::operator=(ControlContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
ControlContainer::~ControlContainer()
{
	free();
}

void ControlContainer::removeAt(size_t ind)
{
	if (ind >= size)
		throw std::out_of_range("Invalid index");

	for (int i = ind;i < size - 1;i++)
	{
		controls[i] = controls[i + 1];
	}
	size--;
	delete controls[size];
	controls[size] = nullptr;
}

void ControlContainer::remove()
{
	size--;
	delete controls[size];
	controls[size] = nullptr;
}

void ControlContainer::free()
{
	for (int i = 0;i < size;i++)
	{
		delete controls[i];
	}

	delete[] controls;

	size = capacity = 0;
}
void ControlContainer::copyFrom(const ControlContainer& other)
{
	controls = new(std::nothrow) Control * [other.capacity];
	size = other.size;
	capacity = other.capacity;

	for (int i = 0;i < size;i++)
	{
		controls[i] = other.controls[i]->clone();
	}
}
void ControlContainer::moveFrom(ControlContainer&& other)
{
	controls = other.controls;
	size = other.size;
	capacity = other.capacity;

	other.controls = nullptr;
	other.size = other.capacity = 0;
}

void ControlContainer::resize()
{
	Control** newData = new Control * [capacity *= 2];

	for (int i = 0;i < size;i++)
		newData[i] = controls[i];

	delete[] controls;
	controls = newData;
}

const Control* ControlContainer::operator[](unsigned ind) const
{
	if (ind >= size)
		throw std::out_of_range("Invalid index");
	return controls[ind];
}
Control* ControlContainer::operator[](unsigned ind)
{

	if (ind >= size)
		throw std::out_of_range("Invalid index");
	return controls[ind];
}