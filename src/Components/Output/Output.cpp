/*
** EPITECH PROJECT, 2017
** default.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "Output.hpp"

unsigned int nts::Coutput::id = 0;

nts::Coutput::Coutput(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "Coutput::" << id;
		_id = sid.str();
	}
	id++;
}

nts::Tristate nts::Coutput::getState()
{
	return COMPUTE_REF(_inputs[0]);
}

nts::Tristate nts::Coutput::compute(std::size_t pin)
{
	if (pin > _nbPins) {
		throw PinNExistError{ _id, pin };
	}
	return COMPUTE(_pinsRef[pin - 1]);
}

void nts::Coutput::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	if (pin > _nbPins || pin == 0) {
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

void nts::Coutput::dump() const
{
	std::cout << _id << ": Output\n";
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

void nts::Coutput::display() const
{
	std::cout << _id << '=' << COMPUTE_REF(_inputs[0]) << std::endl;
}
