/*
** EPITECH PROJECT, 2017
** 4512.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class C4512 : public IComponent {
	public:
		C4512() = default;
		~C4512() override = default;
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
		Tristate compute7();
		Tristate compute8();

	private:
		using computePin_t = Tristate (*)();
		std::array<Output, 8> _outputs;
		std::array<Input, 3> _inputs;
	};
}
