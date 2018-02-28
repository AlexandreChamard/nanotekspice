/*
** EPITECH PROJECT, 2017
** ComponentFactory.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <unordered_map>
#include <map>

#include "IComponents.hpp"
#include "Input/Input.hpp"
#include "Output/Output.hpp"
#include "Clock/Clock.hpp"
#include "True/True.hpp"
#include "False/False.hpp"
#include "BinSum/BinSum.hpp"
#include "4001/4001.hpp"
#include "4011/4011.hpp"
#include "4013/4013.hpp"
#include "4030/4030.hpp"
#include "4069/4069.hpp"
#include "4071/4071.hpp"
#include "4081/4081.hpp"
#include "4017/4017.hpp"
#include "4512/4512.hpp"

namespace nts {
	using component_t = std::unique_ptr<IComponent>;
	using input_t = std::unique_ptr<Cinput>;
	using output_t = std::unique_ptr<Coutput>;

	class ComponentFactory {
	public:
		ComponentFactory();
		~ComponentFactory() = default;
		ComponentFactory(ComponentFactory const &) = delete;
		ComponentFactory(ComponentFactory &&) = delete;
		ComponentFactory &operator=(ComponentFactory const &) = delete;
		ComponentFactory &operator=(ComponentFactory &&) = delete;

	public:
		void componentFactory(std::string const &type, std::string const &value);
		void linkComponent(std::string const &, std::size_t, std::string const &, std::size_t);
		IComponent *getComponent(std::string const &);

	private:
		component_t createComponent(std::string const &type, std::string const &value);
		input_t createInput(std::string const &value);
		output_t createOutput(std::string const &value);

	protected:
		std::unordered_map<std::string, component_t> _components;
		std::unordered_map<std::string, input_t> _inputs;
		std::map<std::string, output_t> _outputs;

	private:
		using createComponent_t = std::function<component_t(std::string const &)>;
		template<class C>
		createComponent_t creatorFactory()
		{
			return [](std::string const &v){
				return std::unique_ptr<C>(new C(v));
			};
		}

		/* component who derive than ComponentFactory must be initiate in the constructor */
		std::unordered_map<std::string, createComponent_t> _map = {
			{"input", nullptr},
			{"output", nullptr},
			{"clock", nullptr},
			{"4001", creatorFactory<C4001>()},
			{"4011", creatorFactory<C4011>()},
			{"4013", creatorFactory<C4013>()},
			{"4030", creatorFactory<C4030>()},
			{"4069", creatorFactory<C4069>()},
			{"4071", creatorFactory<C4071>()},
			{"4081", creatorFactory<C4081>()},
			{"4017", creatorFactory<C4017>()},
			{"4512", creatorFactory<C4512>()},
			{"true", creatorFactory<Ctrue>()},
			{"false", creatorFactory<Cfalse>()},
			{"binSum", creatorFactory<CbinSum>()}
		};
	};
}
