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

		std::string _id;
		std::array<Output, 16> _outputs;
		std::array<Input, 4> _inputs;

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

		static const std::size_t _nbPins = 24;
		const Ref _pinsRef[_nbPins] = {
			{ /* P1 */
				PIN_UNUSED,
				nullptr,
				nullptr
			},
			{ /* P2 -> _inputs[0] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[0]);},
				linkerFactory(0)
			},
			{ /* P3 -> _inputs[1] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[1]);},
				linkerFactory(1)
			},
			{ /* P4 -> _outputs[0] */
				PIN_OUTPUT,
				computeFactory(0, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((COMPUTE_REF(_inputs[0])) &
						(COMPUTE_REF(_inputs[1])) &
						(COMPUTE_REF(_inputs[2])) &
						(!COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P5 -> _outputs[1] */
				PIN_OUTPUT,
				computeFactory(1, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((!COMPUTE_REF(_inputs[0])) &
						(COMPUTE_REF(_inputs[1])) &
						(COMPUTE_REF(_inputs[2])) &
						(!COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P6 -> _outputs[2] */
				PIN_OUTPUT,
				computeFactory(2, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((COMPUTE_REF(_inputs[0])) &
						(!COMPUTE_REF(_inputs[1])) &
						(COMPUTE_REF(_inputs[2])) &
						(!COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P7 -> _outputs[3] */
				PIN_OUTPUT,
				computeFactory(3, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((!COMPUTE_REF(_inputs[0])) &
						(COMPUTE_REF(_inputs[1])) &
						(!COMPUTE_REF(_inputs[2])) &
						(!COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P8 -> _outputs[4] */
				PIN_OUTPUT,
				computeFactory(4, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((COMPUTE_REF(_inputs[0])) &
						(COMPUTE_REF(_inputs[1])) &
						(!COMPUTE_REF(_inputs[2])) &
						(!COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P9 -> _outputs[5] */
				PIN_OUTPUT,
				computeFactory(5, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((COMPUTE_REF(_inputs[0])) &
						(!COMPUTE_REF(_inputs[1])) &
						(!COMPUTE_REF(_inputs[2])) &
						(!COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P10 -> _outputs[6] */
				PIN_OUTPUT,
				computeFactory(6, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((!COMPUTE_REF(_inputs[0])) &
						(COMPUTE_REF(_inputs[1])) &
						(!COMPUTE_REF(_inputs[2])) &
						(!COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P11 -> _outputs[7] */
				PIN_OUTPUT,
				computeFactory(7, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((!COMPUTE_REF(_inputs[0])) &
						(!COMPUTE_REF(_inputs[1])) &
						(!COMPUTE_REF(_inputs[2])) &
						(!COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P12 */
				PIN_UNUSED,
				nullptr,
				nullptr
			},
			{ /* P13 -> _outputs[8] */
				PIN_OUTPUT,
				computeFactory(8, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((COMPUTE_REF(_inputs[0])) &
						(!COMPUTE_REF(_inputs[1])) &
						(COMPUTE_REF(_inputs[2])) &
						(COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P14 -> _outputs[9] */
				PIN_OUTPUT,
				computeFactory(9, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((!COMPUTE_REF(_inputs[0])) &
						(!COMPUTE_REF(_inputs[1])) &
						(COMPUTE_REF(_inputs[2])) &
						(COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P15 -> _outputs[10] */
				PIN_OUTPUT,
				computeFactory(10, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((COMPUTE_REF(_inputs[0])) &
						(COMPUTE_REF(_inputs[1])) &
						(COMPUTE_REF(_inputs[2])) &
						(COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P16 -> _outputs[11] */
				PIN_OUTPUT,
				computeFactory(11, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((!COMPUTE_REF(_inputs[0])) &
						(COMPUTE_REF(_inputs[1])) &
						(COMPUTE_REF(_inputs[2])) &
						(COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P17 -> _outputs[12] */
				PIN_OUTPUT,
				computeFactory(12, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((COMPUTE_REF(_inputs[0])) &
						(!COMPUTE_REF(_inputs[1])) &
						(!COMPUTE_REF(_inputs[2])) &
						(COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P18 -> _outputs[13] */
				PIN_OUTPUT,
				computeFactory(13, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((!COMPUTE_REF(_inputs[0])) &
						(!COMPUTE_REF(_inputs[1])) &
						(!COMPUTE_REF(_inputs[2])) &
						(COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P19 -> _outputs[14] */
				PIN_OUTPUT,
				computeFactory(14, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((COMPUTE_REF(_inputs[0])) &
						(COMPUTE_REF(_inputs[1])) &
						(!COMPUTE_REF(_inputs[2])) &
						(COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P20 -> _outputs[15] */
				PIN_OUTPUT,
				computeFactory(1, [&](){
					return	(!COMPUTE_REF(_inputs[4])) &
						((!COMPUTE_REF(_inputs[0])) &
						(COMPUTE_REF(_inputs[1])) &
						(!COMPUTE_REF(_inputs[2])) &
						(COMPUTE_REF(_inputs[3])));
				}),
				nullptr
			},
			{ /* P21 -> _inputs[2] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[2]);},
				linkerFactory(2)
			},
			{ /* P22 -> _inputs[3] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[3]);},
				linkerFactory(3)
			},
			{ /* P23 -> _inputs[4] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[4]);},
				linkerFactory(4)
			},
			{ /* P24 */
				PIN_UNUSED,
				nullptr,
				nullptr
			}
		};
	};
}
