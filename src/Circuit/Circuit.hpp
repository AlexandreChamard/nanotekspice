/*
** EPITECH PROJECT, 2017
** Circuit.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <unordered_map>
#include <memory>
#include <vector>
#include "IComponents.hpp"

namespace nts {
	extern std::size_t cycle_g;

	class Circuit {
	public:
		Circuit();
		~Circuit() = default;
		Circuit(Circuit const &) = delete;
		Circuit(Circuit &&) = default;
		Circuit &operator=(Circuit const &) = delete;
		Circuit &operator=(Circuit &&) = default;

	public:
		std::unique_ptr<IComponent> createComponent(std::string const &type, std::string const &value);
		void addComponent(std::string const &);
		void addInput(std::string const &);
		void addOutput(std::string const &);

	private:
		using createComponent_t = std::unique_ptr<IComponent> (*)(std::string const &);
		std::unordered_map<std::string, createComponent_t> _map;
		std::vector<Output> _outputs;
		std::vector<std::unique_ptr<IComponent>> _components;
		std::vector<Input> _inputs;
	};
}
