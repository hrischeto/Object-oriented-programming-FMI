#pragma once
class Set
{
	virtual bool accepts(unsigned int num) const =0;
	virtual Set* clone() const=0;
	virtual ~Set() = default;
};

