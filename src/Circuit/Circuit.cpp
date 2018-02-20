/*
** EPITECH PROJECT, 2017
** Circuit.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <unistd.h>

#include "Circuit.hpp"
#include "Tools.hpp"
#include "ParsingErrors.hpp"

std::size_t nts::cycle_g = 0;
nts::InfoPin nts::linker_g = nts::InfoPin::PIN_UNUSED;
volatile sig_atomic_t nts::Circuit::inLoop = false;

void nts::Circuit::display()
{
	for (auto &elem : _outputs) {
		elem.second->display();
	}
}

void nts::Circuit::dump()
{
	for (auto &elem : _inputs) {
		elem.second->dump();
	}
	for (auto &elem : _components) {
		elem.second->dump();
	}
	for (auto &elem : _outputs) {
		elem.second->dump();
	}
}

void nts::Circuit::simulate()
{
	cycle_g++;

	for (auto &elem : _outputs) {
		elem.second->compute(1);
	}
}

void nts::Circuit::loop()
{
	inLoop = true;
	while (inLoop == true) {
		simulate();
		display();
		sleep(1);
	}
}

void nts::Circuit::setValue(std::string const &name, Tristate value)
{
	if (_inputs.find(name) == _inputs.end()) {
		throw nts::ComponentNExistError{ name };
	}
	_inputs[name]->setState(value);
}

void nts::Circuit::setValue(std::string const &name, std::string const &value)
{
	if (_inputs.find(name) == _inputs.end()) {
		throw nts::ComponentNExistError{ name };
	}
	if (lib::Tools::isNumber(value, false) == false) {
		throw nts::NNumberError{ value };
	}
	int v = std::atoi(value.c_str());
	if (v != 0 && v != 1) {
		throw nts::NBoolError{ value };
	}
	_inputs[name]->setState(Tristate(v));
}
