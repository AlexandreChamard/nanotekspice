/*
** EPITECH PROJECT, 2017
** input.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include "IComponents.hpp"

namespace nts {
	class Coutput : public IComponent {
	public:
		Coutput(std::string const &value = "");
		~Coutput() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;
		void display() const;
		nts::Tristate getState();

	private:
		nts::Tristate compute1(std::size_t pin);

	private:
		static unsigned int id;

		std::string _id;
		std::array<Input, 1> _inputs;

		linkPin_t linkerFactory(std::size_t p)
		{
			return [&, p](IComponent &link, std::size_t pin) {
				_inputs[p].link = &link;
				_inputs[p].pin = pin;
			};
		}

		static const std::size_t _nbPins = 1;
		Ref _pinsRef[_nbPins] = {
			{ /* p1 -> _inputs[0] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[0]);},
				linkerFactory(0)
			}
		};
	};
}
