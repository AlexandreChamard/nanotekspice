/*
** EPITECH PROJECT, 2017
** true.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "true.hpp"

unsigned int nts::Ctrue::id = 0;

nts::Ctrue::Ctrue(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "Ctrue::" << id;
		_id = sid.str();
	}
	id++;
}

nts::Tristate nts::Ctrue::compute1(std::size_t __attribute__((unused)) pin)
{
	return _outputs[0].state = nts::Bool(true);
}

nts::Tristate nts::Ctrue::compute(std::size_t pin)
{
	if (_outputs[pin].cycle == cycle_g)
		return _outputs[pin].state;
	_outputs[pin].cycle++;
	return (_outputs[pin].compute)();
}

void nts::Ctrue::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	(void)pin;
	(void)other;
	(void)otherPin;
}

void nts::Ctrue::dump() const
{

}
