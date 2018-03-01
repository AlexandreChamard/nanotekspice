/*
** EPITECH PROJECT, 2017
** ComponentFactory.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "ParsingErrors.hpp"

#include "ComponentFactory.hpp"

nts::ComponentFactory::ComponentFactory() {}

nts::output_t nts::ComponentFactory::createOutput(std::string const &value)
{
	return std::unique_ptr<Coutput>(new Coutput(value));
}

nts::input_t nts::ComponentFactory::createInput(std::string const &value)
{
	return std::unique_ptr<Cinput>(new Cinput(value));
}

nts::component_t nts::ComponentFactory::createComponent(std::string const &type, std::string const &value)
{
	return _map[type](value);
}

void nts::ComponentFactory::componentFactory(std::string const &type, std::string const &value)
{
	if (_map.find(type) == _map.end()) {
		throw nts::ComponentNExistError{ type };
	}
	if (type == "input" || type == "clock") {
		_inputs.insert(std::make_pair(value, createInput(value)));
	} else if (type == "output") {
		_outputs.insert(std::make_pair(value, createOutput(value)));
	} else {
		_components.insert(std::make_pair(value, createComponent(type, value)));
	}
}

nts::IComponent *nts::ComponentFactory::getComponent(std::string const &type)
{
	if (_components.find(type) != _components.end()) {
		return _components[type].get();
	}
	if (_inputs.find(type) != _inputs.end()) {
		return _inputs[type].get();
	}
	if (_outputs.find(type) != _outputs.end()) {
		return _outputs[type].get();
	}
	throw nts::ComponentNExistError{ type };
}

void nts::ComponentFactory::linkComponent(std::string const &c1, std::size_t p1,
					std::string const &c2, std::size_t p2)
{
	nts::IComponent *cc1 = getComponent(c1);
	nts::IComponent *cc2 = getComponent(c2);
	cc1->setLink(p1, *cc2, p2);
}
