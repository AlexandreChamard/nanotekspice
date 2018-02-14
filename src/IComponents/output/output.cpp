/*
** EPITECH PROJECT, 2017
** default.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "ExecErrors.hpp"
#include "output.hpp"

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
	return COMPUTE(_input);
}

nts::Tristate nts::Coutput::compute(std::size_t pin)
{
	if (pin > _nbPins) {
		throw PinNExistError{ _id, pin };
	}
	return _pinsRef[pin - 1].compute();
}

void nts::Coutput::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	if (pin > _nbPins) {
		throw PinNExistError{ _id, pin };
	}
	if (_pinsRef[pin - 1].info == PIN_INPUT) {
		_pinsRef[pin - 1].link(other, otherPin);
	} else {
		other.setLink(otherPin, *this, pin);
	}
}

void nts::Coutput::dump() const
{
	std::cout << _id << ':' << std::endl;
	std::cout << '\t' << COMPUTE(_input) << std::endl;
}
