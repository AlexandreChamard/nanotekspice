/*
** EPITECH PROJECT, 2017
** 4030.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class C4030 : public IComponent {
	public:
		C4030(std::string const &value = "");
		~C4030() override = default;
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
		static unsigned int id;

		std::string _id;
		std::array<Output, 4> _outputs;
		std::array<Input, 8> _inputs;
	};
}
