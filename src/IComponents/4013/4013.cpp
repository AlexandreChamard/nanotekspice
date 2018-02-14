/*
** EPITECH PROJECT, 2017
** 4001.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "4013.hpp"

unsigned int nts::C4013::id = 0;

nts::C4013::C4013(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "C4013::" << id;
		_id = sid.str();
	}
	id++;
}

nts::Tristate nts::C4013::compute4()
{
	if (!nts::Bool(_inputs[7].component->compute(_inputs[7].pin)) &
		!nts::Bool(_inputs[6].component->compute(_inputs[6].pin)) &
		!nts::Bool(_inputs[4].component->compute(_inputs[4].pin)))
		return _outputs[3].state;
	return _outputs[3].state =
	(nts::Bool(_inputs[4].component->compute(_inputs[4].pin)) |
	(nts::Bool(_inputs[7].component->compute(_inputs[7].pin)) &
	nts::Bool(_inputs[5].component->compute(_inputs[5].pin)) &
	!nts::Bool(_inputs[6].component->compute(_inputs[6].pin))));
}

nts::Tristate nts::C4013::compute3()
{
	if (!nts::Bool(_inputs[7].component->compute(_inputs[7].pin)) &
		!nts::Bool(_inputs[6].component->compute(_inputs[6].pin)) &
		!nts::Bool(_inputs[4].component->compute(_inputs[4].pin)))
		return _outputs[2].state;
	return _outputs[2].state =
	(nts::Bool(_inputs[6].component->compute(_inputs[6].pin)) |
	(nts::Bool(_inputs[7].component->compute(_inputs[7].pin)) &
	!nts::Bool(_inputs[5].component->compute(_inputs[5].pin)) &
	!nts::Bool(_inputs[4].component->compute(_inputs[4].pin))));
}

nts::Tristate nts::C4013::compute2()
{
	if (!nts::Bool(_inputs[0].component->compute(_inputs[0].pin)) &
		!nts::Bool(_inputs[3].component->compute(_inputs[3].pin)) &
		!nts::Bool(_inputs[1].component->compute(_inputs[1].pin)))
		return _outputs[1].state;
	return _outputs[1].state =
	(nts::Bool(_inputs[1].component->compute(_inputs[1].pin)) |
	(nts::Bool(_inputs[0].component->compute(_inputs[0].pin)) &
	!nts::Bool(_inputs[2].component->compute(_inputs[2].pin)) &
	!nts::Bool(_inputs[3].component->compute(_inputs[3].pin))));
}

nts::Tristate nts::C4013::compute1()
{
	if (!nts::Bool(_inputs[0].component->compute(_inputs[0].pin)) &
		!nts::Bool(_inputs[3].component->compute(_inputs[3].pin)) &
		!nts::Bool(_inputs[1].component->compute(_inputs[1].pin)))
		return _outputs[0].state;
	return _outputs[0].state =
	(nts::Bool(_inputs[3].component->compute(_inputs[3].pin)) |
	(nts::Bool(_inputs[0].component->compute(_inputs[0].pin)) &
	nts::Bool(_inputs[2].component->compute(_inputs[2].pin)) &
	!nts::Bool(_inputs[1].component->compute(_inputs[1].pin))));
}

nts::Tristate nts::C4013::compute(std::size_t pin)
{
	if (_outputs[pin].cycle == cycle_g)
		return _outputs[pin].state;
	_outputs[pin].cycle++;
	return (_outputs[pin].compute)();
}

void nts::C4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_inputs[pin].component = &other;
	_inputs[pin].pin = otherPin;
}

void nts::C4013::dump() const
{

}
