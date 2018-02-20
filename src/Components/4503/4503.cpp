/*
** EPITECH PROJECT, 2017
** 4001.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "4503.hpp"

unsigned int nts::C4503::id = 0;

nts::C4503::C4503(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "C4503::" << id;
		_id = sid.str();
	}
	id++;
}

nts::Tristate nts::C4503::compute6()
{
	if (_inputs[7].component->compute(_inputs[7].pin))
		return _outputs[5].state = nts::Bool(UNDEFINED);
 	return _outputs[5].state =
	(_inputs[6].component->compute(_inputs[6].pin));
}

nts::Tristate nts::C4503::compute5()
{
	if (_inputs[7].component->compute(_inputs[7].pin))
		return _outputs[4].state = nts::Bool(UNDEFINED);
 	return _outputs[4].state =
	(_inputs[5].component->compute(_inputs[5].pin));
}

nts::Tristate nts::C4503::compute4()
{
	if (_inputs[0].component->compute(_inputs[0].pin))
		return _outputs[3].state = nts::Bool(UNDEFINED);
 	return _outputs[3].state =
	(_inputs[4].component->compute(_inputs[4].pin));
}

nts::Tristate nts::C4503::compute3()
{
	if (_inputs[0].component->compute(_inputs[0].pin))
		return _outputs[2].state = nts::Bool(UNDEFINED);
 	return _outputs[2].state =
	(_inputs[3].component->compute(_inputs[3].pin));
}

nts::Tristate nts::C4503::compute2()
{
	if (_inputs[0].component->compute(_inputs[0].pin))
		return _outputs[1].state = nts::Bool(UNDEFINED);
 	return _outputs[1].state =
	(_inputs[2].component->compute(_inputs[2].pin));
}

nts::Tristate nts::C4503::compute1()
{
	if (_inputs[0].component->compute(_inputs[0].pin))
		return _outputs[0].state = nts::Bool(UNDEFINED);
 	return _outputs[0].state =
	(_inputs[1].component->compute(_inputs[1].pin));
}

nts::Tristate nts::C4503::compute(std::size_t pin)
{
	if (_outputs[pin].cycle == cycle_g)
		return _outputs[pin].state;
	_outputs[pin].cycle++;
	return (_outputs[pin].compute)();
}

void nts::C4503::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_inputs[pin].component = &other;
	_inputs[pin].pin = otherPin;
}

void nts::C4503::dump() const
{

}
