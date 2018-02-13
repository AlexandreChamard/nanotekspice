/*
** EPITECH PROJECT, 2017
** true.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class Ctrue : public IComponent {
	public:
		Ctrue() = default;
		~Ctrue() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:

		nts::Tristate compute1(std::size_t pin);

	private:
		using computePin_t = Tristate (*)();
		std::array<Output, 1> _outputs;
	};
}
