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
	class C4040 : public IComponent {
	public:
		C4040(std::string const &value = "");
		~C4040() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:
		static unsigned int id;

		std::string _id;
		std::size_t _count = 0;
		std::size_t _cycle = 0;
		std::array<Output, 12> _outputs;
		std::array<Input, 2> _inputs;

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
					if (!COMPUTE_REF(_inputs[0]))
						_count++;
					if (COMPUTE_REF(_inputs[1]) == true)
						_count = 0;
				}
				return _outputs[p].state = comp();
			};
		}

		static const std::size_t _nbPins = 16;
		const Ref _pinsRef[_nbPins] = {
			{ /* P1 -> _outputs[0] Q12 */
				PIN_OUTPUT,
				computeFactory(0, [&](){
					return Tristate((_count & (1<<11))>>11);
				}),
				nullptr
			},
			{ /* P2 -> _outputs[1] Q6 */
				PIN_OUTPUT,
				computeFactory(1, [&](){
					return Tristate((_count & (1<<5))>>5);
				}),
				nullptr
			},
			{ /* P3 -> _outputs[2] Q5 */
				PIN_OUTPUT,
				computeFactory(2, [&](){
					return Tristate((_count & (1<<4))>>4);
				}),
				nullptr
			},
			{ /* P4 -> _outputs[3] Q7 */
				PIN_OUTPUT,
				computeFactory(3, [&](){
					return Tristate((_count & (1<<6))>>6);
				}),
				nullptr
			},
			{ /* P5 -> _outputs[4] Q4 */
				PIN_OUTPUT,
				computeFactory(4, [&](){
					return Tristate((_count & (1<<3))>>3);
				}),
				nullptr
			},
			{ /* P6 -> _outputs[5] Q3 */
				PIN_OUTPUT,
				computeFactory(5, [&](){
					return Tristate((_count & (1<<2))>>2);
				}),
				nullptr
			},
			{ /* P7 -> _outputs[6] Q2 */
				PIN_OUTPUT,
				computeFactory(6, [&](){
					return Tristate((_count & (1<<1))>>1);
				}),
				nullptr
			},
			{ /* P8 */
				PIN_UNUSED,
				nullptr,
				nullptr
			},
			{ /* P9 -> _outputs[7] Q1 */
				PIN_OUTPUT,
				computeFactory(7, [&](){
					return Tristate((_count & (1<<0))>>0);
				}),
				nullptr
			},
			{ /* P10 -> _inputs[0] C */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[0]);},
				linkerFactory(0)
			},
			{ /* P11 -> _inputs[1] R */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[1]);},
				linkerFactory(1)
			},
			{ /* P12 -> _outputs[8] Q9 */
				PIN_OUTPUT,
				computeFactory(8, [&](){
					return Tristate((_count & (1<<8))>>8);
				}),
				nullptr
			},
			{ /* P13 -> _outputs[9] Q8 */
				PIN_OUTPUT,
				computeFactory(9, [&](){
					return Tristate((_count & (1<<7))>>7);
				}),
				nullptr
			},
			{ /* P14 -> _outputs[10] Q10 */
				PIN_OUTPUT,
				computeFactory(10, [&](){
					return Tristate((_count & (1<<9))>>9);
				}),
				nullptr
			},
			{ /* P15 -> _outputs[11] Q11 */
				PIN_OUTPUT,
				computeFactory(11, [&](){
					return Tristate((_count & (1<<10))>>10);
				}),
				nullptr
			},
			{ /* P16 */
				PIN_UNUSED,
				nullptr,
				nullptr
			}
		};
	};
}
