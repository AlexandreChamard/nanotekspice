/*
** EPITECH PROJECT, 2017
** main.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <iostream>
#include <exception>

#include "Circuit.hpp"
#include "Parser.hpp"
#include "Shell.hpp"
#include "Bool.hpp"

static void handler(int)
{
	if (nts::Circuit::inLoop == false) {
		std::cout << "(interrupt) use \"exit\" to exit.\n> " << std::flush;
	} else {
		nts::Circuit::inLoop = false;
	}
}

int main(int ac, char **av)
{
	if (ac == 1) {
		return (1);
	}
	nts::Circuit circuit;
	nts::Parser parser { circuit };
	nts::Shell<nts::Circuit> shell{ &circuit };
	signal(SIGINT, handler);

	try {
		parser(av[1]);
		circuit.setStart(ac - 2, av + 2);
		circuit.simulate();
		circuit.display();
		shell.loop();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}
	return 0;
}
