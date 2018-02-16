/*
** EPITECH PROJECT, 2017
** default.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "input.hpp"

unsigned int nts::Cinput::id = 0;

nts::Cinput::Cinput(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "Cinput::" << id;
		_id = sid.str();
	}
	id++;
}

void nts::Cinput::setState(Tristate state)
{
	_outputs[0].state = state;
}

void nts::Cinput::setState(bool state)
{
	_outputs[0].state = Tristate(state);
}

nts::Tristate nts::Cinput::compute(std::size_t pin)
{
	if (pin > _nbPins) throw PinNExistError{ _id, pin };

	return COMPUTE(_pinsRef[pin - 1]);
}

void nts::Cinput::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	if (pin > _nbPins) {
		throw PinNExistError{ _id, pin };
	}
	if (_pinsRef[pin - 1].info == PIN_UNUSED) {
		throw UnvalidLinkError{};
	}
	if (_pinsRef[pin - 1].info == PIN_INPUT) {
		if (linker_g == PIN_UNUSED) {
			linker_g = PIN_INPUT;
			other.setLink(otherPin, *this, pin);
		}
		if (linker_g == PIN_INPUT) {
			throw LinkError{ "Inputs" };
		}
		_pinsRef[pin - 1].link(other, otherPin);
	} else { /* _pinsRef[pin - 1].info == PIN_OUTPUT */
		if (linker_g == PIN_OUTPUT) {
			throw LinkError{ "Outputs" };
		}
		linker_g = PIN_OUTPUT;
		other.setLink(otherPin, *this, pin);
	}
	linker_g = PIN_UNUSED;
}

void nts::Cinput::dump() const
{
	std::cout << _id << ':' << std::endl;
	std::cout << '\t' << _outputs[0].state << std::endl;
}
