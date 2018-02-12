/*
** EPITECH PROJECT, 2017
** main.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <iostream>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "Shell.hpp"
#include "Bool.hpp"

int main(int ac, char **av)
{
	if (ac == 1) {
		return (1);
	}
	nts::Circuit circuit;
	nts::Parser parser { circuit };
	// nts::Shell<nts::Circuit> shell{ &circuit };

	parser(av[1]);
	parser.dump();

	// shell.loop();
	return 0;
}
