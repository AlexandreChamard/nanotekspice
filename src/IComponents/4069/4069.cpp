/*
** EPITECH PROJECT, 2017
** 4069.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "4069.hpp"

unsigned int nts::C4069::id = 0;

nts::C4069::C4069(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "C4069::" << id;
		_id = sid.str();
	}
	id++;
}

nts::Tristate nts::C4069::compute6()
{
	return _outputs[5].state =
	!nts::Bool(_inputs[5].component->compute(_inputs[5].pin));
}

nts::Tristate nts::C4069::compute5()
{
	return _outputs[4].state =
	!nts::Bool(_inputs[4].component->compute(_inputs[4].pin));
}

nts::Tristate nts::C4069::compute4()
{
	return _outputs[3].state =
	!nts::Bool(_inputs[3].component->compute(_inputs[3].pin));
}

nts::Tristate nts::C4069::compute3()
{
	return _outputs[2].state =
	!nts::Bool(_inputs[2].component->compute(_inputs[2].pin));
}

nts::Tristate nts::C4069::compute2()
{
	return _outputs[1].state =
	!nts::Bool(_inputs[1].component->compute(_inputs[1].pin));
}

nts::Tristate nts::C4069::compute1()
{
	return _outputs[0].state =
	!nts::Bool(_inputs[0].component->compute(_inputs[0].pin));
}

nts::Tristate nts::C4069::compute(std::size_t pin)
{
	if (_outputs[pin].cycle == cycle_g)
		return _outputs[pin].state;
	_outputs[pin].cycle++;
	return (_outputs[pin].compute)();
}

void nts::C4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_inputs[pin].component = &other;
	_inputs[pin].pin = otherPin;
}

void nts::C4069::dump() const
{

}
