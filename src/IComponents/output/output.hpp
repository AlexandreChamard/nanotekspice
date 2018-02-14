/*
** EPITECH PROJECT, 2017
** input.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class Coutput : public IComponent {
	public:
		Coutput(std::string const &value = "");
		~Coutput() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;
		nts::Tristate getState();

	private:

		nts::Tristate compute1(std::size_t pin);

	private:
		static unsigned int id;

		std::string _id;
		nts::Tristate state;
	};
}
