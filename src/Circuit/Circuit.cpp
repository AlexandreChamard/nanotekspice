/*
** EPITECH PROJECT, 2017
** Circuit.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Circuit.hpp"
#include "../IComponents/4001/4001.hpp"

std::size_t nts::cycle_g = 0;

nts::Circuit::Circuit()
{
	// _map["4001"] = [](std::string const &value) {
	// 	return std::unique_ptr<IComponent>{new C4001()};
	// };
}

std::unique_ptr<nts::IComponent> nts::Circuit::createComponent(std::string const &type, std::string const &value)
{
	return _map[type](value);
}
