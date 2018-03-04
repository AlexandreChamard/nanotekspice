/*
** EPITECH PROJECT, 2017
** 4008.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class C4017 : public IComponent {
	public:
		C4017(std::string const &value = "");
		~C4017() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:
		static unsigned int id;

		std::array<Tristate, 2> _lastStates{{UNDEFINED, UNDEFINED}};
		std::string _id;
		std::size_t _count = 0;
		std::size_t _cycle = 0;
		std::array<Output, 11> _outputs;
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
				if (_cycle != cycle_g) {
					_cycle = cycle_g;
					if ((COMPUTE_REF(_inputs[0]) != TRUE &&
					_lastStates[1] != TRUE &&
					COMPUTE_REF(_inputs[0]) == TRUE) ||
					(COMPUTE_REF(_inputs[1]) == TRUE &&
					_lastStates[0] == TRUE &&
					COMPUTE_REF(_inputs[0]) != TRUE))
					// if ((COMPUTE_REF(_inputs[0]) != TRUE &&
					// COMPUTE_REF(_inputs[1]) == TRUE) || _count == 0)
						_count++;
					if (COMPUTE_REF(_inputs[2]) == TRUE)
						_count = 0;
					if (_count == 11) {
						_count = 1;
					}
					_lastStates[0] = COMPUTE_REF(_inputs[0]);
					_lastStates[1] = COMPUTE_REF(_inputs[1]);
				}
				return comp();
			};
		}

		static const std::size_t _nbPins = 16;
		const Ref _pinsRef[_nbPins] = {
			{ /* P1 -> _outputs[0] Q5 */
				PIN_OUTPUT,
				computeFactory(0, [&](){
					return Tristate(_count == 6);
				}),
				nullptr
			},
			{ /* P2 -> _outputs[1] Q1 */
				PIN_OUTPUT,
				computeFactory(1, [&](){
					return Tristate(_count == 2);
				}),
				nullptr
			},
			{ /* P3 -> _outputs[2] Q0 */
				PIN_OUTPUT,
				computeFactory(2, [&](){
					return Tristate(_count == 1);
				}),
				nullptr
			},
			{ /* P4 -> _outputs[3] Q2 */
				PIN_OUTPUT,
				computeFactory(3, [&](){
					return Tristate(_count == 3);
				}),
				nullptr
			},
			{ /* P5 -> _outputs[4] Q6 */
				PIN_OUTPUT,
				computeFactory(4, [&](){
					return Tristate(_count == 7);
				}),
				nullptr
			},
			{ /* P6 -> _outputs[5] Q7 */
				PIN_OUTPUT,
				computeFactory(5, [&](){
					return Tristate(_count == 8);
				}),
				nullptr
			},
			{ /* P7 -> _outputs[6] Q3 */
				PIN_OUTPUT,
				computeFactory(6, [&](){
					return Tristate(_count == 4);
				}),
				nullptr
			},
			{ /* P8 */
				PIN_UNUSED,
				nullptr,
				nullptr
			},
			{ /* P9 -> _outputs[7] Q8 */
				PIN_OUTPUT,
				computeFactory(7, [&](){
					return Tristate(_count == 9);
				}),
				nullptr
			},
			{ /* P10 -> _outputs[8] Q4 */
				PIN_OUTPUT,
				computeFactory(8, [&](){
					return Tristate(_count == 5);
				}),
				nullptr
			},
			{ /* P11 -> _outputs[9] Q9 */
				PIN_OUTPUT,
				computeFactory(9, [&](){
					return Tristate(_count == 10);
				}),
				nullptr
			},
			{ /* P12 -> _outputs[10] /Q5-9 */
				PIN_OUTPUT,
				computeFactory(10, [&](){
					return Tristate(!_outputs[0].state &&
					!_outputs[4].state &&
					!_outputs[5].state &&
					!_outputs[8].state &&
					!_outputs[9].state);
				}),
				nullptr
			},
			{ /* P13 -> _inputs[0] CP1 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[0]);},
				linkerFactory(0)
			},
			{ /* P14 -> _inputs[1] CP0 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[1]);},
				linkerFactory(1)
			},
			{ /* P15 -> _inputs[2] MR */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[2]);},
				linkerFactory(2)
			},
			{ /* P16 */
				PIN_UNUSED,
				nullptr,
				nullptr
			}
		};
	};
}
