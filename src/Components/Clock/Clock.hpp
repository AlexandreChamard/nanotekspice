/*
** EPITECH PROJECT, 2017
** false.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "Input/Input.hpp"

namespace nts {
	class Cclock : public Cinput {
	public:
		Cclock(std::string const &value = "");
		~Cclock() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:
		static unsigned int id;

		computePin_t computeFactory(std::size_t p, computePin_t comp)
		{
			return [&, p, comp](){
				if (_outputs[p].cycle == cycle_g) {
					return _outputs[p].state;
				}
				_outputs[p].cycle = cycle_g;
				return _outputs[p].state = comp();
			};
		}

		static const std::size_t _nbPins = 1;
		const Ref _pinsRef[_nbPins] = {
			{ /* p1 -> _outputs[0] */
				PIN_OUTPUT,
				computeFactory(0, [&](){
					return Tristate(_outputs[0].state + (cycle_g % 2));
				}),
				nullptr
			}
		};
	};
}
