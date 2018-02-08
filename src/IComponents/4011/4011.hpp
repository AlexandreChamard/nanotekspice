/*
** EPITECH PROJECT, 2017
** 4011.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class C4011 : public IComponent {
	public:
		C4011() = default;
		~C4011() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:
		Tristate compute1();
		Tristate compute2();
		Tristate compute3();
		Tristate compute4();

	private:
		using computePin_t = Tristate (*)();
		std::array<Output, 4> _outputs;
		std::array<Input, 8> _inputs;
	};
}
