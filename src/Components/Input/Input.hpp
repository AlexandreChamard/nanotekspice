/*
** EPITECH PROJECT, 2017
** input.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include "IComponents.hpp"

namespace nts {
	class Cinput : public IComponent {
	public:
		Cinput(std::string const &value = "");
		~Cinput() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;
		void setState(Tristate state);
		void setState(bool state);

	private:
		static unsigned int id;

		std::string _id;
		std::array<Output, 1> _outputs;

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
					return _outputs[0].state;
				}),
				nullptr
			}
		};
	};
}
