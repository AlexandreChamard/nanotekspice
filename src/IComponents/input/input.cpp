/*
** EPITECH PROJECT, 2017
** default.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "input.hpp"

unsigned int nts::Cinput::id = 0;

nts::Cinput::Cinput(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "Cinput::" << id;
		_id = sid.str();
	}
	id++;
}

void nts::Cinput::setState(Tristate state)
{
	_state = state;
}

nts::Tristate nts::Cinput::compute(std::size_t __attribute__((unused)) pin)
{
	/* if pin != 1 throw */
	return _state;
}

void nts::Cinput::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	(void)pin;
	(void)other;
	(void)otherPin;
}

void nts::Cinput::dump() const
{

}
