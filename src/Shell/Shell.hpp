/*
** EPITECH PROJECT, 2017
** Shell.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

namespace nts {
	template<typename T>
	class Shell {
	public:
		Shell() = default;
		Shell(T *);
		~Shell() = default;
		Shell(Shell const &) = delete;
		Shell(Shell &&) = default;
		Shell &operator=(Shell const &) = delete;
		Shell &operator=(Shell &&) = default;

	public:
		void loop();

	private:
		void echoPrompt() const;
		void execExit();
		void execDisplay();
		void execSimulate();
		void execLoop();
		void execDump();

		using exec_t = void (nts::Shell<T>::*)();

	private:
		bool _exit = false;
		T *_t = NULL;
		std::unordered_map<std::string, exec_t> _builtins = {
			std::pair<std::string, exec_t>{ "exit", &nts::Shell<T>::execExit },
			std::pair<std::string, exec_t>{ "display", &nts::Shell<T>::execDisplay },
			std::pair<std::string, exec_t>{ "simulate", &nts::Shell<T>::execSimulate },
			std::pair<std::string, exec_t>{ "loop", &nts::Shell<T>::execLoop },
			std::pair<std::string, exec_t>{ "dump", &nts::Shell<T>::execDump }
		};
	};
}

template<typename T>
nts::Shell<T>::Shell(T *t)
{
	_t = t;
}

template<typename T>
void nts::Shell<T>::loop()
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

/*
exit: closes the program.
display: prints the value of all outputs on the standard output, sorted by name in ASCII order.
input=value: changes the value of an input. This does not apply to clocks.
simulate: runs the simulation.
loop: continuously runs the simulation without displaying a prompt, until SIGINT is received.
dump: calls the dump method of every component.
*/

template<typename T>
void nts::Shell<T>::echoPrompt() const
{
	std::cout << "> ";
}

template<typename T>
void nts::Shell<T>::execExit()
{
	_exit = true;
}

template<typename T>
void nts::Shell<T>::execDisplay()
{
	_t->display();
}

template<typename T>
void nts::Shell<T>::execSimulate()
{
	_t->simulate();
}

template<typename T>
void nts::Shell<T>::execLoop()
{
	std::cout << "loop!" << std::endl;
}

template<typename T>
void nts::Shell<T>::execDump()
{
	_t->dump();
}
