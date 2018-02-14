/*
** EPITECH PROJECT, 2017
** 4030.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "4030.hpp"

unsigned int nts::C4030::id = 0;

nts::C4030::C4030(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "C4030::" << id;
		_id = sid.str();
	}
	id++;
}

nts::Tristate nts::C4030::compute4()
{
	return _outputs[3].state =
	(nts::Bool(_inputs[6].component->compute(_inputs[6].pin)) ^
	nts::Bool(_inputs[7].component->compute(_inputs[7].pin)));
}

nts::Tristate nts::C4030::compute3()
{
	return _outputs[2].state =
	(nts::Bool(_inputs[4].component->compute(_inputs[4].pin)) ^
	nts::Bool(_inputs[5].component->compute(_inputs[5].pin)));
}

nts::Tristate nts::C4030::compute2()
{
	return _outputs[1].state =
	(nts::Bool(_inputs[2].component->compute(_inputs[2].pin)) ^
	nts::Bool(_inputs[3].component->compute(_inputs[3].pin)));
}

nts::Tristate nts::C4030::compute1()
{
	return _outputs[0].state =
	(nts::Bool(_inputs[0].component->compute(_inputs[0].pin)) ^
	nts::Bool(_inputs[1].component->compute(_inputs[1].pin)));
}

nts::Tristate nts::C4030::compute(std::size_t pin)
{
	if (_outputs[pin].cycle == cycle_g)
		return _outputs[pin].state;
	_outputs[pin].cycle++;
	return (_outputs[pin].compute)();
}

void nts::C4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_inputs[pin].component = &other;
	_inputs[pin].pin = otherPin;
}

void nts::C4030::dump() const
{

}
