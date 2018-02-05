/*
** EPITECH PROJECT, 2017
** 4001.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Circuit.hpp"
#include "4001.hpp"

nts::Tristate nts::C4001::compute4()
{
	return _outputs[3].state =
	!(nts::Bool(_inputs[6].component.compute(_inputs[6].pin)) |
	nts::Bool(_inputs[7].component.compute(_inputs[7].pin)));
}

nts::Tristate nts::C4001::compute3()
{
	return _outputs[2].state =
	!(nts::Bool(_inputs[4].component.compute(_inputs[4].pin)) |
	nts::Bool(_inputs[5].component.compute(_inputs[5].pin)));
}

nts::Tristate nts::C4001::compute2()
{
	return _outputs[1].state =
	!(nts::Bool(_inputs[2].component.compute(_inputs[2].pin)) |
	nts::Bool(_inputs[3].component.compute(_inputs[3].pin)));
}

nts::Tristate nts::C4001::compute1()
{
	return _outputs[0].state =
	!(nts::Bool(_inputs[0].component.compute(_inputs[0].pin)) |
	nts::Bool(_inputs[1].component.compute(_inputs[1].pin)));
}

nts::Tristate nts::C4001::compute(std::size_t pin)
{
	if (_outputs[pin].cycle == cycle_g)
		return _outputs[pin].state;
	_outputs[pin].cycle++;
	return (_outputs[pin].compute)();
}

void nts::C4001::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_inputs[pin].component = other;
	_inputs[pin].pin = otherPin;
}

void nts::C4001::dump() const
{

}
