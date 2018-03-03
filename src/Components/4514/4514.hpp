/*
** EPITECH PROJECT, 2017
** 4514.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class C4514 : public IComponent {
	public:
		C4514(std::string const &value = "");
		~C4514() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:
		static unsigned int id;

		ssize_t _state = -1;
		std::size_t _cycle = 0;
		std::string _id;
		std::array<Output, 16> _outputs;
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
				if (COMPUTE_REF(_inputs[5]) == TRUE) {
					return FALSE;
				}
				for (auto &pin : _inputs) {
					if (COMPUTE_REF(pin) == UNDEFINED) {
						return UNDEFINED;
					}
				}
				if (_cycle != cycle_g && COMPUTE_REF(_inputs[0]) == TRUE) {
					_cycle = cycle_g;
					_state = (ssize_t)COMPUTE_REF(_inputs[1]) +
					((COMPUTE_REF(_inputs[2]) << 1)) +
					((COMPUTE_REF(_inputs[3]) << 2)) +
					((COMPUTE_REF(_inputs[4]) << 3));
				}
				if (_state == -1) {
					return UNDEFINED;
				}
				return comp();
			};
		}

		static const std::size_t _nbPins = 24;
		const Ref _pinsRef[_nbPins] = {
			{ /* P1 _inputs[0] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[0]);},
				linkerFactory(0)
			},
			{ /* P2 -> _inputs[2] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[2]);},
				linkerFactory(1)
			},
			{ /* P3 -> _inputs[2] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[3]);},
				linkerFactory(2)
			},
			{ /* P4 -> _outputs[0] S7 */
				PIN_OUTPUT,
				computeFactory(0, [&](){
					return Tristate(_state == 7);
				}),
				nullptr
			},
			{ /* P5 -> _outputs[1] S6 */
				PIN_OUTPUT,
				computeFactory(1, [&](){
					return Tristate(_state == 6);
				}),
				nullptr
			},
			{ /* P6 -> _outputs[2] S5 */
				PIN_OUTPUT,
				computeFactory(2, [&](){
					return Tristate(_state == 5);
				}),
				nullptr
			},
			{ /* P7 -> _outputs[3] S4 */
				PIN_OUTPUT,
				computeFactory(3, [&](){
					return Tristate(_state == 4);
				}),
				nullptr
			},
			{ /* P8 -> _outputs[4] S3 */
				PIN_OUTPUT,
				computeFactory(4, [&](){
					return Tristate(_state == 3);
				}),
				nullptr
			},
			{ /* P9 -> _outputs[5] S1 */
				PIN_OUTPUT,
				computeFactory(5, [&](){
					return Tristate(_state == 1);
				}),
				nullptr
			},
			{ /* P10 -> _outputs[6] S2 */
				PIN_OUTPUT,
				computeFactory(6, [&](){
					return Tristate(_state == 2);
				}),
				nullptr
			},
			{ /* P11 -> _outputs[7] S0 */
				PIN_OUTPUT,
				computeFactory(7, [&](){
					return Tristate(_state == 0);
				}),
				nullptr
			},
			{ /* P12 */
				PIN_UNUSED,
				nullptr,
				nullptr
			},
			{ /* P13 -> _outputs[8] S13 */
				PIN_OUTPUT,
				computeFactory(8, [&](){
					return Tristate(_state == 13);
				}),
				nullptr
			},
			{ /* P14 -> _outputs[9] S12 */
				PIN_OUTPUT,
				computeFactory(9, [&](){
					return Tristate(_state == 12);
				}),
				nullptr
			},
			{ /* P15 -> _outputs[10] S15 */
				PIN_OUTPUT,
				computeFactory(10, [&](){
					return Tristate(_state == 15);
				}),
				nullptr
			},
			{ /* P16 -> _outputs[11] S14 */
				PIN_OUTPUT,
				computeFactory(11, [&](){
					return Tristate(_state == 14);
				}),
				nullptr
			},
			{ /* P17 -> _outputs[12] S9 */
				PIN_OUTPUT,
				computeFactory(12, [&](){
					return Tristate(_state == 9);
				}),
				nullptr
			},
			{ /* P18 -> _outputs[13] S8 */
				PIN_OUTPUT,
				computeFactory(13, [&](){
					return Tristate(_state == 8);
				}),
				nullptr
			},
			{ /* P19 -> _outputs[14] S11 */
				PIN_OUTPUT,
				computeFactory(14, [&](){
					return Tristate(_state == 11);
				}),
				nullptr
			},
			{ /* P20 -> _outputs[15] S10 */
				PIN_OUTPUT,
				computeFactory(15, [&](){
					return Tristate(_state == 10);
				}),
				nullptr
			},
			{ /* P21 -> _inputs[4] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[4]);},
				linkerFactory(3)
			},
			{ /* P22 -> _inputs[5] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[5]);},
				linkerFactory(4)
			},
			{ /* P23 -> _inputs[5] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[5]);},
				linkerFactory(5)
			},
			{ /* P24 */
				PIN_UNUSED,
				nullptr,
				nullptr
			}
		};
	};
}
