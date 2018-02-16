/*
** EPITECH PROJECT, 2017
** Circuit.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Circuit.hpp"
#include "4001/4001.hpp"
#include "ParsingErrors.hpp"

std::size_t nts::cycle_g = 0;
nts::InfoPin nts::linker_g = nts::InfoPin::PIN_UNUSED;

nts::Circuit::Circuit()
{
	_map["4001"] = [](std::string const &value) {
		return std::unique_ptr<IComponent>{new C4001(value)};
	};
}

std::unique_ptr<nts::IComponent> nts::Circuit::createComponent(std::string const &type, std::string const &value)
{
	if (_map.find(type) == _map.end()) {
		throw nts::ComponentNExistError{ type };
	}
	return _map[type](value);
}
