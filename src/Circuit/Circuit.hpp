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
#include "Input/Input.hpp"
#include "Output/Output.hpp"
#include "Clock/Clock.hpp"
#include "True/True.hpp"
#include "False/False.hpp"
#include "4001/4001.hpp"
#include "4011/4011.hpp"
#include "4013/4013.hpp"
#include "4030/4030.hpp"
#include "4069/4069.hpp"
#include "4071/4071.hpp"
#include "4081/4081.hpp"
#include "4512/4512.hpp"

namespace nts {

	class Circuit {
	public:
		Circuit() = default;
		~Circuit() = default;
		Circuit(Circuit const &) = delete;
		Circuit(Circuit &&) = delete;
		Circuit &operator=(Circuit const &) = delete;
		Circuit &operator=(Circuit &&) = delete;

	public:
		void componentFactory(std::string const &type, std::string const &value);
		std::unique_ptr<IComponent> createComponent(std::string const &type, std::string const &value);
		std::unique_ptr<Cinput> createInput(std::string const &);
		std::unique_ptr<Coutput> createOutput(std::string const &);

	private:
		std::unordered_map<std::string, std::unique_ptr<IComponent>> _components;
		std::unordered_map<std::string, std::unique_ptr<Cinput>> _inputs;
		std::unordered_map<std::string, std::unique_ptr<Coutput>> _outputs;

		using createComponent_t = std::function<std::unique_ptr<IComponent>(std::string const &)>;
		template<class C>
		createComponent_t creatorFactory()
		{
			return [](std::string const &v)->std::unique_ptr<IComponent>{
				return std::make_unique<C>(C(v));
			};
		}

		std::unordered_map<std::string, createComponent_t> _map = {
			{"input", nullptr},
			{"output", nullptr},
			{"4001", creatorFactory<C4001>()},
			{"4011", creatorFactory<C4011>()},
			{"4013", creatorFactory<C4013>()},
			{"4030", creatorFactory<C4030>()},
			{"4069", creatorFactory<C4069>()},
			{"4071", creatorFactory<C4071>()},
			{"4081", creatorFactory<C4081>()},
			{"4512", creatorFactory<C4512>()},
			{"true", creatorFactory<Ctrue>()},
			{"false", creatorFactory<Cfalse>()},
			{"clock", creatorFactory<Cclock>()}
		};
	};
}
