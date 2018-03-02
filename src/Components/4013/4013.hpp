/*
** EPITECH PROJECT, 2017
** 4013.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class C4013 : public IComponent {
	public:
		C4013(std::string const &value = "");
		~C4013() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;


	private:
		static unsigned int id;

		std::string _id;
		std::array<Output, 4> _outputs;
		std::array<Input, 8> _inputs;

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
			{ /* P1 -> _outputs[0] */
				PIN_OUTPUT,
				computeFactory(0, [&](){
				if (((!COMPUTE_REF(_inputs[0])) | ((!COMPUTE_REF(_inputs[0])) & (!COMPUTE_REF(_inputs[2])))) &
					(!COMPUTE_REF(_inputs[3])) &
					(!COMPUTE_REF(_inputs[1])))
					return _outputs[0].state;
				return ((COMPUTE_REF(_inputs[3])) |
				((COMPUTE_REF(_inputs[0])) &
				(COMPUTE_REF(_inputs[2])) &
				(!COMPUTE_REF(_inputs[1]))));
				}),
				nullptr
			},
			{ /* P2 -> _outputs[1] */
				PIN_OUTPUT,
				computeFactory(1, [&](){
				if (((!COMPUTE_REF(_inputs[0])) | ((!COMPUTE_REF(_inputs[0])) & (!COMPUTE_REF(_inputs[2])))) &
					(!COMPUTE_REF(_inputs[3])) &
					(!COMPUTE_REF(_inputs[1])))
					return _outputs[1].state;
				return ((COMPUTE_REF(_inputs[1])) |
				((COMPUTE_REF(_inputs[0])) &
				(!COMPUTE_REF(_inputs[2])) &
				(!COMPUTE_REF(_inputs[3]))));
				}),
				nullptr
			},
			{ /* P3 -> _inputs[0] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[0]);},
				linkerFactory(0)
			},
			{ /* P4 -> _inputs[1] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[1]);},
				linkerFactory(1)
			},
			{ /* P5 -> _inputs[2] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[2]);},
				linkerFactory(2)
			},
			{ /* P6 -> _inputs[3] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[3]);},
				linkerFactory(3)
			},
			{ /* P7 */
				PIN_UNUSED,
				nullptr,
				nullptr
			},
			{ /* P8 -> _inputs[4] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[4]);},
				linkerFactory(4)
			},
			{ /* P9 -> _inputs[5] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[5]);},
				linkerFactory(5)
			},
			{ /* P10 -> _inputs[6] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[6]);},
				linkerFactory(6)
			},
			{ /* P11 -> _inputs[7] */
				PIN_INPUT,
				[&]() {return COMPUTE_REF(_inputs[7]);},
				linkerFactory(7)
			},
			{ /* P12 -> _outputs[2] */
				PIN_OUTPUT,
				computeFactory(2, [&](){
				if (((!COMPUTE_REF(_inputs[7])) | ((!COMPUTE_REF(_inputs[7])) & (!COMPUTE_REF(_inputs[5])))) &
					(!COMPUTE_REF(_inputs[6])) &
					(!COMPUTE_REF(_inputs[4])))
					return _outputs[2].state;
				return ((COMPUTE_REF(_inputs[6])) |
				((COMPUTE_REF(_inputs[7])) &
				(COMPUTE_REF(_inputs[5])) &
				(!COMPUTE_REF(_inputs[4]))));
				}),
				nullptr
			},
			{ /* P13 -> _outputs[3] */
				PIN_OUTPUT,
				computeFactory(3, [&](){
				if (((!COMPUTE_REF(_inputs[7])) | ((!COMPUTE_REF(_inputs[7])) & (!COMPUTE_REF(_inputs[5])))) &
					(!COMPUTE_REF(_inputs[6])) &
					(!COMPUTE_REF(_inputs[4])))
					return _outputs[3].state;
				return ((COMPUTE_REF(_inputs[4])) |
				((COMPUTE_REF(_inputs[7])) &
				(!COMPUTE_REF(_inputs[5])) &
				(!COMPUTE_REF(_inputs[6]))));
				}),
				nullptr
			},
			{ /* P14 */
				PIN_UNUSED,
				nullptr,
				nullptr
			}
		};
	};
}
