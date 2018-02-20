/*
** EPITECH PROJECT, 2017
** Circuit.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <signal.h>
#include <unordered_map>
#include <memory>
#include <vector>
#include "ComponentFactory.hpp"

namespace nts {
	class Circuit : public ComponentFactory {
	public:
		Circuit() = default;
		~Circuit() = default;
		Circuit(Circuit const &) = delete;
		Circuit(Circuit &&) = delete;
		Circuit &operator=(Circuit const &) = delete;
		Circuit &operator=(Circuit &&) = delete;

	public:
		void setValue(std::string const &name, Tristate value);
		void setValue(std::string const &name, std::string const &value);
		void display();
		void dump();
		void simulate();
		void loop();
		void setStart(int, char **);

		static volatile sig_atomic_t inLoop;
	};
}
