/*
** EPITECH PROJECT, 2017
** false.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Circuit.hpp"
#include "clock.hpp"

nts::Tristate nts::Cclock::compute1(std::size_t pin)
{
	return _outputs[0].state = nts::Bool(cycle_g % 2);
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
}

void nts::Cclock::dump() const
{

}
