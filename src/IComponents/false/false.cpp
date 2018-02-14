/*
** EPITECH PROJECT, 2017
** false.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "false.hpp"

unsigned int nts::Cfalse::id = 0;

nts::Cfalse::Cfalse(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "Cfalse::" << id;
		_id = sid.str();
	}
	id++;
}

nts::Tristate nts::Cfalse::compute1(std::size_t __attribute__((unused)) pin)
{
	return _outputs[0].state = nts::Bool(false);
}

nts::Tristate nts::Cfalse::compute(std::size_t pin)
{
	if (_outputs[pin].cycle == cycle_g)
		return _outputs[pin].state;
	_outputs[pin].cycle++;
	return (_outputs[pin].compute)();
}

void nts::Cfalse::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	(void)pin;
	(void)other;
	(void)otherPin;
}

void nts::Cfalse::dump() const
{

}
