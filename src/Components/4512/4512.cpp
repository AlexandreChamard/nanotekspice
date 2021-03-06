/*
** EPITECH PROJECT, 2017
** 4512.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "4512.hpp"

unsigned int nts::C4512::id = 0;

nts::C4512::C4512(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "C4512::" << id;
		_id = sid.str();
	}
	id++;
}

// nts::Tristate nts::C4512::compute8()
// {
// 	return _outputs[7].state =
// 	((_inputs[0].component->compute(_inputs[0].pin)) &
// 	(_inputs[1].component->compute(_inputs[1].pin)) &
// 	(_inputs[2].component->compute(_inputs[2].pin)));
// }
//
// nts::Tristate nts::C4512::compute7()
// {
// 	return _outputs[6].state =
// 	((_inputs[0].component->compute(_inputs[0].pin)) &
// 	(_inputs[1].component->compute(_inputs[1].pin)) &
// 	(!(_inputs[2].component->compute(_inputs[2].pin))));
// }
//
// nts::Tristate nts::C4512::compute6()
// {
// 	return _outputs[5].state =
// 	((_inputs[0].component->compute(_inputs[0].pin)) &
// 	(!(_inputs[1].component->compute(_inputs[1].pin))) &
// 	(_inputs[2].component->compute(_inputs[2].pin)));
// }
//
// nts::Tristate nts::C4512::compute5()
// {
// 	return _outputs[4].state =
// 	((_inputs[0].component->compute(_inputs[0].pin)) &
// 	(!(_inputs[1].component->compute(_inputs[1].pin))) &
// 	(!(_inputs[2].component->compute(_inputs[2].pin))));
// }
//
// nts::Tristate nts::C4512::compute4()
// {
// 	return _outputs[3].state =
// 	((!(_inputs[0].component->compute(_inputs[0].pin))) &
// 	(_inputs[1].component->compute(_inputs[1].pin)) &
// 	(_inputs[2].component->compute(_inputs[2].pin)));
// }
//
// nts::Tristate nts::C4512::compute3()
// {
// 	return _outputs[2].state =
// 	((!(_inputs[0].component->compute(_inputs[0].pin))) &
// 	(_inputs[1].component->compute(_inputs[1].pin)) &
// 	(!(_inputs[2].component->compute(_inputs[2].pin))));
// }
//
// nts::Tristate nts::C4512::compute2()
// {
// 	return _outputs[1].state =
// 	((!(_inputs[0].component->compute(_inputs[0].pin))) &
// 	((!(_inputs[1].component->compute(_inputs[1].pin))) &
// 	(_inputs[2].component->compute(_inputs[2].pin))));
// }
//
// nts::Tristate nts::C4512::compute1()
// {
// 	return _outputs[0].state =
// 	((!(_inputs[0].component->compute(_inputs[0].pin))) &
// 	(!(_inputs[1].component->compute(_inputs[1].pin))) &
// 	(!(_inputs[2].component->compute(_inputs[2].pin))));
// }

nts::Tristate nts::C4512::compute(std::size_t pin)
{
	if (_outputs[pin].cycle == cycle_g)
		return _outputs[pin].state;
	_outputs[pin].cycle++;
	return (_outputs[pin].compute)();
}

void nts::C4512::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_inputs[pin].component = &other;
	_inputs[pin].pin = otherPin;
}

void nts::C4512::dump() const
{
	std::cout << _id << ": 4512\n";
	for (std::size_t i = 0; i < _nbPins; i++) {
		std::cout << "pin" << i << " ";
		if (_pinsRef[i].info == PIN_INPUT) {
			std::cout << " INPUT:" << COMPUTE(_pinsRef[i]);
		} else if (_pinsRef[i].info == PIN_OUTPUT) {
			std::cout << "OUTPUT:" << COMPUTE(_pinsRef[i]);
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
}
