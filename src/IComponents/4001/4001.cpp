/*
** EPITECH PROJECT, 2017
** 4001.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "4001.hpp"

nts::Tristate compute4()
{
	_output[3].first =
	!(nts::Bool(_input[6].first.compute(_input[6].second)) |
	nts::Bool(_input[7].first.compute(_input[7].second)));
	return _output[3].first;
}

nts::Tristate compute3()
{
	_output[2].first =
	!(nts::Bool(_input[4].first.compute(_input[4].second)) |
	nts::Bool(_input[5].first.compute(_input[5].second)));
	return _output[2].first;
}

nts::Tristate compute2()
{
	_output[1].first =
	!(nts::Bool(_input[2].first.compute(_input[2].second)) |
	nts::Bool(_input[3].first.compute(_input[3].second)));
	return _output[1].first;
}

nts::Tristate compute1()
{
	_output[0].first =
	!(nts::Bool(_input[0].first.compute(_input[0].second)) |
	nts::Bool(_input[1].first.compute(_input[1].second)));
	return _output[0].first;
}

nts::Tristate compute(std::size_t pin)
{
	if (_cycles[pin] == cycle_g)
		return _output[pin].first;
	_cycles[pin]++;
	return _output[pin].second();
}

void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_input[pin] = {other, otherPin};
}

void dump()
{

}
