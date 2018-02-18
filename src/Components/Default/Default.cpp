/*
** EPITECH PROJECT, 2017
** default.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "Default.hpp"

unsigned int nts::Cdefault::id = 0;

nts::Cdefault::Cdefault(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "Cdefault::" << id;
		_id = sid.str();
	}
	id++;
}

nts::Tristate nts::Cdefault::compute1(std::size_t __attribute__((unused)) pin)
{
	return _outputs[0].state = nts::Bool();
}

nts::Tristate nts::Cdefault::compute(std::size_t pin)
{
	if (_outputs[pin].cycle == cycle_g)
		return _outputs[pin].state;
	_outputs[pin].cycle++;
	return (_outputs[pin].compute)();
}

void nts::Cdefault::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	(void)pin;
	(void)other;
	(void)otherPin;
}

void nts::Cdefault::dump() const
{

}
