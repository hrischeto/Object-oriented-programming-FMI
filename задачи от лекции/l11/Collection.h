#pragma once
class Collection
{
public:
	virtual void add(int el)=0;
	virtual void remove(int el)=0;
	virtual int count(int el) const =0;
	virtual bool contains(int el) const =0;

	virtual ~Collection() = default;
};