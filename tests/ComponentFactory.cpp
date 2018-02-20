/*
** EPITECH PROJECT, 2017
** ComponentFactory.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "test.hpp"

bool testComponentFactory()
{
	nts::Circuit circuit;

	circuit.componentFactory("input", "a");
	circuit.componentFactory("output", "b");
	circuit.componentFactory("output", "c");
	circuit.linkComponent("a", 1, "b", 1);

	circuit.simulate();
	circuit.display();
	return true;
}
