/*
** EPITECH PROJECT, 2017
** default.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
#include "input.hpp"
#include "ExecErrors.hpp"

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
	_output.state = state;
}

void nts::Cinput::setState(bool state)
{
	_output.state = Tristate(state);
}

nts::Tristate nts::Cinput::compute(std::size_t pin)
{
	if (pin > _nbPins) {
		throw PinNExistError{ _id, pin };
	}
	return _pinsRef[pin - 1].compute();
}

void nts::Cinput::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void nts::Cinput::dump() const
{
	std::cout << _id << ':' << std::endl;
	std::cout << '\t' << _output.state << std::endl;
}
