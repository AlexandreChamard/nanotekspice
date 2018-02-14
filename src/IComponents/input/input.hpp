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
		Output _output;

		// linkPin_t errorLink =

		static const std::size_t _nbPins = 1;
		const Ref _pinsRef[_nbPins] = {
			{
				PIN_OUTPUT,
				[&]() {
					if (_output.cycle == cycle_g) {
						return _output.state;
					}
					_output.cycle = cycle_g;
					/* Compute dependencies */
					return _output.state;
				},
				[](IComponent &, std::size_t)
				{
					throw nts::LinkError();
				}
			}
		};
	};
}
