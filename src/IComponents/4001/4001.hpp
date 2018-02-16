/*
** EPITECH PROJECT, 2017
** 4001.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class C4001 : public IComponent {
	public:
		C4001(std::string const &value = "");
		~C4001() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:
		static unsigned int id;

		std::string _id;
		std::array<Output, 4> _outputs;
		std::array<Input, 8> _inputs;

		static const std::size_t _nbPins = 14;
		const Ref _pinsRef[_nbPins] = {
			{ /* P1 -> _inputs[0] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[0]);},
				[&](IComponent &link, std::size_t pin) {
					_inputs[0].link = &link;
					_inputs[0].pin = pin;
				}
			},
			{ /* P2 -> _inputs[1] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[1]);},
				[&](IComponent &link, std::size_t pin) {
					_inputs[1].link = &link;
					_inputs[1].pin = pin;
				}
			},
			{ /* P3 -> _outputs[0] */
				PIN_OUTPUT,
				[&]() {
					if (_outputs[0].cycle == cycle_g) {
						return _outputs[0].state;
					}
					_outputs[0].cycle = cycle_g;
					return _outputs[0].state =
					!(COMPUTE_REF(_inputs[0]) |
					COMPUTE_REF(_inputs[1]));
				},
				nullptr
			},
			{ /* P4 -> _outputs[1] */
				PIN_OUTPUT,
				[&]() {
					if (_outputs[1].cycle == cycle_g) {
						return _outputs[1].state;
					}
					_outputs[1].cycle = cycle_g;
					return _outputs[1].state =
					!(COMPUTE_REF(_inputs[2]) |
					COMPUTE_REF(_inputs[3]));
				},
				nullptr
			},
			{ /* P5 -> _inputs[2] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[2]);},
				[&](IComponent &link, std::size_t pin) {
					_inputs[2].link = &link;
					_inputs[2].pin = pin;
				}
			},
			{ /* P6 -> _inputs[3] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[3]);},
				[&](IComponent &link, std::size_t pin) {
					_inputs[3].link = &link;
					_inputs[3].pin = pin;
				}
			},
			{ /* P7 */
				PIN_UNUSED,
				nullptr,
				nullptr
			},
			{ /* P8 -> _inputs[4] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[4]);},
				[&](IComponent &link, std::size_t pin) {
					_inputs[4].link = &link;
					_inputs[4].pin = pin;
				}
			},
			{ /* P9 -> _inputs[5] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[5]);},
				[&](IComponent &link, std::size_t pin) {
					_inputs[5].link = &link;
					_inputs[5].pin = pin;
				}
			},
			{ /* P10 -> _outputs[2] */
				PIN_OUTPUT,
				[&]() {
					if (_outputs[2].cycle == cycle_g) {
						return _outputs[2].state;
					}
					_outputs[2].cycle = cycle_g;
					return _outputs[2].state =
					!(COMPUTE_REF(_inputs[4]) |
					COMPUTE_REF(_inputs[5]));
				},
				nullptr
			},
			{ /* P11 -> _outputs[3] */
				PIN_OUTPUT,
				[&]() {
					if (_outputs[3].cycle == cycle_g) {
						return _outputs[3].state;
					}
					_outputs[3].cycle = cycle_g;
					return _outputs[2].state =
					!(_inputs[4].link->compute(_inputs[4].pin) |
					_inputs[5].link->compute(_inputs[5].pin));
				},
				nullptr
			},
			{ /* P12 -> _inputs[6] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[6]);},
				[&](IComponent &link, std::size_t pin) {
					_inputs[6].link = &link;
					_inputs[6].pin = pin;
				}
			},
			{ /* P13 -> _inputs[7] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[7]);},
				[&](IComponent &link, std::size_t pin) {
					_inputs[7].link = &link;
					_inputs[7].pin = pin;
				}
			},
			{ /* P14 */
				PIN_UNUSED,
				nullptr,
				nullptr
			}
		};
	};
}
