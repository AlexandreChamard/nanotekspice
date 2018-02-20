/*
** EPITECH PROJECT, 2017
** default.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class Cdefault : public IComponent {
	public:
		Cdefault(std::string const &value = "");
		~Cdefault() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;

	private:

		nts::Tristate compute1(std::size_t pin);

	private:
		static unsigned int id;

		std::string _id;
		std::array<Output, 1> _outputs;
	};
}
