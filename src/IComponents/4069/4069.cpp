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

nts::Tristate nts::C4069::compute(std::size_t pin)
{
	if (pin > _nbPins) throw PinNExistError{ _id, pin };

	return COMPUTE(_pinsRef[pin - 1]);
}

void nts::C4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void nts::C4069::dump() const
{

}
