/*
** EPITECH PROJECT, 2017
** Circuit.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Circuit.hpp"
#include "ParsingErrors.hpp"

std::size_t nts::cycle_g = 0;
nts::InfoPin nts::linker_g = nts::InfoPin::PIN_UNUSED;

std::unique_ptr<nts::IComponent> nts::Circuit::createComponent(std::string const &type, std::string const &value)
{
	return _map[type](value);
}

void nts::Circuit::componentFactory(std::string const &type, std::string const &value)
{
	if (_map.find(type) == _map.end()) {
		throw nts::ComponentNExistError{ type };
	}
	if (type == "input") {
		auto ptr2 = std::make_unique<Cinput>(Cinput(value));
		_inputs.insert(std::make_pair(value, std::move(ptr2)));
	} else if (type == "output") {
		auto ptr2 = std::make_unique<Coutput>(Coutput(value));
		_outputs.insert(std::make_pair(value, std::move(ptr2)));
	} else {
		auto ptr = createComponent(type, value);
		_components.insert(std::make_pair(value, std::move(ptr)));
	}
}
