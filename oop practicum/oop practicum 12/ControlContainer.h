#pragma once
#include "Control.h"

class ControlContainer
{
public:
	void addControl();
	void changeControlSizeAtIndex(size_t newSize, size_t index);
	//void setControlLocationAtIndex(Location newLocation, size_t index);
	void change(size_t index);

	ControlContainer();

	ControlContainer(const ControlContainer& other);
	ControlContainer(ControlContainer&& other) noexcept;

	ControlContainer& operator=(const ControlContainer& other);
	ControlContainer& operator=(ControlContainer&& other) noexcept;
	~ControlContainer();

	const Control* operator[](unsigned) const;
	Control* operator[](unsigned);


	void removeAt(size_t ind);
	void remove();

private:
	void free();
	void copyFrom(const ControlContainer & other);
	void moveFrom(ControlContainer&& other);
	void resize();

	Control** controls;
	size_t size;
	size_t capacity = 0;
};