/*
** EPITECH PROJECT, 2017
** Bool.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Bool.hpp"

nts::Bool::Bool(bool b): _state((State)b) {}

nts::Bool &nts::Bool::operator=(bool b)
{
	_state = (State)b;
	return *this;
}

nts::Bool::State nts::Bool::getState() const
{
	return _state;
}
