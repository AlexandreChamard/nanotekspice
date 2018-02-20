/*
** EPITECH PROJECT, 2017
** binSum.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class CbinSum : public IComponent {
	public:
		CbinSum(std::string const &value = "");
		~CbinSum() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:
		static unsigned int id;

		std::string _id;
		std::array<Output, 2> _outputs;
		std::array<Input, 3> _inputs;

		linkPin_t linkerFactory(std::size_t p)
		{
			return [&, p](IComponent &link, std::size_t pin) {
				_inputs[p].link = &link;
				_inputs[p].pin = pin;
			};
		}

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


		static const std::size_t _nbPins = 5;
		const Ref _pinsRef[_nbPins] = {
			{ /* P1 -> _inputs[0] = Ci */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[0]);},
				linkerFactory(0)
			},
			{ /* P2 -> _inputs[1] = Ai */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[1]);},
				linkerFactory(1)
			},
			{ /* P3 -> _inputs[2] = Bi */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[2]);},
				linkerFactory(2)
			},
			{ /* P4 -> _outputs[0] = Sum */
				PIN_OUTPUT,
				computeFactory(0, [&](){
					return (COMPUTE_REF(_inputs[0]) ^
					COMPUTE_REF(_inputs[1]) ^
					COMPUTE_REF(_inputs[2]));
				}),
				nullptr
			},
			{ /* P5 -> _outputs[1] = Co */
				PIN_OUTPUT,
				computeFactory(1, [&](){
					return (COMPUTE_REF(_inputs[0]) & COMPUTE_REF(_inputs[1])) |
					(COMPUTE_REF(_inputs[1]) & COMPUTE_REF(_inputs[2])) |
					(COMPUTE_REF(_inputs[2]) & COMPUTE_REF(_inputs[0]));
				}),
				nullptr
			}
		};
	};
}
