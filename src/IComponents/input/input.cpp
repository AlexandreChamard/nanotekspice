/*
** EPITECH PROJECT, 2017
** default.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Circuit.hpp"
#include "input.hpp"

void nts::Cinput::setState(Tristate state)
{
	_state = state;
}

nts::Tristate nts::Cinput::compute(std::size_t pin)
{
	return nts::Bool(UNDEFINED);
}

void nts::Cinput::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
}

void nts::Cinput::dump() const
{

}
