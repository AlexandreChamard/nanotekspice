/*
** EPITECH PROJECT, 2017
** Bool.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Bool.hpp"

nts::Bool::Bool(bool b): _state((Tristate)b) {}

nts::Bool &nts::Bool::operator=(bool b)
{
	_state = (Tristate)b;
	return *this;
}

nts::Tristate nts::Bool::getState() const
{
	return _state;
}

nts::Bool nts::Bool::operator==(Bool const &b) const
{
	if (_state == UNDEFINED || b.getState() == UNDEFINED) {
		return Bool();
	}
	return Bool(_state == b.getState());
}

nts::Bool nts::Bool::operator!=(Bool const &b) const
{
	if (_state == UNDEFINED || b.getState() == UNDEFINED) {
		return Bool();
	}
	return Bool(_state != b.getState());
}

nts::Bool nts::Bool::operator&&(Bool const &b) const
{
	if (_state == UNDEFINED || b.getState() == UNDEFINED) {
		return Bool();
	}
	return Bool(_state & b.getState());
}

nts::Bool nts::Bool::operator&(Bool const &b) const
{
	if (_state == UNDEFINED || b.getState() == UNDEFINED) {
		return Bool();
	}
	return Bool(_state & b.getState());
}

nts::Bool nts::Bool::operator||(Bool const &b) const
{
	if (_state == UNDEFINED || b.getState() == UNDEFINED) {
		return Bool();
	}
	return Bool(_state | b.getState());
}

nts::Bool nts::Bool::operator|(Bool const &b) const
{
	if (_state == UNDEFINED || b.getState() == UNDEFINED) {
		return Bool();
	}
	return Bool(_state | b.getState());
}

nts::Bool nts::Bool::operator^(Bool const &b) const
{
	if (_state == UNDEFINED || b.getState() == UNDEFINED) {
		return Bool();
	}
	return Bool(_state ^ b.getState());
}

nts::Bool nts::Bool::operator!() const
{
	if (_state == UNDEFINED) {
		return Bool();
	}
	return Bool(!_state);
}

nts::Tristate operator!(nts::Tristate state)
{
	switch (state) {
		case nts::Tristate::UNDEFINED:
			return nts::Tristate::UNDEFINED;
		case nts::Tristate::FALSE:
			return nts::Tristate::TRUE;
		case nts::Tristate::TRUE:
			return nts::Tristate::FALSE;
	}
	return nts::Tristate::UNDEFINED;
}

nts::Tristate operator&(nts::Tristate t1, nts::Tristate t2)
{
	if (t1 == nts::Tristate::UNDEFINED || t2 == nts::Tristate::UNDEFINED) {
		return nts::Tristate::UNDEFINED;
	}
	if (t1 == nts::Tristate::TRUE && t2 == nts::Tristate::TRUE) {
		return nts::Tristate::TRUE;
	}
	return nts::Tristate::FALSE;
}

nts::Tristate operator|(nts::Tristate t1, nts::Tristate t2)
{
	if (t1 == nts::Tristate::UNDEFINED || t2 == nts::Tristate::UNDEFINED) {
		return nts::Tristate::UNDEFINED;
	}
	if (t1 == nts::Tristate::TRUE || t2 == nts::Tristate::TRUE) {
		return nts::Tristate::TRUE;
	}
	return nts::Tristate::FALSE;
}

nts::Tristate operator^(nts::Tristate t1, nts::Tristate t2)
{
	if (t1 == nts::Tristate::UNDEFINED || t2 == nts::Tristate::UNDEFINED) {
		return nts::Tristate::UNDEFINED;
	}
	if (t1 != t2) {
		return nts::Tristate::TRUE;
	}
	return nts::Tristate::FALSE;
}

ssize_t operator+(ssize_t t1, nts::Tristate t2)
{
	if (t1 == -1 || t2 == nts::Tristate::UNDEFINED) {
		return -1;
	}
	return t1 + std::size_t(t2);
}

ssize_t operator+(nts::Tristate t1, nts::Tristate t2)
{
	if (t1 == nts::Tristate::UNDEFINED || t2 == nts::Tristate::UNDEFINED) {
		return -1;
	}
	return std::size_t(t1) + std::size_t(t2);
}


std::ostream &operator<<(std::ostream &os, nts::Tristate state)
{
	switch (state) {
		case nts::Tristate::UNDEFINED:
		os << 'U';
		break;
		case nts::Tristate::TRUE:
		os << '1';
		break;
		case nts::Tristate::FALSE:
		os << '0';
	};
	return os;
}

std::ostream &operator<<(std::ostream &os, nts::Bool const &b)
{
	return os << b.getState();
}
