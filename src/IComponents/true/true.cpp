/*
** EPITECH PROJECT, 2017
** true.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Circuit.hpp"
#include "true.hpp"

nts::Tristate nts::Ctrue::compute1(std::size_t pin)
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
}

void nts::Ctrue::dump() const
{

}
