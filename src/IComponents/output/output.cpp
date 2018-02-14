/*
** EPITECH PROJECT, 2017
** default.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sstream>

#include "Circuit.hpp"
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
	return state;
}

nts::Tristate nts::Coutput::compute(std::size_t __attribute__((unused)) pin)
{
	return nts::Bool();
}

void nts::Coutput::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	(void)pin;
	(void)other;
	(void)otherPin;
}

void nts::Coutput::dump() const
{

}
