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
	class C4008 : public IComponent {
	public:
		C4008(std::string const &value = "");
		~C4008() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:
		static unsigned int id;

		std::string _id;
		ssize_t _sum = -1;
		std::size_t _cycle = 0;
		std::array<Output, 5> _outputs;
		std::array<Input, 9> _inputs;

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
					_sum = COMPUTE_REF(_inputs[7]) +
					COMPUTE_REF(_inputs[6]) + COMPUTE_REF(_inputs[5]) +
					(COMPUTE_REF(_inputs[4]) << 1) + (COMPUTE_REF(_inputs[3]) << 1) +
					(COMPUTE_REF(_inputs[2]) << 2) + (COMPUTE_REF(_inputs[1]) << 2) +
					(COMPUTE_REF(_inputs[0]) << 3) + (COMPUTE_REF(_inputs[8]) << 3);
				}
				return _outputs[p].state = comp();
			};
		}

		static const std::size_t _nbPins = 16;
		const Ref _pinsRef[_nbPins] = {
			{ /* P1 -> _inputs[0] A4 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[0]);},
				linkerFactory(0)
			},
			{ /* P2 -> _inputs[1] B3 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[1]);},
				linkerFactory(1)
			},
			{ /* P3 -> _inputs[2] A3 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[2]);},
				linkerFactory(2)
			},
			{ /* P4 -> _inputs[3] B2 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[3]);},
				linkerFactory(3)
			},
			{ /* P5 -> _inputs[4] A2 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[4]);},
				linkerFactory(4)
			},
			{ /* P6 -> _inputs[5] B1 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[5]);},
				linkerFactory(5)
			},
			{ /* P7 -> _inputs[6] A1 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[6]);},
				linkerFactory(6)
			},
			{ /* P8 */
				PIN_UNUSED,
				nullptr,
				nullptr
			},
			{ /* P9 -> _inputs[7] C1 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[7]);},
				linkerFactory(7)
			},
			{ /* P10 -> _outputs[0] S1 */
				PIN_OUTPUT,
				computeFactory(0, [&](){
					return Tristate(_sum != -1 ? BIT(_sum, 1) : -1);
				}),
				nullptr
			},
			{ /* P11 -> _outputs[1] S2 */
				PIN_OUTPUT,
				computeFactory(1, [&](){
					return Tristate(_sum != -1 ? BIT(_sum, 2) : -1);
				}),
				nullptr
			},
			{ /* P12 -> _outputs[2] S3 */
				PIN_OUTPUT,
				computeFactory(2, [&](){
					return Tristate(_sum != -1 ? BIT(_sum, 3) : -1);
				}),
				nullptr
			},
			{ /* P13 -> _outputs[3] S4 */
				PIN_OUTPUT,
				computeFactory(3, [&](){
					return Tristate(_sum != -1 ? BIT(_sum, 4) : -1);
				}),
				nullptr
			},
			{ /* P14 -> _outputs[4] CO */
				PIN_OUTPUT,
				computeFactory(4, [&](){
					return Tristate(_sum != -1 ? BIT(_sum, 5) : -1);
				}),
				nullptr
			},
			{ /* P15 -> _inputs[8] B4 */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[8]);},
				linkerFactory(8)
			},
			{ /* P16 */
				PIN_UNUSED,
				nullptr,
				nullptr
			}
		};
	};
}
