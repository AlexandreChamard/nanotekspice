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
		C4069() = default;
		~C4069() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:
		Tristate compute1();
		Tristate compute2();
		Tristate compute3();
		Tristate compute4();
		Tristate compute5();
		Tristate compute6();

	private:
		using computePin_t = Tristate (*)();
		std::array<Output, 6> _outputs;
		std::array<Input, 6> _inputs;
	};
}
