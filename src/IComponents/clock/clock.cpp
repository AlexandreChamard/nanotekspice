/*
** EPITECH PROJECT, 2017
** false.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "clock.hpp"

unsigned int nts::Cclock::id = 0;

nts::Cclock::Cclock(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "Cclock::" << id;
		_id = sid.str();
	}
	id++;
}


nts::Tristate nts::Cclock::compute1(std::size_t __attribute__((unused)) pin)
{
	return _outputs[0].state = (nts::Tristate)(cycle_g % 2);
}

nts::Tristate nts::Cclock::compute(std::size_t pin)
{
	if (_outputs[pin].cycle == cycle_g)
		return _outputs[pin].state;
	_outputs[pin].cycle++;
	return (_outputs[pin].compute)();
}

void nts::Cclock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	(void)pin;
	(void)other;
	(void)otherPin;
}

void nts::Cclock::dump() const
{

}
