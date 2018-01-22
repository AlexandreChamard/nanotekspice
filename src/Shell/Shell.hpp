/*
** EPITECH PROJECT, 2017
** Shell.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <unordered_map>
#include <string>
#include <functional>

namespace nts {
	class Shell {
	public:
		Shell() = default;
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

	private:
		bool _exit = false;
		using exec_t = void (nts::Shell::*)();
		std::unordered_map<std::string, exec_t> _builtins = {
			std::pair<std::string, exec_t>{ "exit", &nts::Shell::execExit },
			std::pair<std::string, exec_t>{ "display", &nts::Shell::execDisplay },
			std::pair<std::string, exec_t>{ "simulate", &nts::Shell::execSimulate },
			std::pair<std::string, exec_t>{ "loop", &nts::Shell::execLoop },
			std::pair<std::string, exec_t>{ "dump", &nts::Shell::execDump }
		};
	};
}
