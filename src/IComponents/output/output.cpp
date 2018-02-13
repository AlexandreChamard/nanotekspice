/*
** EPITECH PROJECT, 2017
** default.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Circuit.hpp"
#include "output.hpp"

nts::Tristate nts::Coutput::getState()
{
	return state;
}

nts::Tristate nts::Coutput::compute(std::size_t pin)
{
	return nts::Bool(UNDEFINED);
}

void nts::Coutput::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
}

void nts::Coutput::dump() const
{

}
