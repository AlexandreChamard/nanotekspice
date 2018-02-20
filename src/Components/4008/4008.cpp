/*
** EPITECH PROJECT, 2017
** 4008.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "4008.hpp"
#include "Parser.hpp"

unsigned int nts::C4008::id = 0;

nts::C4008::C4008(std::string const &value):
_id{ value }
{
	if (_id.size() == 0) {
		std::stringstream sid;

		sid << "C4008::" << id;
		_id = sid.str();
	}
	id++;
	std::unique_ptr<Parser> parser(new Parser(*this));
	(*parser)("components/pre4008.nts");
	(*ComponentFactory::_inputs["A4"]).setHandle(&_inputs[0]);
	(*ComponentFactory::_inputs["B3"]).setHandle(&_inputs[1]);
	(*ComponentFactory::_inputs["A3"]).setHandle(&_inputs[2]);
	(*ComponentFactory::_inputs["B2"]).setHandle(&_inputs[3]);
	(*ComponentFactory::_inputs["A2"]).setHandle(&_inputs[4]);
	(*ComponentFactory::_inputs["B1"]).setHandle(&_inputs[5]);
	(*ComponentFactory::_inputs["A1"]).setHandle(&_inputs[6]);
	(*ComponentFactory::_inputs["C1"]).setHandle(&_inputs[7]);
	(*ComponentFactory::_inputs["B4"]).setHandle(&_inputs[8]);
}

nts::Tristate nts::C4008::compute(std::size_t pin)
{
	if (pin > _nbPins) {
		throw PinNExistError{ _id, pin };
	}

	return COMPUTE(_pinsRef[pin - 1]);
}

void nts::C4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void nts::C4008::dump() const
{
	std::cout << _id << ": 4008\n";
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
