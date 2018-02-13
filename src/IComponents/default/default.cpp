/*
** EPITECH PROJECT, 2017
** default.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Circuit.hpp"
#include "default.hpp"

nts::Tristate nts::Cdefault::compute1(std::size_t pin)
{
	return _outputs[0].state = nts::Bool(UNDEFINED);
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
}

void nts::Cdefault::dump() const
{

}
