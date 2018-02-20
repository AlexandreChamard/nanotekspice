/*
** EPITECH PROJECT, 2017
** 4069.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class C4069 : public IComponent {
	public:
		C4069(std::string const &value = "");
		~C4069() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:
		static unsigned int id;

		std::string _id;
		std::array<Output, 6> _outputs;
		std::array<Input, 6> _inputs;

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

		static const std::size_t _nbPins = 14;
		const Ref _pinsRef[_nbPins] = {
			{ /* P1 -> _inputs[0] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[0]);},
				linkerFactory(0)
			},
			{ /* P2 -> _outputs[0] */
				PIN_OUTPUT,
				computeFactory(0, [&](){
					return !(COMPUTE_REF(_inputs[0]));
				}),
				nullptr
			},
			{ /* P3 -> _inputs[1] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[1]);},
				linkerFactory(1)
			},
			{ /* P4 -> _outputs[1] */
				PIN_OUTPUT,
				computeFactory(1, [&](){
					return !(COMPUTE_REF(_inputs[1]));
				}),
				nullptr
			},
			{ /* P5 -> _inputs[2] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[2]);},
				linkerFactory(2)
			},
			{ /* P6 -> _outputs[2] */
				PIN_OUTPUT,
				computeFactory(2, [&](){
					return !(COMPUTE_REF(_inputs[2]));
				}),
				nullptr
			},
			{ /* P7 */
				PIN_UNUSED,
				nullptr,
				nullptr
			},
			{ /* P8 -> _outputs[3] */
				PIN_OUTPUT,
				computeFactory(3, [&](){
					return !(COMPUTE_REF(_inputs[3]));
				}),
				nullptr
			},
			{ /* P9 -> _inputs[3] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[3]);},
				linkerFactory(3)
			},
			{ /* P10 -> _outputs[4] */
				PIN_OUTPUT,
				computeFactory(4, [&](){
					return !(COMPUTE_REF(_inputs[4]));
				}),
				nullptr
			},
			{ /* P11 -> _inputs[4] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[4]);},
				linkerFactory(4)
			},
			{ /* P12 -> _outputs[5] */
				PIN_OUTPUT,
				computeFactory(5, [&](){
					return !(COMPUTE_REF(_inputs[5]));
				}),
				nullptr
			},
			{ /* P13 -> _inputs[5] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[5]);},
				linkerFactory(5)
			},
			{ /* P14 */
				PIN_UNUSED,
				nullptr,
				nullptr
			}
		};
	};
}
