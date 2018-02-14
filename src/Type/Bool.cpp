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
