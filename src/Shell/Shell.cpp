/*
** EPITECH PROJECT, 2017
** Shell.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <iostream>
#include "Shell.hpp"

/*
exit: closes the program.
display: prints the value of all outputs on the standard output, sorted by name in ASCII order.
input=value: changes the value of an input. This does not apply to clocks.
simulate: runs the simulation.
loop: continuously runs the simulation without displaying a prompt, until SIGINT is received.
dump: calls the dump method of every component.
*/

void nts::Shell::loop()
{
	char line[256];
	while (!std::cin.eof() && _exit == false) {
		echoPrompt();
		std::cin.getline(line, 256);
		if (_builtins[line]) {
			(this->*_builtins[line])();
		} else if (*line && !std::cin.eof()) {
			std::cerr << line << ": command not found" << std::endl;
		}
	}
}

void nts::Shell::echoPrompt() const
{
	std::cout << "> ";
}

void nts::Shell::execExit()
{
	_exit = true;
}

void nts::Shell::execDisplay()
{
	std::cout << "display!" << std::endl;
}

void nts::Shell::execSimulate()
{
	std::cout << "simulate!" << std::endl;
}

void nts::Shell::execLoop()
{
	std::cout << "loop!" << std::endl;
}

void nts::Shell::execDump()
{
	std::cout << "dump!" << std::endl;
}
