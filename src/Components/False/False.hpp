/*
** EPITECH PROJECT, 2017
** false.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class Cfalse : public IComponent {
	public:
		Cfalse(std::string const &value = "");
		~Cfalse() override = default;
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
