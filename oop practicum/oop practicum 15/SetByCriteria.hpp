#pragma once
#include "Set.h"

template <typename T>
class SetByCriteria :public Set
{
public:
	SetByCriteria(const T& criteria);
	SetByCriteria(T&& criteria);

	virtual bool accepts(unsigned num) const override;
	virtual Set* clone() const override;

private:
	T criteria;//needs op=
};

template <typename T>
SetByCriteria<T>::SetByCriteria(const T& criteria):criteria(criteria){}
template <typename T>
SetByCriteria<T>::SetByCriteria(T&& criteria):criteria(std::move(criteria)){}

template <typename T>
bool SetByCriteria<T>::accepts(unsigned num) const
{
	return T(num);
}

template <typename T>
Set* SetByCriteria<T>::clone() const
{
	return new SetByCriteria(T);
}
