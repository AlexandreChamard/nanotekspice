/*
** EPITECH PROJECT, 2017
** false.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Circuit.hpp"
#include "false.hpp"

nts::Tristate nts::Cfalse::compute1(std::size_t pin)
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
}

void nts::Cfalse::dump() const
{

}
